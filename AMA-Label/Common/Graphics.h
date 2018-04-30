#pragma once

#include <string>
#include <Windows.h>

using namespace std;

enum class Color { Black, Blue, Green, Red, Cyan, Purple, Orange, White };

class Graphics
{
	HANDLE _console;
	Color _background, _foreground;
	void updateConsoleAttributes();
public:
	Graphics(DWORD stdHandle = STD_OUTPUT_HANDLE);
	void clearScreen();
	void moveTo(int x, int y);
	void setCursorVisibility(bool isVisible);
	void write(string s);
	void write(int x, int y, string s);
	void write(wstring s);
	void write(int x, int y, wstring s);
	void setBackground(Color color);
	void setForeground(Color color);
};

bool isInside(int x, int y, int left, int top, int width, int height);