#include<iostream>
using namespace std;
void set(char(*board)[19], int*, int*, int*);
void omok(char(*board)[19], int*, int*, int*, int*, int*);

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
			board[i][j] = '+';//43
	}

	omok(board, &xpos, &ypos, &turn, &black, &white);

	return 0;
}
void set(char(*board)[19], int* x, int* y, int* myturn)
{
	if (*myturn % 2 == 0)
		cout << "player1�� ���ʾ�" << endl;
	else
		cout << "player2�� ���ʾ�" << endl;

	if (!(cin >> *x >> *y))
	{
		cin.clear();
		cin.ignore(5, '\n');
		cout << "�ٽ� �Է��ϼ���" << endl;
		set(board, x, y, myturn);
	}

	if (*x > 18 || *y > 18 || *x < 0 || y < 0)
	{
		cout << "�ٽ� �Է��ϼ���" << endl;
		set(board, x, y, myturn);
	}
	if (*(*(board + *y) + *x) != '+')
	{
		cout << "�̹� ���� �����ֽ��ϴ�" << endl;
		set(board, x, y, myturn);
	}
}

void omok(char(*board)[19], int* x, int* y, int* myturn, int* myblack, int* mywhite)
{
	set(board, x, y, myturn);
	if (*myturn % 2 == 0)
	{
		*(*(board + *y) + *x) = '%';//37
		++* myblack;
		++* myturn;
	}
	else
	{
		*(*(board + *y) + *x) = '&';//38
		++* mywhite;
		++* myturn;
	}

	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
			cout << board[i][j] << " ";
		cout << endl;
	}
	cout << "������: " << *myblack << endl;
	cout << "��: " << *mywhite << endl;
	if (*myturn == 1000000000)                                          ////���� ���� ���� �����°ɷ�
		return;
	else
		omok(board, x, y, myturn, myblack, mywhite);
}