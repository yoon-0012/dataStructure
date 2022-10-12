#include<iostream>
using namespace std;
struct champion_bt
{
	string name;
	int hp;
	int mp;
	int speed;
	int range;
	string position;
};
void Search(champion_bt*, int);
void Insert(champion_bt*, int*);
void DeleteChmp(champion_bt*, int*);
void DeleteAllPo(champion_bt*, int*);
void PrintAll(champion_bt*, int);
void FindMaxHp(champion_bt*, int);
void SortByHp(champion_bt*, int);
int main()
{
	champion_bt champ[40];

	champ[0].name = "�����Ϳ�����";
	champ[0].hp = 540;
	champ[0].mp = 32;
	champ[0].speed = 340;
	champ[0].range = 125;
	champ[0].position = "����";
	champ[1].name = "����";
	champ[1].hp = 575;
	champ[1].mp = 32;
	champ[1].speed = 345;
	champ[1].range = 125;
	champ[1].position = "����";
	champ[2].name = "�̽�����";
	champ[2].hp = 570;
	champ[2].mp = 30;
	champ[2].speed = 325;
	champ[2].range = 550;
	champ[2].position = "����";
	champ[3].name = "�����";
	champ[3].hp = 530;
	champ[3].mp = 30;
	champ[3].speed = 325;
	champ[3].range = 550;
	champ[3].position = "����";
	champ[5].name = "������";
	champ[5].hp = 575;
	champ[5].mp = 32;
	champ[5].speed = 345;
	champ[5].range = 125;
	champ[5].position = "ž";
	champ[6].name = "������";
	champ[6].hp = 561;
	champ[6].mp = 32;
	champ[6].speed = 350;
	champ[6].range = 125;
	champ[6].position = "ž";
	champ[7].name = "������";
	champ[7].hp = 520;
	champ[7].mp = 30;
	champ[7].speed = 340;
	champ[7].range = 525;
	champ[7].position = "����";
	champ[12].name = "����";
	champ[12].hp = 620;
	champ[12].mp = 32;
	champ[12].speed = 340;
	champ[12].range = 175;
	champ[12].position = "ž";
	champ[13].name = "����";
	champ[13].hp = 560;
	champ[13].mp = 32;
	champ[13].speed = 345;
	champ[13].range = 125;
	champ[13].position = "ž";
	champ[14].name = "����ũ��ũ";
	champ[14].hp = 583;
	champ[14].mp = 32;
	champ[14].speed = 325;
	champ[14].range = 125;
	champ[14].position = "����";
	champ[15].name = "���׿�";
	champ[15].hp = 579;
	champ[15].mp = 28;
	champ[15].speed = 345;
	champ[15].range = 150;
	champ[15].position = "�̵�";
	champ[16].name = "����";
	champ[16].hp = 515;
	champ[16].mp = 30;
	champ[16].speed = 330;
	champ[16].range = 550;
	champ[16].position = "����";
	champ[17].name = "������";
	champ[17].hp = 560;
	champ[17].mp = 30;
	champ[17].speed = 335;
	champ[17].range = 450;
	champ[17].position = "����";
	champ[18].name = "�ƹ���";
	champ[18].hp = 615;
	champ[18].mp = 32;
	champ[18].speed = 335;
	champ[18].range = 125;
	champ[18].position = "����";
	champ[19].name = "�ֽ�";
	champ[19].hp = 539;
	champ[19].mp = 30;
	champ[19].speed = 325;
	champ[19].range = 600;
	champ[19].position = "����";
	champ[20].name = "�𸣰���";
	champ[20].hp = 559;
	champ[20].mp = 30;
	champ[20].speed = 335;
	champ[20].range = 450;
	champ[20].position = "����";
	champ[22].name = "�Ƹ�";
	champ[22].hp = 526;
	champ[22].mp = 30;
	champ[22].speed = 330;
	champ[22].range = 550;
	champ[22].position = "�̵�";
	champ[25].name = "��Į��";
	champ[25].hp = 575;
	champ[25].mp = 37;
	champ[25].speed = 345;
	champ[25].range = 125;
	champ[25].position = "�̵�";
	champ[26].name = "�̺�";
	champ[26].hp = 620;
	champ[26].mp = 32;
	champ[26].speed = 335;
	champ[26].range = 125;
	champ[26].position = "����";
	champ[28].name = "����";
	champ[28].hp = 480;
	champ[28].mp = 25;
	champ[28].speed = 330;
	champ[28].range = 500;
	champ[28].position = "����";
	int length = 29;
	int choose = 0;

	while (choose != 11)
	{
		cout << endl << endl << "1. Search[è�Ǿ��̸�]" << endl;
		cout << "2. Insert" << endl;
		cout << "3. Delete[è�Ǿ��̸�]" << endl;
		cout << "4. DeleteAll[position]" << endl;
		cout << "5. PrintAll" << endl;
		cout << "6. FindMaxHp" << endl;
		cout << "7. SortByHp" << endl;
		cout << "11. ����" << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
			Search(champ, length);
			break;
		case 2:
			Insert(champ, &length);
			break;
		case 3:
			DeleteChmp(champ, &length);
			break;
		case 4:
			DeleteAllPo(champ, &length);
			break;
		case 5:
			PrintAll(champ, length);
			break;
		case 6:
			FindMaxHp(champ, length);
			break;
		case 7:
			SortByHp(champ, length);
			break;
		case 11:
			break;
		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
			break;
		}
	}
	return 0;
}
void Search(champion_bt* _champ, int _length)
{
	string _name;
	cout << "è�Ǿ�: ";
	cin >> _name;
	for (int i = 0; i < _length; ++i)
	{
		if (_name == _champ[i].name)
		{
			cout << "ü��: " << _champ[i].hp << endl;
			cout << "������: " << _champ[i].mp << endl;
			cout << "�ӵ�: " << _champ[i].speed << endl;
			cout << "�����Ÿ�: " << _champ[i].range << endl;
			cout << "������: " << _champ[i].position << endl;
			break;
		}
		if (i == _length - 1)
			cout << "�׷� è�Ǿ��� �����ϴ�." << endl;
	}
}
void Insert(champion_bt* _champ, int* _length)
{
	string _name;
	int check = 0;

	cout << "è�Ǿ�: ";
	cin >> _name;
	for (check = 0; check < *_length; ++check)
	{
		if (_name == _champ[check].name)
		{
			cout << "�̹� �ִ� è�Ǿ��Դϴ�." << endl;
			break;
		}
	}
	if (check == *_length)
	{
		_champ[*_length].name = _name;
		cout << "ü��: ";
		cin >> _champ[*_length].hp;
		cout << "������: ";
		cin >> _champ[*_length].mp;
		cout << "�ӵ�: ";
		cin >> _champ[*_length].speed;
		cout << "�����Ÿ�: ";
		cin >> _champ[*_length].range;
		cout << "������: ";
		cin >> _champ[*_length].position;
		++* _length;
	}
}
void DeleteChmp(champion_bt* _champ, int* _length)
{
	string _name;
	int check = 0;
	cout << "è�Ǿ�: ";
	cin >> _name;
	for (int i = 0; i < *_length; ++i)
	{
		if (_champ[i].name == _name)
		{
			for (int j = i; j < *_length; ++j)
			{
				_champ[j].name = _champ[j + 1].name;
				_champ[j].hp = _champ[j + 1].hp;
				_champ[j].mp = _champ[j + 1].mp;
				_champ[j].speed = _champ[j + 1].speed;
				_champ[j].range = _champ[j + 1].range;
				_champ[j].position = _champ[j + 1].position;
				--* _length;
				++check;
			}
			/*_champ[i].name = _champ[*_length - 1].name;
			_champ[i].hp = _champ[*_length - 1].hp;
			_champ[i].mp = _champ[*_length - 1].mp;
			_champ[i].speed = _champ[*_length - 1].speed;
			_champ[i].range = _champ[*_length - 1].range;
			_champ[i].position = _champ[*_length - 1].position;
			--* _length;*/
		}
	}
	if (check == 0)
		cout << "�׷� è�Ǿ��� �����ϴ�." << endl;
}
void DeleteAllPo(champion_bt* _champ, int* _length)
{
	string _position;
	int check = 0;

	cout << "������: ";
	cin >> _position;
	for (int i = 0; i < *_length; ++i)
	{
		if (_champ[i].position == _position)
		{
			for (int j = i; j < *_length; ++j)
			{
				_champ[j].name = _champ[j + 1].name;
				_champ[j].hp = _champ[j + 1].hp;
				_champ[j].mp = _champ[j + 1].mp;
				_champ[j].speed = _champ[j + 1].speed;
				_champ[j].range = _champ[j + 1].range;
				_champ[j].position = _champ[j + 1].position;
			}
		/*	_champ[i].name = _champ[*_length - 1].name;
			_champ[i].hp = _champ[*_length - 1].hp;
			_champ[i].mp = _champ[*_length - 1].mp;
			_champ[i].speed = _champ[*_length - 1].speed;
			_champ[i].range = _champ[*_length - 1].range;
			_champ[i].position = _champ[*_length - 1].position;*/
	
			--* _length;
			--i;
			++check;
		}
	}
	if (check == 0)
		cout << "�׷� �������� �����ϴ�." << endl;
}
void PrintAll(champion_bt* _champ, int _length)
{
	for (int i = 0; i < _length; ++i)
	{
		if (_champ[i].hp > 0)
		{
			cout << "è�Ǿ�: " << _champ[i].name << endl;
			cout << "ü��: " << _champ[i].hp << endl;
			cout << "������: " << _champ[i].mp << endl;
			cout << "�ӵ�: " << _champ[i].speed << endl;
			cout << "�����Ÿ�: " << _champ[i].range << endl;
			cout << "������: " << _champ[i].position << endl << endl;
		}
	}
}
void FindMaxHp(champion_bt* _champ, int _length)
{
	int max = 0;

	for (int i = 0; i < _length; ++i)
		if (max < _champ[i].hp)
			max = _champ[i].hp;
	for (int j = 0; j < _length; ++j)
	{
		if (max == _champ[j].hp)
		{
			cout << "è�Ǿ�: " << _champ[j].name << endl;
			cout << "ü��: " << _champ[j].hp << endl;
			cout << "������: " << _champ[j].mp << endl;
			cout << "�ӵ�: " << _champ[j].speed << endl;
			cout << "�����Ÿ�: " << _champ[j].range << endl;
			cout << "������: " << _champ[j].position << endl << endl;
		}
	}
}
void SortByHp(champion_bt* _champ, int _length)
{
	int check = 0;
	string tmpname;
	int tmphp;
	int tmpmp;
	int tmpspeed;
	int tmprange;
	string tmpposition;

	while (check != _length - 1)
	{
		check = 0;
		for (int i = 0; i < _length - 1; ++i)
		{
			if (_champ[i].hp < _champ[i + 1].hp)
			{
				tmpname = _champ[i].name;
				tmphp = _champ[i].hp;
				tmpmp = _champ[i].mp;
				tmpspeed = _champ[i].speed;
				tmprange = _champ[i].range;
				tmpposition = _champ[i].position;

				_champ[i].name = _champ[i + 1].name;
				_champ[i].hp = _champ[i + 1].hp;
				_champ[i].mp = _champ[i + 1].mp;
				_champ[i].speed = _champ[i + 1].speed;
				_champ[i].range = _champ[i + 1].range;
				_champ[i].position = _champ[i + 1].position;

				_champ[i + 1].name = tmpname;
				_champ[i + 1].hp = tmphp;
				_champ[i + 1].mp = tmpmp;
				_champ[i + 1].speed = tmpspeed;
				_champ[i + 1].range = tmprange;
				_champ[i + 1].position = tmpposition;
			}
			else
				++check;
		}
	}
}
