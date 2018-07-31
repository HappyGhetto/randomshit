class LWindow : public LBaseObject
{
protected:
	int BarHeight = 25;
	int distX = 0;
	int distY = 0;
	bool isDragging = false;

	const char* Title = "new window";
public:
	using LBaseObject::LBaseObject;
	virtual void Think();
	virtual void Paint();

	void SetTitle( const char* Text ) { Title = Text; }
	const char* GetTitle() { return Title; }
};

void LWindow::Think()
{
	
	int MouseX, MouseY;
	InputManager.GetMousePos( &MouseX, &MouseY );

	int X, Y;
	GetPos(&X, &Y);

	if (!isDragging && (!Hovering || MouseY > Y + BarHeight))
		return;

	if (!isDragging && Clicked)
	{
		isDragging = true;

		distX = MouseX - X;
		distY = MouseY - Y;
	} 
	else if (isDragging && !InputManager.IsMouseClicked())
		isDragging = false;

	if (!isDragging)
		return;

	SetPos(MouseX - distX, MouseY - distY);

}

void LWindow::Paint()
{

	int third = w / 3;
	int X, Y;
	GetPos(&X, &Y);

	// The drag-bar on top of the menu
	Interfaces->Surface->DrawSetColor(LMenuFG);
	Interfaces->Surface->DrawFilledRect(X, Y, X + w, Y + BarHeight);

	// The menu background itself
	Interfaces->Surface->DrawSetColor(LMenuBG);
	Interfaces->Surface->DrawFilledRect(X, Y + BarHeight, X + w, Y + h - BarHeight);

	// Outline around the background
	Interfaces->Surface->DrawSetColor(LMenuFG);
	Interfaces->Surface->DrawOutlinedRect(X, Y, X + w, Y + h - BarHeight);

	//Interfaces->Surface->DrawSetColor(Color(0, 0, 0, 255));
	//Interfaces->Surface->DrawFilledRect(X, Y, X + w, Y + BarHeight);

	Draw->DrawString(textFont, X + (w * 0.5), Y + BarHeight * 0.5, Color(255, 255, 255, 255), true, true, "%s", Title);
	//Draw->DrawString(textFont, X + (w * 0.5), Y + BarHeight * 0.5, LMenuFG, true, true, "%s", Title);

}