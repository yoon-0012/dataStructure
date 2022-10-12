#include<iostream>
using namespace std;
class champion_bt
{
public:
	string name;
	int hp;
	int mp;
	int speed;
	int range;
	string position;
};

int Search(champion_bt*, int, int);
void Insert(champion_bt*, int*, int);
void DeleteChamp(champion_bt*, int*, int);
void DeletePosition(champion_bt*, int*);
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

	int choose = 0;
	int length = 29;
	int count = 0;
	while (choose != 11)
	{
		cout << endl << endl;
		cout << "1. Search" << endl;
		cout << "2. Insert" << endl;
		cout << "3. Delete [ 챔피언 이름 ]" << endl;
		cout << "4. DeleteAll [ position ]" << endl;
		cout << "5. PrintAll" << endl;
		cout << "6. FindMaxHp" << endl;
		cout << "7. SortByHp" << endl;
		cout << "11. 종료" << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
			count = Search(champ, length, choose);
			if (count == length)
				cout << "그런 챔피언은 없습니다." << endl;
			else
			{
				cout << "체력: " << champ[count].hp << endl;
				cout << "마법력: " << champ[count].mp << endl;
				cout << "속력: " << champ[count].speed << endl;
				cout << "사정거리: " << champ[count].range << endl;
				cout << "역할: " << champ[count].position << endl;
			}
			break;
		case 2:
			Insert(champ, &length, choose);
			break;
		case 3:
			DeleteChamp(champ, &length, choose);
			break;
		case 4:
			DeletePosition(champ, &length);
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
int Search(champion_bt* _champ, int _length, int _choose)
{
	string _name;
	int check = 0;

	cout << "이름: ";
	cin >> _name;
	for (check = 0; check < _length; ++check)
	{
		if (_name == _champ[check].name)
			break;
	}
	if (_choose == 2)
		_champ[check].name = _name;
	return check;
}
void Insert(champion_bt* _champ, int* _length, int _choose)
{
	int i = 0;
	int count = Search(_champ, *_length, _choose);

	if (count != *_length)
		cout << "이미 있는 챔피언입니다." << endl;
	else
	{
		cout << "체력: ";
		cin >> _champ[count].hp;
		cout << "마법력: ";
		cin >> _champ[count].mp;
		cout << "속력: ";
		cin >> _champ[count].speed;
		cout << "사정거리: ";
		cin >> _champ[count].range;
		cout << "역할: ";
		cin >> _champ[count].position;
		++* _length;
	}
}
void DeleteChamp(champion_bt* _champ, int* _length, int _choose)
{
	int count = Search(_champ, *_length, _choose);

	if (count != *_length)
	{
		_champ[count].name = _champ[*_length - 1].name;
		_champ[count].hp = _champ[*_length - 1].hp;
		_champ[count].mp = _champ[*_length - 1].mp;
		_champ[count].speed = _champ[*_length - 1].speed;
		_champ[count].range = _champ[*_length - 1].range;
		_champ[count].position = _champ[*_length - 1].position;
		--* _length;
	}
	else
		cout << "그런 챔피언은 없습니다." << endl;
}
void DeletePosition(champion_bt* _champ, int* _length)
{
	string _position;
	int check = 0;

	cout << "역할: ";
	cin >> _position;
	for (int i = 0; i < *_length; ++i)
	{
		if (_champ[i].position == _position)
		{
			_champ[i].name = _champ[*_length - 1].name;
			_champ[i].hp = _champ[*_length - 1].hp;
			_champ[i].mp = _champ[*_length - 1].mp;
			_champ[i].speed = _champ[*_length - 1].speed;
			_champ[i].range = _champ[*_length - 1].range;
			_champ[i].position = _champ[*_length - 1].position;
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
			cout << "이름: " << _champ[i].name << endl;
			cout << "체력: " << _champ[i].hp << endl;
			cout << "마법력: " << _champ[i].mp << endl;
			cout << "속력: " << _champ[i].speed << endl;
			cout << "사정거리: " << _champ[i].range << endl;
			cout << "역할: " << _champ[i].position << endl << endl << endl;
		}
	}
}
void FindMaxHp(champion_bt* _champ, int _length)
{
	int max = 0;

	for (int i = 0; i < _length; ++i)
	{
		if (max < _champ[i].hp)
			max = _champ[i].hp;
	}
	for (int j = 0; j < _length; ++j)
	{
		if (max == _champ[j].hp)
		{
			cout << "이름: " << _champ[j].name << endl;
			cout << "체력: " << _champ[j].hp << endl;
			cout << "마법력: " << _champ[j].mp << endl;
			cout << "속력: " << _champ[j].speed << endl;
			cout << "사정거리: " << _champ[j].range << endl;
			cout << "역할: " << _champ[j].position << endl << endl << endl;
		}
	}
}

void SortByHp(champion_bt* _champ, int _length)
{
	string tmpName;
	int tmpHp;
	int tmpMp;
	int tmpSpeed;
	int tmpRange;
	string tmpPosition;

	int check = 0;
	while (check != _length - 1)
	{
		check = 0;
		for (int i = 0; i < _length - 1; ++i)
		{
			if (_champ[i].hp < _champ[i + 1].hp)
			{
				tmpName = _champ[i].name;
				tmpHp = _champ[i].hp;
				tmpMp = _champ[i].mp;
				tmpSpeed = _champ[i].speed;
				tmpRange = _champ[i].range;
				tmpPosition = _champ[i].position;

				_champ[i].name = _champ[i + 1].name;
				_champ[i].hp = _champ[i + 1].hp;
				_champ[i].mp = _champ[i + 1].mp;
				_champ[i].speed = _champ[i + 1].speed;
				_champ[i].range = _champ[i + 1].range;
				_champ[i].position = _champ[i + 1].position;

				_champ[i + 1].name = tmpName;
				_champ[i + 1].hp = tmpHp;
				_champ[i + 1].mp = tmpMp;
				_champ[i + 1].speed = tmpSpeed;
				_champ[i + 1].range = tmpRange;
				_champ[i + 1].position = tmpPosition;
			}
			else
				++check;
		}
	}
}





