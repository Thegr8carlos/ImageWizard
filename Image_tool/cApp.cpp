// Entry point for our program, this is the main for wxWidgets

#include "cApp.h"

wxIMPLEMENT_APP(cApp); 

cApp::cApp()
{
}

cApp::~cApp()
{
}

bool cApp::OnInit() // Init
{
	m_frame1 = new cMain(); // Creating a new instance of a wx frame
	m_frame1->Show(); // window show
	return true;
}