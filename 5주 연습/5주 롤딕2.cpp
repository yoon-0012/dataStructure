#include<iostream>
#include<string>
using namespace std;
class champion_bt
{
public:
	string name;
	int hp;//ü��
	int mp;//������
	int speed;//�̵��ӵ�[
	int range;//��Ÿ�
	string position;//ž �̵� ��
};
int search_r(champion_bt*, int, string, int, int*, int*);
void insert_r(champion_bt*, int*, string, int, int*);
void delChamp_r(champion_bt*, int*, string, int, int);
void delPosition_r(champion_bt*, int*, string, int*, int, int);
void printAll_r(champion_bt*, int, int*);
void findMaxHp_r(champion_bt*, int, int*, int*, int*, int*);
void sortByHp_r(champion_bt*, int, int, int*);

int main()
{
	champion_bt champ[40];
	//���� �̺� 620
	//����4 �̵�3 ����4 ž4 ����5
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
	champ[4].name = " ";
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
	champ[8].name = " ";
	champ[9].name = " ";
	champ[10].name = " ";
	champ[11].name = " ";
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
	champ[21].name = " ";
	champ[22].name = "�Ƹ�";
	champ[22].hp = 526;
	champ[22].mp = 30;
	champ[22].speed = 330;
	champ[22].range = 550;
	champ[22].position = "�̵�";
	champ[23].name = " ";
	champ[24].name = " ";
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
	champ[27].name = " ";
	champ[28].name = "����";
	champ[28].hp = 480;
	champ[28].mp = 25;
	champ[28].speed = 330;
	champ[28].range = 500;
	champ[28].position = "����";
	champ[29].name = " ";
	champ[30].name = " ";
	champ[31].name = " ";
	champ[32].name = " ";
	champ[33].name = " ";
	champ[34].name = " ";
	champ[35].name = " ";
	champ[36].name = " ";
	champ[37].name = " ";
	champ[38].name = " ";
	champ[39].name = " ";

	string Name;
	int length = 29;
	int choose = 0;
	int location = 0;
	int empty = 0;
	int max = 0;
	int secPrint = 0;
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

		cin >> choose;
		switch (choose)
		{
		case 1:
			// 1. Search[è�Ǿ��̸�] : �־��� è�Ǿ��� ������ ����Ѵ�.
			lenChan = length - 1;
			cout << "�̸�: ";
			cin >> Name;
			location = search_r(champ, length, Name, choose, &lenChan, &empty);
			if (location == -1)
				cout << "�׷� è�Ǿ��� �����ϴ�." << endl;
			else
			{
				cout << "ü��: " << champ[location].hp << endl;
				cout << "������: " << champ[location].mp << endl;
				cout << "�̵��ӵ�: " << champ[location].speed << endl;
				cout << "��Ÿ�: " << champ[location].range << endl;
				cout << "������: " << champ[location].position << endl;
			}
			break;
		case 2:
			// 2. Insert : ���ο� è�Ǿ��� ������ �Է¹޾ƻ����Ѵ�.
			empty = 0;
			cout << "�̸�: ";
			cin >> Name;
			insert_r(champ, &length, Name, choose, &empty);
			break;
		case 3:
			// 3. Delete[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ������ �����Ѵ�.
			cout << "�̸�: ";
			cin >> Name;
			delChamp_r(champ, &length, Name, choose, empty);
			break;
		case 4:
			// 4. DeleteAll[position] : �־��� ��ġ�� ��� è�Ǿ� ������ �����Ѵ�.
			check = 0;
			cout << "������ : ";
			cin >> Name;
			delPosition_r(champ, &length, Name, &check, empty, choose);
			break;
		case 5:
			// 5. PrintAll : ��� è�Ǿ��� ������ �迭�� ����� ������� ����Ѵ�.
			lenChan = 0;
			printAll_r(champ, length, &lenChan);
			break;
		case 6:
			// 6. FindMaxHp : ���� ü���� ū è�Ǿ��� ������ ����Ѵ�.
			check = 0;
			max = 0;
			location = -1;
			secPrint = 0;
			findMaxHp_r(champ, length, &max, &location, &check, &secPrint);
			break;
		case 7:
			// 7. SortByHp : ü���� ū è�Ǿ���� ������� �����Ѵ�. 
			lenChan = length;
			check = 0;
			sortByHp_r(champ, length, lenChan, &check);
			break;
		case 11:
			break;
		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
		}
	}
	return 0;
}
int search_r(champion_bt* _champ, int _length, string _Name, int _choose, int* _count, int* _empty)
{
	// 1. Search[è�Ǿ��̸�] : �־��� è�Ǿ��� ������ ����Ѵ�.
	if (_length == 1)
	{
		if (_choose == 1 || _choose == 2 || _choose == 3)
		{
			if (_Name != _champ[0].name)
			{
				if (_champ[0].name == " ")
					*_empty = *_count;
				--* _count;
			}
		}
		else if (_choose == 4)
			if (_Name != _champ[0].position)
				--* _count;
	}
	else
	{
		if (_choose == 1 || _choose == 2 || _choose == 3)
		{
			if (_Name != _champ[_length - 1].name)
			{
				if (_champ[_length - 1].name == " ")
					*_empty = *_count;
				--* _count;
				search_r(_champ, _length - 1, _Name, _choose, _count, _empty);
			}
		}
		else if (_choose == 4)
		{
			if (_Name != _champ[_length - 1].position)
			{
				--* _count;
				search_r(_champ, _length - 1, _Name, _choose, _count, _empty);
			}
		}
	}
	return *_count;
}
void insert_r(champion_bt* _champ, int* _length, string _Name, int _choose, int* _empty)
{
	// 2. Insert : ���ο� è�Ǿ��� ������ �Է¹޾ƻ����Ѵ�.
	int tmplength = *_length - 1;
	int _count = search_r(_champ, *_length, _Name, _choose, &tmplength, _empty);
	if (_count != -1)
	{
		cout << "�̹� �ִ� è�Ǿ��Դϴ�." << endl;
		cout << "�̸�: ";
		cin >> _Name;
		insert_r(_champ, _length, _Name, _choose, _empty);
	}
	else
	{
		_champ[*_empty].name = _Name;
		cout << "ü��: ";
		cin >> _champ[*_empty].hp;
		cout << "������: ";
		cin >> _champ[*_empty].mp;
		cout << "�̵��ӵ�: ";
		cin >> _champ[*_empty].speed;
		cout << "��Ÿ�: ";
		cin >> _champ[*_empty].range;
		cout << "������: ";
		cin >> _champ[*_empty].position;
		++* _length;
	}
}
void delChamp_r(champion_bt* _champ, int* _length, string delName, int _choose, int _empty)
{
	// 3. Delete[è�Ǿ��̸�] : �־��� è�Ǿ� ���� ������ �����Ѵ�.
	int tmplength = *_length - 1;
	int _count = search_r(_champ, *_length, delName, _choose, &tmplength, &_empty);
	if (_count == -1)
	{
		cout << "�׷� è�Ǿ��� �����ϴ�." << endl;
		cout << "�̸�: ";
		cin >> delName;
		delChamp_r(_champ, _length, delName, _choose, _empty);
	}
	else
	{ 
		_champ[_count].name = _champ[*_length - 1].name;
		_champ[_count].hp = _champ[*_length - 1].hp;
		_champ[_count].mp = _champ[*_length - 1].mp;
		_champ[_count].speed = _champ[*_length - 1].speed;
		_champ[_count].range = _champ[*_length - 1].range;
		_champ[_count].position = _champ[*_length - 1].position;
		--* _length;
	}
}
void delPosition_r(champion_bt* _champ, int* _length, string delPosition, int* _check, int _empty, int _choose)
{
	// 4. DeleteAll[position] : �־��� ��ġ�� ��� è�Ǿ� ������ �����Ѵ�.
	int tmplength = *_length - 1;
	int _count = search_r(_champ, *_length, delPosition, _choose, &tmplength, &_empty);
	if (_count == -1)
	{
		if (*_check == 0)
		{
			cout << "�׷� �������� �����ϴ�." << endl;
			cout << "������: ";
			cin >> delPosition;
			delPosition_r(_champ, _length, delPosition, _check, _empty, _choose);
		}
		else
			return;
	}
	else
	{
		_champ[_count].name = _champ[*_length - 1].name;
		_champ[_count].hp = _champ[*_length - 1].hp;
		_champ[_count].mp = _champ[*_length - 1].mp;
		_champ[_count].speed = _champ[*_length - 1].speed;
		_champ[_count].range = _champ[*_length - 1].range;
		_champ[_count].position = _champ[*_length - 1].position;
		--* _length;
		++* _check;
		delPosition_r(_champ, _length, delPosition, _check, _empty, _choose);
	}
}
void printAll_r(champion_bt* _champ, int _length, int* _lenChan)
{
	// 5. PrintAll : ��� è�Ǿ��� ������ �迭�� ����� ������� ����Ѵ�.
	if (_length == 1)
	{
		if (_champ[*_lenChan].name != " ")
		{
			cout << "�̸�: " << _champ[*_lenChan].name << endl;
			cout << "ü��: " << _champ[*_lenChan].hp << endl;
			cout << "������: " << _champ[*_lenChan].mp << endl;
			cout << "�̵��ӵ�: " << _champ[*_lenChan].speed << endl;
			cout << "��Ÿ�: " << _champ[*_lenChan].range << endl;
			cout << "������: " << _champ[*_lenChan].position << endl;
			cout << endl;
		}
	}
	else
	{
		if (_champ[*_lenChan].name != " ")
		{
			cout << "�̸�: " << _champ[*_lenChan].name << endl;
			cout << "ü��: " << _champ[*_lenChan].hp << endl;
			cout << "������: " << _champ[*_lenChan].mp << endl;
			cout << "�̵��ӵ�: " << _champ[*_lenChan].speed << endl;
			cout << "��Ÿ�: " << _champ[*_lenChan].range << endl;
			cout << "������: " << _champ[*_lenChan].position << endl;
			cout << endl;
		}
		++* _lenChan;
		printAll_r(_champ, _length - 1, _lenChan);
	}
}
void findMaxHp_r(champion_bt* _champ, int _length, int* _max, int* count, int* _check, int* _secPrint)
{
	if (_length == 1)
	{
		if (*_check == 0)
		{
			if (*_max < _champ[0].hp)
			{
				*_max = _champ[0].hp;
				*count = 0;
			}
		}
		else
		{
			if (*_secPrint == *count)
			{
				if (*_max == _champ[0].hp)
					*count = 0;
				else
					return;
			}
		}
		cout << "�̸�: " << _champ[*count].name << endl;
		cout << "ü��: " << _champ[*count].hp << endl;
		cout << "������: " << _champ[*count].mp << endl;
		cout << "�̵��ӵ�: " << _champ[*count].speed << endl;
		cout << "��Ÿ�: " << _champ[*count].range << endl;
		cout << "������: " << _champ[*count].position << endl << endl;
		if (*count == 0)
			return;
		++* _check;
		*_secPrint = *count;
		findMaxHp_r(_champ, *count, _max, count, _check, _secPrint);
	}
	else
	{
		if (*_check != 0)
		{
			if (*_max == _champ[_length - 1].hp)
			{
				*count = _length - 1;
				findMaxHp_r(_champ, 1, _max, count, _check, _secPrint);
			}
			else
				findMaxHp_r(_champ, _length - 1, _max, count, _check, _secPrint);
		}
		else
		{
			if (*_max < _champ[_length - 1].hp)
			{
				*_max = _champ[_length - 1].hp;
				*count = _length - 1;
			}
			findMaxHp_r(_champ, _length - 1, _max, count, _check, _secPrint);
		}
	}
}
void sortByHp_r(champion_bt* _champ, int _length, int _lenChan, int* _check)
{
	//// 7. SortByHp : ü���� ū è�Ǿ���� ������� �����Ѵ�.  
	//string tempname;
	//int temphp = 0;//ü��
	//int tempmp = 0;//������
	//int tempspeed = 0;//�̵��ӵ�
	//int temprange = 0;//��Ÿ�
	//string tempposition;//ž �̵� ��

	//if (_length == 2)
	//{
	//	if (_champ[0].hp < _champ[1].hp)
	//	{
	//		tempname = _champ[0].name;
	//		temphp = _champ[0].hp;
	//		tempmp = _champ[0].mp;
	//		tempspeed = _champ[0].speed;
	//		temprange = _champ[0].range;
	//		tempposition = _champ[0].position;

	//		_champ[0].name = _champ[1].name;
	//		_champ[0].hp = _champ[1].hp;
	//		_champ[0].mp = _champ[1].mp;
	//		_champ[0].speed = _champ[1].speed;
	//		_champ[0].range = _champ[1].range;
	//		_champ[0].position = _champ[1].position;

	//		_champ[1].name = tempname;
	//		_champ[1].hp = temphp;
	//		_champ[1].mp = tempmp;
	//		_champ[1].speed = tempspeed;
	//		_champ[1].range = temprange;
	//		_champ[1].position = tempposition;
	//	}
	//	else
	//		++* _check;
	//	if (*_check != _lenChan - 1)
	//	{
	//		*_check = 0;
	//		sortByHp_r(_champ, _lenChan, _lenChan, _check);
	//	}
	//}
	//else
	//{
	//	if (_champ[_length - 2].hp < _champ[_length - 1].hp)
	//	{
	//		tempname = _champ[_length - 2].name;
	//		temphp = _champ[_length - 2].hp;
	//		tempmp = _champ[_length - 2].mp;
	//		tempspeed = _champ[_length - 2].speed;
	//		temprange = _champ[_length - 2].range;
	//		tempposition = _champ[_length - 2].position;

	//		_champ[_length - 2].name = _champ[_length - 1].name;
	//		_champ[_length - 2].hp = _champ[_length - 1].hp;
	//		_champ[_length - 2].mp = _champ[_length - 1].mp;
	//		_champ[_length - 2].speed = _champ[_length - 1].speed;
	//		_champ[_length - 2].range = _champ[_length - 1].range;
	//		_champ[_length - 2].position = _champ[_length - 1].position;

	//		_champ[_length - 1].name = tempname;
	//		_champ[_length - 1].hp = temphp;
	//		_champ[_length - 1].mp = tempmp;
	//		_champ[_length - 1].speed = tempspeed;
	//		_champ[_length - 1].range = temprange;
	//		_champ[_length - 1].position = tempposition;
	//	}
	//	else
	//		++* _check;
	//	sortByHp_r(_champ, _length - 1, _lenChan, _check);
	//}
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
		++* _check;

	if (_length == 2)
	{
		if (*_check != _lenChan - 1)
		{
			*_check = 0;
			sortByHp_r(_champ, _lenChan, _lenChan, _check);
		}
	}
	else
		sortByHp_r(_champ, _length - 1, _lenChan, _check);
}
