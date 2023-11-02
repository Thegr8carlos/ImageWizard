// like a meta_main...

#pragma once
#include "wx/wx.h"
#include "cMain.h"



class cApp : public wxApp
{
public:
	cApp();
	~cApp();

public: 
	virtual bool OnInit(); // Initializer of the window application 

private:
	cMain* m_frame1 = nullptr; // initial frame wich is null at the initial state of the application 

};

