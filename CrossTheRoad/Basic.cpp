#include "Basic.h"


HWND Basic::consoleWindow = GetConsoleWindow();
HANDLE Basic::consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);



void Basic::gotoXY(int x, int y)
{

	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { (short int)(x - 1),(short int)(y - 1) };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void Basic::Console_showCursor(bool s)
{
	CONSOLE_CURSOR_INFO info = { 1, s };
	SetConsoleCursorInfo(consoleOutput, &info);
}

int Basic::getKeyInput()
{
	short upState = GetAsyncKeyState(VK_UP);
	short leftState = GetAsyncKeyState(VK_LEFT);
	short downState = GetAsyncKeyState(VK_DOWN);
	short rightState = GetAsyncKeyState(VK_RIGHT);

	short wState = GetAsyncKeyState('W');
	short aState = GetAsyncKeyState('A');
	short sState = GetAsyncKeyState('S');
	short dState = GetAsyncKeyState('D');

	short escState = GetAsyncKeyState(VK_ESCAPE);

	short spaceState = GetAsyncKeyState(VK_SPACE);
	short enterState = GetAsyncKeyState(VK_RETURN);

	short hState = GetAsyncKeyState('H');


	if (upState & 1 || wState & 1)
		return 1;
	if (leftState & 1 || aState & 1)
		return 2;
	if (downState & 1 || sState & 1)
		return 3;
	if (rightState & 1 || dState & 1)
		return 4;
	if (escState & 1)
		return 5;
	if (spaceState & 1 || enterState & 1)
		return 6;
	if (hState & 1)
		return 7;
	return 0;
}

void Basic::Console_SetAndCenterWindow()
{
	RECT rectClient, rectWindow;
	GetClientRect(consoleWindow, &rectClient), GetWindowRect(consoleWindow, &rectWindow);
	int width = 1540;
	int height = 800;
	int posX = 50;
	int	posY = 15;
	MoveWindow(consoleWindow, posX, posY, width, height, TRUE);

}



void Basic::Console_SetColor(int background, int text)
{
	SetConsoleTextAttribute(consoleOutput, background * 16 + text);
	//background*16 + text: the formula give the correct combination of background and text

}

void Basic::Console_setTitle()
{
	SetConsoleTitleA("CROSS THE ROAD");
}

void Basic::Console_SetFont()
{
	CONSOLE_FONT_INFOEX info;
	info.cbSize = sizeof(info);
	GetCurrentConsoleFontEx(consoleOutput, FALSE, &info);
	info.dwFontSize.X = 12;//input width here
	info.dwFontSize.Y = 24;//input height here
	wcscpy_s(info.FaceName, L"Consolas");//input font here
	SetCurrentConsoleFontEx(consoleOutput, FALSE, &info);

	//Font: Consolas, Size: 24
}

void Basic::Console_DisableMaxSize()
{
	SetWindowLong(consoleWindow, GWL_STYLE,
		GetWindowLong(consoleWindow, GWL_STYLE) & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME));
}

void Basic::Console_HideScrollBar()
{
	ShowScrollBar(consoleWindow, SB_BOTH, 0);

}

void Basic::Console_ClearScreen()
{
	system("cls");
}

void Basic::Console_DisableMouseInput()
{
	DWORD prev_mode;
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hInput, &prev_mode);
	SetConsoleMode(hInput, prev_mode & ~ENABLE_QUICK_EDIT_MODE);
}

void Basic::Console_Setup()
{
	Console_SetColor(WHITE, WHITE);
	Console_SetFont();
	Console_SetAndCenterWindow();
	Console_setTitle();
	Console_HideScrollBar();
	Console_showCursor(false);
	Console_DisableMouseInput();
	Console_DisableMaxSize();
	Console_SetColor(LIGHTBLUE, LIGHTBLUE);
	Console_ClearScreen();
}

void Basic::textcolor(int x)
{
	consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleOutput, x);
}

void Basic::joinThread(std::thread* t)
{
	if (t->joinable())
		t->join();
}

void Basic::sleepFor_second(int sec)
{
	std::this_thread::sleep_for(std::chrono::seconds(sec));
}

void Basic::sleepFor_milisec(int milisec)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(milisec));
}

void Basic::Console_setFullscr()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}

