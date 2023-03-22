/**
 * @file Program.cpp
 * @author Aman Todi
 */

#include "pch.h"
#include "Program.h"

/// Program image filename
const std::wstring ProgramImage = L"images/laptop.png";

/// Program name font size
const int ProgramNameFontSize = 22;

/**
 * Program Constructor
 *
 * @param game
 * @param filename
 */
Program::Program(Game* game) : Item(game, ProgramImage)
{
	this->SetLocation(625, 500);
}

