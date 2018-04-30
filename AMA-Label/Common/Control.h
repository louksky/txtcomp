#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Graphics.h"

using namespace std;

enum class ForegroundColor { Black, Blue, Green, Red, Cyan, Purple, Orange, White };
enum class BackgroundColor { Black, Blue, Green, Red, Cyan, Purple, Orange, White };

class Border {
protected:
	char leftTop;
	char rightTop;
	char topBotton;
	char leftBotton;
	char rightBotton;
	char rightLeft;
	Color _color;
	Border() { _color = Color::White; }
public:
	char getLeftTop()const { return leftTop; }
	char getRightTop()const { return rightTop; }
	char getRightLeft()const { return rightLeft; }
	char getTopBotton()const { return topBotton; }
	char getLeftBotton()const { return leftBotton; }
	char getRightBotton()const { return rightBotton; }
	//Can set the border color.
	void setColor(Color color) { _color = color; }
	Color getColor() { return _color; }
};


class BorderNon : public Border {
public:
	BorderNon() {
		leftTop = ' ';
		rightTop = ' ';
		rightLeft = ' ';
		topBotton = ' ';
		leftBotton = ' ';
		rightBotton = ' ';
	}
};

class BorderDouble : public Border {
public:
	BorderDouble() {
		leftTop = '\xC9';
		rightTop = '\xBB';
		rightLeft = '\xBA';
		topBotton = '\xCD';
		leftBotton = '\xC8';
		rightBotton = '\xBC';
	}
};

class BorderSolid : public Border {
public:
	BorderSolid() {
		leftTop = '\xDA';
		rightTop = '\xBF';
		rightLeft = '\xB3';
		topBotton = '\xC4';
		leftBotton = '\xC0';
		rightBotton = '\xD9';
	}
};


class Control
{
	int _zIndex = 0;
	bool _isVisible;
	bool _isFocused;
protected:
	Graphics graphics;
	HANDLE _console = GetStdHandle(STD_OUTPUT_HANDLE);
	Border _border = BorderDouble();
	ForegroundColor _foregroundColor;
	BackgroundColor _backgroundColor;

	int _width, _height, _top, _left;

	static Control* _inFocus;
public:

	static Control* getFocus() { return _inFocus; }

	Control(int width, int height) :_width(width), _height(height), _top(0), _left(0), _isVisible(true), _foregroundColor(ForegroundColor::White),
		_backgroundColor(BackgroundColor::Black) {}
	~Control() {};

	static void setFocus(Control &control) {
		_inFocus = &control;
		_inFocus->nowInFocus();
		control.setZIndex(5);
	}
	int getZIndex() { return _zIndex; }
	void setZIndex(int zIndex) { _zIndex = zIndex; }
	int getWidth() { return _width; }
	void setTop(int top) { _top = top; }
	int getTop() { return _top; }
	void setLeft(int left) { _left = left; }
	int getLeft() { return _left; }
	virtual void SetForeground(ForegroundColor color) { _foregroundColor = color; }
	virtual BackgroundColor GetBackground() { return _backgroundColor; }
	virtual ForegroundColor GetForeground() { return _foregroundColor; }
	virtual void SetBackground(BackgroundColor color) { _backgroundColor = color; }
	virtual void SetBorder(Border border) { _border = border; }

	virtual void Show() { _isVisible = true; }
	virtual void Hide() { _isVisible = false; }
	bool isVisible() { return _isVisible; }
	virtual void draw(Graphics graphics, int left, int top, int layer);
	virtual void keyDown(WORD code, CHAR chr) = 0;
	
	virtual void getAllControls(vector<Control*> *controls) { controls->push_back(this); }
	virtual void nowInFocus() {}

};

