/**
 * @file Game.cpp
 * @author sriram
 * @author ethan
 */

#include "pch.h"

#include "Game.h"
#include <wx/xml/xml.h>
#include <wx/graphics.h>
#include <algorithm>
#include "Bug.h"
#include "GarbageBug.h"
#include "NullBug.h"
#include "RedundancyBug.h"
#include "FeatureBug.h"

using namespace std;

/// Game area in virtual pixels
const static int GameWidth = 1250;

/// Game area height in virtual pixels
const static int GameHeight = 1000;

/// Shrink Scaler
const static double ShrinkScale = .75;

/// Program image filename
const std::wstring ProgramImage = L"images/laptop.png";

/// Program name font size
const int ProgramNameFontSize = 22;


/**
 * Draw the game
 * @param dc The device context to draw on
 */
void Game::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    //Create Image Bitmap
    if (mLaptopBitmap.IsNull()) {
        mLaptopBitmap = graphics->CreateBitmapFromImage(*mLaptopImage);
    }

    int laptopWid = mLaptopImage->GetWidth();
    int laptopHgt = mLaptopImage->GetHeight();

    //
    // Automatic Scaling
    //
    auto scaleX = double(width) / double(GameWidth);
    auto scaleY = double(height) / double(GameHeight);
    mScale = std::min(scaleX, scaleY);

    if(mShrinked)
    {
        mScale *= ShrinkScale;
    }

    mXOffset = (width - GameWidth * mScale) / 2;
    mYOffset = (height - GameHeight * mScale) / 2;

    graphics->PushState();

    graphics->Translate(mXOffset, mYOffset);
    graphics->Scale(mScale, mScale);

    int centerX = (GameWidth * mScale)/2;
    int centerY = (GameHeight * mScale)/2;

    //
    // A rectangle for the virtual area we are drawing on
    //

    wxBrush rectBrush(*wxWHITE);
    graphics->SetBrush(rectBrush);
    graphics->SetPen(*wxWHITE_PEN);
    graphics->DrawRectangle(0, 0, GameWidth, GameHeight);

    //Draw Laptop
    graphics->DrawBitmap(mLaptopBitmap, centerX, centerY, laptopWid, laptopHgt);

	wxFont font(wxSize(0, 22),
				wxFONTFAMILY_SWISS,
				wxFONTSTYLE_NORMAL,
				wxFONTWEIGHT_NORMAL);
    graphics->SetFont(font, wxColour(255, 0, 255));

//	for(auto bug : mItems)
//	{
//		bug->Draw(dc);
//	}

    graphics->PopState();
}

/**
 * Game Constructor
 */
Game::Game()
{
    mLaptopImage = std::make_shared<wxImage>(ProgramImage);
}

/**
 * Add an bug to the game
 * @param bug New bug to add
 */
void Game::Add(std::shared_ptr<Bug> bug)
{
	//Use Bug visitor to get list of bugs
	//bug->SetLocation(X, Y);
	mItems.push_back(bug);
}


/**
 * Test an x,y click location to see if it clicked
 * on some bug in the game.
 * @param x X location in pixels
 * @param y Y location in pixels
 * @returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<Item> Game::HitTest(int x, int y)
{

	//Use Bug visitor to get list of bugs
	for(auto i = mItems.rbegin(); i != mItems.rend(); i++)
	{
		if((*i)->HitTest(x, y))
		{
			return *i;
		}
	}
	return nullptr;
}




/**
 * Handle a node of type bug.
 * @param node XML node
 */
//void Game::XmlBug(wxXmlNode *node)
//{
//	// A pointer for the item we are loading
//	shared_ptr<Bug> bug;
//
//	// We have a bug. What type?
//	auto type = node->GetAttribute(L"type");
//	if(type == L"garbage")
//	{
//		bug = make_shared<GarbageBug>(this);
//	}
//	else if(type == L"null")
//	{
//		bug = make_shared<NullBug>(this);
//	}
//	else if(type == L"redundancy")
//	{
//		bug = make_shared<RedundancyBug>(this);
//	}
//	else if(type == L"feature")
//	{
//		bug = make_shared<FeatureBug>(this);
//	}
//
//	if(bug != nullptr)
//	{
//		Add(bug);
//		bug->XmlLoad(node);
//	}
//
//}

/**
 * Clear the game data.
 *
 * Deletes all known items in the game.
 */
void Game::Clear()
{
	// TO DO...
	mItems.clear();

}


/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Game::Update(double elapsed)
{
	for (auto bug : mItems)
	{
		bug->Update(elapsed);
	}
}

/**  Delete an bug from the game
*
* @param bug The item to delete.
*/
void Game::DeleteBug(std::shared_ptr<Bug> bug)
{

	auto loc = find(std::begin(mItems), std::end(mItems), bug);
	if (loc != std::end(mItems))
	{
		mItems.erase(loc);
	}
}

void Game::Shrink()
{
    mShrinked = !(mShrinked);
}
