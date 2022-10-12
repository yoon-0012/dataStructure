#include<iostream>
#include<Windows.h>
#include<random>
#include"Judgment.h"
using namespace std;
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> yPos(0, 18);
std::uniform_int_distribution<int> xPos(0, 18);
#define MAX_STACK_SIZE 361
class order
{
public:
	char rock;
	int type;    //가로0 세로1 우상2 좌하3
	int y;
	int x;
	order* link=NULL;
};
char board[19][19] = {};
int xpos = 0;
int ypos = 0;
int turn = 0;
int Max = 0;
char choose = '0';
bool defense = FALSE;
//bool compile = FALSE;

order* continue1 = new order;
order* continue2 = new order;
order* continue3 = new order;
order* continue4 = new order;

void omok();
void set();//초기화
void draw();//출력
//최대연속돌표시
void maxConDis0();//가로
void maxConDis1();//세로
void maxConDis2();//우상향
void maxConDis3();//좌하향
//1.바둑판에 놓인 돌에 대하여 한 칸이 떨어진 것까지 포함해서 연속으로 놓인 돌의 개수가 가장 많은 경우를 표시하고 좌표를 출력하라.
//2. 오목 진행 중에 상대방의3 또는 4 공격을 막아야 하는 위치가 있으면 화면에 표시하여 알려주는 기능을 구현하라.
void newNode(order* head, int type, int column, int row);
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
	choose = '0';

	while (choose != '6')
	{
		/*cout << "1. 다음 턴" << endl;
		cout << "2. 공백 포함 최대 연속인 돌을 표시" << endl;
		cout << "3. 3,4 공격 방어" << endl;
			case '1'://좌표 입력
			set();
			draw();
			break;
		case '2'://최대연속돌 표시 좌표
			maxConDis0();//가로줄 반짝
			maxConDis1();//세로
			maxConDis2();//우상향
			maxConDis3();//좌하향
			draw();
			break;
		case '3'://3 4공격 방어
			maxConDis0();
			maxConDis1();
			maxConDis2();//우상향
			maxConDis3();
			draw();
			break;*/
		cout << "1. 자동 두기" << endl;
		cout << "2. 1수 예측하고 두기" << endl;
		cout << "choose: ";
		cin >> choose;
		switch (choose)
		{
		case '1':
			set();
			draw();
			break;
		case '2':
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
	for (int check = 0; check < 19; ++check)
	{
		for (int check2 = 0; check2 < 19; ++check2)
		{
			if (board[check][check2] != 'b' && board[check][check2] != 'w' && board[check][check2] != '+')
				board[check][check2] = '+';
		}
	}
	if (turn % 2 == 0)
	{
		cout << "you: ";
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
			board[ypos][xpos] = 'b';
	}
	else
	{
		//ypos = yPos(gen);
				//xpos = xPos(gen);
		maxConDis0();//가로
		//maxConDis1();//세로
		//maxConDis2();//우상향
		//maxConDis3();//좌하향
		for (int i = 0; i < 19; ++i)
		{
			for (int j = 0; j < 19; ++j)
			{
				if (board[i][j] == '1'|| board[i][j] == 'W')
				{
					ypos = i;
					xpos = j;
					break;
				}
				else
				{
					for (;;)
					{
						ypos = yPos(gen);
						xpos = xPos(gen);
						if (board[ypos][xpos] == '+')
							break;
					}
				}
			}
			if (board[ypos][xpos] == '1'||board[ypos][xpos]=='W')
				break;
		}
		board[ypos][xpos] = 'w';
	}
	++turn;
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
void maxConDis0()//가로줄 돌 반짝
{
	int thismax = 0;
	bool space = FALSE;

	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{
			if (board[i][j] == 'b')
			{
				if (board[i][j + 1] == 'b')
					++thismax;
				else if (board[i][j + 2] == 'b' && space == FALSE)
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
					//if (thismax == 2 || thismax == 3 || thismax == 4 || thismax == 5 || thismax == 6 || thismax == 7)//방어
					if(thismax==2&&j!=18&&j-thismax-1!=0&&space==TRUE&&board[i][j+1]!='w'&&board[i][j-thismax-2]!='w'&&turn%2!=0)
						defense = TRUE;
					else if (thismax == 2 && j != 18 && j - thismax  != 0 && space == FALSE && board[i][j + 1] != 'w' && board[i][j - thismax - 1] != 'w')
						defense = TRUE;
					else if (thismax == 3 && j != 18 && j - thismax - 1 != 0 && space == TRUE && board[i][j + 1] != 'w' && board[i][j - thismax - 2] != 'w')
						defense = TRUE;
					else if (thismax == 3 && j != 18 && j - thismax  != 0 && space == FALSE && board[i][j + 1] != 'w' && board[i][j - thismax - 1] != 'w')
						defense = TRUE;


					if (defense == TRUE)
					{
						if (space == FALSE)
						{
							board[i][j + 1] = '1';
							board[i][j - thismax - 1] = '2';
						}
						else
						{
							board[i][j + 1] = '2';
							board[i][j - thismax - 2] = '3';
							int tmpj = j;
							for (int h = thismax + 1; h >= 0; --h)
							{
								if (board[i][tmpj--] == '+')
									board[i][tmpj + 1] = '1';
							}
						}
					}
					else//공격
					{
						for (int i = 0; i < 19; i++)
						{
							for (int j = 0; j < 19; j++)
							{
								if (board[i][j] == '+')
								{
									int howMany = 0;
									
									for (int h = j - 1; h >= 0;-- h)
									{
										if (board[i][h] == 'w')
											++howMany;
										else
											break;
									}
									for (int h = j + 1; h <= 18; ++h)
									{
										if (board[i][h] == 'w')
											++howMany;
										else
											break;
									}
									if (howMany == 5)
										cout << "백돌 승리" << endl;
									else if (howMany == 4)
										newNode(continue4, 0, i, j);
									else if (howMany == 3)
										newNode(continue3, 0, i, j);
									else if (howMany == 2)
										newNode(continue2, 0, i, j);
									else if (howMany == 1)
										newNode(continue1, 0, i, j);

									if (continue4->link != NULL)
									{
										board[continue4->link->y][continue4->link->x] = 'W';
										break;
									}
									else if (continue3->link != NULL)
									{
										board[continue3->link->y][continue3->link->x] = 'W';
										break;
									}
									else if (continue2->link != NULL)
									{
										board[continue2->link->y][continue2->link->x] = 'W';
										break;
									}
									else if (continue1->link != NULL)
									{
										board[continue1->link->y][continue1->link->x] = 'W';
										break;
									}
								}
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
			if (board[i][j] == 'b')
			{
				if (board[i + 1][j] == 'b')
					++thismax;
				else if (board[i + 2][j] == 'b' && space == FALSE)
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
					if (thismax == 2 || thismax == 3 || thismax == 4 || thismax == 5 || thismax == 6 || thismax == 7)
					{
						if (turn % 2 != 0)
						{
							if (i == 18 && thismax == 2 || space == TRUE && i - thismax - 1 == 0 && thismax == 2 || space == FALSE && i - thismax == 0 && thismax == 2)
							{
							}
							else
							{
								if (space == FALSE)
								{
									board[i + 1][j] = '1';
									board[i - thismax - 1][j] = '2';
								}
								else
								{
									board[i + 1][j] = '2';
									board[i - thismax - 2][j] = '3';
									int tmpi = i;
									for (int h = thismax + 1; h >= 0; --h)
									{
										if (board[tmpi--][j] == '+')
											board[tmpi + 1][j] = '1';
									}
								}
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
			if (board[i][j] == 'b')
			{
				tmpj = j;
				thismax = 0;
				for (int h = i + 1; h <= 19; ++h)
				{
					if (board[h][--tmpj] == 'b')
						++thismax;
					else if (board[h + 1][tmpj - 1] == 'b' && space == FALSE)
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
						if (thismax == 2 || thismax == 3 || thismax == 4 || thismax == 5 || thismax == 6 || thismax == 7)
						{
							if (turn % 2 != 0)
							{
								if (h - 1 == 18 && thismax == 2 || space == TRUE && h - thismax - 2 == 0 && thismax == 2 || space == FALSE && h - 1 - thismax == 0 && thismax == 2)
								{
								}
								else if (tmpj + 1 == 0 && thismax == 2 || space == TRUE && tmpj + thismax + 2 == 18 && thismax == 2 || space == FALSE && tmpj + thismax + 1 == 18 && thismax == 2)
								{
								}
								else
								{
									if (space == FALSE)
									{
										board[i - 1][j + 1] = '1';
										board[i + thismax + 1][j - thismax - 1] = '2';
									}
									else
									{
										board[i - 1][j + 1] = '2';
										board[i + thismax + 2][j - thismax - 2] = '3';
										int tmpi = --h;
										for (int h2 = thismax + 1; h2 >= 0; --h2)
										{
											if (board[tmpi][++tmpj] == '+')
												board[tmpi][tmpj] = '1';
											--tmpi;
										}
									}
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
			if (board[i][j] == 'b')
			{
				tmpj = j;
				thismax = 0;
				for (int h = i + 1; h <= 19; ++h)
				{
					if (board[h][++tmpj] == 'b')
						++thismax;
					else if (board[h + 1][tmpj + 1] == 'b' && space == FALSE)
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
						if (thismax == 2 || thismax == 3 || thismax == 4 || thismax == 5 || thismax == 6 || thismax == 7)
						{
							if (turn % 2 != 0)
							{
								if (h - 1 == 18 && thismax == 2 || space == TRUE && h - thismax - 2 == 0 && thismax == 2 || space == FALSE && h - 1 - thismax == 0 && thismax == 2)
								{
								}
								else if (tmpj - 1 == 18 && thismax == 2 || space == TRUE && tmpj + thismax == 0 && thismax == 2 || space == FALSE && tmpj + thismax - 1 == 0 && thismax == 2)
								{
								}
								else
								{
									if (space == FALSE)
									{
										board[i - 1][j - 1] = '1';
										board[i + thismax + 1][j + thismax + 1] = '2';
									}
									else
									{
										board[i - 1][j - 1] = '2';
										board[i + thismax + 2][j + thismax + 2] = '3';
										int tmpi = h - 1;
										for (int h2 = thismax + 1; h2 >= 0; --h2)
										{
											if (board[tmpi][--tmpj] == '+')
												board[tmpi][tmpj] = '1';
											--tmpi;
										}
									}
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
void newNode(order* head, int type, int y, int x)
{
	order* node = new order;

	node->link = head->link;
	head->link = node;

	node->type = type;
	node->y = y;
	node->x = x;
}


