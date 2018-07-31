class LSlider : public LBaseObject
{
protected:
	float Value, PaintValue, MinVar, MaxVar;
	float* Var = &Value;

	bool isDragging = false;
	const char* Text = "Slider";
public:
	using LBaseObject::LBaseObject;
	LSlider();
	virtual void Think();
	virtual void Paint();

	void SetRange(float min, float max) { MinVar = min; MaxVar = max; }
	void SetDefault(float value) { Value = value; PaintValue = clamp((Value / MaxVar) * w, 0, w); }

	void SetText(const char* text) { Text = text; }
	const char* GetText() { return Text; }

	void SetVar(float* VAR) { Var = VAR; SetDefault(*VAR); }
	float GetVar() { return *Var; }
};

LSlider::LSlider()
{
	w = 200;
	h = 20;
}

void LSlider::Paint()
{

	int X, Y;
	GetPos(&X, &Y);

	Draw->DrawRect(X, Y, w, h, Color(0, 0, 0, 100));
	Draw->DrawRect(X, Y, PaintValue, h, LMenuFG);

	if (Hovering)
		Draw->DrawRect(X, Y, PaintValue, h, Color(255, 255, 255, 20));
	
	int txtW, txtH;
	wchar_t wbuffer[512];
	swprintf(wbuffer, L"%g", Value);
	Interfaces->Surface->GetTextSize(smallFont, wbuffer, txtW, txtH);

	Draw->DrawString(smallFont, X, Y - 15, Color(255, 255, 255, 255), false, false, "%s", Text);
	Draw->DrawString(smallFont, X + w - txtW, Y - 15, Color(255, 255, 255, 255), false, false, "%g", Value);

}

void LSlider::Think()
{

	if (!isDragging && InputManager.IsMouseClicked() && Hovering)
		isDragging = true;

	if (!InputManager.IsMouseClicked())
		isDragging = false;

	if (!isDragging)
		return;

	int MouseX, _;
	InputManager.GetMousePos(&MouseX, &_);

	int X;
	GetPos(&X, &_);

	float diff = (MouseX - X);

	PaintValue = clamp(diff, 0, w);

	float perc = (diff / w);
	float range = MaxVar - MinVar;
	range = range * perc;

	Value = clamp(roundf(MinVar + range), MinVar, MaxVar);
	*Var = Value;

}