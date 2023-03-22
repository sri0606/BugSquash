/**
 * @file FeatureBug.h
 * @author srira
 *
 *
 */

#ifndef GAME_GAME_GAMELIB_FEATUREBUG_H
#define GAME_GAME_GAMELIB_FEATUREBUG_H

#include "Bug.h"
#include "Game.h"


class FeatureBug: public Bug
{
private:

public:
	/// Default constructor (disabled)
	FeatureBug() = delete;

	/// Copy constructor (disabled)
	FeatureBug(const FeatureBug &) = delete;

	/// Assignment operator
	void operator=(const FeatureBug &) = delete;
	FeatureBug(Game *game);
};

#endif //GAME_GAME_GAMELIB_FEATUREBUG_H
