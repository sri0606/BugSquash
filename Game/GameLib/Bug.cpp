/**
 * @file Bug.cpp
 * @author srira
 */

#include "Bug.h"
#include "pch.h"
#include <random>
#include "Game.h"

/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 50;

/// Minimum speed in the X direction in
/// pixels per second
const double MinSpeedX = 20;

/**
 * Constructor
 * @param game The game we are in
 * @param filename Filename for the image we use
 */
Bug::Bug(Game *game, const std::wstring &filename) :
        Item(game, filename)
{
    std::uniform_real_distribution<> distribution(MinSpeedX, MaxSpeedX);
    mSpeedX = distribution(game->GetRandom());
    mSpeedY = 0;
}

/**
 * Handle updates in time of our bug
 *
 * This is called before we draw and allows us to
 * move our bug. We add our speed times the amount
 * of time that has elapsed.
 * @param elapsed Time elapsed since the class call
 */
void Bug::Update(double elapsed)
{
    SetLocation(GetX() + mSpeedX * elapsed,
            GetY() + mSpeedY * elapsed);
    //need to implement
//    if (mSpeedX > 0 && GetX() >= GetGame()->GetWidth())
//    {
//        mSpeedX = -mSpeedX;
//        SetMirror(true);
//
}