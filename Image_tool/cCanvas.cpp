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
	this->FileName = filename;
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
	wxColour text_color(0, 0, 0); // Color del texto (negro en este caso)
	wxFont text_font(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	text_font.SetFaceName(wxT("Arial")); // Cambia la fuente seg�n tus preferencias
	dc.SetTextForeground(text_color);
	dc.SetFont(text_font);

	// Dibuja el texto en el contexto del dispositivo
	wxString message1 = wxT("Tama�o: ") + wxString::Format(wxT("%d x %d"), m_imageWidth, m_imageHeight);
	dc.DrawText(message1, this->m_imageWidth+30, 30); // Coordenadas (x, y) donde 
	wxString message2 = wxT("formato: ") + this->getformat();
	dc.DrawText(message2, this->m_imageWidth + 30, 50); // Coordenadas (x, y) donde 
	dc.DrawBitmap(this->m_imageBitmap, 0, 0);

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
	m_imageRGB = new wxImage(this->FileName, wxBITMAP_TYPE_ANY, -1); // ANY => can load many image formats
	m_imageBitmap = wxBitmap(*m_imageRGB, -1); // ...to get the corresponding bitmap

	m_imageWidth = m_imageRGB->GetWidth();
	m_imageHeight = m_imageRGB->GetHeight();

	m_myImage = (unsigned char*)malloc(m_imageWidth * m_imageHeight * 3);
	memcpy(m_myImage, m_imageRGB->GetData(), m_imageWidth * m_imageHeight * 3);
	if (this->m_myImage == nullptr)
	{
		wxString message = wxT("Imagen cargada\nTama�o: ") + wxString::Format(wxT("%d x %d"), m_imageWidth, m_imageHeight);
		wxMessageBox(message);
		return;
	}
	// update display
	//this->getformat();
	this->SetSize(m_imageWidth+30, m_imageHeight+30);
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
