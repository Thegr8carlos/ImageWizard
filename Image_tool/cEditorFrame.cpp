#include "cEditorFrame.h"

wxBEGIN_EVENT_TABLE(cEditorFrame,wxMDIChildFrame)
EVT_SLIDER(20001, cEditorFrame::OnZoomChange) // when the slider moves, calls the function 
wxEND_EVENT_TABLE()

// when a new instance of CeditorFrame gets called, that means that we hace to display a new image so we need to initialice and draw in the canvas

	cEditorFrame::cEditorFrame(wxMDIParentFrame* parent, wxString FileName) : wxMDIChildFrame(parent, wxID_ANY, FileName) // init constructor of mdiChild
	{
		n_canvas = new cCanvas(this,FileName); // setting the canvas with the file name
		n_canvas->LoadImage(); // AAdding the image to the canvas
		n_StatusBar = this->CreateStatusBar(2, wxSTB_DEFAULT_STYLE, wxID_ANY);
		zoomSlider = new wxSlider(n_StatusBar, 20001, 8, 1, 32);
	}

cEditorFrame::~cEditorFrame()
{
	// maybe manage all the files and delete them orr maaybe no jeje
}

void cEditorFrame::OnZoomChange(wxCommandEvent& event)
{
	n_StatusBar->SetStatusText(wxString("Zoom : ") << zoomSlider->GetValue(), 1);
	n_canvas->setPixelSize(zoomSlider->GetValue());
	event.Skip();
}
