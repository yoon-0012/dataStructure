#include<iostream>
using namespace std;
int main()
{
	char matrix[19][19] = { 0, };
	int xpos = 0;
	int ypos = 0;
	int turn = 0;
	int black = 0;
	int white = 0;

	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
			matrix[i][j] = 43;
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
		if (matrix[ypos][xpos] != 43)
		{
			cout << "이미 돌이 놓여 있습니다" << endl;
			goto tryAgain;
		}
		if (turn % 2 == 0)
		{
			matrix[ypos][xpos] = 37;
			++black;
			++turn;
		}
		else
		{
			matrix[ypos][xpos] = 38;
			++white;
			++turn;
		}
		for (int i = 0; i < 19; ++i)
		{
			for (int j = 0; j < 19; ++j)
				cout << matrix[i][j];
			cout << endl;
		}
		cout << "검은 돌: " << black << endl;
		cout << "흰 돌:   " << white << endl;
	}


	return 0;
}