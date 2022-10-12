#include<iostream>
#include<Windows.h>
using namespace std;
#define MAX_STACK_SIZE 361
struct order
{
	char rock;
	int y;
	int x;
};
order stack[MAX_STACK_SIZE];
order cancel[MAX_STACK_SIZE];
order item;
int top = -1;
int top_c = -1;
FILE* in;
FILE* out;
char board[19][19] = {};
int xpos = 0;
int ypos = 0;
int turn = 0;
int black = 0;
int white = 0;
int Max = 0;
char choose = 48;

void omok();
void set();//초기화
void draw();//출력
void countVer();//세로몇개
void countHor();//가로몇개
void verMax();//세로연속
void horMax();//가로연속
void rdiagon();//우상향
void ldiagon();//좌하향
//최대연속돌표시
void maxConDis0();//가로
void maxConDis1();//세로
void maxConDis2();//우상향
void maxConDis3();//좌하향
//1.바둑판에 놓인 돌에 대하여 한 칸이 떨어진 것까지 포함해서 연속으로 놓인 돌의 개수가 가장 많은 경우를 표시하고 좌표를 출력하라.
//2. 오목 진행 중에 상대방의3 또는 4 공격을 막아야 하는 위치가 있으면 화면에 표시하여 알려주는 기능을 구현하라.
int empty(int);
int is_full(int);
void push(order, order*, int*);
void pop(order*, int*);
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
	choose = 48;

	while (choose != 54)
	{
		cout << "1. 모든 가로줄, 세로줄의 흑돌, 백돌의 개수" << endl;
		cout << "2. 모든 가로줄, 세로줄의 최대 연속 돌과 개수" << endl;
		cout << "3. 모든 대각선 줄의 최대 연속 돌과 개수" << endl;
		cout << "4. 저장" << endl;
		cout << "5. 저장된 게임 불러오기" << endl;
		cout << "6. 다음 좌표 입력" << endl;
		cout << "7. 공백 포함 최대 연속인 돌을 표시" << endl;
		cout << "8. 3,4 공격 방어" << endl;
		cout << "U. 무르기" << endl;
		cout << "R. 무르기 취소" << endl;
		cout << "choose: ";
		cin >> choose;
		switch (choose)
		{
		case 49:
			countVer();
			countHor();
			break;
		case 50:
			verMax();
			horMax();
			break;
		case 51:
			rdiagon();
			ldiagon();
			break;
		case 52://저장
			if (fopen_s(&in, "game.txt", "wb") == 0)
				fwrite(stack, sizeof(order), top + 1, in);
			fclose(in); // 파일을 닫아주고
			break;
		case 53://불러오기
			for (int i = 0; i < 19; ++i)
				for (int j = 0; j < 19; ++j)
					board[i][j] = '+';
			top = -1;
			if (fopen_s(&out, "game.txt", "rb") == 0)
				fread(stack, sizeof(order), 361, out);
			fclose(out);
			while (stack[++top].rock != '\0')
				board[stack[top].y][stack[top].x] = stack[top].rock;
			--top;
			if (top % 2 != 0)
				turn = 0;
			else
				turn = 1;
			draw();
			break;
		case 54://좌표 입력
			set();
			draw();
			break;
		case 55://최대연속돌 표시 좌표
			maxConDis0();//가로줄 반짝
			maxConDis1();//세로
			maxConDis2();//우상향
			maxConDis3();//좌하향
			draw();
			break;
		case 56://3 4공격 방어
			maxConDis0();
			maxConDis1();
			maxConDis2();//우상향
			maxConDis3();
			draw();
			break;
		case 85://무르기
		case 117:
			if (top != -1)
			{
				board[stack[top].y][stack[top].x] = '+';
				item.rock = stack[top].rock;
				item.y = stack[top].y;
				item.x = stack[top].x;
				push(item, cancel, &top_c);
				pop(stack, &top);
				--turn;
				draw();
			}
			break;
		case 82://무르기 취소
		case 114:
			if (top_c != -1)
			{
				board[cancel[top_c].y][cancel[top_c].x] = cancel[top_c].rock;
				item.rock = cancel[top_c].rock;
				item.y = cancel[top_c].y;
				item.x = cancel[top_c].x;
				push(item, stack, &top);
				pop(cancel, &top_c);
				++turn;
				draw();
			}
			break;
		default:
			cin.clear();
			cin.ignore(5, '\n');
			cout << "잘못된 입력입니다." << endl;
			break;
		}
	}
	draw();
	system("cls");
	draw();
	if (turn == 1000000000)                                          ////오목 결판 나면 끝나는걸로
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
	if (!(cin >> ypos >> xpos))
	{
		cin.clear();
		cin.ignore(5, '\n');
		cout << "다시 입력하세요." << endl;
		set();
	}
	else if (xpos > 18 || ypos > 18 || xpos < 0 || ypos < 0)
	{
		cout << "다시 입력하세요." << endl;
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
		{
			board[ypos][xpos] = 'b';
			item.rock = 'b';
		}
		else
		{
			board[ypos][xpos] = 'w';
			item.rock = 'w';
		}
		++turn;
		item.y = ypos;
		item.x = xpos;
		push(item, stack, &top);
	}
}
void draw()
{
	cout << "  0 1 2 3 4 5 6 7 8 9 A B C D E F G H I" << endl;
	for (int i = 0; i < 19; ++i)
	{
		if (i > 9)
		{
			char i2 = i + 55;
			cout << i2 << " ";
		}
		else
			cout << i << " ";
		for (int j = 0; j < 19; ++j)
			cout << board[i][j] << " ";
		cout << endl;
	}
}
void countVer()
{
	char i2 = 65;//16진수라서 10부터는 A
	cout << "가로" << endl;
	for (int i = 0; i < 19; ++i)
	{
		black = 0;
		white = 0;
		for (int j = 0; j < 19; ++j)
		{
			if (board[i][j] == 'b' || board[i][j] == 'B')
				++black;
			else if (board[i][j] == 'w' || board[i][j] == 'W')
				++white;
		}
		if (i < 10)
			cout << i << " " << "b" << black << " " << "w" << white;
		else
		{
			cout << i2 << " " << "b" << black << " " << "w" << white;
			++i2;
		}
		cout << endl;
	}
}
void countHor()
{
	char i2 = 65;
	cout << "세로" << endl;
	for (int i = 0; i < 19; ++i)
	{
		black = 0;
		white = 0;
		for (int j = 0; j < 19; ++j)
		{
			if (board[j][i] == 'b' || board[i][j] == 'B')
				++black;
			else if (board[j][i] == 'w' || board[i][j] == 'W')
				++white;
		}
		if (i < 10)
			cout << i << " " << "b" << black << " " << "w" << white;
		else
		{
			cout << i2 << " " << "b" << black << " " << "w" << white;
			++i2;
		}
		cout << endl;
	}
}
void verMax()//세로줄연속맥스
{
	int p1max[19] = {};
	int p2max[19] = {};
	int thismax = 0;

	for (int j = 0; j < 19; ++j)
	{
		for (int i = 0; i < 19; ++i)
		{
			if (board[i][j] == 'b' || board[i][j] == 'B')
			{
				if (board[i + 1][j] == 'b' || board[i + 1][j] == 'B')
					++thismax;
				else
				{
					if (thismax > p1max[j])
						p1max[j] = thismax;
					thismax = 0;
				}
			}
			else if (board[i][j] == 'w' || board[i][j] == 'W')
			{
				if (board[i + 1][j] == 'w' || board[i + 1][j] == 'W')
					++thismax;
				else
				{
					if (thismax > p2max[j])
						p2max[j] = thismax;
					thismax = 0;
				}
			}
		}
		if (p1max[j] == 0 && p2max[j] == 0)
			continue;
		else
		{
			if (p1max[j] > p2max[j])
				cout << j << " 세로 MAX b : " << p1max[j] + 1;
			else if (p1max[j] < p2max[j])
				cout << j << " 세로 MAX w : " << p2max[j] + 1;
			else
				cout << j << " 세로 MAX b & w : " << p2max[j] + 1;
			cout << endl;
		}
	}
}
void horMax()//가로줄연속맥스
{
	int p1max[19] = {};
	int p2max[19] = {};
	int thismax = 0;

	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{
			if (board[i][j] == 'b' || board[i][j] == 'B')
			{
				if (board[i][j + 1] == 'b' || board[i][j + 1] == 'B')
					++thismax;
				else
				{
					if (thismax > p1max[i])
						p1max[i] = thismax;
					thismax = 0;
				}
			}
			else if (board[i][j] == 'w' || board[i][j] == 'W')
			{
				if (board[i][j + 1] == 'w' || board[i][j + 1] == 'W')
					++thismax;
				else
				{
					if (thismax > p2max[i])
						p2max[i] = thismax;
					thismax = 0;
				}
			}
		}
		if (p1max[i] == 0 && p2max[i] == 0)
			continue;
		else
		{
			if (p1max[i] > p2max[i])
				cout << i << " 가로 MAX b : " << p1max[i] + 1 << endl;
			else if (p1max[i] < p2max[i])
				cout << i << " 가로 MAX w : " << p2max[i] + 1 << endl;
			else
				cout << i << " 가로 MAX b & w : " << p2max[i] + 1 << endl;;
		}
	}
}
void rdiagon()
{
	int p1max[37] = {};
	int p2max[37] = {};
	int thismax = 0;
	int tmpj = 0;

	for (int j = 1; j < 19; ++j)
	{
		for (int i = 0; i < 18; ++i)
		{
			if (board[i][j] == 'b' || board[i][j] == 'B')
			{
				tmpj = j;
				for (int h = i + 1; h <= 19; ++h)
				{
					if (board[h][--tmpj] == 'b' || board[h][tmpj] == 'B')
						++thismax;
					else
					{
						if (thismax > p1max[j + i])
							p1max[j + i] = thismax;
						thismax = 0;
						break;
					}
				}
			}
			else if (board[i][j] == 'w' || board[i][j] == 'W')
			{
				tmpj = j;
				for (int h = i + 1; h <= 19; ++h)
				{
					if (board[h][--tmpj] == 'w' || board[h][tmpj] == 'W')
						++thismax;
					else
					{
						if (thismax > p2max[j + i])
							p2max[j + i] = thismax;
						thismax = 0;
						break;
					}
				}
			}
		}
	}
	for (int h = 1; h < 36; ++h)
	{
		if (p1max[h] == 0 && p2max[h] == 0)
			continue;
		else if (p1max[h] > p2max[h])
			cout << h << " 우상향 MAX b : " << p1max[h] + 1;
		else if (p1max[h] < p2max[h])
			cout << h << " 우상향 MAX w : " << p2max[h] + 1;
		else
			cout << h << " 우상향 MAX b & w : " << p2max[h] + 1;
		cout << endl;
	}
}
void ldiagon()
{
	int p1max[37] = {};
	int p2max[37] = {};
	int thismax = 0;
	int tmpj = 0;

	for (int j = 17; j >= 0; --j)
	{
		for (int i = 0; i < 18; ++i)
		{
			if (board[i][j] == 'b' || board[i][j] == 'B')
			{
				tmpj = j;
				for (int h = i + 1; h <= 19; ++h)
				{
					if (board[h][++tmpj] == 'b' || board[h][tmpj] == 'B')
						++thismax;
					else
					{
						if (thismax > p1max[18 - j + i])
							p1max[18 - j + i] = thismax;
						thismax = 0;
						break;
					}
				}
			}
			else if (board[i][j] == 'w' || board[i][j] == 'W')
			{
				tmpj = j;
				for (int h = i + 1; h <= 19; ++h)
				{
					if (board[h][++tmpj] == 'w' || board[h][tmpj] == 'W')
						++thismax;
					else
					{
						if (thismax > p2max[18 - j + i])
							p2max[18 - j + i] = thismax;
						thismax = 0;
						break;
					}
				}
			}
		}
	}
	for (int h = 1; h < 36; ++h)
	{
		if (p1max[h] == 0 && p2max[h] == 0)
			continue;
		else if (p1max[h] > p2max[h])
			cout << h << " 좌하향 MAX b : " << p1max[h] + 1;
		else if (p1max[h] < p2max[h])
			cout << h << " 좌하향 MAX w : " << p2max[h] + 1;
		else
			cout << h << " 좌하향 MAX b & w : " << p2max[h] + 1;
		cout << endl;
	}
}
int empty(int _top)
{
	return (_top == -1);
}
int is_full(int _top)
{
	return (_top == (MAX_STACK_SIZE - 1));
}
void push(order item, order* _stack, int* _top)
{
	if (is_full(*_top))
	{
		cout << "스택 포화 에러" << endl;
		return;
	}
	else
		_stack[++ * _top] = item;
}
void pop(order* _stack, int* _top)
{
	if (empty(*_top))
	{
		cout << "스택 공백 에러" << endl;
		exit(1);
	}
	else
		--* _top;
}
void maxConDis0()//가로줄 돌 반짝
{
	int thismax = 0;
	bool space = FALSE;

	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{
			if (board[i][j] == 'b' || board[i][j] == 'B')
			{
				if (board[i][j + 1] == 'b' || board[i][j + 1] == 'B')
					++thismax;
				else if (board[i][j + 2] == 'b' && space == FALSE || board[i][j + 2] == 'B' && space == FALSE)
				{
					if (j < 17)
					{
						space = TRUE;
						++j;
						++thismax;
					}
				}
				else
				{
					if (choose == 56)
					{
						if (thismax == 2 || thismax == 3 || thismax == 4 || thismax == 5 || thismax == 6 || thismax == 7)
						{
							if (turn % 2 != 0)
							{
								for (int check = 0; check < 19; ++check)
								{
									for (int check2 = 0; check2 < 19; ++check2)
									{
										if (board[check][check2] == 'W')
											board[check][check2] = 'w';
									}
								}
								if (j == 18 && thismax == 2 || space == TRUE && j - thismax - 1 == 0 && thismax == 2 || space == FALSE && j - thismax == 0 && thismax == 2)
								{
								}
								else
								{
									int tmpj = j;
									if (space == FALSE)
										for (int h = thismax; h >= 0; --h)
											board[i][tmpj--] = 'B';
									else
									{
										for (int h = thismax + 1; h >= 0; --h)
										{
											if (board[i][tmpj] == '+')
												--tmpj;
											else
												board[i][tmpj--] = 'B';
										}
									}
								}
							}
						}
					}
					else if (thismax >= Max && thismax != 0)
					{
						if (thismax > Max)
						{
							for (int check = 0; check < 19; ++check)
							{
								for (int check2 = 0; check2 < 19; ++check2)
								{
									if (board[check][check2] == 'B')
										board[check][check2] = 'b';
									else if (board[check][check2] == 'W')
										board[check][check2] = 'w';
								}
							}
						}
						Max = thismax;
						int tmpj = j;
						if (space == FALSE)
							for (int h = Max; h >= 0; --h)
								board[i][tmpj--] = 'B';
						else
						{
							for (int h = Max + 1; h >= 0; --h)
							{
								if (board[i][tmpj] == '+')
									--tmpj;
								else
									board[i][tmpj--] = 'B';
							}
						}
					}
					space = FALSE;
					thismax = 0;
				}
			}
			else if (board[i][j] == 'w' || board[i][j] == 'W')
			{
				if (board[i][j + 1] == 'w' || board[i][j + 1] == 'W')
					++thismax;
				else if (board[i][j + 2] == 'w' && space == FALSE || board[i][j + 2] == 'W' && space == FALSE)
				{
					if (j < 17)
					{
						space = TRUE;
						++j;
						++thismax;
					}
				}
				else
				{
					if (choose == 56)
					{
						if (thismax == 2 || thismax == 3 || thismax == 4 || thismax == 5 || thismax == 6 || thismax == 7)
						{
							if (turn % 2 == 0)
							{
								for (int check = 0; check < 19; ++check)
								{
									for (int check2 = 0; check2 < 19; ++check2)
									{
										if (board[check][check2] == 'B')
											board[check][check2] = 'b';
									}
								}
								if (j == 18 && thismax == 2 || space == TRUE && j - thismax - 1 == 0 && thismax == 2 || space == FALSE && j - thismax == 0 && thismax == 2)
								{
								}
								else
								{
									int tmpj = j;
									if (space == FALSE)
										for (int h = thismax; h >= 0; --h)
											board[i][tmpj--] = 'W';
									else
									{
										for (int h = thismax + 1; h >= 0; --h)
										{
											if (board[i][tmpj] == '+')
												--tmpj;
											else
												board[i][tmpj--] = 'W';
										}
									}
								}
							}
						}
					}
					else if (thismax >= Max && thismax != 0)
					{
						if (thismax > Max)
						{
							for (int check = 0; check < 19; ++check)
							{
								for (int check2 = 0; check2 < 19; ++check2)
								{
									if (board[check][check2] == 'B')
										board[check][check2] = 'b';
									else if (board[check][check2] == 'W')
										board[check][check2] = 'w';
								}
							}
						}
						Max = thismax;
						int tmpj = j;
						if (space == FALSE)
							for (int h = Max; h >= 0; --h)
								board[i][tmpj--] = 'W';
						else
						{
							for (int h = Max + 1; h >= 0; --h)
							{
								if (board[i][tmpj] == '+')
									--tmpj;
								else
									board[i][tmpj--] = 'W';
							}
						}
					}
					space = FALSE;
					thismax = 0;
				}
			}
		}
	}
}
void maxConDis1()//세로
{
	int thismax = 0;
	bool space = FALSE;

	for (int j = 0; j < 19; ++j)
	{
		for (int i = 0; i < 19; ++i)
		{
			if (board[i][j] == 'b' || board[i][j] == 'B')
			{
				if (board[i + 1][j] == 'b' || board[i + 1][j] == 'B')
					++thismax;
				else if (board[i + 2][j] == 'B' && space == FALSE || board[i + 2][j] == 'b' && space == FALSE)
				{
					if (i < 17)
					{
						space = TRUE;
						++i;
						++thismax;
					}
				}
				else
				{
					if (choose == 56)
					{
						if (thismax == 2 || thismax == 3 || thismax == 4 || thismax == 5 || thismax == 6 || thismax == 7)
						{
							if (turn % 2 != 0)
							{
								for (int check = 0; check < 19; ++check)
								{
									for (int check2 = 0; check2 < 19; ++check2)
									{
										if (board[check][check2] == 'W')
											board[check][check2] = 'w';
									}
								}
								if (i == 18 && thismax == 2 || space == TRUE && i - thismax - 1 == 0 && thismax == 2 || space == FALSE && i - thismax == 0 && thismax == 2)
								{
								}
								else
								{
									int tmpi = i;
									if (space == FALSE)
										for (int h = thismax; h >= 0; --h)
											board[tmpi--][j] = 'B';
									else
									{
										for (int h = thismax + 1; h >= 0; --h)
										{
											if (board[tmpi][j] == '+')
												--tmpi;
											else
												board[tmpi--][j] = 'B';
										}
									}
								}
							}
						}
					}
					else if (thismax >= Max && thismax != 0)
					{
						if (thismax > Max)
						{
							for (int check = 0; check < 19; ++check)
							{
								for (int check2 = 0; check2 < 19; ++check2)
								{
									if (board[check][check2] == 'B')
										board[check][check2] = 'b';
									else if (board[check][check2] == 'W')
										board[check][check2] = 'w';
								}
							}
						}
						Max = thismax;
						int tmpi = i;
						if (space == FALSE)
							for (int h = Max; h >= 0; --h)
								board[tmpi--][j] = 'B';
						else
						{
							for (int h = Max + 1; h >= 0; --h)
							{
								if (board[tmpi][j] == '+')
									--tmpi;
								else
									board[tmpi--][j] = 'B';
							}
						}
					}
					space = FALSE;
					thismax = 0;
				}
			}
			else if (board[i][j] == 'w' || board[i][j] == 'W')
			{
				if (board[i + 1][j] == 'w' || board[i + 1][j] == 'W')
					++thismax;
				else if (board[i + 2][j] == 'W' && space == FALSE || board[i + 2][j] == 'w' && space == FALSE)
				{
					if (i < 17)
					{
						space = TRUE;
						++i;
						++thismax;
					}
				}
				else
				{
					if (choose == 56)
					{
						if (thismax == 2 || thismax == 3 || thismax == 4 || thismax == 5 || thismax == 6 || thismax == 7)
						{
							if (turn % 2 == 0)
							{
								for (int check = 0; check < 19; ++check)
								{
									for (int check2 = 0; check2 < 19; ++check2)
									{
										if (board[check][check2] == 'B')
											board[check][check2] = 'b';
									}
								}
								if (i == 18 && thismax == 2 || space == TRUE && i - thismax - 1 == 0 && thismax == 2 || space == FALSE && i - thismax == 0 && thismax == 2)
								{
								}
								else
								{
									int tmpi = i;
									if (space == FALSE)
										for (int h = thismax; h >= 0; --h)
											board[tmpi--][j] = 'W';
									else
									{
										for (int h = thismax + 1; h >= 0; --h)
										{
											if (board[tmpi][j] == '+')
												--tmpi;
											else
												board[tmpi--][j] = 'W';
										}
									}
								}
							}
						}
					}
					else if (thismax >= Max && thismax != 0)
					{
						if (thismax > Max)
						{
							for (int check = 0; check < 19; ++check)
							{
								for (int check2 = 0; check2 < 19; ++check2)
								{
									if (board[check][check2] == 'B')
										board[check][check2] = 'b';
									else if (board[check][check2] == 'W')
										board[check][check2] = 'w';
								}
							}
						}
						Max = thismax;
						int tmpi = i;
						if (space == FALSE)
							for (int h = Max; h >= 0; --h)
								board[tmpi--][j] = 'W';
						else
						{
							for (int h = Max + 1; h >= 0; --h)
							{
								if (board[tmpi][j] == '+')
									--tmpi;
								else
									board[tmpi--][j] = 'W';
							}
						}
					}
					space = FALSE;
					thismax = 0;
				}
			}
		}
	}
}
void maxConDis2()//우상향
{
	int thismax = 0;
	int tmpj = 0;
	bool space = FALSE;

	for (int i = 0; i < 18; ++i)
	{
		for (int j = 1; j < 19; ++j)
		{
			if (board[i][j] == 'b' || board[i][j] == 'B')
			{
				tmpj = j;
				thismax = 0;
				for (int h = i + 1; h <= 19; ++h)
				{
					if (board[h][--tmpj] == 'b' || board[h][tmpj] == 'B')
						++thismax;
					else if (board[h + 1][tmpj - 1] == 'B' && space == FALSE || board[h + 1][tmpj - 1] == 'b' && space == FALSE)
					{
						if (h < 18 && tmpj>0)
						{
							space = TRUE;
							--tmpj;
							++h;
							++thismax;
						}
					}
					else
					{
						if (choose == 56)
						{
							if (thismax == 2 || thismax == 3 || thismax == 4 || thismax == 5 || thismax == 6 || thismax == 7)
							{
								if (turn % 2 != 0)
								{
									for (int check = 0; check < 19; ++check)
									{
										for (int check2 = 0; check2 < 19; ++check2)
										{
											if (board[check][check2] == 'W')
												board[check][check2] = 'w';
										}
									}
									if (h - 1 == 18 && thismax == 2 || space == TRUE && h - thismax - 2 == 0 && thismax == 2 || space == FALSE && h - 1 - thismax == 0 && thismax == 2)
									{
									}
									else if (tmpj + 1 == 0 && thismax == 2 || space == TRUE && tmpj + thismax + 2 == 18 && thismax == 2 || space == FALSE && tmpj + thismax + 1 == 18 && thismax == 2)
									{
									}
									else
									{
										int tmpi = --h;
										if (space == FALSE)
											for (int h2 = thismax; h2 >= 0; --h2)
												board[tmpi--][++tmpj] = 'B';
										else
										{
											for (int h2 = thismax + 1; h2 >= 0; --h2)
											{
												if (board[tmpi][++tmpj] == '+')
													--tmpi;
												else
													board[tmpi--][tmpj] = 'B';
											}
										}
									}
								}
							}
						}
						else if (thismax >= Max && thismax != 0)//////////////////////////////////이거 반복된다 함수로 만들어주자
						{
							if (thismax > Max)
							{
								for (int check = 0; check < 19; ++check)
								{
									for (int check2 = 0; check2 < 19; ++check2)
									{
										if (board[check][check2] == 'B')
											board[check][check2] = 'b';
										else if (board[check][check2] == 'W')
											board[check][check2] = 'w';
									}
								}
							}
							Max = thismax;
							int tmpi = --h;
							if (space == FALSE)
								for (int h2 = Max; h2 >= 0; --h2)
									board[tmpi--][++tmpj] = 'B';
							else
							{
								for (int h2 = Max + 1; h2 >= 0; --h2)
								{
									if (board[tmpi][++tmpj] == '+')
										--tmpi;
									else
										board[tmpi--][tmpj] = 'B';
								}
							}
						}
						space = FALSE;
						thismax = 0;
					}
				}
			}
			else if (board[i][j] == 'w' || board[i][j] == 'W')
			{
				tmpj = j;
				thismax = 0;
				for (int h = i + 1; h <= 19; ++h)
				{
					if (board[h][--tmpj] == 'w' || board[h][tmpj] == 'W')
						++thismax;
					else if (board[h + 1][tmpj - 1] == 'W' && space == FALSE || board[h + 1][tmpj - 1] == 'w' && space == FALSE)
					{
						if (h < 18 && tmpj>0)
						{
							space = TRUE;
							--tmpj;
							++h;
							++thismax;
						}
					}
					else
					{
						if (choose == 56)
						{
							if (thismax == 2 || thismax == 3 || thismax == 4 || thismax == 5 || thismax == 6 || thismax == 7)
							{
								if (turn % 2 == 0)
								{
									for (int check = 0; check < 19; ++check)
									{
										for (int check2 = 0; check2 < 19; ++check2)////////////////////////////요거도 반복
										{
											if (board[check][check2] == 'B')
												board[check][check2] = 'b';
										}
									}
									if (h - 1 == 18 && thismax == 2 || space == TRUE && h - thismax - 2 == 0 && thismax == 2 || space == FALSE && h - 1 - thismax == 0 && thismax == 2)
									{
									}
									else if (tmpj + 1 == 0 && thismax == 2 || space == TRUE && tmpj + thismax + 2 == 18 && thismax == 2 || space == FALSE && tmpj + thismax + 1 == 18 && thismax == 2)
									{
									}
									else
									{
										int tmpi = --h;
										if (space == FALSE)
											for (int h2 = thismax; h2 >= 0; --h2)
												board[tmpi--][++tmpj] = 'W';
										else
										{
											for (int h2 = thismax + 1; h2 >= 0; --h2)
											{
												if (board[tmpi][++tmpj] == '+')
													--tmpi;
												else
													board[tmpi--][tmpj] = 'W';
											}
										}
									}
								}
							}
						}
						else if (thismax >= Max && thismax != 0)
						{
							if (thismax > Max)
							{
								for (int check = 0; check < 19; ++check)
								{
									for (int check2 = 0; check2 < 19; ++check2)
									{
										if (board[check][check2] == 'B')
											board[check][check2] = 'b';
										else if (board[check][check2] == 'W')
											board[check][check2] = 'w';
									}
								}
							}
							Max = thismax;
							int tmpi = --h;
							if (space == FALSE)
								for (int h2 = Max; h2 >= 0; --h2)
									board[tmpi--][++tmpj] = 'W';
							else
							{
								for (int h2 = Max + 1; h2 >= 0; --h2)
								{
									if (board[tmpi][++tmpj] == '+')
										--tmpi;
									else
										board[tmpi--][tmpj] = 'W';
								}
							}
						}
						space = FALSE;
						thismax = 0;
					}
				}
			}
		}
	}
}
void maxConDis3()//좌하향
{
	int thismax = 0;
	int tmpj = 0;
	bool space = FALSE;

	for (int i = 0; i < 18; ++i)
	{
		for (int j = 17; j >= 0; --j)
		{
			if (board[i][j] == 'b' || board[i][j] == 'B')
			{
				tmpj = j;
				thismax = 0;
				for (int h = i + 1; h <= 19; ++h)
				{
					if (board[h][++tmpj] == 'b' || board[h][tmpj] == 'B')
						++thismax;
					else if (board[h + 1][tmpj + 1] == 'B' && space == FALSE || board[h + 1][tmpj + 1] == 'b' && space == FALSE)
					{
						if (h < 18 && tmpj < 18)
						{
							space = TRUE;
							++tmpj;
							++h;
							++thismax;
						}
					}
					else
					{
						if (choose == 56)
						{
							if (thismax == 2 || thismax == 3 || thismax == 4 || thismax == 5 || thismax == 6 || thismax == 7)
							{
								if (turn % 2 != 0)
								{
									for (int check = 0; check < 19; ++check)
									{
										for (int check2 = 0; check2 < 19; ++check2)
										{
											if (board[check][check2] == 'W')
												board[check][check2] = 'w';
										}
									}
									if (h - 1 == 18 && thismax == 2 || space == TRUE && h - thismax - 2 == 0 && thismax == 2 || space == FALSE && h - 1 - thismax == 0 && thismax == 2)
									{
									}
									else if (tmpj - 1 == 18 && thismax == 2 || space == TRUE && tmpj + thismax == 0 && thismax == 2 || space == FALSE && tmpj + thismax - 1 == 0 && thismax == 2)
									{
									}
									else
									{
										int tmpi = h - 1;//--h
										if (space == FALSE)
											for (int h2 = thismax; h2 >= 0; --h2)
												board[tmpi--][--tmpj] = 'B';
										else
										{
											for (int h2 = thismax + 1; h2 >= 0; --h2)
											{
												if (board[tmpi][--tmpj] == '+')
													--tmpi;
												else
													board[tmpi--][tmpj] = 'B';
											}
										}
									}
								}
							}
						}
						else if (thismax >= Max && thismax != 0)
						{
							if (thismax > Max)
							{
								for (int check = 0; check < 19; ++check)
								{
									for (int check2 = 0; check2 < 19; ++check2)
									{
										if (board[check][check2] == 'B')
											board[check][check2] = 'b';
										else if (board[check][check2] == 'W')
											board[check][check2] = 'w';
									}
								}
							}
							Max = thismax;
							int tmpi = h - 1;//--h
							if (space == FALSE)
								for (int h2 = Max; h2 >= 0; --h2)
									board[tmpi--][--tmpj] = 'B';
							else
							{
								for (int h2 = Max + 1; h2 >= 0; --h2)
								{
									if (board[tmpi][--tmpj] == '+')
										--tmpi;
									else
										board[tmpi--][tmpj] = 'B';
								}
							}
						}
						space = FALSE;
						thismax = 0;
					}
				}
			}
			else if (board[i][j] == 'w' || board[i][j] == 'W')
			{
				tmpj = j;
				thismax = 0;
				for (int h = i + 1; h <= 19; ++h)
				{
					if (board[h][++tmpj] == 'w' || board[h][tmpj] == 'W')
						++thismax;
					else if (board[h + 1][tmpj + 1] == 'W' && space == FALSE || board[h + 1][tmpj + 1] == 'w' && space == FALSE)
					{
						if (h < 18 && tmpj < 18)
						{
							space = TRUE;
							++tmpj;
							++h;
							++thismax;
						}
					}
					else
					{
						if (choose == 56)
						{
							if (thismax == 2 || thismax == 3 || thismax == 4 || thismax == 5 || thismax == 6 || thismax == 7)
							{
								if (turn % 2 == 0)
								{
									for (int check = 0; check < 19; ++check)
									{
										for (int check2 = 0; check2 < 19; ++check2)
										{
											if (board[check][check2] == 'B')
												board[check][check2] = 'b';
										}
									}
									if (h - 1 == 18 && thismax == 2 || space == TRUE && h - thismax - 2 == 0 && thismax == 2 || space == FALSE && h - 1 - thismax == 0 && thismax == 2)
									{
									}
									else if (tmpj - 1 == 18 && thismax == 2 || space == TRUE && tmpj + thismax == 0 && thismax == 2 || space == FALSE && tmpj + thismax - 1 == 0 && thismax == 2)
									{
									}
									else
									{
										int tmpi = h - 1;//--h
										if (space == FALSE)
											for (int h2 = thismax; h2 >= 0; --h2)
												board[tmpi--][--tmpj] = 'W';
										else
										{
											for (int h2 = thismax + 1; h2 >= 0; --h2)
											{
												if (board[tmpi][--tmpj] == '+')
													--tmpi;
												else
													board[tmpi--][tmpj] = 'W';
											}
										}
									}
								}
							}
						}
						else if (thismax >= Max && thismax != 0)
						{
							if (thismax > Max)
							{
								for (int check = 0; check < 19; ++check)
								{
									for (int check2 = 0; check2 < 19; ++check2)
									{
										if (board[check][check2] == 'B')
											board[check][check2] = 'b';
										else if (board[check][check2] == 'W')
											board[check][check2] = 'w';
									}
								}
							}
							Max = thismax;
							int tmpi = h - 1;//--h
							if (space == FALSE)
								for (int h2 = Max; h2 >= 0; --h2)
									board[tmpi--][--tmpj] = 'W';
							else
							{
								for (int h2 = Max + 1; h2 >= 0; --h2)
								{
									if (board[tmpi][--tmpj] == '+')
										--tmpi;
									else
										board[tmpi--][tmpj] = 'W';
								}
							}
						}
						space = FALSE;
						thismax = 0;
					}
				}
			}
		}
	}
}

