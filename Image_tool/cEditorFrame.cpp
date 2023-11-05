#include "cEditorFrame.h"

wxBEGIN_EVENT_TABLE(cEditorFrame,wxMDIChildFrame)
EVT_SLIDER(20001, cEditorFrame::OnZoomChange) // when the slider moves, calls the function 
wxEND_EVENT_TABLE()

cEditorFrame::cEditorFrame(wxMDIParentFrame* parent, wxString wName) : wxMDIChildFrame(parent, wxID_ANY, wName)
{
	n_canvas = new cCanvas(this);
	n_StatusBar = this->CreateStatusBar(2, wxSTB_DEFAULT_STYLE, wxID_ANY);
	zoomSlider = new wxSlider(n_StatusBar, 20001, 8, 1, 32);
}

cEditorFrame::~cEditorFrame()
{
}

void cEditorFrame::OnZoomChange(wxCommandEvent& event)
{
	n_StatusBar->SetStatusText(wxString("Zoom : ") << zoomSlider->GetValue(), 1);
	n_canvas->setPixelSize(zoomSlider->GetValue());
	event.Skip();
}
