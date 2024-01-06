#include <iostream>
#include <list>
using namespace std;

#include <windows.h>

int nScreenWidth = 120;
int nScreenHeight = 80;

struct sSnakeSegment
{
    int x;
    int y;
};

int main()
{
    // Create Screen Buffer
	wchar_t *screen = new wchar_t[nScreenWidth*nScreenHeight];
	for (int i = 0; i < nScreenWidth*nScreenHeight; i++) screen[i] = L' ';
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;
    
    while (1)
    {
        // Reset to known state
		list<sSnakeSegment> snake = { {60,15},{61,15},{62,15},{63,15},{64,15},{65,15},{66,15},{67,15},{68,15},{69,15} };
		int nFoodX = 30;
		int nFoodY = 15;
		int nScore = 0;
		int nSnakeDirection = 3;
		bool bDead = false;
		bool bKeyLeft = false, bKeyRight = false, bKeyLeftOld = false, bKeyRightOld = false;

        // Timing & Input
        
 
        // Game Logic


        // Display to player
        // Clear Screen
        for (int i = 0; i < nScreenWidth*nScreenHeight; i++) screen[i] = L' ';

        // Draw stats & Border
        for (int i = 0; i < nScreenWidth; i++)
        {
            screen[i] = L'=';
            screen[2*nScreenWidth + i] = L'=';
        }
        wsprintf(&screen[nScreenWidth + 5], L"www.OneLoneCoder.com - S N A K E ! !                SCORE: %d", nScore);

        // Draw Snake body
        for (auto s : snake)
            screen[s.y * nScreenWidth + s.x] = bDead ? L'+' : L'O';
        
        // Draw Snake Head
        screen[snake.front().y * nScreenWidth + snake.front().x] = bDead ? L'X' : L'@';

        // Draw Food
        screen[nFoodY * nScreenWidth + nFoodX] = L'%';

        // Display Frame
	    WriteConsoleOutputCharacterW(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
    }

    return 0;
}