#pragma once
#include "wx/wx.h"
#include "cCanvas.h"
// all the subwindows visualizer
class cEditorFrame : public wxMDIChildFrame
{
public: 
	cEditorFrame(wxMDIParentFrame* parent, wxString FileName);
	~cEditorFrame();
private:
	cCanvas* n_canvas = nullptr; // canvas for edit the sprite
	wxStatusBar* n_StatusBar = nullptr; // status of the sprite
	wxSlider* zoomSlider =  nullptr; // slider to zoom 

	void OnZoomChange(wxCommandEvent& event); // handle event when the zoom slider changes

	wxDECLARE_EVENT_TABLE();
};

