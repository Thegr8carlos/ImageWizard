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
	cCanvas(wxWindow* parent, wxString filename);
	~cCanvas();
	wxString FileName; // file name of the image

private: 
	int m_nPixelSize = 8; // for the slider

	//----- Image variables---------------------------------------------------------------------
	int m_imageWidth;                                                                         //
	int m_imageHeight;                                                                        //
	wxBitmap m_imageBitmap;	// used to display the image                                      //
	wxImage* m_imageRGB;		// used to load the image                                     //
	unsigned char* m_myImage = nullptr;	// used to process the image (raw data) pixels in 1d  //
	//-----------------------------------------------------------------------------------------
public:
	//--------Image functions--------------------------------------------------------------------------------------------

	void LoadImage(); // for load the image and set m_imageHeight , m_imageWidth, m_imageBitmap, m_imageRGB, m_myImage //
	void OnPaint(wxPaintEvent& event); // for init the draw context                                                    //
	void OnDraw(wxDC& dc); // actually drawing                                                                         //
	wxString getformat(); // returns the format of the image                                                           //
	//-------------------------------------------------------------------------------------------------------------------
	
	void setPixelSize(int p); // for the slider
private:
	virtual wxCoord OnGetRowHeight(size_t row) const; // for the slider
	virtual wxCoord OnGetColumnWidth(size_t col)const; // for the slider

	wxDECLARE_EVENT_TABLE();

};

