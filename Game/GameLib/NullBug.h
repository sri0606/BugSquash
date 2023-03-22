/**
 * @file NullBug.h
 * @author srira
 *
 *
 */

#ifndef GAME_GAME_GAMELIB_NULLBUG_H
#define GAME_GAME_GAMELIB_NULLBUG_H

#include "Bug.h"
#include "Game.h"
class NullBug: public Bug
{
private:

public:
	/// Default constructor (disabled)
	NullBug() = delete;

	/// Copy constructor (disabled)
	NullBug(const NullBug &) = delete;

	/// Assignment operator
	void operator=(const NullBug &) = delete;
	NullBug(Game *game);
};

#endif //GAME_GAME_GAMELIB_NULLBUG_H
