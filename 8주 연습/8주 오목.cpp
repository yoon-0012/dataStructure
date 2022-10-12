#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct order
{
	int y;
	int x;
	char rock;
	struct order* link;
};
char board[19][19] = {};
order* champ = nullptr;
order* last = nullptr;

ofstream in;            //쓸 목적의 파일 선언
ifstream out;
int xpos = 0;
int ypos = 0;
int turn = 0;
int black = 0;
int white = 0;

void omok();
void set();//초기화
void draw();//출력
void countVer();//세로몇개
void countHor();//가로몇개
void verMax();//세로연속
void horMax();//가로연속
void maxConDis0();//가로반짝
void rdiagon();//우상향
void ldiagon();//좌하향
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
	char choose = '0';

	while (choose != 55)
	{
		cout << "1. 모든 가로줄, 세로줄의 흑돌, 백돌의 개수" << endl;
		cout << "2. 모든 가로줄, 세로줄의 최대 연속 돌과 개수" << endl;
		cout << "3. 모든 대각선 줄의 최대 연속 돌과 개수" << endl;
		cout << "4. 모든 가로줄에서 최대 연속인 돌과 좌표" << endl;
		cout << "5. 저장" << endl;
		cout << "6. 저장된 게임 불러오기" << endl;
		cout << "7. 다음 좌표 입력" << endl;
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
		case 52:
			maxConDis0();
			draw();
			break;
		case 53:
			in.open("game.txt");    //파일 열기
			if (in.is_open())    //파일이 열렸는지 확인
				in.write(board[0], 361);    //파일에 문자열 쓰기
			in.close();    //파일 닫기
			break;
		case 54:
			out.open("game.txt");    //파일 열기
			if (out.is_open())
			{
				while (!out.eof())
				{
					for (int i = 0; i < 19; ++i)
						for (int j = 0; j < 19; ++j)
							if (!(out >> board[i][j]))
							{
							}
				}
				out.close();    //파일 닫아줍니다.
			}
			break;
		case 55:
			break;
		case 85://무르기
		case 117:
			if (champ->link == NULL)
			{
				board[champ->y][champ->x] = '+';
				delete champ;
				champ = NULL;
			}
			else
			{
				for (last = champ; last->link->link != NULL; last = last->link)
				{
				}
				board[last->link->y][last->link->x] = '+';
				delete last->link;
				last->link = NULL;
			}
			draw();
			break;
		case 82://무르기 취소
		case 114:
			break;
		default:
			cin.clear();
			cin.ignore(5, '\n');
			cout << "잘못된 입력입니다." << endl;
			break;
		}
	}
	draw();
	set();
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
		order* tmp = new order;
		tmp->y = ypos;
		tmp->x = xpos;
		if (turn % 2 == 0)
		{
			board[ypos][xpos] = 'b';
			tmp->rock = 'b';
			if (champ == NULL)
			{
				champ = tmp;
				tmp->link = NULL;
			}
			else
			{
				for (last = champ; last->link != NULL; last = last->link)
				{
				}
				last->link = tmp;
				tmp->link = NULL;
			}
		}
		else
		{
			board[ypos][xpos] = 'w';
			tmp->rock = 'w';
			if (champ == NULL)
			{
				champ = tmp;
				champ->link = NULL;
			}
			else
			{
				for (last = champ; last->link != NULL; last = last->link)
				{
				}
				tmp->link = last->link;
				last->link = tmp;
				tmp->link = NULL;
			}
		}
		++turn;
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
void maxConDis0()//가로줄 돌 반짝
{
	int rocksMax[19] = {};
	int p1x[5] = {};
	int thismax = 0;
	int countRocks[19] = {};

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
					if (thismax >= rocksMax[i] && thismax != 0)
					{
						if (thismax > rocksMax[i] && countRocks[i] != 0)
						{
							for (int check = 0; check < 19; ++check)
							{
								if (board[i][check] == 'B')
									board[i][check] = 'b';
								else if (board[i][check] == 'W')
									board[i][check] = 'w';
							}
						}
						rocksMax[i] = thismax;
						int tmpj = j;
						for (int h = rocksMax[i]; h >= 0; --h)
							board[i][tmpj--] = 'B';
						++countRocks[i];
					}
					thismax = 0;
				}
			}
			else if (board[i][j] == 'w' || board[i][j] == 'W')
			{
				if (board[i][j + 1] == 'w' || board[i][j + 1] == 'W')
					++thismax;
				else
				{
					if (thismax >= rocksMax[i] && thismax != 0)
					{
						if (thismax > rocksMax[i] && countRocks[i] != 0)
						{
							for (int check = 0; check < 19; ++check)
							{
								if (board[i][check] == 'W')
									board[i][check] = 'w';
								else if (board[i][check] == 'B')
									board[i][check] = 'b';
							}
						}
						rocksMax[i] = thismax;
						int tmpj = j;
						for (int h = rocksMax[i]; h >= 0; --h)
							board[i][tmpj--] = 'W';
						++countRocks[i];
					}
					thismax = 0;
				}
			}
		}
	}
}
void rdiagon()
{
	int p1max[37] = {};
	int p2max[37] = {};
	int thismax = 0;
	int tmph = 0;
	int tmpi = 0;

	for (int i = 1; i < 19; ++i)
	{
		for (int h = 0; h < 18; ++h)
		{
			if (board[h][i] == 'b' || board[h][i] == 'B')
			{
				tmpi = i;
				for (int j = h + 1; j <= 19; ++j)
				{
					if (board[j][--tmpi] == 'b' || board[j][--tmpi] == 'B')
						++thismax;
					else
					{
						tmph = h;
						if (thismax > p1max[i + tmph])
							p1max[i + tmph] = thismax;
						thismax = 0;
						break;
					}
				}
			}
			else if (board[h][i] == 'w' || board[h][i] == 'W')
			{
				tmpi = i;
				for (int j = h + 1; j <= 19; ++j)
				{
					if (board[j][--tmpi] == 'w' || board[j][--tmpi] == 'W')
						++thismax;
					else
					{
						tmph = h;
						if (thismax > p2max[i + tmph])
							p2max[i + tmph] = thismax;
						thismax = 0;
						break;
					}
				}
			}
		}
	}
	for (int j = 1; j < 36; ++j)
	{
		if (p1max[j] == 0 && p2max[j] == 0)
			continue;
		else if (p1max[j] > p2max[j])
			cout << j << " 우상향 MAX b : " << p1max[j] + 1;
		else if (p1max[j] < p2max[j])
			cout << j << " 우상향 MAX w : " << p2max[j] + 1;
		else
			cout << j << " 우상향 MAX b & w : " << p2max[j] + 1;
		cout << endl;
	}
}
void ldiagon()
{
	int p1max[37] = {};
	int p2max[37] = {};
	int thismax = 0;
	int tmph = 0;
	int tmpi = 0;

	for (int i = 17; i >= 0; --i)
	{
		for (int h = 0; h < 18; ++h)
		{
			if (board[h][i] == 'b' || board[h][i] == 'B')
			{
				tmpi = i;
				for (int j = h + 1; j <= 19; ++j)
				{
					if (board[j][++tmpi] == 'b' || board[j][++tmpi] == 'B')
						++thismax;
					else
					{
						tmph = h;
						if (thismax > p1max[18 - i + tmph])
							p1max[18 - i + tmph] = thismax;
						thismax = 0;
						break;
					}
				}
			}
			else if (board[h][i] == 'w' || board[h][i] == 'W')
			{
				tmpi = i;
				for (int j = h + 1; j <= 19; ++j)
				{
					if (board[j][++tmpi] == 'w' || board[j][++tmpi] == 'W')
						++thismax;
					else
					{
						tmph = h;
						if (thismax > p2max[18 - i + tmph])
							p2max[18 - i + tmph] = thismax;
						thismax = 0;
						break;
					}
				}
			}
		}
	}
	for (int j = 1; j < 36; ++j)
	{
		if (p1max[j] == 0 && p2max[j] == 0)
			continue;
		else if (p1max[j] > p2max[j])
			cout << j << " 좌하향 MAX b : " << p1max[j] + 1;
		else if (p1max[j] < p2max[j])
			cout << j << " 좌하향 MAX w : " << p2max[j] + 1;
		else
			cout << j << " 좌하향 MAX b & w : " << p2max[j] + 1;
		cout << endl;
	}
}

