//
// Created by fhasa on 18/03/24.
//

#include "../Headers/SecondWindow.h"
#include "../Headers/MainFrame.h"

SecondWindow::SecondWindow(const wxString &title, const wxPoint &pos, const wxSize &size)
        : wxFrame(NULL, wxID_ANY, title, pos, size) {

    wxPanel* panel = new wxPanel(this, wxID_ANY);
    wxStaticText* label = new wxStaticText(panel, wxID_ANY, "This is a new window", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);

    // Bind the close event to the OnClose method
    Bind(wxEVT_CLOSE_WINDOW, &SecondWindow::OnClose, this);

};

void SecondWindow::OnClose(wxCloseEvent &event) {
    MainFrame* mainFrame = dynamic_cast<MainFrame*>(wxTheApp->GetTopWindow());
    if (mainFrame) {
        mainFrame->Show(true); // Show the main frame again
    }
    Destroy(); // Close the second window
}
