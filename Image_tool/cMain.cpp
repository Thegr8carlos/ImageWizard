#include "cMain.h"

// our implementation of the GUI

// The parent of all the components is wxMDIParentFrame
cMain::cMain() : wxMDIParentFrame(nullptr, wxID_ANY, "Image Wizard", wxPoint(30,30), wxSize(600,400 ))
{
	// menu bar  []
	wxMenuBar* menuBar = new wxMenuBar();
	this->SetMenuBar(menuBar);
	// adding sub-menus for the file menu [1001],[1002],[1003],[1004]
	wxMenu* menuFile = new wxMenu();
	menuFile->Append(1001, "New");
	menuFile->Append(1002, "Open");
	menuFile->Append(1003, "Save");
	menuFile->Append(1004, "Exit");
	// ading the menu for the instance of the menuBar [ File[ New[1001], Open[1002], Save[1003], Exit[1004] ] ]
	menuBar->Append(menuFile, "File");
	// you got the idea...
	wxMenu* menuBf = new wxMenu();
	menuBf->Append(2001, "Bf1");
	menuBf->Append(2002, "Bf2");
	menuBf->Append(2003, "Bf3");
	menuBf->Append(2004, "Bf4");
	menuBar->Append(menuBf, "Basic filters");
}

cMain:: ~cMain()
{
}