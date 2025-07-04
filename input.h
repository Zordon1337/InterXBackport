#pragma once

class CInput
{
public:
	CInput() {};

	HWND hwCSGO;

	POINT GetMousePos();
	void GetClicked();
	bool Holding(int, int, int, int);
	bool Hovering(int, int, int, int);
	bool Clicked(int, int, int, int);
private:
	bool bClicked, bMouseD;
}; extern CInput* Input;

template< class T, class Y >
T Clamp(T const &val, Y const &minVal, Y const &maxVal)
{
	if (val < minVal)
		return minVal;
	else if (val > maxVal)
		return maxVal;
	else
		return val;
}