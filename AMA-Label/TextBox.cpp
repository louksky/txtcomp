#include "TextBox.h"

TextBox::TextBox(int width)
	:Control(width, 3),
	_cursorPosition(0),
	_panelLeft(0),
	_panelTop(0),
	presscount(0),
	_value("") {
}
void TextBox::Update() {
	Control::graphics.clearScreen();
	this->draw(Control::graphics, _left, _top, 1);
	Control::graphics.moveTo(_left + presscount, _top + 1);
}
void TextBox::keyDown(WORD keyCode, CHAR character) {
	if (_value.size() < _width - 2) {//check if you can change the content in textbox
		if (character > '\x1F' && character < '\x7F') {//check if value is not a navigation key
			int s = _value.size();
			if (s == presscount) {
				_value += character;
			}
			else {
				_value.insert(presscount -1, &character, 1);
			}
			 presscount++;
			TextBox::Update();
			//++_cursorPosition;
			return;
		}
	}
	switch (keyCode) {
	case VK_RIGHT: {
		if (presscount < _width) {
			++presscount;
			TextBox::Update();
		}
		break;
	}
	case VK_LEFT: {
		if (presscount > 0) {
			--presscount;
			TextBox::Update();
		}
		break;
	}
	case VK_BACK: {
		
		
	}
	case VK_DELETE: {
		if (presscount > 0) {
		 std::string str = " ";
		 --presscount;
		 _value.erase(presscount);
		 TextBox::Update();
		}
		break;
	}
	}
}


void  TextBox::draw(Graphics g, int left, int top, int layer) {
	//if (layer == getZIndex()) {
	this->_top = top;
	this->_left = left;
		Control::draw(g, left, top, layer);
		g.setCursorVisibility(true);
		g.setBackground(static_cast<Color>(GetBackground()));
		g.setForeground(static_cast<Color>(GetForeground()));
		g.write(left + 1, top + 1, _value);
		g.moveTo(left + 1 + _value.size(), top + 1);
	//}
}


string TextBox::GetValue() { return _value; }

void TextBox::SetValue(string value) { _cursorPosition = (_value = value).length(); }


TextBox::~TextBox() {}