/**
 * Name: MainFrame.h
 * Author: Fatlum Hasaj
 * Date: 15/3/24
 * Description: This is the header file for the MainFrame class.
 *
 * Updated on: 15/3/24
 * Updater: Fatlum Hasaj
 */

#pragma once

#include <wx/wx.h>
#include "../Headers/SecondWindow.h"

class MainFrame : public wxFrame
{
public: 
	MainFrame(const wxString& title, const wxPoint &pos, const wxSize &size);

private:


    wxPanel* mainPanel;
    wxBoxSizer* vbox;
    wxPanel* panel_top;
    wxBoxSizer* topSizer;

    wxStaticBitmap* imageControl;
    wxTextCtrl* Username_txt;
    wxTextCtrl* Password_txt;
    wxBoxSizer* passwordAndButtonSizer;
    wxBitmapButton* PasswordHider_button;
    wxButton* Login_button;

    /****** This logic weill be on the backend server to make sure that I have access to log into the system. **********/
    void OnOpenNewWindow(wxCommandEvent& event);
    void OnNewWindowClosed(wxCloseEvent& event);
    void OnButtonFocus(wxFocusEvent& event);
    void OnButtonBlur(wxFocusEvent& event);
};
