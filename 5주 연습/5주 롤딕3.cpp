#include<iostream>
#include<string>
using namespace std;
struct champion_bt
{
	string name;
	int hp;//ü��
	int mp;//������
	int speed;//�̵��ӵ�
	int range;//��Ÿ�
	string position;//ž �̵� ��
};
void search_sl(champion_bt*, int, int, string);
void insert_sl(champion_bt*, int*, string, int);
void delChamp_sl(champion_bt*, int*, int, string);
void delPosition_sl(champion_bt*, int*, int, string);
void printAll_sl(champion_bt*, int, int);
void findMaxHp_sl(champion_bt*, int, int*);
void sortByHp_sl(champion_bt*, int, int, int);

int main()
{
	champion_bt champ[40] = { {"�����Ϳ�����" , 540,32,340, 125, "����"},
		{"����" , 575 , 32 , 345 , 125 , "����" },
		{"�̽�����" , 570 , 30 , 325 , 550 , "����" },
		{ "�����" , 530 , 30 , 325 , 550 , "����"},{" " },
		{ "������" , 575 , 32 , 345 , 125, "ž"},
		{ "������" , 561 ,32,350,125, "ž"},
		{ "������",  520,  30, 340,  525, "����" },{" "},{ " "},{ " "},{" "},
		{"����", 620, 32, 340,175, "ž"},
		{ "����", 560,  32,  345,  125, "ž"   },
		{ "����ũ��ũ", 583, 32,325, 125, "����"},
		{ "���׿�", 579, 28,  345,  150,  "�̵�"},
		{"����",515, 30, 330, 550, "����"},
		{"������",560,30, 335, 450,"����"},
		{ "�ƹ���",615, 32, 335,  125,  "����"},
		{ "�ֽ�",  539, 30, 325,  600, "����"},
		{ "�𸣰���",559,  30,  335, 450,  "����"},{ " "},
		{ "�Ƹ�",  526, 30,  330,  550, "�̵�"},{ " "},{ " "},
		{ "��Į��",  575,  37,  345,  125,  "�̵�" },
		{ "�̺�",620, 32, 335, 125, "����"},{ " "},
		{"����",  480,  25, 330,  500,  "����"},
		{ " "},{" "},{ " "},{ " "},{ " "},{ " "},
		{ " "},{ " "},{ " "},{ " "},{ " "} };
	//���� �̺� 620
	//����4 �̵�3 ����4 ž4 ����5

	string Name;
	int length = 29;
	int choose = 0;
	int max = 0;
	int lenChan = 0;
	int check = 0;

	while (choose != 11)
	{
		cout << endl << endl;
		cout << "1. Search" << endl;
		cout << "2. Insert" << endl;
		cout << "3. Delete [ è�Ǿ� �̸� ]" << endl;
		cout << "4. DeleteAll [ position ]" << endl;
		cout << "5. PrintAll" << endl;
		cout << "6. FindMaxHp" << endl;
		cout << "7. SortByHp" << endl;
		cout << "11. ����" << endl;

		switch (choose)
		{
		case 1:
			cout << "�̸�: ";
			cin >> Name;
			search_sl(champ, length, check, Name);
			break;
		case 2:
			lenChan = 0;
			cout << "�̸�: ";
			cin >> Name;
			insert_sl(champ, &length, Name, lenChan);
			break;
		case 3:
			cout << "�̸�: ";
			cin >> Name;
			delChamp_sl(champ, &length, length, Name);
			break;
		case 4:
			cout << "������ : ";
			cin >> Name;
			delPosition_sl(champ, &length, length, Name);
			break;
		case 5:
			lenChan = 0;
			printAll_sl(champ, length, lenChan);
			break;
		case 6:
			max = 0;
			findMaxHp_sl(champ, length, &max);
			for (int i = 0; i < length; ++i)
			{
				if (max == champ[i].hp)
				{
					cout << "�̸�: " << champ[i].name << endl;
					cout << "ü��: " << champ[i].hp << endl;
					cout << "������: " << champ[i].mp << endl;
					cout << "�̵��ӵ�: " << champ[i].speed << endl;
					cout << "�����Ÿ�: " << champ[i].range << endl;
					cout << "������: " << champ[i].position << endl << endl;
				}
			}
			break;
		case 7:
			lenChan = length;
			sortByHp_sl(champ, length, lenChan, check);
			break;
		case 11:
			break;
		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
		}
	}
	return 0;
}
void search_sl(champion_bt* _champ, int _length, int _check, string _Name)
{
	if (_Name == _champ[_length - 1].name)
	{
		cout << "ü��: " << _champ[_length - 1].hp << endl;
		cout << "������: " << _champ[_length - 1].mp << endl;
		cout << "�̵��ӵ�: " << _champ[_length - 1].speed << endl;
		cout << "��Ÿ�: " << _champ[_length - 1].range << endl;
		cout << "������: " << _champ[_length - 1].position << endl << endl;
		++_check;
	}
	else if (_length == 1 && _check == 0)
		cout << "�׷� è�Ǿ��� �����ϴ�." << endl;
	if (_length > 1)
		search_sl(_champ, _length - 1, _check, _Name);
}
void insert_sl(champion_bt* _champ, int* _length, string _Name, int _lenChan)
{
	if (_champ[_lenChan].name == " ")
	{
		_champ[_lenChan].name = _Name;
		cout << "ü��: ";
		cin >> _champ[_lenChan].hp;
		cout << "������: ";
		cin >> _champ[_lenChan].mp;
		cout << "�̵��ӵ�: ";
		cin >> _champ[_lenChan].speed;
		cout << "�����Ÿ�: ";
		cin >> _champ[_lenChan].range;
		cout << "������: ";
		cin >> _champ[_lenChan].position;
		if (_lenChan >= *_length)
			++* _length;
	}
	else if (_lenChan < 39)
		insert_sl(_champ, _length, _Name, ++_lenChan);
}
void delChamp_sl(champion_bt* _champ, int* _length, int tmplength, string delName)
{
	if (delName == _champ[tmplength - 1].name)
	{
		_champ[tmplength - 1].name = _champ[*_length - 1].name;
		_champ[tmplength - 1].hp = _champ[*_length - 1].hp;
		_champ[tmplength - 1].mp = _champ[*_length - 1].mp;
		_champ[tmplength - 1].speed = _champ[*_length - 1].speed;
		_champ[tmplength - 1].range = _champ[*_length - 1].range;
		_champ[tmplength - 1].position = _champ[*_length - 1].position;
		--* _length;
		if (tmplength != 1)
			delChamp_sl(_champ, _length, tmplength, delName);
	}
	else if (tmplength != 1)
		delChamp_sl(_champ, _length, tmplength - 1, delName);
}
void delPosition_sl(champion_bt* _champ, int* _length, int tmplength, string delPosition)
{
	if (delPosition == _champ[tmplength - 1].position)
	{
		_champ[tmplength - 1].name = _champ[*_length - 1].name;
		_champ[tmplength - 1].hp = _champ[*_length - 1].hp;
		_champ[tmplength - 1].mp = _champ[*_length - 1].mp;
		_champ[tmplength - 1].speed = _champ[*_length - 1].speed;
		_champ[tmplength - 1].range = _champ[*_length - 1].range;
		_champ[tmplength - 1].position = _champ[*_length - 1].position;
		--* _length;
		if (tmplength != 1)
			delPosition_sl(_champ, _length, tmplength, delPosition);
	}
	else if (tmplength != 1)
		delPosition_sl(_champ, _length, tmplength - 1, delPosition);
}
void printAll_sl(champion_bt* _champ, int _length, int _lenChan)
{
	if (_champ[_lenChan].name != " ")
	{
		cout << "�̸�: " << _champ[_lenChan].name << endl;
		cout << "ü��: " << _champ[_lenChan].hp << endl;
		cout << "������: " << _champ[_lenChan].mp << endl;
		cout << "�̵��ӵ�: " << _champ[_lenChan].speed << endl;
		cout << "��Ÿ�: " << _champ[_lenChan].range << endl;
		cout << "������: " << _champ[_lenChan].position << endl;
		cout << endl;
	}
	if (_length != 1)
		printAll_sl(_champ, _length - 1, ++_lenChan);
}
void findMaxHp_sl(champion_bt* _champ, int _length, int* _max)
{
	if (*_max < _champ[_length - 1].hp)
		*_max = _champ[_length - 1].hp;
	if (_length != 1)
		findMaxHp_sl(_champ, _length - 1, _max);
}
void sortByHp_sl(champion_bt* _champ, int _length, int _lenChan, int _check)
{
	string tempname;
	int temphp = 0;//ü��
	int tempmp = 0;//������
	int tempspeed = 0;//�̵��ӵ�
	int temprange = 0;//��Ÿ�
	string tempposition;//ž �̵� ��

	if (_champ[_length - 2].hp < _champ[_length - 1].hp)
	{
		tempname = _champ[_length - 2].name;
		temphp = _champ[_length - 2].hp;
		tempmp = _champ[_length - 2].mp;
		tempspeed = _champ[_length - 2].speed;
		temprange = _champ[_length - 2].range;
		tempposition = _champ[_length - 2].position;

		_champ[_length - 2].name = _champ[_length - 1].name;
		_champ[_length - 2].hp = _champ[_length - 1].hp;
		_champ[_length - 2].mp = _champ[_length - 1].mp;
		_champ[_length - 2].speed = _champ[_length - 1].speed;
		_champ[_length - 2].range = _champ[_length - 1].range;
		_champ[_length - 2].position = _champ[_length - 1].position;

		_champ[_length - 1].name = tempname;
		_champ[_length - 1].hp = temphp;
		_champ[_length - 1].mp = tempmp;
		_champ[_length - 1].speed = tempspeed;
		_champ[_length - 1].range = temprange;
		_champ[_length - 1].position = tempposition;
	}
	else
		++_check;

	if (_length == 2)
	{
		if (_check != _lenChan - 1)
		{
			_check = 0;
			sortByHp_sl(_champ, _lenChan, _lenChan, _check);
		}
	}
	else
		sortByHp_sl(_champ, _length - 1, _lenChan, _check);
}
