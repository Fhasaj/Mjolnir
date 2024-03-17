/**
 * Name: appMain.cpp
 * Author: Fatlum Hasaj
 * Date: 15/3/24
 * Description: This file contains the main function of the application.
 * 
 * Updated on: 15/3/24
 * Updater: Fatlum Hasaj
 */

// Local Headers
#include "../Headers/appMain.h"
#include "../Headers/MainFrame.h"

// Standard Headers + wxWidgets Headers
#include <wx/wx.h>

wxIMPLEMENT_APP(MyApp);	

bool MyApp::OnInit()
{
	MainFrame *frame = new MainFrame("Mjolnir Inventory System");
	frame->SetClientSize(400, 400);
//	frame->SetMinSize(wxSize(400, 400)); //Sets the minimum size of the window, Might not be needed thats why its commented out
//	frame->SetMaxSize(wxSize(400, 400)); //Sets the maximum size of the window, Might not be needed thats why its commented out
	frame->Center();
	frame->Show(true);
	return true;
}