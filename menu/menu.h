
std::vector<void*> PanelObjects;
std::vector<void*> PanelObjectsSorted;

bool bRain = true;

Color LMenuFG = Color( 255, 115, 130, 255 ); // LS = 255, 115, 130, 255
Color LMenuBG = Color( 30, 30, 50, 250 );

unsigned long textFont;
unsigned long smallFont;

void SetupFonts()
{
	textFont = Interfaces->Surface->CreateFont();
	Interfaces->Surface->SetFontGlyphSet(textFont, "Arial", 14, 400, 0, 0, 0x010);

	smallFont = Interfaces->Surface->CreateFont();
	Interfaces->Surface->SetFontGlyphSet(smallFont, "Arial", 12, 400, 0, 0, 0x010);
}

#include "inputsystem.h"
#include "elements\baseobject.h"
#include "elements\window.h"
#include "elements\checkbox.h"
#include "elements\form.h"
#include "elements\slider.h"
#include "elements\tabs.h"
#include "elements\colorpicker.h"
#include "elements\combobox.h"
#include "elements\image.h"

#include "setup.h"

bool didToggle = false;

void MenuThink()
{

	if ( GetAsyncKeyState( VK_INSERT ))
	{
		if (!didToggle)
		{
			InputManager.ToggleMenu();
			didToggle = true;
		}
	}
	else
	{
		didToggle = false;
	}

	InputManager.Clicked = (bool)(GetAsyncKeyState(VK_LBUTTON) & 0x8000);

	if ( !InputManager.IsMenuEnabled() )
	{
		return;
	}

	for (void* vPanel : PanelObjects)
	{
		LBaseObject* Panel = (LBaseObject*)vPanel;

		if (Panel == NULL || !Panel->GetVisible()) continue;

		Panel->Tick();
	}

}

void MenuPaint()
{
	if ( !InputManager.IsMenuEnabled() )
	{
		return;
	}

	if (bRain)
	{

	}

	for (void* vPanel : PanelObjects)
	{
		LBaseObject* Panel = (LBaseObject*)vPanel;

		if (Panel == NULL || !Panel->GetVisible()) continue;

		Panel->Paint();
	}
}
