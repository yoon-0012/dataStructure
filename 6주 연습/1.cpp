#include<iostream>
using namespace std;
int turn = 0;
int black = 0;
int white = 0;
int xpos = 0;
int ypos = 0;
char board[19][19];
void set();
void omok();
void ver();
void hor();
void vermax();
void hormax();
void rdiagon();
void ldiagon();
int main()
{
	for (int i = 0; i < 19; ++i)
		for (int j = 0; j < 19; ++j)
			board[i][j] = '+';
	omok();

	return 0;
}
void omok()
{
	set();
	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
			cout << board[i][j] << " ";
		cout << endl;
	}
	ver();
	hor();
	vermax();
	hormax();
	rdiagon();
	//ldiagon();
	if (turn == 1000000000000000000)
		return;
	else
		omok();
}
void set()
{
	if (turn % 2 == 0)
		cout << "p1: ";
	else
		cout << "p2: ";
	if (!(cin >> xpos >> ypos))
	{
		cin.clear();
		cin.ignore(5, '\n');
		cout << "다시 입력해주세요." << endl;
		set();
	}
	else if (xpos > 18 || ypos > 18 || xpos < 0 || ypos < 0)
	{
		cout << "다시 입력해주세요." << endl;
		set();
	}
	else if (board[ypos][xpos] != '+')
	{
		cout << "이미 돌이 있습니다." << endl;
		set();
	}
	else
	{
		if (turn % 2 == 0)
			board[ypos][xpos] = '%';
		else
			board[ypos][xpos] = '&';
		++turn;
	}
}
void ver()
{
	cout << "세로줄" << endl;
	for (int j = 0; j< 19; ++j)
	{
		for (int i = 0; i < 19; ++i)
		{
			if (board[i][j] == '%')
				++black;
			else if(board[i][j]=='&')
				++white;
		}
		cout << j << " B " << black << " W " << white << endl;
		black = 0;
		white = 0;
	}
}
void hor()
{
	cout << "가로줄" << endl;
	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{
			if (board[i][j] == '%')
				++black;
			else if (board[i][j] == '&')
				++white;
		}
		cout << i << " B " << black << " W " << white << endl;
		black = 0;
		white = 0;
	}
}
void vermax()
{
	int p1max[19] = {};
	int p2max[19] = {};
	int thismax = 0;

	for (int j = 0; j < 19; ++j)
	{
		for (int i = 0; i < 19; ++i)
		{
			if (board[i][j] == '%')
			{
				if (board[i + 1][j] == '%')
					++thismax;
				else if (thismax > p1max[j])
				{
					p1max[j] = thismax;
					thismax = 0;
				}
			}
			else if (board[i][j] == '&')
			{
				if (board[i + 1][j] == '&')
					++thismax;
				else if (thismax > p2max[j])
				{
					p2max[j] = thismax;
					thismax = 0;
				}
			}
		}
		if (p1max[j] == 0 && p2max[j]==0)
			continue;
		else
		{
			cout << "세로줄 최대 연속" << endl;
			if (p1max[j] > p2max[j])
				cout << j << " B " << p1max[j] + 1 << endl;
			else if (p2max[j] > p1max[j])
				cout << j << " W " << p2max[j] + 1 << endl;
			else
				cout << j << " B&W " << p1max[j] + 1 << endl;
		}
	}
}
void hormax()
{
	int p1max[19] = {};
	int p2max[19] = {};
	int thismax = 0;

	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{
			if (board[i][j] == '%')
			{
				if (board[i][j + 1] == '%')
					++thismax;
				else if (thismax > p1max[i])
				{
					p1max[i] = thismax;
					thismax = 0;
				}
			}
			else if (board[i][j] == '&')
			{
				if (board[i][j + 1] == '&')
					++thismax;
				else if (thismax > p2max[i])
				{
					p2max[i] = thismax;
					thismax = 0;
				}
			}
		}
		if (p1max[i] == 0 && p2max[i]==0)
			continue;
		else
		{
			cout << "가로줄 최대 연속" << endl;
			if (p1max[i] > p2max[i])
				cout << i << " B " << p1max[i] + 1 << endl;
			else if (p2max[i] > p1max[i])
				cout << i << " W " << p2max[i] + 1 << endl;
			else
				cout << i << " B&W " << p1max[i] + 1 << endl;
		}
	}
}
void rdiagon()
{
	int p1max[37] = {};
	int p2max[37] = {};
	int thismax = 0;

	for (int i = 1; i < 19; ++i)
	{
	
		for (int j = 0; j < 18; ++j)
		{
			
			if (board[j][i] == '%')
			{
				int tmpi = i;
				for (int h = j + 1; h <= 19; ++h)
				{
					if (board[j][--tmpi] == '%')
						++thismax;
					else if (thismax > p1max[i+j])
					{
						p1max[i+j] = thismax;
						thismax = 0;
					}
				}
			}
		
			else if (board[i][j] == '&')
			{
				int tmpi = i;
				for (int h = j + 1; h <= 19; ++h)
				{
					if (board[h][--tmpi] == '&')
						++thismax;
					else if (thismax > p2max[i+j])
					{
						p2max[i+j] = thismax;
						thismax = 0;
					}
				}
			}
		}
	}
	for (int i = 0; i < 37; ++i)
	{
		if (p1max[i] == 0 && p2max[i] == 0)
			continue;
		else
		{
			cout << "우상향줄 최대 연속" << endl;
			if (p1max[i] > p2max[i])
				cout << i << " B " << p1max[i] + 1 << endl;
			else if (p2max[i] > p1max[i])
				cout << i << " W " << p2max[i] + 1 << endl;
			else
				cout << i << " B&W " << p1max[i] + 1 << endl;
		}
	}
}
void ldiagon()
{
	int p1max[37] = {};
	int p2max[37] = {};
	int thismax = 0;

	for (int i = 17; i >= 0; --i)
	{

		for (int j = 0; j < 18; ++j)
		{

			if (board[j][i] == '%')
			{
				int tmpi = i;
				for (int h = j + 1; h <= 19; ++h)
				{
					if (board[h][++tmpi] == '%')
						++thismax;
					else if (thismax > p1max[h-i])
					{
						p1max[h - i] = thismax;
						thismax = 0;
					}
				}
			}

			else if (board[i][j] == '&')
			{
				int tmpi = i;
				for (int h = j + 1; h <= 19; ++h)
				{
					if (board[h][++tmpi] == '&')
						++thismax;
					else if (thismax > p2max[h - i])
					{
						p2max[h - i] = thismax;
						thismax = 0;
					}
				}
			}
		}
	}
	for (int i = 0; i < 37; ++i)
	{
		if (p1max[i] == 0 && p2max[i] == 0)
			continue;
		else
		{
			cout << "좌하향줄 최대 연속" << endl;
			if (p1max[i] > p2max[i])
				cout << i << " B " << p1max[i] + 1 << endl;
			else if (p2max[i] > p1max[i])
				cout << i << " W " << p2max[i] + 1 << endl;
			else
				cout << i << " B&W " << p1max[i] + 1 << endl;
		}
	}
}