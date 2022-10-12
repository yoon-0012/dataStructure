#include<iostream>
using namespace std;

int main()
{
	char board[19][19] = { 0, };
	int xpos = 0;
	int ypos = 0;
	int turn = 0;
	int white = 0;
	int black = 0;

	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
			board[i][j] = 43;
	}

	for (;;)
	{
	triAgain:
		cout << "좌표: ";
		cin >> xpos;
		if (xpos == -1)
			break;

		cin >> ypos;
		if (board[ypos][xpos] == 37 || board[ypos][xpos] == 38)
		{
			cout << "이미 돌이 놓여 있습니다. " << endl;
			goto triAgain;
		}
		if (ypos > 18 || xpos > 18 || ypos < 0 || xpos < -1)
		{
			cout << "다시 입력 하세요. " << endl;
			goto triAgain;
		}
		for (int i = 0; i < 19; ++i)
		{
			for (int j = 0; j < 19; ++j)
			{
				if (xpos == j && ypos == i)
				{
					if (turn % 2 == 0)
					{
						board[i][j] = 37;
						++white;
					}
					else
					{
						board[i][j] = 38;
						++black;
					}
					++turn;
				}

			}

		}

		for (int i = 0; i < 19; ++i)
		{
			for (int j = 0; j < 19; ++j)
				cout << board[i][j];
			cout << endl;
		}
		cout << "흰돌: " << white << endl;
		cout << "검은돌: " << black << endl;
	}

	return 0;
}