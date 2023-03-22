/**
 * @file GarbageBug.cpp
 * @author srira
 */

#include "pch.h"
#include "GarbageBug.h"
#include "Game.h"

/// The bug sprite image
const std::wstring GarbageBugSpriteImageName = L"images/blue-maize-bug.png";

/// The splat image
const std::wstring GarbageBugSplatImageName = L"images/blue-maize-splat.png";

/// Number of sprite images
const int GarbageBugNumSpriteImages = 5;

/**
 * GarbageBug Constructor
 * @param game Game this bug is a member of
 */
GarbageBug::GarbageBug(Game *game) : Bug(game, GarbageBugSpriteImageName)
{
}