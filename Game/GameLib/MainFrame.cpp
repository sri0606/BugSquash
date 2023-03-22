/**
 * @file MainFrame.cpp
 * @author Auden Garrard
 */

#include "pch.h"
#include "MainFrame.h"
#include "GameView.h"
#include "ids.h"
/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{
	// To make the intial fram bigger change the xx and yyo
	Create(nullptr,wxID_ANY,L"Bug Squash",
		   	wxDefaultPosition,wxSize(1000,800));

	auto sizer = new wxBoxSizer( wxVERTICAL );

	 //Create the view class object as a child of MainFrame
	mGameView = new GameView();
	mGameView->Initialize(this);

	sizer->Add(mGameView,1, wxEXPAND | wxALL);

	SetSizer(sizer);

	Layout();

	//This makes the status bar
	CreateStatusBar(1,wxSTB_SIZEGRIP,wxID_ANY);

	auto menuBar = new wxMenuBar();

	// Making the menu bar categorises
	auto fileMenu = new wxMenu();
	auto levelMenu = new wxMenu();
	auto viewMenu = new wxMenu();

	//assigning the menubar with the
	menuBar->Append(fileMenu,L"&File");
	menuBar->Append(levelMenu,L"&Level");
	menuBar->Append(viewMenu,L"&View");

	//File menu  Does nothing in the game
	fileMenu->Append(wxID_EXIT, "E&xit\tAlt-X", "Quit this program");

	//Level menu bar
	levelMenu->Append(IDM_LEVELZERO,L"&Level Zero", L"Take you to level zero");
	levelMenu->Append(IDM_LEVELONE,L"&Level One", L"Take you to level one");
	levelMenu->Append(IDM_LEVELTWO,L"&Level Two", L"Take you to level two");
	levelMenu->Append(IDM_LEVELTHREE,L"&Level Three", L"Take you to level three");

	//Shrink menu bar
	viewMenu->Append(IDM_SHRINK,L"&Shrink",L"Turning off clipping ");

	Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
	Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnAbout, this, wxID_ABOUT);

	SetMenuBar(menuBar);
}

/**
 * Exit menu option handlers
 * @param event Mouse event
 */
void MainFrame::OnExit(wxCommandEvent& event)
{
	Close(true);
}
/**
* About menu option handler
* @param event Mouse event
*/
void MainFrame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox(L"Welcome to the Bug Squash!",
			  L"About Bug Squash",
			  wxOK,
			  this);
}

void MainFrame::OnClose(wxCommandEvent& event)
{

}
