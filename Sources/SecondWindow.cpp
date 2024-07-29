//
// Created by fhasa on 18/03/24.
//

#include "../Headers/SecondWindow.h"
#include "../Headers/MainFrame.h"
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/splitter.h>
#include <wx/notebook.h>


SecondWindow::SecondWindow(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, title, pos, size) {

	//Splitters
	wxSplitterWindow* splitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_LIVE_UPDATE);

	wxPanel* left_panel = new wxPanel(splitter, wxID_ANY);
	wxPanel* right_panel = new wxPanel(splitter, wxID_ANY);

	
	
	left_panel->SetBackgroundColour(wxColour(100,200,100));
	right_panel->SetBackgroundColour(wxColour(200,100,100));
	
	splitter->SetSashGravity(0);
	splitter->SetMinimumPaneSize(100);
	splitter->SetSashSize(10);


	splitter->SplitVertically(left_panel, right_panel);

	wxNotebook* notebook = new wxNotebook(right_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_TOP);
	closeButton = new wxButton(left_panel, wxID_ANY, "Click to Close", wxDefaultPosition, wxDefaultSize);
	label = new wxStaticText(right_panel, wxID_ANY, "This is a second window", wxDefaultPosition, wxDefaultSize);
	notebook->AddPage(label, "Page 1");

	sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(notebook, 1, wxEXPAND);
	left_panel->SetSizer(sizer);


	//closeButton2 = new wxButton(right_panel, wxID_ANY, "Click to Close", wxDefaultPosition, wxDefaultSize);

	// Bind the close event to the OnClose method
	Bind(wxEVT_CLOSE_WINDOW, &SecondWindow::OnClose, this);
	Bind(wxEVT_BUTTON, &SecondWindow::OnCloseButton, this, closeButton->GetId());
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
