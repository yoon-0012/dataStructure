#include<iostream>
using namespace std;
char board[19][19] = { 0, };
int xpos = 0;
int ypos = 0;
int turn = 0;
int black = 0;
int white = 0;

void set();
void omok();
void countVer();//���θ
void countHor();//���θ
void verMax();//���ο���
void horMax();//���ο���
void rdiagon();//�����
void ldiagon();//������
int main()
{
	for (int i = 0; i < 19; ++i)
		for (int j = 0; j < 19; ++j)
			board[i][j] = '+';//43

	omok();
	return 0;
}
void set()
{
	if (turn % 2 == 0)
		cout << "player1�� ���ʾ�" << endl;
	else
		cout << "player2�� ���ʾ�" << endl;

	if (!(cin >> xpos >> ypos))
	{
		
		cin.clear();
		cin.ignore(5, '\n');
		cout << "�ٽ� �Է��ϼ���" << endl;
		set();
	}
	if (xpos > 18 || ypos > 18 || xpos < 0 || ypos < 0)
	{
		cout << "�ٽ� �Է��ϼ���" << endl;
		set();
	}
	if (board[ypos][xpos] != '+')
	{
		cout << "�̹� ���� �����ֽ��ϴ�" << endl;
		set();
	}
}
void omok()
{
	set();
	if (turn % 2 == 0)
	{
		board[ypos][xpos] = '%';//37
		++turn;
	}
	else
	{
		board[ypos][xpos] = '&';//38
		++turn;
	}
	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
			cout << board[i][j] << " ";
		cout << endl;
	}
	countVer();
	countHor();
	verMax();
	horMax();
	rdiagon();
	ldiagon();
	if (turn == 1000000000)                                          ////���� ���� ���� �����°ɷ�
		return;
	else
		omok();
}
void countVer()
{
	char i2 = 65;//16������ 10���ʹ� A
	cout << "����" << endl;
	for (int i = 0; i < 19; ++i)
	{
		black = 0;
		white = 0;
		for (int j = 0; j < 19; ++j)
		{
			if (board[i][j] == '%')
				++black;
			else if (board[i][j] == '&')
				++white;
		}
		if (i < 10)
			cout << i << " " << "B" << black << " " << "W" << white;
		else
		{
			cout << i2 << " " << "B" << black << " " << "W" << white;
			++i2;
		}
		cout << endl;
	}
	cout << endl;
}
void countHor()
{
	char i2 = 65;
	cout << "����" << endl;
	for (int i = 0; i < 19; ++i)
	{
		black = 0;
		white = 0;
		for (int j = 0; j < 19; ++j)
		{
			if (board[j][i] == '%')
				++black;
			else if (board[j][i] == '&')
				++white;
		}
		if (i < 10)
			cout << i << " " << "B" << black << " " << "W" << white;
		else
		{
			cout << i2 << " " << "B" << black << " " << "W" << white;
			++i2;
		}
		cout << endl;
	}
	cout << endl;
}
void verMax()//�����ٿ��Ӹƽ�
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
				else
				{
					if (thismax > p1max[j])
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
				cout << j << "��° �����ٿ��� ���� ���� ������ ��: B : " << p1max[j] + 1;
			else if (p1max[j] < p2max[j])
				cout << j << "��° �����ٿ��� ���� ���� ������ ��: W : " << p2max[j] + 1;
			else
				cout << j << "��° �����ٿ��� ���� ���� ������ ��: B & W : " << p2max[j] + 1;
			cout << endl;
		}
	}
	cout << endl;
}
void horMax()//�����ٿ��Ӹƽ�//������ ��ǥ
{
	static int p1max[19] = {};//����ƽ��¿��
	static int p2max[19] = {};
	static int p1maxxline[5] = {};//9��
	static int p2maxxline[5] = {};
	static int p1maxyline = 0;
	static int p2maxyline = 0;
	int xstart = 0; int thismax = 0;

	for (int i = 0; i < 19; ++i)
	{
		xstart = 0;
		//thismax = 0;
		for (int j = 0; j < 19; ++j)
		{
			if (board[i][j] == '%')
			{
				if (board[i][j + 1] == '%')//&&board[i][j-1]!='+')
					++thismax;
				else if (thismax >=p1max[i])
				{
					p1max[i] = thismax;
					thismax = 0;
					for (int h = j - p1max[i]; h <= j; ++h)
					{
						p1maxxline[xstart++] = h;
						p1maxyline = i;
					}
					
					//break;
				}
				else
					thismax = 0;
				/*else
					break;*/
			}
			else if (board[i][j] == '&')
			{
				if (board[i][j + 1] == '&') //&& board[i][j - 1] != '+')
					++thismax;
				else if (thismax >= p2max[i])
				{
					p2max[i] = thismax;
					thismax = 0;
					for (int h = j - p2max[i]; h <= j; ++h)
					{
						p2maxxline[xstart++] = h;
						p2maxyline = i;
					}

					//break;
				}
				else
					thismax = 0;
				/*	else
						break;*/
			}
		}
		if (p1max[i] == 0 && p2max[i] == 0)
			continue;
		else
		{
			if (p1max[i] > p2max[i])
			{
				cout << i << "��° �����ٿ��� ���� ���� ������ ��: B : " << p1max[i] + 1 << endl;
				cout << "������ ������ ��ǥ: ";
				for (int u = 0; u < p1max[i] + 1; ++u)
					cout << "( " << p1maxxline[u] << "," << p1maxyline << " )    ";
				cout << endl;
			}
			else if (p1max[i] < p2max[i])
			{
				cout << i << "��° �����ٿ��� ���� ���� ������ ��: W : " << p2max[i] + 1 << endl;
				cout << "������ ������ ��ǥ: ";
				for (int u = 0; u < p2max[i] + 1; ++u)
					cout << "( " << p2maxxline[u] << "," << p2maxyline << " )    ";
				cout << endl;
			}
			else
			{
				cout << i << "��° �����ٿ��� ���� ���� ������ ��: B & W : " << p2max[i] + 1;
				cout << endl;
				cout << "������ P������ ��ǥ: ";
				for (int u = 0; u < p1max[i] + 1; u++)
					cout << "( " << p1maxxline[u] << "," << p1maxyline << " )    ";
				cout << endl;
				cout << "������ A������ ��ǥ: ";
				for (int u = 0; u < p2max[i] + 1; u++)
					cout << "( " << p2maxxline[u] << "," << p2maxyline << " )    ";
				cout << endl;
			}
		}
	}
	cout << endl;
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
			if (board[h][i] == '%')
			{
				tmpi = i;
				for (int j = h + 1; j <= 19; ++j)
				{
					if (board[j][--tmpi] == '%')
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
			else if (board[h][i] == '&')
			{
				tmpi = i;
				for (int j = h + 1; j <= 19; ++j)
				{
					if (board[j][--tmpi] == '&')
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
			cout << j << "��° ������ٿ��� ���� ���� ������ ��: B : " << p1max[j] + 1;
		else if (p1max[j] < p2max[j])
			cout << j << "��° ������ٿ��� ���� ���� ������ ��: W : " << p2max[j] + 1;
		else
			cout << j << "��° ������ٿ��� ���� ���� ������ ��: B & W : " << p2max[j] + 1;
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
			if (board[h][i] == '%')
			{
				tmpi = i;
				for (int j = h + 1; j <= 19; ++j)
				{
					if (board[j][++tmpi] == '%')
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
			else if (board[h][i] == '&')
			{
				tmpi = i;
				for (int j = h + 1; j <= 19; ++j)
				{
					if (board[j][++tmpi] == '&')
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
			cout << j << "��° �������ٿ��� ���� ���� ������ ��: B : " << p1max[j] + 1;
		else if (p1max[j] < p2max[j])
			cout << j << "��° �������ٿ��� ���� ���� ������ ��: W : " << p2max[j] + 1;
		else
			cout << j << "��° �������ٿ��� ���� ���� ������ ��: B & W : " << p2max[j] + 1;
		cout << endl;
	}
}