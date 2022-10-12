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

	champ[0].name = "누누와월럼프";
	champ[0].hp = 540;
	champ[0].mp = 32;
	champ[0].speed = 340;
	champ[0].range = 125;
	champ[0].position = "정글";
	champ[1].name = "리신";
	champ[1].hp = 575;
	champ[1].mp = 32;
	champ[1].speed = 345;
	champ[1].range = 125;
	champ[1].position = "정글";
	champ[2].name = "미스포츈";
	champ[2].hp = 570;
	champ[2].mp = 30;
	champ[2].speed = 325;
	champ[2].range = 550;
	champ[2].position = "원딜";
	champ[3].name = "이즈리얼";
	champ[3].hp = 530;
	champ[3].mp = 30;
	champ[3].speed = 325;
	champ[3].range = 550;
	champ[3].position = "원딜";
	champ[5].name = "레넥톤";
	champ[5].hp = 575;
	champ[5].mp = 32;
	champ[5].speed = 345;
	champ[5].range = 125;
	champ[5].position = "탑";
	champ[6].name = "나서스";
	champ[6].hp = 561;
	champ[6].mp = 32;
	champ[6].speed = 350;
	champ[6].range = 125;
	champ[6].position = "탑";
	champ[7].name = "벨코즈";
	champ[7].hp = 520;
	champ[7].mp = 30;
	champ[7].speed = 340;
	champ[7].range = 525;
	champ[7].position = "서폿";
	champ[12].name = "가렌";
	champ[12].hp = 620;
	champ[12].mp = 32;
	champ[12].speed = 340;
	champ[12].range = 175;
	champ[12].position = "탑";
	champ[13].name = "리븐";
	champ[13].hp = 560;
	champ[13].mp = 32;
	champ[13].speed = 345;
	champ[13].range = 125;
	champ[13].position = "탑";
	champ[14].name = "블리츠크랭크";
	champ[14].hp = 583;
	champ[14].mp = 32;
	champ[14].speed = 325;
	champ[14].range = 125;
	champ[14].position = "서폿";
	champ[15].name = "판테온";
	champ[15].hp = 579;
	champ[15].mp = 28;
	champ[15].speed = 345;
	champ[15].range = 150;
	champ[15].position = "미드";
	champ[16].name = "베인";
	champ[16].hp = 515;
	champ[16].mp = 30;
	champ[16].speed = 330;
	champ[16].range = 550;
	champ[16].position = "원딜";
	champ[17].name = "쓰레쉬";
	champ[17].hp = 560;
	champ[17].mp = 30;
	champ[17].speed = 335;
	champ[17].range = 450;
	champ[17].position = "서폿";
	champ[18].name = "아무무";
	champ[18].hp = 615;
	champ[18].mp = 32;
	champ[18].speed = 335;
	champ[18].range = 125;
	champ[18].position = "정글";
	champ[19].name = "애쉬";
	champ[19].hp = 539;
	champ[19].mp = 30;
	champ[19].speed = 325;
	champ[19].range = 600;
	champ[19].position = "원딜";
	champ[20].name = "모르가나";
	champ[20].hp = 559;
	champ[20].mp = 30;
	champ[20].speed = 335;
	champ[20].range = 450;
	champ[20].position = "서폿";
	champ[22].name = "아리";
	champ[22].hp = 526;
	champ[22].mp = 30;
	champ[22].speed = 330;
	champ[22].range = 550;
	champ[22].position = "미드";
	champ[25].name = "아칼리";
	champ[25].hp = 575;
	champ[25].mp = 37;
	champ[25].speed = 345;
	champ[25].range = 125;
	champ[25].position = "미드";
	champ[26].name = "이블린";
	champ[26].hp = 620;
	champ[26].mp = 32;
	champ[26].speed = 335;
	champ[26].range = 125;
	champ[26].position = "정글";
	champ[28].name = "유미";
	champ[28].hp = 480;
	champ[28].mp = 25;
	champ[28].speed = 330;
	champ[28].range = 500;
	champ[28].position = "서폿";
	int length = 29;
	int choose = 0;

	while (choose != 11)
	{
		cout << endl << endl << "1. Search[챔피언이름]" << endl;
		cout << "2. Insert" << endl;
		cout << "3. Delete[챔피언이름]" << endl;
		cout << "4. DeleteAll[position]" << endl;
		cout << "5. PrintAll" << endl;
		cout << "6. FindMaxHp" << endl;
		cout << "7. SortByHp" << endl;
		cout << "11. 종료" << endl;
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
			cout << "잘못된 입력입니다." << endl;
			break;
		}
	}
	return 0;
}
void Search(champion_bt* _champ, int _length)
{
	string _name;
	cout << "챔피언: ";
	cin >> _name;
	for (int i = 0; i < _length; ++i)
	{
		if (_name == _champ[i].name)
		{
			cout << "체력: " << _champ[i].hp << endl;
			cout << "마법력: " << _champ[i].mp << endl;
			cout << "속도: " << _champ[i].speed << endl;
			cout << "사정거리: " << _champ[i].range << endl;
			cout << "포지션: " << _champ[i].position << endl;
			break;
		}
		if (i == _length - 1)
			cout << "그런 챔피언은 없습니다." << endl;
	}
}
void Insert(champion_bt* _champ, int* _length)
{
	string _name;
	int check = 0;

	cout << "챔피언: ";
	cin >> _name;
	for (check = 0; check < *_length; ++check)
	{
		if (_name == _champ[check].name)
		{
			cout << "이미 있는 챔피언입니다." << endl;
			break;
		}
	}
	if (check == *_length)
	{
		_champ[*_length].name = _name;
		cout << "체력: ";
		cin >> _champ[*_length].hp;
		cout << "마법력: ";
		cin >> _champ[*_length].mp;
		cout << "속도: ";
		cin >> _champ[*_length].speed;
		cout << "사정거리: ";
		cin >> _champ[*_length].range;
		cout << "포지션: ";
		cin >> _champ[*_length].position;
		++* _length;
	}
}
void DeleteChmp(champion_bt* _champ, int* _length)
{
	string _name;
	int check = 0;
	cout << "챔피언: ";
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
		cout << "그런 챔피언은 없습니다." << endl;
}
void DeleteAllPo(champion_bt* _champ, int* _length)
{
	string _position;
	int check = 0;

	cout << "포지션: ";
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
		cout << "그런 포지션은 없습니다." << endl;
}
void PrintAll(champion_bt* _champ, int _length)
{
	for (int i = 0; i < _length; ++i)
	{
		if (_champ[i].hp > 0)
		{
			cout << "챔피언: " << _champ[i].name << endl;
			cout << "체력: " << _champ[i].hp << endl;
			cout << "마법력: " << _champ[i].mp << endl;
			cout << "속도: " << _champ[i].speed << endl;
			cout << "사정거리: " << _champ[i].range << endl;
			cout << "포지션: " << _champ[i].position << endl << endl;
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
			cout << "챔피언: " << _champ[j].name << endl;
			cout << "체력: " << _champ[j].hp << endl;
			cout << "마법력: " << _champ[j].mp << endl;
			cout << "속도: " << _champ[j].speed << endl;
			cout << "사정거리: " << _champ[j].range << endl;
			cout << "포지션: " << _champ[j].position << endl << endl;
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
