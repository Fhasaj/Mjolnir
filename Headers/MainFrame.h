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
    /****** This logic weill be on the backend server to make sure that I have access to log into the system. **********/
    void OnOpenNewWindow(wxCommandEvent& event);
    void OnNewWindowClosed(wxCloseEvent& event);


};
