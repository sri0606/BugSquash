/**
 * @file Bug.h
 * @author sriram
 *
 *
 */

#ifndef GAME_GAME_GAMELIB_BUG_H
#define GAME_GAME_GAMELIB_BUG_H

#include "Item.h"


class Game;

class Bug : public Item {
private:
    /// Bug speed in the X direction
    /// in pixels per second
    double mSpeedX;

    /// Bug speed in the Y direction
    /// in pixels per second
    double mSpeedY;

public:
    /// Default constructor (disabled)
    Bug() = delete;

    /// Copy constructor (disabled)
    Bug(const Bug &) = delete;

    /// Assignment operator
    void operator=(const Game &) = delete;


	//virtual void Draw(wxDC *dc);

    // not sure if either of these did anything

	//virtual void XmlLoad(wxXmlNode *node);

//	/**  Test this item to see if it has been clicked on
//    * @param x X location on the city to test
//    * @param y Y location on the city to test
//    * @return true if clicked on */
//	virtual bool HitTest(int x, int y);

	///  Handle updates for animation
	/// @param elapsed The time since the last update
	void Update(double elapsed);
    //made not virtual, not sure if it did anything
protected:
    Bug(Game* game, const std::wstring& filename);

};

#endif //GAME_GAME_GAMELIB_BUG_H
