/**
 * @file MainFrame.h
 * @author Auden Garrard
 *
 * The top-level (main) frame of the application
 */

#ifndef PROJECT_GAMELIB_MAINFRAME_H
#define PROJECT_GAMELIB_MAINFRAME_H

#include <wx/filehistory.h>
#include <wx/config.h>

class GameView;

/**
 * The top-level (main) frame of the application
 */
class MainFrame : public wxFrame
{
private:

	/// Pointer to GameView
	GameView *mGameView;

	void OnExit(wxCommandEvent& event);

	void OnAbout(wxCommandEvent& event);

	void OnClose(wxCommandEvent& event);

public:

	void Initialize();

};

#endif //PROJECT_GAMELIB_MAINFRAME_H
