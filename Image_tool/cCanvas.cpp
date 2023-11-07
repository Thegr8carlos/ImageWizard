#include "cCanvas.h"
#include <string>
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

	wxPosition s = GetVisibleBegin();
	wxPosition e = GetVisibleEnd(); // ya tienes la imagen , trata ya de mostrarla.

	pen.SetStyle(wxPENSTYLE_LONG_DASH);
	pen.SetColour(wxColour(200, 200, 200));
	dc.SetPen(pen);

	dc.SetBrush(brush);
	dc.DrawRectangle(20, 20, 200, 200);
	wxColour text_color(0, 0, 0); // Color del texto (negro en este caso)
	wxFont text_font(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	text_font.SetFaceName(wxT("Arial")); // Cambia la fuente seg�n tus preferencias
	dc.SetTextForeground(text_color);
	dc.SetFont(text_font);

	// Dibuja el texto en el contexto del dispositivo
	wxString message = wxT("Imagen cargada\nTama�o: ") + wxString::Format(wxT("%d x %d"), m_imageWidth, m_imageHeight);
	dc.DrawText(message, 30, 30); // Coordenadas (x, y) donde 
	

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
