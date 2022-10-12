#include<iostream>
#include<cstdio>
#define MAXSIZE 19*19
using namespace std;
char board[19][19] = {};
int xpos = 0;
int ypos = 0;
int turn = 0;
int black = 0;
int white = 0;
void set();
void draw();
void omok();
void ver();
void hor();
void vermax();
void hormax();
void rdiagon();
void ldiagon();
//4시 54분
class order
{
public:
	char rock;
	int xpos;
	int ypos;
};
order stack[MAXSIZE];
order cancel[MAXSIZE];
order item;
int top = -1;
int top_c = -1;
FILE* in, * out;
int empty(int _top);
int full(int _top);
void push(order item, order* _stack, int* _top);
void pop(order* _stack, int* _top);

int main()
{
	for (int i = 0; i < 19; ++i)
		for (int j = 0; j < 19; ++j)
			board[i][j] = '+';

	omok();
	return 0;
}
void set()
{
	if (!(cin >> xpos >> ypos))
	{
		cin.clear();
		cin.ignore(5, '\n');
		cout << "다시 입력하세요" << endl;
		set();
	}
	else if (xpos > 18 || ypos > 18 || xpos < -1 || ypos < 0)
	{
		cout << "다시 입력하세요" << endl;
		set();
	}
	else if (board[ypos][xpos] != '+')
	{
		cout << "이미 돌이 놓여 있습니다" << endl;
		set();
	}
	else
	{
		if (turn % 2 == 0)
		{
			board[ypos][xpos] = '%';
			stack[++top].rock = '%';
		}
		else
		{
			board[ypos][xpos] = '&';
			stack[++top].rock = '&';
		}
		++turn;
		stack[top].xpos = xpos;
		stack[top].ypos = ypos;
	}
}
void draw()
{
	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
			cout << board[i][j] << " ";
		cout << endl;
	}
}
void omok()
{
	char choose = 48;
	while(choose!=52)
	{
		cout << "1.가로 세로 몇개" << endl;
		cout << "2.가로 세로 최대 연속 몇개" << endl;
		cout << "3.대각선 최대 연속 몇개" << endl;
		cout << "4.다음 좌표입력" << endl;
		cout << "5.저장" << endl;
		cout << "6.불러오기" << endl;
		cout << "u.무르기" << endl;
		cout << "r.무르기 취소" << endl;

		cin >> choose;
		switch (choose)
		{
		case 49:
			draw();
			ver();
			hor();
			break;
		case 50:
			draw();
			vermax();
			hormax();
			break;
		case 51:
			draw();
			rdiagon();
			ldiagon();
			break;
		case 52:
			draw();
			set();
			break;
		case 53://저장
			if (!(fopen_s(&in, "game.txt", "wb")))
				fwrite(stack, sizeof(order), 361, in);
			fclose(in);
			break;
		case 54://불러오기
			if (!(fopen_s(&out, "game.txt", "rb")))
				fread(stack, sizeof(order), 361, out);
			while (stack[++top].rock != '\0')
				board[stack[top].ypos][stack[top].xpos] = stack[top].rock;
			--top;
			fclose(out);
			draw();
			break;
		case 85://무르기
		case 117://무르기
			if (top != -1)
			{
				board[stack[top].ypos][stack[top].xpos] = '+';
				item = stack[top];
				push(item, cancel, &top_c);
				pop(stack, &top);
				draw();
			}
			break;
		case 82://무르기 취소
		case 114://무르기 취소
			if (top_c != -1)
			{
				board[cancel[top_c].ypos][cancel[top_c].xpos] = cancel[top_c].rock;
				item = cancel[top_c];
				push(item, stack, &top);
				pop(cancel, &top_c);
				draw();
			}
			break;
		default:
			cout << "잘못된 입력입니다." << endl;
			break;
		}
		draw();
		system("cls");
		draw();
	}
	if (turn != 1000000000000)
		omok();
	else
		return;
}
void ver()
{
	cout << "가로줄에 몇 개" << endl;
	for (int i = 0; i < 19; ++i)
	{

		for (int j = 0; j < 19; ++j)
		{
			if (board[i][j] == '%')
				++black;
			else if (board[i][j] == '&')
				++white;
		}
		cout << i << " 가로 " << "B" << black << "  W" << white << endl;
		black = 0;
		white = 0;

	}
}
void hor()
{
	cout << "세로줄에 몇 개" << endl;
	for (int j = 0; j < 19; ++j)
	{

		for (int i = 0; i < 19; ++i)
		{
			if (board[i][j] == '%')
				++black;
			else if (board[i][j] == '&')
				++white;
		}
		cout << j << " 세로 " << "B" << black << "  W" << white << endl;
		black = 0;
		white = 0;
	}
}
void vermax()
{
	int p1max[19] = {};
	int p2max[19] = {};
	int thismax = 0;
	cout << "가로줄 연속 몇 개" << endl;
	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{
			if (board[i][j] == '%')
			{
				if (board[i][j + 1] == '%')
					++thismax;
				else
				{
					if (p1max[i] < thismax)
						p1max[i] = thismax;
					thismax = 0;
				}
			}
			else if (board[i][j] == '&')
			{
				if (board[i][j + 1] == '&')
					++thismax;
				else
				{
					if (p2max[i] < thismax)
						p2max[i] = thismax;
					thismax = 0;
				}
			}

		}
		if (p1max[i] == 0 && p2max[i] == 0)
		{
			cout << i << " 연속x" << endl;
			continue;
		}
		else
		{

			if (p1max[i] > p2max[i])
				cout << i << " B " << p1max[i] + 1 << endl;
			else if (p1max[i] < p2max[i])
				cout << i << " W " << p2max[i] + 1 << endl;
			else
				cout << i << " B&W " << p2max[i] + 1 << endl;
		}

	}
}
void hormax()
{
	int p1max[19] = {};
	int p2max[19] = {};
	int thismax = 0;
	cout << "세로줄 연속 몇 개" << endl;
	for (int j = 0; j < 19; ++j)
	{
		for (int i = 0; i < 19; ++i)
		{
			if (board[i][j] == '%')
			{
				if (board[i + 1][j] == '%')
					++thismax;
				else
				{
					if (p1max[j] < thismax)
						p1max[j] = thismax;
					thismax = 0;
				}
			}
			else if (board[i][j] == '&')
			{
				if (board[i + 1][j] == '&')
					++thismax;
				else
				{
					if (p2max[j] < thismax)
						p2max[j] = thismax;
					thismax = 0;
				}
			}

		}
		if (p1max[j] == 0 && p2max[j] == 0)
		{
			cout << j << " 연속x" << endl;
			continue;
		}
		else
		{

			if (p1max[j] > p2max[j])
				cout << j << " B " << p1max[j] + 1 << endl;
			else if (p1max[j] < p2max[j])
				cout << j << " W " << p2max[j] + 1 << endl;
			else
				cout << j << " B&W " << p2max[j] + 1 << endl;
		}

	}
}
void rdiagon()
{
	int p1max[37] = {};
	int p2max[37] = {};
	int thismax = 0;
	cout << "우상향 연속 몇 개" << endl;
	for (int i = 0; i < 19; ++i)//0 18
	{
		for (int j = 0; j < 19; ++j)// 1 19
		{
			if (board[i][j] == '%')
			{
				if (board[i + 1][j - 1] == '%')
					++thismax;
				else
				{
					if (p1max[i + j] < thismax)
						p1max[i + j] = thismax;
					thismax = 0;
				}
			}
			else if (board[i][j] == '&')
			{
				if (board[i + 1][j - 1] == '&')
					++thismax;
				else
				{
					if (p2max[i + j] < thismax)
						p2max[i + j] = thismax;
					thismax = 0;
				}
			}

		}

	}
	
	for (int h = 0; h < 37; ++h)
	{
		if (p1max[h] == 0 && p2max[h] == 0)
		{
			cout << h << " 연속x" << endl;
			continue;
		}
		else
		{
			if (p1max[h] > p2max[h])
				cout << h << " B " << p1max[h] + 1 << endl;
			else if (p1max[h] < p2max[h])
				cout << h << " W " << p2max[h] + 1 << endl;
			else
				cout << h << " B&W " << p2max[h] + 1 << endl;
		}

	}
}
void ldiagon()
{
	int p1max[37] = {};
	int p2max[37] = {};
	int thismax = 0;
	cout << "좌하향 연속 몇 개" << endl;
	for (int i = 0; i < 19; ++i)//0/18
	{
		for (int j = 0; j < 19; ++j)//0/18
		{
			if (board[i][j] == '%')
			{
				if (board[i + 1][j + 1] == '%')
					++thismax;
				else
				{

					if (p1max[i - j + 18] < thismax)
						p1max[i - j + 18] = thismax;

					//0 16	//0 17  0 18
					//1 16	//1 17  1 18
					//2 16    2 17  2 18


				//16 0  16 1  16 2
				//17 0  17 1  17 2
				//18 0  18 1  18 2




					thismax = 0;
				}
			}
			else if (board[i][j] == '&')
			{
				if (board[i + 1][j + 1] == '&')
					++thismax;
				else
				{
					if (p2max[i - j + 18] < thismax)
						p2max[i - j + 18] = thismax;
					thismax = 0;
				}
			}

		}

	}
	for (int h = 0; h < 37; ++h)
	{
		if (p1max[h] == 0 && p2max[h] == 0)
		{
			cout << h << " 연속x" << endl;
			continue;
		}
		else
		{
			if (p1max[h] > p2max[h])
				cout << h << " B " << p1max[h] + 1 << endl;
			else if (p1max[h] < p2max[h])
				cout << h << " W " << p2max[h] + 1 << endl;
			else
				cout << h << " B&W " << p2max[h] + 1 << endl;
		}

	}
}
int empty(int _top)
{
	if (_top == -1)
		return 1;
	else 
		return 0;
}
int full(int _top)
{
	if (_top ==MAXSIZE-1)
		return 1;
	else 
		return 0;
}
void push(order item, order* _stack, int* _top)
{
	if (full(*_top) == 1)
		cout << "스택 포화" << endl;
	else
		_stack[++ * _top] = item;
}
void pop(order* _stack, int* _top)
{
	if (empty(*_top) == 1)
		cout << "스택 공백" << endl;
	else
		--* _top;
}
