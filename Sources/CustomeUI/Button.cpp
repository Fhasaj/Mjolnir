#include "../../Headers/CustomeUI/Button.h"

CustomedButton::CustomedButton(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& pos, const wxSize& size, const wxValidator& validator, const wxColour& BackGroundColour, const wxColour& TextColour)
	: wxPanel(parent, id)
{
	CustomeButton = new wxButton(this, id, label, pos, size, wxNO_BORDER, validator);
	CustomeButton->SetBackgroundColour(BackGroundColour);
	CustomeButton->SetForegroundColour(TextColour);

	CustomeButton->Bind(wxEVT_ENTER_WINDOW, &CustomedButton::OnMouseEnter, this);
	CustomeButton->Bind(wxEVT_LEAVE_WINDOW, &CustomedButton::OnMouseLeave, this);
}

void CustomedButton::OnMouseEnter(wxMouseEvent& event)
{
	CustomeButton->SetBackgroundColour(wxColour(158, 157, 157)); // Example color
	CustomeButton->SetForegroundColour(wxColour(255, 255, 255)); // Example color
	CustomeButton->Refresh();
}

void CustomedButton::OnMouseLeave(wxMouseEvent& event)
{
	CustomeButton->SetBackgroundColour(wxColour(49, 54, 63)); // Set the background color of the button
	CustomeButton->SetForegroundColour(wxColour(238, 238, 238)); // Set the text color of the button
	CustomeButton->Refresh();
}