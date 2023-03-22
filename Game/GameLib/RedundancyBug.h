/**
 * @file RedundancyBug.h
 * @author srira
 *
 *
 */

#ifndef GAME_GAME_GAMELIB_REDUNDANCYBUG_H
#define GAME_GAME_GAMELIB_REDUNDANCYBUG_H

#include "Bug.h"
#include "Game.h"

class RedundancyBug: public Bug
{
private:

public:

	/// Default constructor (disabled)
	RedundancyBug() = delete;

	/// Copy constructor (disabled)
	RedundancyBug(const RedundancyBug &) = delete;

	/// Assignment operator
	void operator=(const RedundancyBug &) = delete;
	RedundancyBug(Game *game);

};

#endif //GAME_GAME_GAMELIB_REDUNDANCYBUG_H
