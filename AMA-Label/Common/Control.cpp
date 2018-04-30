#include "Control.h"

Control* Control::_inFocus = nullptr;

void Control::draw(Graphics graphics, int left, int top, int layer) {
	

	graphics.setBackground((Color)_backgroundColor);
	graphics.setForeground(_border.getColor());

	graphics.moveTo(left, top);

	printf("%c", _border.getLeftTop());//corner north west

	for (short i = 0; i < _width - 2; i++) {
		printf("%c", _border.getTopBotton());//line north
	}

	printf("%c", _border.getRightTop()); //corner north east

	for (short i = 1; i < _height - 1; i++) {
		graphics.moveTo(left, top + i);
		printf("%c", _border.getRightLeft()); // line west
		for (short i = 0; i < _width - 2; i++) {
			printf("%c", ' ');//line north
		}
		graphics.moveTo(left + _width - 1, top + i);
		printf("%c", _border.getRightLeft()); //line east
	}

	graphics.moveTo(left, top + _height - 1);

	printf("%c", _border.getLeftBotton()); // corner south west

	for (short i = 0; i < _width - 2; i++) {
		printf("%c", _border.getTopBotton());// south line
	}

	printf("%c", _border.getRightBotton()); //corner south west

}
