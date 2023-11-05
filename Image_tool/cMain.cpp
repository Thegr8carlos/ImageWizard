#include "cMain.h"
#include "cEditorFrame.h"
// our implementation of the GUI

wxBEGIN_EVENT_TABLE(cMain, wxMDIParentFrame)
// handle the event in the menu when is click (ID of the menuElement and the funciton to call in that event)
EVT_MENU(1001, cMain::InMenuNew) 
EVT_MENU(1002, cMain::InMenuOpen)
EVT_MENU(1003, cMain::InMenuSave)
EVT_MENU(1004, cMain::InMenuExit)
wxEND_EVENT_TABLE()

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

	// Toolbar
	toolBar = this->CreateToolBar(wxTB_HORIZONTAL, wxID_ANY);

	wxColour colors[16];
	colors[0] = wxColour(0, 0, 0);
	colors[1] = wxColour(0, 0, 128);
	colors[2] = wxColour(0, 128, 0);
	colors[3] = wxColour(0, 128, 128);
	colors[4] = wxColour(128, 0, 0);
	colors[5] = wxColour(128, 0, 128);
	colors[6] = wxColour(128, 128, 0);
	colors[7] = wxColour(192, 192, 192);
	colors[8] = wxColour(128, 128, 128);
	colors[9] = wxColour(0, 0, 255);
	colors[10] = wxColour(0, 255, 0);
	colors[11] = wxColour(0, 255, 255);
	colors[12] = wxColour(255, 0, 0);
	colors[13] = wxColour(255, 0, 255);
	colors[14] = wxColour(255, 255, 0);
	colors[15] = wxColour(255, 255, 255);

	for (int i = 0; i < 16; i++)
	{
		wxButton* b = new wxButton(toolBar, 10100 + i, "", wxDefaultPosition, wxSize(40, 24), 0);
		b->SetBackgroundColour(colors[i]);
		toolBar->AddControl(b);
	}

	wxButton* b = new wxButton(toolBar, 10100 + 16, "ALPHA", wxDefaultPosition, wxSize(40, 24), 0);
	toolBar->AddControl(b);
	toolBar->Realize();
}

cMain:: ~cMain()
{
}

void cMain::InMenuNew(wxCommandEvent& event) // event to create a new window (wxMDIChildFrame)
{
	cEditorFrame* window = new cEditorFrame(this, "son");
	window->Show();
	event.Skip();
}

void cMain::InMenuOpen(wxCommandEvent& event)
{
}

void cMain::InMenuSave(wxCommandEvent& event)
{
}

void cMain::InMenuExit(wxCommandEvent& event)
{
	Close();
	event.Skip();
}
