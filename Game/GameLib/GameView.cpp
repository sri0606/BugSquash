/**
 * @file GameView.cpp
 * @author sriram
 * @author ethan
 */

#include "pch.h"

#include <sstream>
#include <wx/stdpaths.h>
#include <wx/dcbuffer.h>
#include <wx/graphics.h>

#include "ids.h"

#include "GameView.h"
#include "GarbageBug.h"
#include "NullBug.h"
#include "RedundancyBug.h"
#include "FeatureBug.h"


/// Frame duration in milliseconds
const int FrameDuration = 30;

/// Game area in virtual pixels
const static int GameWidth = 1250;

/// Game area height in virtual pixels
const static int GameHeight = 1000;


using namespace std;

/**
 * Initialize the game view class.
 * @param parent The parent window for this class
 */
void GameView::Initialize(wxFrame* parent)
{

	Create(parent, wxID_ANY,
            wxDefaultPosition, wxDefaultSize,
            wxFULL_REPAINT_ON_RESIZE);

	SetBackgroundStyle(wxBG_STYLE_PAINT);

	Bind(wxEVT_PAINT, &GameView::OnPaint, this);
	//parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnFileSaveAs, this, wxID_SAVEAS);
	//parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnFileOpen, this, wxID_OPEN);
	parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnAddGarbageBug, this, IDM_ADDGARBAGEBUG);
	parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnAddNullBug, this, IDM_ADDNULLBUG);
	parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnAddRedundancyBug, this, IDM_ADDREDUNDANCYBUG);
	parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnAddFeatureBug, this, IDM_ADDFEATUREBUG);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnViewShrink, this, IDM_SHRINK);

	// The mouse events
	Bind(wxEVT_LEFT_DOWN, &GameView::OnLeftDown, this);
	Bind(wxEVT_LEFT_UP, &GameView::OnLeftUp, this);
	Bind(wxEVT_MOTION, &GameView::OnMouseMove, this);
	Bind(wxEVT_LEFT_DCLICK, &GameView::OnDoubleClick, this);
	Bind(wxEVT_TIMER, &GameView::OnTimer, this);

	// The timer for animation
	mTimer.SetOwner(this);
	mTimer.Start(FrameDuration);
	mStopWatch.Start();
}



/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void GameView::OnPaint(wxPaintEvent& event)
{
    // Create a double-buffered display context
    wxAutoBufferedPaintDC dc(this);

    // Clear the image to black
    wxBrush background(*wxBLACK);
    dc.SetBackground(background);
    dc.Clear();

    // Compute the time that has elapsed
    // since the last call to OnPaint.
    auto newTime = mStopWatch.Time();
    auto elapsed = (double)(newTime - mTime) * 0.001;
    mTime = newTime;

    mGame.Update(elapsed);

    // Create a graphics context
    auto gc = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));

    // Tell the game class to draw
    wxRect rect = GetRect();
    auto minDimension = min(rect.GetWidth(), rect.GetHeight());
    if(minDimension == 0)
    {
        // No reason to draw if the window is size zero
        // and this avoids any divide by zero errors
        return;
    }

    mGame.OnDraw(gc, rect.GetWidth(), rect.GetHeight());
}


/**
 * Event handler for wxEVT_TIMER
 * @param event Timer event
 */
void GameView::OnTimer(wxTimerEvent &event){
	Refresh();
}


/**
* Handle the left mouse button down event
* @param event
*/
void GameView::OnLeftDown(wxMouseEvent &event)
{
	OnMouseMove(event);
}


/**
* Handle the left mouse button up event
* @param event
*/
void GameView::OnLeftUp(wxMouseEvent &event)
{
	OnMouseMove(event);
}

/**
* Handle the left mouse button down event
* @param event
*/
void GameView::OnMouseMove(wxMouseEvent &event)
{

}

/**
* Checks for double click
* @param event
*/

