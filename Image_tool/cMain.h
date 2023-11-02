#pragma once
#include "wx/wx.h"
class cMain : public wxMDIParentFrame
{
public:
	cMain(); // all the init of the GUI happens here...
	~cMain();
private:
	wxToolBar* toolBar = nullptr; // not yet...
	wxMenuBar* menuBar = nullptr; // Implemented

	//void InMenuNew(wxCommandEvent& event);
	//void InMenuOpen(wxCommandEvent& event);
	//void InMenuSave(wxCommandEvent& event); handle events functions
	//void InMenuExit(wxCommandEvent& event);

	//wxDECLARE_EVENT_TABLE();
};


