/**
 * @file FeatureBug.cpp
 * @author srira
 */

#include "pch.h"
#include "FeatureBug.h"
#include "Game.h"

/// The feature sprite image
const std::wstring FeatureImageName = L"images/feature.png";

/// The splat image
const std::wstring FeatureSplatImageName = L"images/feature-splat.png";

/// Number of sprite images
const int FeatureNumSpriteImages = 7;

/**
 * FeatureBug Constructor
 * @param game Game this bug is a member of
 */
FeatureBug::FeatureBug(Game *game) : Bug(game, FeatureImageName)
{
}

