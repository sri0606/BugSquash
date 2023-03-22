/**
 * @file NullBug.cpp
 * @author srira
 */

#include "pch.h"
#include "NullBug.h"
#include "Game.h"

/// The bug sprite image
const std::wstring NullBugSpriteImageName = L"images/scarlet-gray-bug.png";

/// The splat image
const std::wstring NullBugSplatImageName = L"images/scarlet-gray-splat.png";

/// Number of sprite images
const int NullBugNumSpriteImages = 6;

/**
 * NullBug Constructor
 * @param game Game this bug is a member of
 */
NullBug::NullBug(Game *game) : Bug(game, NullBugSpriteImageName)
{
}
