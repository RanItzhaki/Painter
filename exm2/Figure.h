
#pragma once

class Figure:public CObject
{
	DECLARE_SERIAL(Figure)
protected:
public:
	int x1, y1, x2, y2,x,s,idxN;
	COLORREF curColor;
	COLORREF lineColor;
	
	void Serialize(CArchive& ar)
	{
		CObject::Serialize(ar);
		if (ar.IsStoring())
		{
			ar << x1;
			ar << x2;
			ar << y1;
			ar << y2;
			ar << curColor;
			ar << lineColor;
			ar << x;
			ar << s;
			ar << idxN;
		}
		else 
		{
			ar >> x1;
			ar >> x2;
			ar >> y1;
			ar >> y2;
			ar >> curColor;
			ar >> lineColor;
			ar >> x;
			ar >> s;
			ar >> idxN;
		}

	}

	Figure()
	{
	}
	Figure(int xx1, int yy1, int xx2, int yy2, COLORREF curColor2, int size, COLORREF lineColor2,int shape1,int index)
	{
		x1 = xx1;
		x2 = xx2;
		y1 = yy1;
		y2 = yy2;
		curColor = curColor2;
		lineColor = lineColor2;
		x = size;
		s = shape1;
		idxN = index;
	}
	virtual void Draw(CDC *dc) {}

	virtual ~Figure(void) {}
};


class RectangleM :public Figure{
public:

	DECLARE_SERIAL(RectangleM)

	RectangleM()
	{
	}

	virtual ~RectangleM(void) {}

	RectangleM(int xx1, int yy1, int xx2, int yy2, COLORREF curColor2, int size, COLORREF lineColor2, int shape1, int index)
		:Figure(xx1, yy1, xx2, yy2, curColor2, size, lineColor2,shape1,index)
	{
	}
	void Draw(CDC *dc)
	{
		
		CBrush brush, *pOldBrush;

		brush.CreateHatchBrush(s, curColor);

		pOldBrush = (CBrush*)dc->SelectObject(&brush);

		CPen penBlack;
		penBlack.CreatePen(PS_SOLID, x, lineColor);
		CPen* pOldPen = dc->SelectObject(&penBlack);

		CRect rect;
		
		rect.DeflateRect(x2-x1, y2-y1);
		dc->Rectangle(x1, y1, x2, y2);
		dc->SelectObject(pOldBrush);
		dc->SelectObject(pOldPen);
	}
};

class TriangleM :public Figure{
public:

	DECLARE_SERIAL(TriangleM)

	TriangleM()
	{
	}

	virtual ~TriangleM(void) {}


	TriangleM(int xx1, int yy1, int xx2, int yy2, COLORREF curColor2, int size, COLORREF lineColor2, int shape1, int index)
		:Figure(xx1, yy1, xx2, yy2, curColor2, size, lineColor2, shape1, index)
	{
	}
	void Draw(CDC *dc)
	{
		CBrush brush, *pOldBrush;

		brush.CreateHatchBrush(s, curColor);

		pOldBrush = (CBrush*)dc->SelectObject(&brush);

		CPen penBlack;
		penBlack.CreatePen(PS_SOLID, x, lineColor);
		CPen* pOldPen = dc->SelectObject(&penBlack);

		CPoint pt[3];
		pt[0].SetPoint(x1, y2);
		pt[1].SetPoint(x2, y2);
		pt[2].SetPoint((x1 + x2) / 2, y1);

		dc->Polygon(pt, 3);
		dc->SelectObject(pOldBrush);
		dc->SelectObject(pOldPen);
	}
};


class EllipseM :public Figure{
public:

	DECLARE_SERIAL(EllipseM)

	EllipseM()
	{
	}

	virtual ~EllipseM(void) {}

	EllipseM(int xx1, int yy1, int xx2, int yy2, COLORREF curColor2, int size, COLORREF lineColor2,int shape1,int index)
		:Figure(xx1, yy1, xx2, yy2, curColor2, size, lineColor2,shape1,index)
	{
	}
	void Draw(CDC *dc)
	{

		CBrush brush, *pOldBrush;

		brush.CreateHatchBrush(s, curColor);

		pOldBrush = (CBrush*)dc->SelectObject(&brush);

		CPen penBlack;
		penBlack.CreatePen(PS_SOLID, x, lineColor);
		CPen* pOldPen = dc->SelectObject(&penBlack);

		CRect rect;

		rect.DeflateRect(x2 - x1, y2 - y1);
		dc->Ellipse(x1, y1, x2, y2);
		dc->SelectObject(pOldBrush);
		dc->SelectObject(pOldPen);
	}
};

class CircleM :public EllipseM{
public:
	DECLARE_SERIAL(CircleM)

	CircleM()
	{
	}

	virtual ~CircleM() {}

	CircleM(int xx1, int yy1, int xx2, int yy2, COLORREF curColor2, int size, COLORREF lineColor2, int shape1, int index)
		:EllipseM(xx1, yy1, xx2, yy2, curColor2, size, lineColor2, shape1, index)
	{
	}

	void Draw(CDC *dc)
	{
		CBrush brush, *pOldBrush;

		brush.CreateHatchBrush(s, curColor);

		pOldBrush = (CBrush*)dc->SelectObject(&brush);

		CPen penBlack;
		penBlack.CreatePen(PS_SOLID, x, lineColor);
		CPen* pOldPen = dc->SelectObject(&penBlack);
		int shiftX, shiftY;

		int deltaX = abs(x1 - x2);
		int deltaY = abs(y1 - y2);
		int radious = (min(deltaX, deltaY) / 2);
		if (x1<x2)
			shiftX = (deltaX / 2) - radious;
		else
			shiftX = -(deltaX / 2) - radious;

		if (y1<y2)
			shiftY = (deltaY / 2) - radious;
		else
			shiftY = -(deltaY / 2) - radious;

		dc->Ellipse(x1 + shiftX, y1 + shiftY, x1 + shiftX + 2 * radious, y1 + shiftY + 2 * radious);
		dc->SelectObject(pOldBrush);
		dc->SelectObject(pOldPen);
	}
};

class LineM :public Figure{
public:
	DECLARE_SERIAL(LineM)

	LineM()
	{
	}

	virtual ~LineM() {}

	LineM(int xx1, int yy1, int xx2, int yy2, COLORREF curColor2, int size, int index)
		:Figure(xx1, yy1, xx2, yy2, curColor2, size, curColor2, 0, index)
	{
	}
	void Draw(CDC *dc)
	{

		CPen penBlack;
		penBlack.CreatePen(PS_SOLID, x, curColor);
		CPen* pOldPen = dc->SelectObject(&penBlack);
		dc->MoveTo(x1, y1);
		dc->LineTo(x2, y2);
	}
};