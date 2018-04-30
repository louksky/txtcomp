#pragma once
#include "Common\Graphics.h"
#include "Common\Control.h"
class Checklist : public Control
{
protected:
	vector <string> _options;
	vector <bool> optionsSelected;
	int logicalPosition = 0;
	int cursorPosX;
	int cursorPosY;
	int panelLeft = 0;
	int panelTop = 0;
	Graphics _graphics;
	virtual void selectOption();
	bool indexInVector();
public:
	Checklist(int height, int width, vector<string> ListOfStrings, string Square_shape = "( ) ") :Control(width, height), _options(ListOfStrings) {
		int size = _options.size();
		for (int i = 0; i < size; i++) {
			_options[i].insert(0, Square_shape);
		}
		cursorPosX = _left + 2;
		cursorPosY = _top + 1;
		optionsSelected = vector<bool>(ListOfStrings.size());
	}

	void nowInFocus() {
		if (isVisible()) {
			_graphics.moveTo(panelLeft + _left + 2, panelTop + _top + logicalPosition + 1);
			_graphics.setCursorVisibility(true);
		}
	}
	void SelectIndex(size_t index);
	void DeselectIndex(size_t index);
	vector<size_t> GetSelectedIndices();
	void draw(Graphics graphics, int left, int top, int layer);
	void keyDown(WORD code, CHAR chr);
	void mousePressed(int x, int y, bool ifFirstButton);
	bool canGetFocus() {
		if (isVisible()) {
			return true;
		}
		else {
			return false;
		}
	}
	~Checklist();
	void Update();
};