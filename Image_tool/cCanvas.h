#pragma once
#include "wx/wx.h"
#include "wx/vscroll.h"
#include "wx/dcclient.h"
#include "wx/dcmemory.h"
#include "wx/dcbuffer.h"

// canvas in wich wee can edite the sprite
class cCanvas : public wxHVScrolledWindow
{
public: 
	cCanvas(wxWindow* parent);
	~cCanvas();


private: 
	int m_nPixelSize = 8;
public:
	void setPixelSize(int p);
	void OnPaint(wxPaintEvent& event);
	void OnDraw(wxDC& dc);
private:
	virtual wxCoord OnGetRowHeight(size_t row) const;
	virtual wxCoord OnGetColumnWidth(size_t col)const;

	wxDECLARE_EVENT_TABLE();

};

