#pragma once
#include "wx/wx.h"
class cMain : public wxFrame
{
public:
	cMain();
	~cMain();
public: // aall the instances of the main window
	wxButton* bttn1 = nullptr;
	wxTextCtrl* txt1 = nullptr;
	wxListBox* list1 =  nullptr;
};

