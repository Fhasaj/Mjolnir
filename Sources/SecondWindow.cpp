//
// Created by fhasa on 18/03/24.
//

#include "../Headers/SecondWindow.h"
#include "../Headers/MainFrame.h"
#include <wx/button.h>



SecondWindow::SecondWindow(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, title, pos, size) {

	//Font for the text controls
	wxFont MainFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, "Moulpali-Regular", wxFONTENCODING_SYSTEM);

	//MENU BAR
	mainMenu = new wxMenu;
	mainMenu->Append(wxID_EXIT, "E&xit");
	mainMenu->Append(wxID_CLOSE, "C&lose");
	mainMenu->Append(wxID_ABOUT, "A&bout");

	EditMenu = new wxMenu;
	EditMenu->Append(wxID_EXIT, "E&xit");
	EditMenu->Append(wxID_CLOSE, "C&lose");
	EditMenu->Append(wxID_ABOUT, "A&bout");

	ViewMenu = new wxMenu;
	ViewMenu->Append(wxID_EXIT, "E&xit");
	ViewMenu->Append(wxID_CLOSE, "C&lose");
	ViewMenu->Append(wxID_ABOUT, "A&bout");

	AccountMenu = new wxMenu;
	AccountMenu->Append(wxID_EXIT, "E&xit");
	AccountMenu->Append(wxID_CLOSE, "C&lose");
	AccountMenu->Append(wxID_ABOUT, "A&bout");

	ToolsMenu = new wxMenu;
	ToolsMenu->Append(wxID_EXIT, "E&xit");
	ToolsMenu->Append(wxID_CLOSE, "C&lose");
	ToolsMenu->Append(wxID_ABOUT, "A&bout");


	menuBar = new wxMenuBar;
	menuBar->Append(mainMenu, "&File");
	menuBar->Append(EditMenu, "&Edit");
	menuBar->Append(ViewMenu, "&View");

	//Custom menu Items
	menuBar->Append(AccountMenu, "&Account");
	menuBar->Append(ToolsMenu, "&Tools");

	//menuBar->Append(mainMenu, "&Reports");
	//menuBar->Append(mainMenu, "&Window");
	//menuBar->Append(mainMenu, "&Help");

	SetMenuBar(menuBar);

	//TOP PANEL Under the menu bar
	TopPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
	TopPanel->SetBackgroundColour(wxColour(100, 100, 200));

	//!!!! TEST BUTTON TO BE REMOVED AFTER TESTING IS DONE !!!!!
	TestButton = new wxButton(TopPanel, ID_CloseButton, "Close", wxDefaultPosition, wxDefaultSize, 0);

	wxBoxSizer* TopSizer = new wxBoxSizer(wxHORIZONTAL);

	//wxArrayString TestChoicesText;
	//TestChoicesText.Add("My Account");
	//TestChoicesText.Add("Settings");
	//TestChoicesText.Add("Sign Out");

	//TestChoice = new wxChoice(TopPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize,TestChoicesText);

	//wxBitmap AccountIMG(wxT("ACCOUNT"), wxBITMAP_TYPE_PNG_RESOURCE);



	//TestBitmapCombo = new wxBitmapComboBox(TopPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_READONLY | wxBORDER_NONE);
	//TestBitmapCombo->SetBackgroundColour(wxColour(99, 115, 103));
	//TestBitmapCombo->SetForegroundColour(wxColour(0, 0, 0));

	//TestBitmapCombo->Append("Account", AccountIMG);
	//TestBitmapCombo->Append("Settings", AccountIMG);

	//TestBitmapCombo->SetSelection(0);

	TestDropdownButton = new DropdownButton(TopPanel, wxID_ANY, "Account", wxSize(350, 40), wxColour(238, 238, 238), wxColour(49, 54, 63));
	TestDropdownButton->AddMenuItem("My Account", wxID_HIGHEST + 1);
	TestDropdownButton->AddMenuItem("Settings", wxID_HIGHEST + 2);


	TopSizer->Add(TestButton, 0, wxALL, 5);
	TopSizer->AddStretchSpacer(1);
	//TopSizer->Add(TestChoice, 0, wxALL, 5);
	//TopSizer->Add(TestBitmapCombo, 0, wxALL, 5);
	TopSizer->Add(TestDropdownButton, 0, wxALL, 5);
	TopPanel->SetSizer(TopSizer);
	

	//SPLITTER WINDOW

	splitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_LIVE_UPDATE);

	left_panel = new wxPanel(splitter, wxID_ANY);
	left_panel->SetBackgroundColour(wxColour(100,200,100));

	right_panel = new wxPanel(splitter, wxID_ANY);
	right_panel->SetBackgroundColour(wxColour(200,100,100));
	
	splitter->SetSashGravity(0);
	splitter->SetMinimumPaneSize(100);
	splitter->SetSashSize(10);
	splitter->SplitVertically(left_panel, right_panel);

	main_sizer = new wxBoxSizer(wxVERTICAL);
	main_sizer-> Add(TopPanel, 0, wxEXPAND | wxALL, 0);
	main_sizer->Add(splitter, 1, wxEXPAND | wxALL, 0);

	this->SetSizer(main_sizer);

	// EVENT HANDLERS FOR THE SECOND WINDOW
	Bind(wxEVT_CLOSE_WINDOW, &SecondWindow::OnClose, this);
	//Bind(wxEVT_BUTTON, &SecondWindow::OnCloseButton, this, closeButton->GetId());


	//BINDING THE MENU ITEMS
	Bind(wxEVT_MENU, &SecondWindow::OnMenuItemSelected, this, wxID_HIGHEST + 1);
	Bind(wxEVT_MENU, &SecondWindow::OnMenuItemSelected, this, wxID_HIGHEST + 2);
}

void SecondWindow::OnClose(wxCloseEvent& event) {
	MainFrame* mainFrame = dynamic_cast<MainFrame*>(wxTheApp->GetTopWindow());
	if (mainFrame) {
		mainFrame->Show(true); // Show the main frame again
	}
	Destroy(); // Close the second window
}

void SecondWindow::OnCloseButton(wxCommandEvent& event)
{
	MainFrame* mainFrame = dynamic_cast<MainFrame*>(wxTheApp->GetTopWindow());
	if (mainFrame) {
		mainFrame->Show(true); // Show the main frame again
	}
	Destroy(); // Close the second window
}

void SecondWindow::OnMenuItemSelected(wxCommandEvent& event)
{
	switch (event.GetId())
	{
	case wxID_HIGHEST + 1:
		wxMessageBox("Menu Item 1 Selected");
		break;
	case wxID_HIGHEST + 2:
		wxMessageBox("Menu Item 2 Selected");
		break;
	}
}
