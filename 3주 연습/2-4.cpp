#include<iostream>
using namespace std;

int main()
{
	char board[19][19] = { 0, };
	int xpos = 0;
	int ypos = 0;
	int turn = 0;
	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{
			board[i][j] = 43;
		}
	}
	for (;;)
	{
	tryAgain:
		cout << "좌표: ";
		cin >> xpos;
		if (xpos == -1)
			break;
		cin >> ypos;
		if (xpos > 18 || ypos > 18 || xpos < -1 || ypos < 0)
		{
			cout << "다시 입력하세요" << endl;
			goto tryAgain;
		}
		if (board[ypos][xpos] != 43)
		{
			cout << "이미 돌이 놓여있습니다" << endl;
			goto tryAgain;
		}
		if (turn % 2 == 0)
		{
			board[ypos][xpos] = 37;
			++turn;
		}
		else
		{
			board[ypos][xpos] = 38;
			++turn;
		}

		for (int i = 0; i < 19; ++i)
		{
			for (int j = 0; j < 19; ++j)
			{
				cout << board[i][j];
			}
			cout << endl;
		}
	}

}