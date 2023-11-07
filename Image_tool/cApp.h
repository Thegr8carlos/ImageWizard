// like a meta_main...

#pragma once
#include "wx/wx.h"
#include "cMain.h"



class cApp : public wxApp
{
private:
	cMain* m_frame1 = nullptr; // initial frame wich is null at the initial state of the application 

public: 
	cApp(); // class constructor 
	~cApp(); // class deconstructor 
	virtual bool OnInit(); // Initializer of the window application 
};

