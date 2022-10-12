#include<iostream>
using namespace std;

int main()
{
	char board[19][19] = { 0, };
	int xpos = 0;
	int ypos = 0;

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
					board[i][j] = 37;
			}

		}

		for (int i = 0; i < 19; ++i)
		{
			for (int j = 0; j < 19; ++j)
				cout << board[i][j];
			cout << endl;
		}
	}

	return 0;
}
