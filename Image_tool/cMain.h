#pragma once
#include "wx/wx.h"
class cMain : public wxMDIParentFrame
{
public:
	cMain(); // all the init of the GUI happens here...
	~cMain();
private:
	wxToolBar* toolBar = nullptr; // Implemented
	wxMenuBar* menuBar = nullptr; // Implemented


	// Manejo de los eventos-----------------
	void InMenuOpenNew(wxCommandEvent& event);//
	void InMenuSave(wxCommandEvent& event);// 
	void InMenuExit(wxCommandEvent& event);//
	// ------------------------------------
	wxDECLARE_EVENT_TABLE();
};


// this is a test to see if the new branch actually works.