class LTab : public LBaseObject
{
protected:
	int Index = 0;
	bool CurTab = false;
	const char* Name = "Tab";
	float lh = 0.0f;
public:
	using LBaseObject::LBaseObject;
	LTab();
	LTab(int);
	virtual void Paint();
	virtual void MouseClick();

	void SetName(const char* name) { Name = name; }
	const char* GetName() { return Name; }

	void SetIndex(int index) { Index = index; }
	int GetIndex() { return Index; }

	void SetCurTab(bool curtab) { CurTab = curtab; }
	bool GetCurTab() { return CurTab; }
};

LTab::LTab()
{
	w = 60;
	h = 20;
}

LTab::LTab(int index)
{
	w = 60;
	h = 20;

	Index = index;
}

void LTab::Paint()
{

	int X, Y;
	GetPos(&X, &Y);
	int tall = h;

	if (CurTab)
		lh = Util.Lerp(Interfaces->Globals->frametime * 10.f, lh, 0);
	else
		lh = Util.Lerp(Interfaces->Globals->frametime * 10.f, lh, 4);

	Util.Clamp(lh, 0, 4);

	Y += ceil(lh);
	tall -= ceil(lh);

	Interfaces->Surface->DrawSetColor(LMenuFG);

	Interfaces->Surface->DrawLine(X, Y, X, Y + tall);
	Interfaces->Surface->DrawLine(X, Y, X + w, Y);
	Interfaces->Surface->DrawLine(X + w, Y, X + w, Y + tall);

	if (!CurTab)
	{
		//if (Hovering)
		//	lh = Util.Lerp(Interfaces->Globals->frametime * 5.f, lh, tall);
		//else
		//	lh = Util.Lerp(Interfaces->Globals->frametime * 5.f, lh, 0);

		//Util.Clamp(lh, 0, tall);

		//Interfaces->Surface->DrawFilledRect(X, Y, X + w, Y + lh);

		Draw->DrawString(textFont, X + (w * 0.5), Y + (tall * 0.5), GetTextCol(), true, true, "%s", Name);
		//Draw->DrawString(textFont, X + (w * 0.5), Y + (tall * 0.5), Color(255, 255, 255, 255), true, true, "%s", Name);
	}
	else
		Draw->DrawString(textFont, X + (w * 0.5), Y + (tall * 0.5), Color(255, 255, 255, 255), true, true, "%s", Name);

}

//

class LTabPanel : public LBaseObject
{
protected:
	std::vector<LTab*> Tabs;
	std::vector<LBaseObject*> Panels;
	int CurTab = 0;

public:
	using LBaseObject::LBaseObject;
	virtual void Paint();

	LBaseObject* AddTab(const char*);
	void SetCurrentTab(int);
	void SetCurrentTab(const char*);

	LBaseObject* GetTab(const char*);
	LBaseObject* GetTab(int);
};

void LTab::MouseClick()
{
	LTabPanel* par = (LTabPanel*)Parent;
	par->SetCurrentTab(Index);
}

void LTabPanel::Paint()
{

	int X, Y;
	GetPos(&X, &Y);

	Y = Y + 20;

	int H = h - 20;

	Interfaces->Surface->DrawSetColor(LMenuFG);

	Interfaces->Surface->DrawLine(X, Y, X, Y + H);
	Interfaces->Surface->DrawLine(X, Y + H, X + w, Y + H);
	Interfaces->Surface->DrawLine(X + w, Y, X + w, Y + H);

	if (Tabs.size() <= 0) 
		return;

	int TabX, TabY;
	Tabs[CurTab]->GetPos(&TabX, &TabY);

	Interfaces->Surface->DrawLine(X, Y, TabX, Y);
	Interfaces->Surface->DrawLine(TabX + 60, Y, X + w, Y);

}

LBaseObject* LTabPanel::AddTab(const char* name)
{

	LTab* Tab = new LTab(Tabs.size());
	Tab->SetParent(this);
	Tab->SetPos(65 * Tabs.size(), 0);
	Tab->SetName(name);

	Tabs.push_back(Tab);

	LBaseObject* Panel = new LBaseObject();
	Panel->SetParent(this);
	Panel->SetPos(0, 20);
	Panel->SetSize(w, h - 20);
	Panel->SetVisible(false);

	Panels.push_back(Panel);

	SetCurrentTab(Tabs.size() - 1);

	return Panel;

}

void LTabPanel::SetCurrentTab(int index)
{

	if (CurTab == index)
		return;

	CurTab = index;

	for (LTab* Tab : Tabs)
	{
		Tab->SetCurTab(Tab->GetIndex() == index);
	}

	for (LBaseObject* Panel : Panels)
	{
		Panel->SetVisible(false);
	}

	Panels[index]->SetVisible(true);

}

void LTabPanel::SetCurrentTab(const char* name)
{

	int index = 0;

	for (LTab* Tab : Tabs)
	{
		if (strcmp(Tab->GetName(), name) == 0)
		{
			index = Tab->GetIndex();
			break;
		}
	}

	if (CurTab == index)
		return;

	CurTab = index;

	for (LTab* Tab : Tabs)
	{
		Tab->SetCurTab(Tab->GetIndex() == index);
	}

	for (LBaseObject* Panel : Panels)
	{
		Panel->SetVisible(false);
	}

	Panels[index]->SetVisible(true);

}

LBaseObject* LTabPanel::GetTab(const char* name)
{

	for (LTab* Tab : Tabs)
	{
		if (strcmp(Tab->GetName(), name) == 0)
			return Panels[Tab->GetIndex()];
	}

	return Panels[0];

}

LBaseObject* LTabPanel::GetTab(int index)
{

	return Panels[index];

}