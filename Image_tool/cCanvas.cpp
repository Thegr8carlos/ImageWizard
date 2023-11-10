#include "cCanvas.h"
#include <string>
#include <fstream>
wxBEGIN_EVENT_TABLE(cCanvas, wxHVScrolledWindow)
EVT_PAINT(cCanvas::OnPaint)
wxEND_EVENT_TABLE()

cCanvas::cCanvas(wxWindow* parent, wxString filename) : wxHVScrolledWindow(parent, wxID_ANY)
{
	SetRowColumnCount(40, 40); // see the changes if change that values
	SetBackgroundStyle(wxBG_STYLE_PAINT);
	this->fileName = filename;
}

cCanvas::cCanvas(wxWindow* parent, unsigned char* data, int w, int h) : wxHVScrolledWindow(parent, wxID_ANY)
{
	SetRowColumnCount(40, 40); // see the changes if change that values
	SetBackgroundStyle(wxBG_STYLE_PAINT);
	this->m_myImage = data;
	this->m_imageWidth = w;
	this->m_imageHeight = h;
	this->m_imageRGB = new wxImage(this->m_imageWidth, this->m_imageHeight, this->m_myImage, true);
}

int cCanvas::getWidth()
{
	return this->m_imageWidth;
}

int cCanvas::getHeight()
{
	return this->m_imageHeight;
}

cCanvas::~cCanvas()
{
}

void cCanvas::setPixelSize(int p)
{
	m_nPixelSize = p; // se the changes of that variable
	wxVarHScrollHelper::RefreshAll();
	wxVarVScrollHelper::RefreshAll();
	Refresh();
}

void cCanvas::OnPaint(wxPaintEvent& event) // pre painting, the paint handle event
{
	wxBufferedPaintDC dc(this);
	this->PrepareDC(dc);
	this->OnDraw(dc);
}

void cCanvas::OnDraw(wxDC& dc) // Arregla esta problematica para dibujar la imagen 
{ 	
		
	dc.Clear();
	wxBrush brush = dc.GetBrush();
	wxPen pen = dc.GetPen();

	
	dc.SetBrush(brush);
	wxImage* tempImage;
	
	if (this->m_myImage)
	{
		tempImage = new wxImage(m_imageWidth, m_imageHeight, m_myImage, true); // lend my image buffer...
		m_imageBitmap = wxBitmap(*tempImage, -1); // ...to get the corresponding bitmap
		delete(tempImage);		// buffer not needed any more
		dc.DrawBitmap(this->m_imageBitmap, 0, 0);
	}
	else
	{
		wxMessageBox(wxT("Error en la carga de imagen "));
	}
		
}
unsigned char* cCanvas::ToGray() // testing...
{
	// generar un buffer que guarda los nuevos valores, y retornar eso, para asi crear una nueva ventana
	
	if (this->getformat() == (wxString)"RGB")
	{
		wxMessageBox(wxT("RGB to gray"));
		unsigned char* temp = (unsigned char*)malloc(m_imageWidth * m_imageHeight * 3);
		int long pixels = m_imageHeight * m_imageWidth;
		for (int i = 0; i < pixels; ++i)
		{
			unsigned char red = this->m_myImage[i * 3];
			unsigned char green = this->m_myImage[i * 3 + 1];
			unsigned char blue = this->m_myImage[i * 3 + 2];
			unsigned char gray = (unsigned char)(0.299 * red + 0.587 * green + 0.114 * blue);
			temp[i * 3] = gray;
			temp[i * 3 + 1] = gray;
			temp[i * 3 + 2] = gray;
		}
		return temp;
		
	}
	else if (this->getformat() == (wxString)"RGBA")
	{
		//wxMessageBox(wxT("RGBA to gray"));
		return this->m_myImage;
	}
	else if (this->getformat() == (wxString)"GRAY")
	{
		//wxMessageBox(wxT("Already Gray"));
		return nullptr;
	}
	else
	{
		//wxMessageBox(wxT("Not implemented..."));
		return nullptr;
	}
	
}
wxString cCanvas::getformat()
{
	for (int i = 0; i < this->m_imageHeight; i++)
	{
		for (int j = 0; j < this->m_imageWidth; j++)
		{
			int offset = (i * this->m_imageWidth + j) * 3; // 3 canales (RGB)
			unsigned char red = this->m_myImage[offset] - 0;
			unsigned char green = this->m_myImage[offset + 1]- 0;
			unsigned char blue = this->m_myImage[offset + 2] - 0;
			//ofs << "[" << red + ","<< green << "," << blue << "]";
			if (red != green || green != blue)
			{
				if (this->m_imageRGB->HasAlpha())
				{
					return (wxString)"RGBA";
				}
				else
				{
					return (wxString)"RGB";
				}
			}
		}
	}
	return (wxString)"GRAY";

	
}
void cCanvas::LoadImage()
{
	if (m_myImage)
		free(m_myImage);
	if (m_imageRGB)
		delete m_imageRGB;

	// open image dialog box
	m_imageRGB = new wxImage(this->fileName, wxBITMAP_TYPE_ANY, -1); // ANY => can load many image formats
	m_imageBitmap = wxBitmap(*m_imageRGB, -1); // ...to get the corresponding bitmap

	m_imageWidth = m_imageRGB->GetWidth();
	m_imageHeight = m_imageRGB->GetHeight();

	m_myImage = (unsigned char*)malloc(m_imageWidth * m_imageHeight * 3);
	memcpy(m_myImage, m_imageRGB->GetData(), m_imageWidth * m_imageHeight * 3);
	if (this->m_myImage == nullptr)
	{
		wxString message = wxT("Image carge failed") + wxString::Format(wxT("%d x %d"), m_imageWidth, m_imageHeight);
		wxMessageBox(message);
		return;
	}
	// update display
	//this->getformat();
	// agregar aqui para probar un filtro en la imagen para probar como se obtienen los valores 

	this->SetSize(m_imageHeight, m_imageWidth);
	Refresh(false);
}
wxCoord cCanvas::OnGetRowHeight(size_t row) const
{
	return wxCoord(m_nPixelSize);
}

wxCoord cCanvas::OnGetColumnWidth(size_t col) const
{
	return wxCoord(m_nPixelSize);
}
