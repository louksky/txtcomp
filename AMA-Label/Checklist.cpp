#include "Checklist.h"


void Checklist::draw(Graphics graphics, int left, int top, int layer)
{


	
	Control::draw(graphics, _left + left, _top + top, layer);
	panelLeft = left;
	panelTop = top;
	int vector_size = _options.size();
	graphics.moveTo(panelLeft + _left + 1, panelTop + _top + 1);
	for (int i = 0; i < vector_size; i++) {
		graphics.setBackground((Color)GetBackground());
		graphics.setForeground((Color)GetForeground());
		if (i == logicalPosition) {
			if (Control::getFocus() == this) {
				_graphics.setBackground(Color::Blue);
			}
			graphics.write(_options[i]);
			graphics.moveTo(panelLeft + _left + 1, panelTop + _top + i + 2);

		}
		else {
			graphics.setBackground((Color)GetBackground());
			graphics.setForeground((Color)GetForeground());
			graphics.write(_options[i]);
			graphics.moveTo(left + _left + 1, top + _top + i + 2);
		}

	}
	_graphics.setBackground(Color::Black);

}
void Checklist::Update() {
	Control::graphics.clearScreen();
	this->draw(Control::graphics, panelLeft, panelTop, 1);
	Control::graphics.moveTo(panelLeft +2  , panelTop + logicalPosition + 1);
}
void Checklist::keyDown(WORD code, CHAR chr) {
	if (!isVisible()) {
		return;
	}
	switch (code) {
	case VK_UP: 
		if (logicalPosition >= 1) {
			logicalPosition--;		}
		else {
			logicalPosition = _options.size() - 1;	}
		Checklist::Update();
		break;
	case VK_DOWN: 
		if (logicalPosition < _options.size() - 1) {
			logicalPosition++;		}
		else {
			logicalPosition = 0;	}
		Checklist::Update();
		break;
	
	case VK_RETURN: 
	case VK_SPACE: 
		selectOption();
		Checklist::Update();
		break;
	
	}
}



void Checklist::SelectIndex(size_t index) {
	logicalPosition = index;
	selectOption();
}
void Checklist::DeselectIndex(size_t index) {
	logicalPosition = index;
	selectOption();
}

void Checklist::mousePressed(int x, int y, bool ifFirstButton) {
	if (!ifFirstButton || !isInside(x, y, _left + panelLeft, _top + panelTop, _width, _height) ||
		x != _left + panelLeft + 2) {
		return;
	}
	if (isVisible()) {
		Control::setFocus(*this);
		int pressed = y - panelTop - _top - 1;
		if (pressed >= _options.size()) {
			return;
		}
		logicalPosition = pressed;
		selectOption();
	}

}

void  Checklist::selectOption() {
	if (optionsSelected[logicalPosition]) {
		optionsSelected[logicalPosition] = false;
		_graphics.moveTo(panelLeft + _left + 2, panelTop + _top + logicalPosition + 1);
		_options[logicalPosition].replace(1, 1, " ");
	}
	else {
		_graphics.moveTo(panelLeft + _left + 2, panelTop + _top + logicalPosition + 1);
		_options[logicalPosition].replace(1, 1, "X");
		optionsSelected[logicalPosition] = true;
	}
}


vector<size_t> Checklist::GetSelectedIndices() {
	vector<size_t> result;
	for (int i = 0; i < optionsSelected.size(); i++) {
		if (optionsSelected[i] == true) {
			result.push_back(i);
		}
	}
	return result;
}

bool Checklist::indexInVector() {
	return optionsSelected[logicalPosition];
}


Checklist::~Checklist()
{
}