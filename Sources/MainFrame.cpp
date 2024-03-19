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

	/********  USERNAME Text Control *************/

	// Create a panel for the background
	wxPanel* backgroundPanel = new wxPanel(panel_top, wxID_ANY, wxDefaultPosition, wxSize(-1, 40)); // Adjust the height as needed
	backgroundPanel->SetBackgroundColour(wxColour(49, 54, 63));

	// Add the text control to the background panel
	wxBoxSizer* backgroundSizer = new wxBoxSizer(wxVERTICAL);

#ifdef __WXMSW__
	// Windows-specific code
	// Add a spacer above the text control to push it down
	backgroundSizer->Add(0, 12, 0); // Add a 10-pixel spacer
#endif

	// Create UserName text control
	Username_txt = new wxTextCtrl(backgroundPanel, wxID_ANY, "Enter your username", wxDefaultPosition, wxDefaultSize, wxEXPAND | wxBORDER_NONE);
	Username_txt->SetFont(MainFont);
	Username_txt->SetBackgroundColour(wxColour(49, 54, 63)); // Set the background color of the text box
	Username_txt->SetForegroundColour(wxColour(238, 238, 238)); // Set the text color of the text box

#ifdef __WXMSW__
	// Windows-specific code
	// Set the size of the text control to be smaller in height than the background panel
	Username_txt->SetSize(wxDefaultCoord, 30); // Set the height to 30 pixels, less than the panel
#endif

	// Add the text control to the sizer with padding to center it horizontally
	backgroundSizer->Add(Username_txt, 0, wxEXPAND | wxLEFT | wxRIGHT, 10);

	// Add the background panel to the top sizer
	topSizer->Add(backgroundPanel, 0, wxEXPAND | wxBOTTOM, 10);

	// Set the sizer for the background panel
	backgroundPanel->SetSizer(backgroundSizer);


	/*******************************  Password Text Control	******************************************/

	// Create a panel for the password text control and the button
	wxPanel* passwordPanel = new wxPanel(panel_top, wxID_ANY, wxDefaultPosition, wxSize(-1, 40));
	passwordPanel->SetBackgroundColour(wxColour(49, 54, 63));

	// Create a vertical box sizer for the password panel
	wxBoxSizer* passwordPanelSizer = new wxBoxSizer(wxVERTICAL);

	// Add a spacer above the password text control to push it down
	passwordPanelSizer->AddSpacer(12); // Add a 12-pixel spacer

	// Create a horizontal box sizer for the password text box and the button within the panel
	wxBoxSizer* passwordSizer = new wxBoxSizer(wxHORIZONTAL);

	// Create Password text control inside the panel
	Password_txt = new wxTextCtrl(passwordPanel, wxID_ANY, "Enter your password", wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD | wxEXPAND | wxBORDER_NONE);
	Password_txt->SetFont(MainFont);
	Password_txt->SetBackgroundColour(wxColour(49, 54, 63));
	Password_txt->SetForegroundColour(wxColour(238, 238, 238));

	// Add Password text control to the sizer
	passwordSizer->Add(Password_txt, 1, wxEXPAND | wxLEFT, 10);


	// Load images for different button states
	#if defined(__WXMSW__)
	// If compiling for Windows, load images from .rc file
		normalBitmap = wxBitmap(wxT("SHOW_WHITE_PNG"), wxBITMAP_TYPE_PNG_RESOURCE);
		HiddenBitmap = wxBitmap(wxT("HIDDEN_WHITE_PNG"), wxBITMAP_TYPE_PNG_RESOURCE);
	#else
	// For other platforms (macOS, Linux), load images from file system
		normalBitmap = wxBitmap(wxT("../Resources/images/Buttons/eye_white.png"), wxBITMAP_TYPE_PNG);
		HiddenBitmap = wxBitmap(wxT("../Resources/images/Buttons/hidden_White.png"), wxBITMAP_TYPE_PNG);
	#endif

	// Create the button inside the panel
	PasswordHider_button = new wxBitmapButton(passwordPanel, wxID_ANY, normalBitmap, wxDefaultPosition, wxSize(40, 40), wxBU_AUTODRAW | wxBORDER_NONE);
	PasswordHider_button->SetBackgroundColour(wxColour(49, 54, 63));
	PasswordHider_button->SetForegroundColour(wxColour(238, 238, 238));

	// Add a spacer to adjust the vertical alignment of the button
	//passwordSizer->AddSpacer(5); // Adjust the value as needed

	// Add Password button to the sizer with right alignment and no bottom margin
	passwordSizer->Add(PasswordHider_button, 0, wxEXPAND | wxBOTTOM , 10);

	// Add passwordSizer to passwordPanelSizer
	passwordPanelSizer->Add(passwordSizer, 0, wxEXPAND);

	// Set the sizer for the password panel
	passwordPanel->SetSizer(passwordPanelSizer);

	// Add the password panel to the main sizer
	topSizer->Add(passwordPanel, 0, wxEXPAND);

	// Set the main sizer for the main panel
	panel_top->SetSizer(topSizer);


    /***************  LOGIN BUTTON **********************/

	Login_button = new wxButton(panel_top, wxID_ANY, "Login", wxDefaultPosition, wxSize(350, 40), wxNO_BORDER);
	topSizer->Add(Login_button, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP, 10); // Add the button to the sizer
	Login_button->SetBackgroundColour(wxColour (49,54,63)); // Set the background color of the button
	Login_button->SetForegroundColour(wxColour(238,238,238)); // Set the text color of the button
	Login_button->SetFont(MainFont); // Set the font of the button

    /**************************************************/

	// Set the sizer for the top panel
	panel_top->SetSizer(topSizer);

	// Add the top panel to the main sizer
	vbox->Add(panel_top, 1, wxEXPAND | wxALL, 25);

	// Set the main sizer for the main panel
	mainPanel->SetSizer(vbox);

	// Center the frame on the screen
	Centre();


	// Bind the button event
	Login_button->Bind(wxEVT_BUTTON, &MainFrame::OnOpenNewWindow, this);
    PasswordHider_button->Bind(wxEVT_BUTTON, &MainFrame::onButtonClick, this);

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

void MainFrame::onButtonClick(wxCommandEvent& event) {
#ifdef __WXMSW__
	// Windows-specific code
	//This bullshit that windows does is not needed on Linux or macOS so I will not include it. PS: I hate how windows does things sometimes
	bool hidepwd = isPasswordShowEnabled;
	HWND hwnd = (HWND)Password_txt->GetHandle();
	SendMessage(hwnd, EM_SETPASSWORDCHAR, hidepwd ? 0 : 0x25cf, 0); // 0x25cf is ● character
	Password_txt->Refresh();
#else
	// Linux-specific code
	if (isPasswordShowEnabled) {
		// Remove the wxTE_PASSWORD style
		Password_txt->SetWindowStyleFlag(Password_txt->GetWindowStyleFlag() & ~wxTE_PASSWORD);
	}
	else {
		// Add the wxTE_PASSWORD style
		Password_txt->SetWindowStyleFlag(Password_txt->GetWindowStyleFlag() | wxTE_PASSWORD);
	}
#endif

	// Toggle the flag and update the button bitmap
	isPasswordShowEnabled = !isPasswordShowEnabled;
	PasswordHider_button->SetBitmap(isPasswordShowEnabled ? normalBitmap : HiddenBitmap);
}