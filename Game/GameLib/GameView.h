/**
 * @file GameView.h
 * @author sriram
 *
 *
 */


#ifndef PROJECT1_GAMELIB_GAMEVIEW_H
#define PROJECT1_GAMELIB_GAMEVIEW_H

#include "Game.h"
#include "Item.h"

/**
 * Class that defines our Game View
 */
class GameView : public wxWindow
{
private:

	/// An object that describes our game
	Game mGame;

	/// The timer that allows for animation
	wxTimer mTimer;

	/// Stopwatch used to measure elapsed time
	wxStopWatch mStopWatch;

	/// Any bug we are currently dragging
	std::shared_ptr<Item> mClickedItem;

	/// The last stopwatch time
	long mTime = 0;

	void OnPaint(wxPaintEvent& event);

	void OnAddGarbageBug(wxCommandEvent& event);
	void OnAddNullBug(wxCommandEvent& event);
	void OnAddRedundancyBug(wxCommandEvent& event);
	void OnAddFeatureBug(wxCommandEvent& event);


public:

	void Initialize(wxFrame* );

	void OnMouseMove(wxMouseEvent &event);
	void OnLeftUp(wxMouseEvent &event);
	void OnLeftDown(wxMouseEvent &event);
	void OnDoubleClick(wxMouseEvent &event);


	void OnTimer(wxTimerEvent &event);

	void OnViewShrink(wxCommandEvent &event);
	void OnUpdateViewShrink(wxUpdateUIEvent &event);
	void AddLevelMenuOption(wxFrame* mainFrame, wxMenu* menu, int id, const std::wstring& text, const std::wstring& help);

//	void OnAddGarbageBug(wxCommandEvent &event);
//	void OnAddNullBug(wxCommandEvent &event);
//	void OnAddRedundancyBug(wxCommandEvent &event);
//	void OnAddFeatureBug(wxCommandEvent &event);
};

#endif //PROJECT1_GAMELIB_GAMEVIEW_H
