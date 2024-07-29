//
// Created by fhasa on 18/03/24.
//
#pragma once

#include <wx/wx.h>

class SecondWindow : public wxFrame {

public:
    SecondWindow(const wxString& title, const wxPoint &pos, const wxSize &size);
   void OnClose(wxCloseEvent& event);
   void OnCloseButton(wxCommandEvent& event);

private:

    wxPanel* panel;
	wxStaticText* label;
	wxBoxSizer* sizer;
	wxButton* closeButton;
	wxButton* closeButton2;

};
