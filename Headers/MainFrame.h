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
#include <string>
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
    wxPanel* backgroundPanelPassword;
    wxBoxSizer* backgroundSizerPassword;

    wxStaticBitmap* imageControl;
    wxTextCtrl* Username_txt;
    wxTextCtrl* Password_txt;
    wxBoxSizer* passwordAndButtonSizer;
    wxBitmapButton* PasswordHider_button;
    wxButton* Login_button;

    //Images
    wxBitmap normalBitmap;
    wxBitmap HiddenBitmap;

    bool isPasswordShowEnabled = true;
    std::string usernamePlaceHolderTxt;
    std::string passwordPlaceHolderTxt;

    /****** This logic weill be on the backend server to make sure that I have access to log into the system. **********/
    void OnOpenNewWindow(wxCommandEvent& event);
    void OnNewWindowClosed(wxCloseEvent& event);
    void onButtonClick(wxCommandEvent& event);

    //Function to change the background color of the button on hover and clicked
    void OnMouseEnter(wxMouseEvent& event);
    void OnMouseLeave(wxMouseEvent& event);
    void OnLoginButtonClick(wxCommandEvent& event);

    // Custom TextCtrl attributes to show placeholder text
    void SetPlaceholderText(wxTextCtrl* textCtrl, const wxString& placeholderText);
    void ClearPlaceholderText(wxTextCtrl* textCtrl, const wxString& placeholderText);
    void OnTextFocus(wxFocusEvent& event);
    void OnTextKillFocus(wxFocusEvent& event);
};
