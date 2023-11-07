// Entry point for our program, this is the main for wxWidgets

#include "cApp.h"

#define APP_NAME "Image Wizard"



wxIMPLEMENT_APP(cApp); 

cApp::cApp()
{
}

cApp::~cApp()
{
}

bool cApp::OnInit() // Init
{
	wxInitAllImageHandlers(); // To suport all the image files
	m_frame1 = new cMain(); // Creating a new instance of a wx frame (the main window)
	m_frame1->Show(); // window show
	return true;
}