class LCheckBox : public LBaseObject
{
protected:
	bool* Var = false;

	const char* Text = "Checkbox";
	float radius = 0.0f;
public:
	using LBaseObject::LBaseObject;
	LCheckBox();
	virtual void Paint();
	virtual void MouseClick();

	void SetText(const char* text) { Text = text; }
	const char* GetText() { return Text; }

	void SetVar(bool* VAR) { Var = VAR; }
	bool GetVar() { return *Var; }
};

LCheckBox::LCheckBox()
{
	w = 20;
	h = 20;
}

void LCheckBox::Paint()
{
	
	int X, Y;
	GetPos(&X, &Y);

	if (Hovering)
		Interfaces->Surface->DrawSetColor(Util.AddCol(LMenuFG, Color(30, 30, 30, 0)));
	else
		Interfaces->Surface->DrawSetColor(LMenuFG);

	Interfaces->Surface->DrawOutlinedRect(X, Y, X + w, Y + h);

	/*
	if (GetVar())
	{
		Interfaces->Surface->DrawFilledRect(X + 2, Y + 2, X + w - 2, Y + h - 2);
	}
	else if (Hovering)
	{
		Interfaces->Surface->DrawSetColor(Util.SubCol(LMenuFG, Color(0, 0, 0, 220)));
		Interfaces->Surface->DrawFilledRect(X + 2, Y + 2, X + w - 2, Y + h - 2);
	}
	*/

	if (GetVar())
		radius = Util.Lerp(Interfaces->Globals->frametime * 5.f, radius, w);
	else
		radius = Util.Lerp(Interfaces->Globals->frametime * 5.f, radius, 0);

	Util.Clamp(radius, 0, w);
	int rad = ceil(radius);

	Interfaces->Surface->DrawFilledRect(X + (w - rad), Y + (h - rad), X + rad, Y + rad);

	Draw->DrawString(textFont, X + w + 10, Y + (h * 0.5) - 10, Color(255, 255, 255, 255), false, false, "%s", Text);
	
}

void LCheckBox::MouseClick()
{
	*Var = !*Var;
}