class LInputManager
{
protected:
	bool IsEnabled = false;
public:
	bool Clicked = false;
	void* ClickedPanel = nullptr;
	void GetMousePos(int*, int*);
	bool IsMouseClicked();
	bool CanClick() { return ClickedPanel == nullptr; };
	void Focus( void* );
	void ToggleMenu();
	bool IsMenuEnabled() { return IsEnabled; };
}; LInputManager InputManager;

void LInputManager::GetMousePos( int* x, int* y )
{
	POINT CursorPos;
	GetCursorPos(&CursorPos);
	ClientToScreen(GetActiveWindow(), &CursorPos);
	*x = CursorPos.x;
	*y = CursorPos.y;
}

bool LInputManager::IsMouseClicked()
{
	return Clicked;
}

void LInputManager::Focus( void* Object )
{

	if ( ClickedPanel == Object )
		return;

	ClickedPanel = Object;
	
	int Index = 0;
	for ( Index = 0; Index < PanelObjects.size(); Index++ )
	{
		if ( PanelObjects[Index] == Object )
			break;
	}

	if ( Index == PanelObjects.size() )
		return;

	PanelObjects.erase( PanelObjects.begin()+Index );
	PanelObjects.push_back( Object );

}

void LInputManager::ToggleMenu()
{
	IsEnabled = !IsEnabled;

	if (IsEnabled)
		Interfaces->Engine->ClientCmd("cl_mouseenable 0");
	else
		Interfaces->Engine->ClientCmd("cl_mouseenable 1");
}