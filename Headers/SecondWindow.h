//
// Created by fhasa on 18/03/24.
//
#pragma once

#include <wx/wx.h>
#include <wx/sizer.h>
#include <wx/splitter.h>

#include <wx/bmpcbox.h>

#include "../Headers/CustomeUI/DropdownButton.h"


class SecondWindow : public wxFrame {

public:
    SecondWindow(const wxString& title, const wxPoint &pos, const wxSize &size);
   void OnClose(wxCloseEvent& event);
   void OnCloseButton(wxCommandEvent& event);

private:

  wxMenu *mainMenu;
  wxMenu *EditMenu;
  wxMenu *ViewMenu;
  wxMenu *AccountMenu;
  wxMenu *ToolsMenu;
  wxMenu *ReportsMenu;
  wxMenu *WindowMenu;
  wxMenu *HelpMenu;
  wxMenuBar *menuBar;

  wxPanel* TopPanel;

  wxSplitterWindow* splitter;

  wxPanel* left_panel;
  wxPanel* right_panel;
  wxBoxSizer* sizer;
  wxBoxSizer* main_sizer;


  //TESTING
  wxButton* TestButton;
  wxChoice* TestChoice;
  wxBitmapComboBox* TestBitmapCombo;

  DropdownButton* TestDropdownButton;
  void OnMenuItemSelected(wxCommandEvent& event);


};

enum
{
    ID_CloseButton = wxID_HIGHEST + 1
};
