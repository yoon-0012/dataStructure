#include<iostream>
#include<string>
using namespace std;
struct champion_bt
{
	string name;
	int hp;//체력
	int mp;//마법력
	int speed;//이동속도
	int range;//사거리
	string position;//탑 미드 봇
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
	champion_bt champ[40] = { {"누누와월럼프" , 540,32,340, 125, "정글"},
		{"리신" , 575 , 32 , 345 , 125 , "정글" },
		{"미스포츈" , 570 , 30 , 325 , 550 , "원딜" },
		{ "이즈리얼" , 530 , 30 , 325 , 550 , "원딜"},{" " },
		{ "레넥톤" , 575 , 32 , 345 , 125, "탑"},
		{ "나서스" , 561 ,32,350,125, "탑"},
		{ "벨코즈",  520,  30, 340,  525, "서폿" },{" "},{ " "},{ " "},{" "},
		{"가렌", 620, 32, 340,175, "탑"},
		{ "리븐", 560,  32,  345,  125, "탑"   },
		{ "블리츠크랭크", 583, 32,325, 125, "서폿"},
		{ "판테온", 579, 28,  345,  150,  "미드"},
		{"베인",515, 30, 330, 550, "원딜"},
		{"쓰레쉬",560,30, 335, 450,"서폿"},
		{ "아무무",615, 32, 335,  125,  "정글"},
		{ "애쉬",  539, 30, 325,  600, "원딜"},
		{ "모르가나",559,  30,  335, 450,  "서폿"},{ " "},
		{ "아리",  526, 30,  330,  550, "미드"},{ " "},{ " "},
		{ "아칼리",  575,  37,  345,  125,  "미드" },
		{ "이블린",620, 32, 335, 125, "정글"},{ " "},
		{"유미",  480,  25, 330,  500,  "서폿"},
		{ " "},{" "},{ " "},{ " "},{ " "},{ " "},
		{ " "},{ " "},{ " "},{ " "},{ " "} };
	//가렌 이블린 620
	//정글4 미드3 원딜4 탑4 서폿5

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
		cout << "3. Delete [ 챔피언 이름 ]" << endl;
		cout << "4. DeleteAll [ position ]" << endl;
		cout << "5. PrintAll" << endl;
		cout << "6. FindMaxHp" << endl;
		cout << "7. SortByHp" << endl;
		cout << "11. 종료" << endl;

		switch (choose)
		{
		case 1:
			cout << "이름: ";
			cin >> Name;
			search_sl(champ, length, check, Name);
			break;
		case 2:
			lenChan = 0;
			cout << "이름: ";
			cin >> Name;
			insert_sl(champ, &length, Name, lenChan);
			break;
		case 3:
			cout << "이름: ";
			cin >> Name;
			delChamp_sl(champ, &length, length, Name);
			break;
		case 4:
			cout << "포지션 : ";
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
					cout << "이름: " << champ[i].name << endl;
					cout << "체력: " << champ[i].hp << endl;
					cout << "마법력: " << champ[i].mp << endl;
					cout << "이동속도: " << champ[i].speed << endl;
					cout << "사정거리: " << champ[i].range << endl;
					cout << "포지션: " << champ[i].position << endl << endl;
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
			cout << "잘못된 입력입니다." << endl;
		}
	}
	return 0;
}
void search_sl(champion_bt* _champ, int _length, int _check, string _Name)
{
	if (_Name == _champ[_length - 1].name)
	{
		cout << "체력: " << _champ[_length - 1].hp << endl;
		cout << "마법력: " << _champ[_length - 1].mp << endl;
		cout << "이동속도: " << _champ[_length - 1].speed << endl;
		cout << "사거리: " << _champ[_length - 1].range << endl;
		cout << "포지션: " << _champ[_length - 1].position << endl << endl;
		++_check;
	}
	else if (_length == 1 && _check == 0)
		cout << "그런 챔피언은 없습니다." << endl;
	if (_length > 1)
		search_sl(_champ, _length - 1, _check, _Name);
}
void insert_sl(champion_bt* _champ, int* _length, string _Name, int _lenChan)
{
	if (_champ[_lenChan].name == " ")
	{
		_champ[_lenChan].name = _Name;
		cout << "체력: ";
		cin >> _champ[_lenChan].hp;
		cout << "마법력: ";
		cin >> _champ[_lenChan].mp;
		cout << "이동속도: ";
		cin >> _champ[_lenChan].speed;
		cout << "사정거리: ";
		cin >> _champ[_lenChan].range;
		cout << "포지션: ";
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
		cout << "이름: " << _champ[_lenChan].name << endl;
		cout << "체력: " << _champ[_lenChan].hp << endl;
		cout << "마법력: " << _champ[_lenChan].mp << endl;
		cout << "이동속도: " << _champ[_lenChan].speed << endl;
		cout << "사거리: " << _champ[_lenChan].range << endl;
		cout << "포지션: " << _champ[_lenChan].position << endl;
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
	int temphp = 0;//체력
	int tempmp = 0;//마법력
	int tempspeed = 0;//이동속도
	int temprange = 0;//사거리
	string tempposition;//탑 미드 봇

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
