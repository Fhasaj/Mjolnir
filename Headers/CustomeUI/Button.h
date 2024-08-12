#pragma once

#include "wx/wx.h"
#include "wx/sizer.h"


class CustomedButton : public wxPanel
{
public:
	/**
	 * @brief Construct a new Customed Button object
	 * @param parent The parent window
	 * @param id The ID of the button
	 * @param label The text to be displayed on the button - default is "Button"
	 * @param pos The position of the button - default is wxDefaultPosition
	 * @param size The size of the button - default is wxDefaultSize
	 * @param style The style of the button - default is wxEXPAND
	 * @param validator The validator of the button - default is wxDefaultValidator
	 * @param name The name of the button - default is wxButtonNameStr
	 * @param BackGroundColour The background colour of the button - default is wxColour(158, 157, 157)
	 * @param TextColour The text colour of the button - default is wxColour(255, 255, 255)
	 * 
	 */
	CustomedButton(wxWindow* parent, 
		wxWindowID id = wxID_ANY,
		const wxString& label = "Button",
		const wxPoint& pos = wxDefaultPosition,
		const wxSize& size = wxDefaultSize,
		const wxValidator& validator = wxDefaultValidator,
		const wxColour& BackGroundColour = wxColour(49, 54, 63),
		const wxColour& TextColour = wxColour(238, 238, 238)
	);


private:

	void OnMouseEnter(wxMouseEvent& event);
	void OnMouseLeave(wxMouseEvent& event);

	wxButton* CustomeButton;

};