void GameView::OnDoubleClick(wxMouseEvent &event)
{
	mClickedItem  = mGame.HitTest(event.GetX(), event.GetY());

	//ADD THIS: Use Bug visitor to check if mClickedItem is bug
	if (mClickedItem != nullptr )
	{
		// DO BUG SQUASH
		// DELETE BUG AND PAINT SQUASH
		//ADD COUNTER
		Refresh();
	}
}

/**
 * Menu handler for Add Bug> Garbage Bug
 * @param event Menu event
 */
 void GameView::OnAddGarbageBug(wxCommandEvent &event) {
	 auto bug = make_shared<GarbageBug>(&mGame);
	 mGame.Add(bug);
	 Refresh();
 }

/**
* Menu handler for Add Bug> Null Bug
* @param event Menu event
*/
void GameView::OnAddNullBug(wxCommandEvent &event) {
	auto bug = make_shared<NullBug>(&mGame);
	mGame.Add(bug);
	Refresh();
}

/**
 * Menu handler for Add Bug> Redundancy Bug
 * @param event Menu event
 */
void GameView::OnAddRedundancyBug(wxCommandEvent &event) {
	auto bug = make_shared<RedundancyBug>(&mGame);
	mGame.Add(bug);
	Refresh();
}

/**
 * Menu handler for Add Bug> Feature Bug
 * @param event Menu event
 */
void GameView::OnAddFeatureBug(wxCommandEvent &event) {
	auto bug = make_shared<FeatureBug>(&mGame);
	mGame.Add(bug);
	Refresh();
}

void GameView::OnViewShrink(wxCommandEvent& event)
{
    mGame.Shrink();
    Refresh();
}


///**
// * Add menus specific to the view
// * @param mainFrame The main frame that owns the menu bar
// * @param menuBar The menu bar to add menus to
// * @param fileMenu The file menu, so we can add to it if we wish
// * @param viewMenu The view menu, so we can add to it if we wish
// */
//
//void GameView::AddMenus(wxFrame* mainFrame, wxMenuBar *menuBar, wxMenu* fileMenu, wxMenu* viewMenu)
//{
//	auto levelMenu = new wxMenu();
//
//
//	// Options added to the view menu
//	viewMenu->Append(IDM_VIEW_SHRINK, L"&Shrink", L"Enable to disable shrink", wxITEM_CHECK);
//
//	mainFrame->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnViewShrink, this, IDM_VIEW_SHRINK);
//	mainFrame->Bind(wxEVT_UPDATE_UI, &CityView::OnUpdateViewShrink, this, IDM_VIEW_SHRINK);
//
//	//
//	// Level menu options
//	//
//	AddLevelMenuOption(mainFrame, levelMenu, IDM_LEVEL0, L"&Level 0", L"Play Level 0");
//	AddLevelMenuOption(mainFrame, levelMenu, IDM_LEVEL1, L"&Level 1", L"Play Level 1");
//	AddLevelMenuOption(mainFrame, levelMenu, IDM_LEVEL2, L"&Level 2", L"Play Level 2");
//	AddLevelMenuOption(mainFrame, levelMenu, IDM_LEVEL3, L"&Level 3", L"Play Level 3");
//
//	//
//	// Append the menus to the menubar
//	//
//	menuBar->Append(levelMenu, L"Level" );
//}
//
//
///**
// * Append an option to a menu and bind it to the function GameView::OnAddLevelMenuOption
// *
// * All of the menu options to add a tile use the same menu handler, which uses
// * a switch based on the ID to determine which option to make.
// *
// * @param mainFrame The MainFrame object that owns the menu
// * @param menu The Menu we are adding the option to
// * @param id The Menu option ID
// * @param text Text for the menu option
// * @param help Help for the menu option
// */
//void GameView::AddLevelMenuOption(wxFrame *mainFrame, wxMenu *menu, int id,
//								  const std::wstring& text, const std::wstring& help)
//{
//	menu->Append(id, text, help);
//	mainFrame->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnAddLevelMenuOption, this, id);
//}

