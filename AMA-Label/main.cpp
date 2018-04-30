#include <stdio.h>
#include <Windows.h>
#include "Common\Graphics.h"
#include "Common\Control.h"
#include <concrt.h>
#include <string>
#include <iostream>
#include "TextBox.h"
using namespace std;
#define MaxSize 25

int main(int argc, char** argv) {

	HANDLE in = GetStdHandle(STD_INPUT_HANDLE);
	int i = 0;



	Graphics g;


	TextBox t(10);
	t.draw(g, 10, 15, 1);
	INPUT_RECORD ir;
	DWORD count;

	i = 0;
	while (1) {

		ReadConsoleInput(in, &ir, 1, &count);
		//if (ir.EventType == 1)cout << ir.Event.KeyEvent.wVirtualKeyCode;
		if (i++ % 2 == 0)
			switch (ir.EventType) {


			case KEY_EVENT:
				t.keyDown(ir.Event.KeyEvent.wVirtualKeyCode, ir.Event.KeyEvent.uChar.AsciiChar);
				break;
			}

	}

}










