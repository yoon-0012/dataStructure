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
			board[i][j] = 43;
	}

	for (;;)
	{
	triAgain:
		cout << "��ǥ: ";
		cin >> xpos;
		if (xpos == -1)
			break;

		cin >> ypos;
		if (board[ypos][xpos] == 37 || board[ypos][xpos] == 38)
		{
			cout << "�̹� ���� ���� �ֽ��ϴ�. " << endl;
			goto triAgain;
		}
		if (ypos > 18 || xpos > 18 || ypos < 0 || xpos < -1)
		{
			cout << "�ٽ� �Է� �ϼ���. " << endl;
			goto triAgain;
		}
		for (int i = 0; i < 19; ++i)
		{
			for (int j = 0; j < 19; ++j)
			{
				if (xpos == j && ypos == i)
				{
					if (turn % 2 == 0)
						board[i][j] = 37;
					else
						board[i][j] = 38;
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
	}
	return 0;
}
