
#include "../../Headers/CustomeUI/DropdownButton.h"

wxBEGIN_EVENT_TABLE(DropdownButton, wxPanel)
	EVT_BUTTON(wxID_ANY, DropdownButton::onButtonClicked)
wxEND_EVENT_TABLE()

DropdownButton::DropdownButton(wxWindow* parent, wxWindowID id, const wxString& label, const wxSize& size, const wxColour& Colour1, const wxColour& Colour2)
	: wxPanel(parent, id)
{
	//Creating the button that will be clicked to show the dropdown menu
	//A new class will need to be created to allow for the button to be a bitMap button as this will only take text

	/*
	* The Button will be un-styled and I will create the default style here Not sure if I want to allow for the style to be changed
	* This can be done by passing in a style parameter and setting the style of the button to that style i.e the colour, font, mouse hover, mouse leave
	*/
	dropdownButton = new wxButton(this, id, label, wxDefaultPosition, size, wxNO_BORDER);
	//Reference, ID,   Label, Position,          Size,         Style

	dropdownButton->SetBackgroundColour(Colour1); // Set the background color of the button
	dropdownButton->SetForegroundColour(Colour2); // Set the text color of the button

	//Creating the menu that will be shown when the button is clicked
	dropdownmenu = new wxMenu;

	MenuSizer = new wxBoxSizer(wxVERTICAL);
	MenuSizer->Add(dropdownButton, 0, wxALL);
	MenuSizer->GetPosition();
	SetSizer(MenuSizer);

	//Bind the events to the button
	dropdownButton->Bind(wxEVT_ENTER_WINDOW, &DropdownButton::OnMouseEnter, this);
	dropdownButton->Bind(wxEVT_LEAVE_WINDOW, &DropdownButton::OnMouseLeave, this);
}

void DropdownButton::AddMenuItem(const wxString& item, wxWindowID itemID)
{
	dropdownmenu->Append(itemID, item);
}

/****************** DropDown Button On click ******************************/
/* To Get the correct position of the Button you need to do three things*/
/* 1. Get the position of the button relative to its parent panel        */
/* 2. Convert the position to screen coordinates relative to the top-level window */
/* 3. Get the size of the button                                        */
/* 4. Calculate the position for the menu to appear directly underneath the button */
/* 5. Popup the menu at the calculated position                         */
/* To calculate the position of the menu you have to get the screenPos at x */
/* and divide it by the size of the button in x and subtract 50 from it */
/* and for the y position you have to get the screenPos at y and divide it by the size of the button in y and add 20 to it */
/* The two values 50 and 20 are used for this application and are not may not be needed for others*/
/************************************************************************/

void DropdownButton::onButtonClicked(wxCommandEvent& event)
{
	// Get the position of the button relative to its parent panel
	wxPoint pos = dropdownButton->GetPosition();

	// Convert the position to screen coordinates relative to the top-level window
	wxPoint screenPos = this->ClientToScreen(pos);

	// Get the size of the button
	wxSize size = dropdownButton->GetSize();


	// Calculate the position for the menu to appear directly underneath the button
	int menuX = screenPos.x / size.x ; // TODO: This is still on top of the button
	int menuY = screenPos.y / size.y ; // TODO: This is still on top of the button


	// Popup the menu at the calculated position
	PopupMenu(dropdownmenu, menuX, menuY);
}

void DropdownButton::OnMouseEnter(wxMouseEvent& event)
{
	dropdownButton->SetBackgroundColour(wxColour(158, 157, 157)); // Example color
	dropdownButton->SetForegroundColour(wxColour(255, 255, 255)); // Example color
	dropdownButton->Refresh();
}

void DropdownButton::OnMouseLeave(wxMouseEvent& event)
{
	dropdownButton->SetBackgroundColour(wxColour(49, 54, 63)); // Set the background color of the button
	dropdownButton->SetForegroundColour(wxColour(238, 238, 238)); // Set the text color of the button
	dropdownButton->Refresh();
}

wxSize DropdownButton::DoGetBestSize() const
{
	wxSize bestSize = wxPanel::DoGetBestSize();
	bestSize.SetWidth(100);
	return bestSize;
}

