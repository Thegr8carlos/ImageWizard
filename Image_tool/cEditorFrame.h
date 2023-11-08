#pragma once
#include "wx/wx.h"
#include "cCanvas.h"
// window parent that handles all the subwindows
class cEditorFrame : public wxMDIChildFrame
{
public: 
	cEditorFrame(wxMDIParentFrame* parent, wxString FileName);
	~cEditorFrame();
private:
	cCanvas* n_canvas = nullptr; // canvas to show the image


	wxStatusBar* n_StatusBar = nullptr; // slider status
	wxSlider* zoomSlider =  nullptr; // slider to zoom 

	void OnZoomChange(wxCommandEvent& event); // handle event when the zoom slider changes

	wxDECLARE_EVENT_TABLE();
};

