/**
 * @file Game.h
 * @author sriram
 *
 *
 */

#ifndef PROJECT1_GAMELIB_GAME_H
#define PROJECT1_GAMELIB_GAME_H

#include <memory>
#include <vector>
#include <map>
#include <utility>
#include <string>
#include "Bug.h"
#include "Item.h"
#include <random>
#include <wx/graphics.h>

class Game
{
private:
    /// The Laptop image
    std::shared_ptr<wxImage> mLaptopImage;

    //Laptop Bitmap
	wxGraphicsBitmap mLaptopBitmap;

	/// All of the bugs in game
	std::vector<std::shared_ptr<Item> > mItems;

	void XmlBug(wxXmlNode *node);

	/// Random number generator
	std::mt19937 mRandom;

    //Is Window Shrunk?
    bool mShrinked;

    //Scaled Window Value
    double mScale;

    //X-coord scale offset
    double mXOffset;

    //Y-coord scale offset
    double mYOffset;

public:
	Game();

	/**
	 * Destructor
	*/
	virtual ~Game() = default;


	void Add(std::shared_ptr<Bug> item);
	std::shared_ptr<Item> HitTest(int x, int y);
	void MoveToFront(std::shared_ptr<Bug> item);
	void MovetoEnd(std::shared_ptr<Bug> item);
	void DeleteBug(std::shared_ptr<Bug> item);


	void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

	void Clear();

    /**
     * Shrink The Game Window
     */
    void Shrink();

    /**
     * Is the Game Shrunk?
     * @return bool
     */
    bool IsShrunk() {return mShrinked;}

	void Update(double elapsed);
	void SortBugs();


	/**
     * Get the random number generator
     * @return Pointer to the random number generator
     */
	std::mt19937 &GetRandom() {
		// Seed the random number generator
		std::random_device rd;
		mRandom.seed(1238197374);
		return mRandom;}
};

#endif //PROJECT1_GAMELIB_GAME_H
