#include<iostream>
#include<cstdio>
#define MAX 19*19
using namespace std;
#include<random>

random_device rd;
mt19937 gen;
uniform_int_distribution<int>xPos(0, 18);
uniform_int_distribution<int>yPos(0, 18);

class saveContinue
{
public:
	bool exist = false;
	int y;
	int x;
};
saveContinue attack[4];
saveContinue defense[4];
int Attack();// (node* head, int type, int y, int x);
int Defense();// (node* head, int type, int y, int x);

int whiteContinue = 0;
int blackContinue = 0;
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
class order
{
public:
	char rock;
	int xpos;
	int ypos;
};
order stack[MAX];
//order stack2[MAX];
order cancel[MAX];
order item;
int top = -1;
int top_c = -1;
int Max = 0;
char choose = 48;
//int top2 = -1;
FILE* in, * out;
int empty(int _top);
int full(int _top);
void push(order item, order* _stack, int* _top);
void pop(order* _stack, int* _top);
void maxConDis();//가로
void maxConDis2();//세로
void maxConDis3();//우상향
void maxConDis4();//좌하향
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
		if (!(cin >> ypos >> xpos))
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

			board[ypos][xpos] = 'b';
			stack[++top].rock = 'b';

		}
	}
	else
	{

		if (defense[3].exist == true && board[defense[3].y][defense[3].x] == '+')
		{
			board[defense[3].y][defense[3].x] = 'w';
			int recommend = 50;
			if (board[defense[3].y][defense[3].x + 1] != 'b')
				board[defense[3].y][defense[3].x + 1] = recommend++;
			if (board[defense[3].y + 1][defense[3].x] != 'b')
				board[defense[3].y + 1][defense[3].x] = recommend++;
			if (board[defense[3].y][defense[3].x - 1] != 'b')
				board[defense[3].y][defense[3].x - 1] = recommend++;
			if (board[defense[3].y - 1][defense[3].x] != 'b')
				board[defense[3].y - 1][defense[3].x] = recommend++;
		}
		else if (attack[3].exist == true && board[defense[3].y][defense[3].x] == '+')
		{
			board[attack[3].y][attack[3].x] = 'w';
			int recommend = 50;
			if (board[attack[3].y][attack[3].x + 1] != 'b')
				board[attack[3].y][attack[3].x + 1] = recommend++;
			if (board[attack[3].y + 1][attack[3].x] != 'b')
				board[attack[3].y + 1][attack[3].x] = recommend++;
			if (board[attack[3].y][attack[3].x - 1] != 'b')
				board[attack[3].y][attack[3].x - 1] = recommend++;
			if (board[attack[3].y - 1][attack[3].x] != 'b')
				board[attack[3].y - 1][attack[3].x] = recommend++;
		}

		else if (defense[2].exist == true && board[defense[2].y][defense[2].x] == '+')
		{
			board[defense[2].y][defense[2].x] = 'w';
			int recommend = 50;
			if (board[defense[2].y][defense[2].x + 1] != 'b')
				board[defense[2].y][defense[2].x + 1] = recommend++;
			if (board[defense[2].y + 1][defense[2].x] != 'b')
				board[defense[2].y + 1][defense[2].x] = recommend++;
			if (board[defense[2].y][defense[2].x - 1] != 'b')
				board[defense[2].y][defense[2].x - 1] = recommend++;
			if (board[defense[2].y - 1][defense[2].x] != 'b')
				board[defense[2].y - 1][defense[2].x] = recommend++;
		}
		else if (attack[2].exist == true && board[attack[2].y][attack[2].x] == '+')
		{
			board[attack[2].y][attack[2].x] = 'w';
			int recommend = 50;
			if (board[attack[2].y][attack[2].x + 1] != 'b')
				board[attack[2].y][attack[2].x + 1] = recommend++;
			if (board[attack[2].y + 1][attack[2].x] != 'b')
				board[attack[2].y + 1][attack[2].x] = recommend++;
			if (board[attack[2].y][attack[2].x - 1] != 'b')
				board[attack[2].y][attack[2].x - 1] = recommend++;
			if (board[attack[2].y - 1][attack[2].x] != 'b')
				board[attack[2].y - 1][attack[2].x] = recommend++;
		}

		else if (attack[1].exist == true && board[attack[1].y][attack[1].x] == '+')
		{
			board[attack[1].y][attack[1].x] = 'w';
			int recommend = 50;
			if (board[attack[1].y][attack[1].x + 1] != 'b')
				board[attack[1].y][attack[1].x + 1] = recommend++;
			if (board[attack[1].y + 1][attack[1].x] != 'b')
				board[attack[1].y + 1][attack[1].x] = recommend++;
			if (board[attack[1].y][attack[1].x - 1] != 'b')
				board[attack[1].y][attack[1].x - 1] = recommend++;
			if (board[attack[1].y - 1][attack[1].x] != 'b')
				board[attack[1].y - 1][attack[1].x] = recommend++;
		}

		else if (attack[0].exist == true && board[attack[0].y][attack[0].x] == '+')
		{
			board[attack[0].y][attack[0].x] = 'w';
			int recommend = 50;
			if (board[attack[0].y][attack[0].x + 1] != 'b')
				board[attack[0].y][attack[0].x + 1] = recommend++;
			if (board[attack[0].y + 1][attack[0].x] != 'b')
				board[attack[0].y + 1][attack[0].x] = recommend++;
			if (board[attack[0].y][attack[0].x - 1] != 'b')
				board[attack[0].y][attack[0].x - 1] = recommend++;
			if (board[attack[0].y - 1][attack[0].x] != 'b')
				board[attack[0].y - 1][attack[0].x] = recommend++;
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
			board[ypos][xpos] = 'w';
			stack[++top].rock = 'w';
		}

	
		stack[++top].rock = 'w';
	}
	++turn;
	stack[top].ypos = ypos;
	stack[top].xpos = xpos;
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
	choose = '0';
	/*attack1->link = NULL;
	attack2->link = NULL;
	attack3->link = NULL;
	attack4->link = NULL;
	defense1->link = NULL;
	defense2->link = NULL;
	defense3->link = NULL;
	defense4->link = NULL;*/

	//while (choose != 52)
	//{
	//	cout << "1.가로 세로 몇개" << endl;
	//	cout << "2.가로 세로 최대 연속 몇개" << endl;
	//	cout << "3.대각선 최대 연속 몇개" << endl;
	//	cout << "4.다음 좌표 입력" << endl;
	//	cout << "5.저장" << endl;
	//	cout << "6.불러오기" << endl;
	//	cout << "7.최대 연속 돌 표시" << endl;
	//	cout << "8.상대방 3,4돌 표시" << endl;
	//	cout << "U.무르기" << endl;
	//	cout << "R.무르기 취소" << endl;

	//	cin >> choose;
	//	switch (choose)
	//	{
	//	case 49:
	//		draw();
	//		ver();
	//		hor();
	//		break;
	//	case 50:
	//		draw();
	//		vermax();
	//		hormax();
	//		break;
	//	case 51:
	//		draw();
	//		rdiagon();
	//		ldiagon();
	//		break;
	//	case 52:
	//		draw();
	//		set();
	//		break;
	//	case 53://저장
	//		if (!(fopen_s(&in, "game.txt", "wb")));
	//		fwrite(stack, sizeof(order), MAX, in);
	//		fclose(in);
	//		break;
	//	case 54://불러오기
	//		for (int i = 0; i < 19; ++i)
	//			for (int j = 0; j < 19; ++j)
	//				board[i][j] = '+';
	//		top = -1;
	//		if (!(fopen_s(&out, "game.txt", "rb")));
	//		fread(stack, sizeof(order), MAX, out);
	//		while (stack[++top].rock != '\0')
	//			board[stack[top].ypos][stack[top].xpos] = stack[top].rock;
	//		--top;
	//		if (top % 2 != 0)
	//			turn = 0;
	//		else
	//			turn = 1;
	//		fclose(out);
	//		break;
	//	case 55://최대 연속
	//		maxConDis();//가로
	//		maxConDis2();//세로
	//		//maxConDis3();//우상향
	//		//maxConDis4();//좌하향
	//		break;
	//	case 56://3 4 막기
	//		maxConDis();//가로
	//		maxConDis2();//세로
	//		//maxConDis3();//우상향
	//		//maxConDis4();//좌하향
	//		break;
	//	case 85://무르기
	//	case 117:
	//		if (top != -1)
	//		{
	//			board[stack[top].ypos][stack[top].xpos] = '+';
	//			item = stack[top];
	//			push(item, cancel, &top_c);
	//			pop(stack, &top);
	//			--turn;
	//		}
	//		break;
	//	case 82://무르기 취소
	//	case 114:
	//		if (top_c != -1)
	//		{
	//			board[cancel[top_c].ypos][cancel[top_c].xpos] = cancel[top_c].rock;
	//			item = cancel[top_c];
	//			push(item, stack, &top);
	//			pop(cancel, &top_c);
	//			++turn;
	//		}
	//		break;
	//	default:
	//		cout << "잘못된 입력입니다." << endl;
	//		break;
	//	}
	//	draw();
	//	system("cls");
	//	draw();
	//}
	cout << "choose: ";
	cin >> choose;
	if (choose == '1')
	{
		/*if (Defense() == true)
			failDefense = true;
		else if (Attack() == true)
			successAttack = true;*/
		if (Defense() == true)
		{
			cout << "you win!" << endl;
			return;
		}
		else if (Attack() == true)
		{
			cout << "ai win!" << endl;
			return;
		}
	

		draw();
		set();


		draw();
		system("cls");
		draw();
	}
		omok();
}
void ver()
{
	cout << "가로줄에 몇 개" << endl;
	for (int i = 0; i < 19; ++i)
	{

		for (int j = 0; j < 19; ++j)
		{
			if (board[i][j] == 'B' || board[i][j] == 'b')
				++black;
			else if (board[i][j] == 'W' || board[i][j] == 'w')
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
			if (board[i][j] == 'B' || board[i][j] == 'b')
				++black;
			else if (board[i][j] == 'W' || board[i][j] == 'w')
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
			if (board[i][j] == 'B' || board[i][j] == 'b')
			{
				if (board[i][j + 1] == 'B' || board[i][j + 1] == 'b')
					++thismax;
				else
				{
					if (p1max[i] < thismax)
						p1max[i] = thismax;
					thismax = 0;
				}
			}
			else if (board[i][j] == 'W' || board[i][j] == 'w')
			{
				if (board[i][j + 1] == 'W' || board[i][j + 1] == 'w')
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
			if (board[i][j] == 'B' || board[i][j] == 'b')
			{
				if (board[i][j] == 'B' || board[i][j] == 'b')
					++thismax;
				else
				{
					if (p1max[j] < thismax)
						p1max[j] = thismax;
					thismax = 0;
				}
			}
			else if (board[i][j] == 'W' || board[i][j] == 'w')
			{
				if (board[i + 1][j] == 'W' || board[i + 1][j] == 'w')
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
			if (board[i][j] == 'B' || board[i][j] == 'b')
			{
				if (board[i][j] == 'B' || board[i][j] == 'b')
					++thismax;
				else
				{
					if (p1max[i + j] < thismax)
						p1max[i + j] = thismax;
					thismax = 0;
				}
			}
			else if (board[i][j] == 'W' || board[i][j] == 'w')
			{
				if (board[i + 1][j - 1] == 'W' || board[i + 1][j - 1] == 'w')
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
			if (board[i][j] == 'B' || board[i][j] == 'b')
			{
				if (board[i][j] == 'B' || board[i][j] == 'b')
					++thismax;
				else
				{

					if (p1max[i - j + 18] < thismax)
						p1max[i - j + 18] = thismax;

					thismax = 0;
				}
			}
			if (board[i][j] == 'W' || board[i][j] == 'w')
			{
				if (board[i + 1][j + 1] == 'W' || board[i + 1][j + 1] == 'w')
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
	if (_top == MAX - 1)
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
void maxConDis()//가로
{
	int thismax = 0;
	bool space = false;

	for (int i = 0; i < 19; ++i)
	{
		thismax = 0;
		space = false;
		for (int j = 0; j < 19; ++j)
		{
			if (board[i][j] == 'B' || board[i][j] == 'b')
			{
				if (board[i][j + 1] == 'B' || board[i][j + 1] == 'b')
					++thismax;
				else if (board[i][j + 2] == 'B' || board[i][j + 2] == 'b')
				{
					space = true;
					++thismax;
					++j;
				}
				else
				{
					if (choose == 56)//34 공격
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
								if (j == 18 && thismax == 2 || space == false && j - thismax == 0 && thismax == 2 || space == true && j - thismax - 1 == 0 && thismax == 2)
								{
								}
								else
								{
									int tmpj = j;
									if (space == true)
									{
										for (int h = thismax + 1; h >= 0; --h)
										{
											if (board[i][tmpj] == 'b')
												board[i][tmpj--] = 'B';
											else if (board[i][tmpj] == '+')
												--tmpj;
										}
									}
									else
										for (int h = thismax; h >= 0; --h)
											board[i][tmpj--] = 'B';
								}
							}
						}
					}
					else//통틀어서 최대연속
					{
						if (thismax != 0 && thismax >= Max)
						{
							if (thismax > Max)
							{
								for (int check = 0; check < 19; ++check)
								{
									for (int check2 = 0; check2 < 19; ++check2)
									{
										if (board[check][check2] == 'W')
											board[check][check2] = 'w';
										else if (board[check][check2] == 'B')
											board[check][check2] = 'b';
									}
								}
							}
							Max = thismax;
							int tmpj = j;
							if (space == false)
								for (int h = Max; h >= 0; --h)
									board[i][tmpj--] = 'B';
							else
							{
								for (int h = Max + 1; h <= 0; --h)
								{
									if (board[i][tmpj] == 'b')
										board[i][tmpj--] = 'B';
									else if (board[i][tmpj] == '+')
										--tmpj;
								}
							}
						}
					}
				}
			}
			else if (board[i][j] == 'W' || board[i][j] == 'w')
			{
				if (board[i][j + 1] == 'W' || board[i][j + 1] == 'w')
					++thismax;
				else if (board[i][j + 2] == 'W' || board[i][j + 2] == 'w')
				{
					space = true;
					++thismax;
					++j;
				}
				else
				{
					if (choose == 56)//34 공격
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
								if (j == 18 && thismax == 2 || space == false && j - thismax == 0 && thismax == 2 || space == true && j - thismax - 1 == 0 && thismax == 2)
								{
								}
								else
								{
									int tmpj = j;
									if (space == true)
									{
										for (int h = thismax + 1; h >= 0; --h)
										{
											if (board[i][tmpj] == 'w')
												board[i][tmpj--] = 'W';
											else if (board[i][tmpj] == '+')
												--tmpj;
										}
									}
									else
										for (int h = thismax; h >= 0; --h)
											board[i][tmpj--] = 'W';
								}
							}
						}
					}
					else//통틀어서 최대연속
					{
						if (thismax != 0 && thismax >= Max)
						{
							if (thismax > Max)
							{
								for (int check = 0; check < 19; ++check)
								{
									for (int check2 = 0; check2 < 19; ++check2)
									{
										if (board[check][check2] == 'W')
											board[check][check2] = 'w';
										else if (board[check][check2] == 'B')
											board[check][check2] = 'b';
									}
								}
							}
							Max = thismax;
							int tmpj = j;
							if (space == false)
								for (int h = Max; h >= 0; --h)
									board[i][tmpj--] = 'W';
							else
							{
								for (int h = Max + 1; h <= 0; --h)
								{
									if (board[i][tmpj] == 'w')
										board[i][tmpj--] = 'W';
									else if (board[i][tmpj] == '+')
										--tmpj;
								}
							}
						}
					}
				}
			}
		}
	}
}
void maxConDis2()//세로
{
	int thismax = 0;
	bool space = false;

	for (int j = 0; j < 19; ++j)
	{
		thismax = 0;
		space = false;
		for (int i = 0; i < 19; ++i)
		{
			if (board[i][j] == 'B' || board[i][j] == 'b')
			{
				if (board[i + 1][j] == 'B' || board[i + 1][j] == 'b')
					++thismax;
				else if (board[i + 2][j] == 'B' || board[i + 2][j] == 'b')
				{
					space = true;
					++thismax;
					++i;
				}
				else
				{
					if (choose == 56)//34 공격
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
								if (i == 18 && thismax == 2 || space == false && i - thismax == 0 && thismax == 2 || space == true && i - thismax - 1 == 0 && thismax == 2)
								{
								}
								else
								{
									int tmpi = i;
									if (space == true)
									{
										for (int h = thismax + 1; h >= 0; --h)
										{
											if (board[tmpi][j] == 'b')
												board[tmpi--][j] = 'B';
											else if (board[tmpi][j] == '+')
												--tmpi;
										}
									}
									else
										for (int h = thismax; h >= 0; --h)
											board[tmpi--][j] = 'B';
								}
							}
						}
					}
					else//통틀어서 최대연속
					{
						if (thismax != 0 && thismax >= Max)
						{
							if (thismax > Max)
							{
								for (int check = 0; check < 19; ++check)
								{
									for (int check2 = 0; check2 < 19; ++check2)
									{
										if (board[check][check2] == 'W')
											board[check][check2] = 'w';
										else if (board[check][check2] == 'B')
											board[check][check2] = 'b';
									}
								}
							}
							Max = thismax;
							int tmpi = i;
							if (space == false)
								for (int h = Max; h >= 0; --h)
									board[tmpi--][j] = 'B';
							else
							{
								for (int h = Max + 1; h <= 0; --h)
								{
									if (board[tmpi][j] == 'b')
										board[tmpi--][j] = 'B';
									else if (board[tmpi][j] == '+')
										--tmpi;
								}
							}
						}
					}
				}
			}
			else if (board[i][j] == 'W' || board[i][j] == 'w')
			{
				if (board[i + 1][j] == 'W' || board[i + 1][j] == 'w')
					++thismax;
				else if (board[i + 2][j] == 'W' || board[i + 2][j] == 'w')
				{
					space = true;
					++thismax;
					++i;
				}
				else
				{
					if (choose == 56)//34 공격
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
								if (i == 18 && thismax == 2 || space == false && i - thismax == 0 && thismax == 2 || space == true && i - thismax - 1 == 0 && thismax == 2)
								{
								}
								else
								{
									int tmpi = i;
									if (space == true)
									{
										for (int h = thismax + 1; h >= 0; --h)
										{
											if (board[tmpi][j] == 'w')
												board[tmpi--][j] = 'W';
											else if (board[tmpi][j] == '+')
												--tmpi;
										}
									}
									else
										for (int h = thismax; h >= 0; --h)
											board[tmpi--][j] = 'W';
								}
							}
						}
					}
					else//통틀어서 최대연속
					{
						if (thismax != 0 && thismax >= Max)
						{
							if (thismax > Max)
							{
								for (int check = 0; check < 19; ++check)
								{
									for (int check2 = 0; check2 < 19; ++check2)
									{
										if (board[check][check2] == 'W')
											board[check][check2] = 'w';
										else if (board[check][check2] == 'B')
											board[check][check2] = 'b';
									}
								}
							}
							Max = thismax;
							int tmpi = i;
							if (space == false)
								for (int h = Max; h >= 0; --h)
									board[tmpi--][j] = 'W';
							else
							{
								for (int h = Max + 1; h <= 0; --h)
								{
									if (board[tmpi][j] == 'w')
										board[tmpi--][j] = 'W';
									else if (board[tmpi][j] == '+')
										--tmpi;
								}
							}
						}
					}
				}
			}
		}
	}
}
void maxConDis3()//우상향
{

}
void maxConDis4()//좌하향
{

}
int Attack()//(node* head, int type, int y, int x)
{
	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{

			if (board[i][j] == '+')
			{
				//가로
				whiteContinue = 0;
				for (int h = j - 1; h >= 0; --h)
				{
					if (board[i][h] == 'w')
						++whiteContinue;
					else
						break;
				}
				
				for (int h = j + 1; h <= 18; ++h)
				{
					if (board[i][h] == 'w')
						++whiteContinue;
					else
						break;
				}
				switch (whiteContinue)
				{
				case 1:
					attack[0].exist = true;
					attack[0].y = i;
					attack[0].x = j;
					break;
				case 2:
					attack[1].exist = true;
					attack[1].y = i;
					attack[1].x = j;
					break;
				case 3:
					attack[2].exist = true;
					attack[2].y = i;
					attack[2].x = j;
					break;
				case 4:
					attack[3].exist = true;
					attack[3].y = i;
					attack[3].x = j;
					break;
				case 5:
					return 1;
				}

				//세로
				whiteContinue = 0;
				for (int h = i - 1; h >= 0; --h)
				{
					if (board[h][j] == 'w')
						++whiteContinue;
					else
						break;
				}
				for (int h = i + 1; h <= 18; ++h)
				{
					if (board[h][j] == 'w')
						++whiteContinue;
					else
						break;
				}
				switch (whiteContinue)
				{
				case 1:
					attack[0].exist = true;
					attack[0].y = i;
					attack[0].x = j;
					break;
				case 2:
					attack[1].exist = true;
					attack[1].y = i;
					attack[1].x = j;
					break;
				case 3:
					attack[2].exist = true;
					attack[2].y = i;
					attack[2].x = j;
					break;
				case 4:
					attack[3].exist = true;
					attack[3].y = i;
					attack[3].x = j;
					break;
				case 5:
					return 1;
				}

				//우상
				whiteContinue = 0;
				for (int h = i - 1, t = j + 1; h >= 0, t <= 18; --h, ++t)
				{
					if (board[h][t] == 'w')
						++whiteContinue;
					else
						break;
				}
				for (int h = i + 1, t = j - 1; h <= 18, t >= 0; ++h, --t)
				{
					if (board[h][t] == 'w')
						++whiteContinue;
					else
						break;
				}
				switch (whiteContinue)
				{
				case 1:
					attack[0].exist = true;
					attack[0].y = i;
					attack[0].x = j;
					break;
				case 2:
					attack[1].exist = true;
					attack[1].y = i;
					attack[1].x = j;
					break;
				case 3:
					attack[2].exist = true;
					attack[2].y = i;
					attack[2].x = j;
					break;
				case 4:
					attack[3].exist = true;
					attack[3].y = i;
					attack[3].x = j;
					break;
				case 5:
					return 1;
				}

				//좌하
				whiteContinue = 0;
				for (int h = i - 1, t = j - 1; h >= 0, t >= 0; --h, --t)
				{
					if (board[h][t] == 'w')
						++whiteContinue;
					else
						break;
				}
				for (int h = i + 1, t = j + 1; h <= 18, t <= 18; ++h, ++t)
				{
					if (board[h][t] == 'w')
						++whiteContinue;
					else
						break;
				}
				switch (whiteContinue)
				{
				case 1:
					attack[0].exist = true;
					attack[0].y = i;
					attack[0].x = j;
					break;
				case 2:
					attack[1].exist = true;
					attack[1].y = i;
					attack[1].x = j;
					break;
				case 3:
					attack[2].exist = true;
					attack[2].y = i;
					attack[2].x = j;
					break;
				case 4:
					attack[3].exist = true;
					attack[3].y = i;
					attack[3].x = j;
					break;
				case 5:
					return 1;
				}
			}
		}
	}
	return 0;
}
int Defense()//(node* head, int type, int y, int x)//927 어택
{
	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{

			if (board[i][j] == '+')
			{
				//가로
				blackContinue = 0;
				for (int h = j - 1; h >= 0; --h)
				{
					if (board[i][h] == 'b')
						++blackContinue;
					else
						break;
				}
				
				for (int h = j + 1; h <= 18; ++h)
				{
					if (board[i][h] == 'b')
						++blackContinue;
					else
						break;
				}
				switch (blackContinue)
				{
				case 1:
					defense[0].exist = true;
					defense[0].y = i;
					defense[0].x = j;
					break;
				case 2:
					defense[1].exist = true;
					defense[1].y = i;
					defense[1].x = j;
					break;
				case 3:
					defense[2].exist = true;
					defense[2].y = i;
					defense[2].x = j;
					break;
				case 4:
					defense[3].exist = true;
					defense[3].y = i;
					defense[3].x = j;
					break;
				case 5:
					return 1;
				}

				//세로
				blackContinue = 0;
				for (int h = i - 1; h >= 0; --h)
				{
					if (board[h][j] == 'b')
						++blackContinue;
					else
						break;
				}
				for (int h = i + 1; h <= 18; ++h)
				{
					if (board[h][j] == 'b')
						++blackContinue;
					else
						break;
				}
				switch (blackContinue)
				{
				case 1:
					defense[0].exist = true;
					defense[0].y = i;
					defense[0].x = j;
					break;
				case 2:
					defense[1].exist = true;
					defense[1].y = i;
					defense[1].x = j;
					break;
				case 3:
					defense[2].exist = true;
					defense[2].y = i;
					defense[2].x = j;
					break;
				case 4:
					defense[3].exist = true;
					defense[3].y = i;
					defense[3].x = j;
					break;
				case 5:
					return 1;
				}

				//우상
				blackContinue = 0;
				for (int h = i - 1, t = j + 1; h >= 0, t <= 18; --h, ++t)
				{
					if (board[h][t] == 'b')
						++blackContinue;
					else
						break;
				}
				for (int h = i + 1, t = j - 1; h <= 18, t >= 0; ++h, --t)
				{
					if (board[h][t] == 'b')
						++blackContinue;
					else
						break;
				}
				switch (blackContinue)
				{
				case 1:
					defense[0].exist = true;
					defense[0].y = i;
					defense[0].x = j;
					break;
				case 2:
					defense[1].exist = true;
					defense[1].y = i;
					defense[1].x = j;
					break;
				case 3:
					defense[2].exist = true;
					defense[2].y = i;
					defense[2].x = j;
					break;
				case 4:
					defense[3].exist = true;
					defense[3].y = i;
					defense[3].x = j;
					break;
				case 5:
					return 1;
				}

				//좌하
				blackContinue = 0;
				for (int h = i - 1, t = j - 1; h >= 0, t >= 0; --h, --t)
				{
					if (board[h][t] == 'b')
						++blackContinue;
					else
						break;
				}
				for (int h = i + 1, t = j + 1; h <= 18, t <= 18; ++h, ++t)
				{
					if (board[h][t] == 'b')
						++blackContinue;
					else
						break;
				}
				switch (blackContinue)
				{
				case 1:
					defense[0].exist = true;
					defense[0].y = i;
					defense[0].x = j;
					break;
				case 2:
					defense[1].exist = true;
					defense[1].y = i;
					defense[1].x = j;
					break;
				case 3:
					defense[2].exist = true;
					defense[2].y = i;
					defense[2].x = j;
					break;
				case 4:
					defense[3].exist = true;
					defense[3].y = i;
					defense[3].x = j;
					break;
				case 5:
					return 1;
				}
			}
		}
	}
	return 0;
}
