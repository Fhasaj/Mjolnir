/**
 * Name: MainFrame.cpp
 * Author: Fatlum Hasaj
 * Date: 15/3/24
 * Description: This File is the first window of the application and will host the login screen.
 *              The user will have to login to access the rest of the application if the logout or close
 *              the application then they will be firstly logged off and then they will been shown this screen.
 * Updated on: 15/3/24
 * Updater: Fatlum Hasaj
 */


#include "../Headers/SecondWindow.h"
#include "../Headers/MainFrame.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    // Create a panel as the main container
    wxPanel* mainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);

    // Create a vertical box sizer to arrange widgets vertically
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    // Create a panel for the top section
    wxPanel* panel_top = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition);

    // Create a vertical box sizer for the top panel
    wxBoxSizer* topSizer = new wxBoxSizer(wxVERTICAL);

    // Load the image file
    wxString imagePath = wxT("../Resources/images/logo.png");
    wxBitmap bitmap(imagePath, wxBITMAP_TYPE_PNG_RESOURCE);

    // Create a wxStaticBitmap control to display the image
    wxStaticBitmap* imageControl = new wxStaticBitmap(panel_top, wxID_ANY, bitmap);

    // Get the size of the wxStaticBitmap control
    wxSize controlSize = imageControl->GetSize();
    int controlWidth = controlSize.GetWidth() / 4;
    int controlHeight = controlSize.GetHeight() / 4;

    // Scale the bitmap to fit the control's size
    wxImage image = bitmap.ConvertToImage();
    image = image.Scale(controlWidth, controlHeight, wxIMAGE_QUALITY_HIGH);

    // Set the scaled bitmap to the wxStaticBitmap control
    imageControl->SetBitmap(wxBitmap(image));

    // Add the image control to the sizer
    topSizer->Add(imageControl, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 0);

    topSizer->AddSpacer(30);

    // Create Username text control
    wxTextCtrl* Username_txt = new wxTextCtrl(panel_top, wxID_ANY, "Username", wxDefaultPosition, wxSize(0,40), wxEXPAND);
    topSizer->Add(Username_txt, 0, wxEXPAND | wxBOTTOM, 10);

    // Create a horizontal box sizer for the password text box and the buttons
    wxBoxSizer* passwordAndButtonSizer = new wxBoxSizer(wxHORIZONTAL);

    // Create Password text control
    wxTextCtrl* Password_txt = new wxTextCtrl(panel_top, wxID_ANY, "Password", wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD | wxEXPAND);
    passwordAndButtonSizer->Add(Password_txt, 1, wxEXPAND | wxLEFT | wxBOTTOM);

    // Create a spacer to add some space between the password text box and the buttons
    passwordAndButtonSizer->AddSpacer(5);

    // Load images for different button states
    wxBitmap normalBitmap(wxT("../Resources/images/Buttons/eye.bmp"), wxBITMAP_TYPE_BMP_RESOURCE);
    wxBitmap focusedBitmap(wxT("../Resources/images/Buttons/hidden.png"), wxBITMAP_TYPE_PNG);



//// Set the focused bitmap
//    PasswordHider_button->SetBitmapPressed(focusedBitmap);

    // Create another button next to the login button
    wxBitmapButton* PasswordHider_button = new wxBitmapButton(panel_top, wxID_ANY, normalBitmap, wxDefaultPosition, wxSize(40,40), wxBU_AUTODRAW);
    passwordAndButtonSizer->Add(PasswordHider_button, 0, wxALIGN_CENTER_VERTICAL | wxALL, 0);

    // Add the horizontal sizer holding the password text box and buttons to the vertical sizer
    topSizer->Add(passwordAndButtonSizer, 0, wxEXPAND);

//    // Create Login button
    wxButton* Login_button = new wxButton(panel_top, wxID_ANY, "Login", wxDefaultPosition, wxSize(350,40), 0);
    topSizer->Add(Login_button, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP, 10);


// Set the sizer for the top panel
    panel_top->SetSizer(topSizer);

    // Add the top panel to the main sizer
    vbox->Add(panel_top, 1, wxEXPAND | wxALL, 25);

    // Set the main sizer for the main panel
    mainPanel->SetSizer(vbox);

    // Center the frame on the screen
    Centre();

    // Bind the Login button event
    Login_button->Bind(wxEVT_BUTTON, &MainFrame::OnOpenNewWindow, this);
}


/****** This logic weill be on the backend server to make sure that I have access to log into the system. **********/
void MainFrame::OnOpenNewWindow(wxCommandEvent& event) {

    SecondWindow *NewWindow = new SecondWindow("Hello", wxDefaultPosition, wxDefaultSize);
    NewWindow->Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnNewWindowClosed, this);
    NewWindow->Show(true);
    Show(false);
}

void MainFrame::OnNewWindowClosed(wxCloseEvent& event) {
    Show(true);
    SecondWindow* NewWindow = dynamic_cast<SecondWindow*>(event.GetEventObject());
    NewWindow->Unbind(wxEVT_CLOSE_WINDOW, &MainFrame::OnNewWindowClosed, this);
    NewWindow->Destroy();
}
/*****************************************************************************************************************/

