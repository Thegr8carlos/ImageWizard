#include "cMain.h"

// our implementation of the GUI

// The parent of all the components is wxFrame
cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Image Tool", wxPoint(30,30), wxSize(600, 600))
{
	// all of these are the sons of wxFrame an thats why we pass this in wxParent
	bttn1 = new wxButton(this, wxID_ANY, "Click me", wxPoint(10, 10), wxSize(150, 50));
	txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 70), wxSize(300, 300));
	list1 = new wxListBox(this, wxID_ANY, wxPoint(10, 110), wxSize(300, 300));
}

cMain:: ~cMain()
{
}