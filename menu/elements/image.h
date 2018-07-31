class LImage : public LBaseObject
{
private:
	TextureHolder img;
public:
	virtual void Paint();
	void SetImage(int res, const char* gr, Color COL = Color(255, 255, 255, 255)) { img = TextureHolder((const unsigned char*)Util.GetResource(res, gr), w, h, COL); };
};

void LImage::Paint()
{
	int X, Y;
	GetPos(&X, &Y);

	img.Draw(X, Y);
}