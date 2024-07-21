#pragma once

#include "wx/wx.h"
#include "wx/sizer.h"


class CustomedButton : public wxWindow, wxButton 
{
public:
	CustomedButton(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& pos, const wxSize& size, long style = 0, const wxValidator& validator = wxDefaultValidator, const wxString& name = wxButtonNameStr);
	~CustomedButton();

	void OnPaint(wxPaintEvent& event);
	void OnMouseEnter(wxMouseEvent& event);
	void OnMouseLeave(wxMouseEvent& event);
	void OnMouseClick(wxMouseEvent& event);
};