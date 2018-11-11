#pragma once


class Paint
{
protected:
public:
	Paint(void);
	virtual void Draw2(CDC *dc)
	{
		CBrush brushBlue(RGB(0, 0, 255));
		CBrush* pOldBrush = dc->SelectObject(&brushBlue);

		// create and select a thick, black pen
		CPen penBlack;
		penBlack.CreatePen(PS_SOLID, 3, RGB(0, 70, 0));
		CPen* pOldPen = dc->SelectObject(&penBlack);
	}


};

