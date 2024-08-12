#pragma once


#include <wx/wx.h>
#include <wx/menu.h>

class DropdownButton : public wxPanel {
public:

	/** Constructor Allows for the creation of the custom dropdown button
	* @param parent The parent window
	* @param id The ID of the button
	* @param label The text to be displayed on the button
	* 
	*/
	DropdownButton(wxWindow* parent, wxWindowID id = wxID_ANY, 
					const wxString& label = "DropDown Button",
					const wxSize& size = wxDefaultSize,
					const wxColour& Colour1 = wxColour(49, 54, 63),
					const wxColour& Colour2 = wxColour(238, 238, 238)
				);

	/**
	 *  Add a menu item to the dropdown button
	 * @param item The text to be displayed on the menu item
	 * @param itemID The ID of the menu item
	 */
	void AddMenuItem(const wxString& item, wxWindowID itemID);

private:
	void onButtonClicked(wxCommandEvent& event);
	void OnMouseEnter(wxMouseEvent& event);
	void OnMouseLeave(wxMouseEvent& event);


	wxSize DoGetBestSize() const;

	wxButton* dropdownButton;
	wxMenu* dropdownmenu;
	wxBoxSizer* MenuSizer;

	wxDECLARE_EVENT_TABLE();
};