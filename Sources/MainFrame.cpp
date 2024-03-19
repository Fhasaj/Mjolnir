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

	wxFont MainFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, "Moulpali-Regular");

	// Create a panel as the main container
	mainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
	mainPanel->SetBackgroundColour(wxColour(34, 40, 49)); // Set the background color of the panel

	// Create a vertical box sizer to arrange widgets vertically
	vbox = new wxBoxSizer(wxVERTICAL);

	// Create a panel for the top section
	panel_top = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition);

	// Create a vertical box sizer for the top panel
	wxBoxSizer* topSizer = new wxBoxSizer(wxVERTICAL);

#if defined(__WXMSW__)
	// If compiling for Windows, load images from .rc file

	// Load the image file using wxResource
	wxBitmap bitmap(wxT("LOGO_PNG"), wxBITMAP_TYPE_PNG_RESOURCE);

#else
	// For other platforms (macOS, Linux), load images from file system

	// Load the image file
	wxString imagePath = wxT("../Resources/images/logo.png");
	wxBitmap bitmap(imagePath, wxBITMAP_TYPE_PNG);

#endif

	// Create a wxStaticBitmap control to display the image
	imageControl = new wxStaticBitmap(panel_top, wxID_ANY, bitmap);

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
	Username_txt = new wxTextCtrl(panel_top, wxID_ANY, "Username", wxDefaultPosition, wxSize(0, 40), wxEXPAND | wxBORDER_NONE );
	topSizer->Add(Username_txt, 0, wxEXPAND | wxBOTTOM, 10);
	Username_txt->SetFont(MainFont);
	Username_txt->SetBackgroundColour(wxColour(49, 54, 63)); // Set the background color of the text box
	Username_txt->SetForegroundColour(wxColour(238, 238, 238)); // Set the text color of the text box

	// Create a horizontal box sizer for the password text box and the buttons
	passwordAndButtonSizer = new wxBoxSizer(wxHORIZONTAL);

	// Create Password text control
	 Password_txt = new wxTextCtrl(panel_top, wxID_ANY, "Password", wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD | wxEXPAND | wxBORDER_NONE);
	passwordAndButtonSizer->Add(Password_txt, 1, wxEXPAND | wxLEFT | wxBOTTOM);
	Password_txt->SetFont(MainFont);
	Password_txt->SetBackgroundColour(wxColour(49, 54, 63)); // Set the background color of the text box
	Password_txt->SetForegroundColour(wxColour(238, 238, 238)); // Set the text color of the text box

	// Create a spacer to add some space between the password text box and the buttons
	passwordAndButtonSizer->AddSpacer(5);

	// Load images for different button states
#if defined(__WXMSW__)
	// If compiling for Windows, load images from .rc file
	wxBitmap normalBitmap(wxT("SHOW_PNG"), wxBITMAP_TYPE_PNG_RESOURCE); // Assume the image is in the .rc file
	wxBitmap focusedBitmap(wxT("HIDDEN_PNG"), wxBITMAP_TYPE_PNG_RESOURCE); // Assume the image is in the .rc file
#else
	// For other platforms (macOS, Linux), load images from file system
	wxBitmap normalBitmap(wxT("../Resources/images/Buttons/eye.bmp"), wxBITMAP_TYPE_BMP);
	wxBitmap focusedBitmap(wxT("../Resources/images/Buttons/hidden.png"), wxBITMAP_TYPE_PNG);
#endif

	// Create another button next to the login button
	PasswordHider_button = new wxBitmapButton(panel_top, wxID_ANY, normalBitmap, wxDefaultPosition, wxSize(40, 40), wxBU_AUTODRAW | wxBORDER_NONE);
	passwordAndButtonSizer->Add(PasswordHider_button, 0, wxALIGN_CENTER_VERTICAL | wxALL, 0);
	PasswordHider_button->SetBackgroundColour(wxColour(49, 54, 63)); // Set the background color of the button
	PasswordHider_button->SetForegroundColour(wxColour(238, 238, 238)); // Set the text color of the button

	// Add the horizontal sizer holding the password text box and buttons to the vertical sizer
	topSizer->Add(passwordAndButtonSizer, 0, wxEXPAND);

	// Create Login button

	Login_button = new wxButton(panel_top, wxID_ANY, "Login", wxDefaultPosition, wxSize(350, 40), wxNO_BORDER);

	topSizer->Add(Login_button, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP, 10); // Add the button to the sizer
	Login_button->SetBackgroundColour(wxColour (49,54,63)); // Set the background color of the button
	Login_button->SetForegroundColour(wxColour(238,238,238)); // Set the text color of the button
	Login_button->SetFont(MainFont); // Set the font of the button

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

	// Bind focus events for the button
	PasswordHider_button->Bind(wxEVT_SET_FOCUS, &MainFrame::OnButtonFocus, this);
	PasswordHider_button->Bind(wxEVT_KILL_FOCUS, &MainFrame::OnButtonBlur, this);


}



/****** This logic will be on the backend server to make sure that I have access to log into the system. **********/
void MainFrame::OnOpenNewWindow(wxCommandEvent& event) {

	SecondWindow* NewWindow = new SecondWindow("Hello", wxDefaultPosition, wxDefaultSize);
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


void MainFrame::OnButtonFocus(wxFocusEvent& event) {
	// Set the button's background color to your custom color when focused
	PasswordHider_button->SetBackgroundColour(wxColour(255, 0, 0)); // Change to your custom color
	PasswordHider_button->Refresh(); // Refresh to apply the color change
	event.Skip(); // Skip the event to allow default handling
}

void MainFrame::OnButtonBlur(wxFocusEvent& event) {
	// Set the button's background color back to its original color when focus is lost
	PasswordHider_button->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE)); // Change to original color
	PasswordHider_button->Refresh(); // Refresh to apply the color change
	event.Skip(); // Skip the event to allow default handling
}