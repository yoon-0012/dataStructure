#include<iostream>
using namespace std;
#include<string>
class champion_bt
{
public:
	string name;
	int hp;//체력
	int mp;//마법력
	int speed;//이동속도
	int range;//사거리
	string position;//탑 미드 봇
};
void search_r(champion_bt*, int, string, int*);
void insert_r(champion_bt*, int*, string*, int*);
void delChamp_r(champion_bt*, int*, string, int*);
void delPosition_r(champion_bt*, int*, string, int*);
void printAll_r(champion_bt*, int, int*);
void findMaxHp_sl(champion_bt*, int, int*);
void sortByHp_r(champion_bt*, int, int, int*);

int main()
{
	champion_bt champ[40];
	int length = 29;
	int choose = 0;
	string Name;
	int check = 0;
	string newcham;
	int max = 0;
	int tmpLength = 0;
	string delName;
	string delPosition;

	//가렌 이블린 620
	//정글4 미드3 원딜4 탑4 서폿5
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
			// 1. Search[챔피언이름] : 주어진 챔피언의 정보를 출력한다.
			check = 0;
			cin >> Name;
			search_r(champ, length, Name, &check);
			break;
		case 2:
			// 2. Insert : 새로운 챔피언의 정보를 입력받아삽입한다.
			cout << "새로운 챔피언의 정보를 입력하세요" << endl;
			check = 20;
			cin >> newcham;
			insert_r(champ, &length, &newcham, &check);
			break;
		case 3:
			// 3. Delete[챔피언이름] : 주어진 챔피언에 대한 정보를 삭제한다.
			cout << "삭제할 챔피언의 이름을 입력하세요: ";
			check = length;
			cin >> delName;
			delChamp_r(champ, &length, delName, &check);
			break;
		case 4:
			// 4. DeleteAll[position] : 주어진 위치의 모든 챔피언 정보를 삭제한다.
			cout << "삭제할 챔피언의 포지션을 입력하세요 : ";
			check = length;
			cin >> delPosition;
			delPosition_r(champ, &length, delPosition, &check);
			break;
		case 5:
			// 5. PrintAll : 모든 챔피언의 정보를 배열에 저장된 순서대로 출력한다.
			check = 0;
			printAll_r(champ, length, &check);
			break;
		case 6:
			// 6. FindMaxHp : 가장 체력이 큰 챔피언의 정보를 출력한다.
			max = 0;
			findMaxHp_sl(champ, length, &max);
			break;
		case 7:
			// 7. SortByHp : 체력이 큰 챔피언부터 순서대로 저장한다. 
			tmpLength = length;
			check = 0;
			sortByHp_r(champ, length, tmpLength, &check);
			break;
		case 11:
			break;
		default:
			cout << "잘못된 입력입니다." << endl;
		}
	}
	return 0;
}
void search_r(champion_bt* _champ, int _length, string _Name, int* _check)
{
	// 1. Search[챔피언이름] : 주어진 챔피언의 정보를 출력한다.
	//-858993460정수   //1330....스트링
	if (_length == 1)
	{
		if (_Name == _champ[0].name)
		{
			cout << "체력: " << _champ[0].hp << endl;
			cout << "마법력: " << _champ[0].mp << endl;
			cout << "이동속도: " << _champ[0].speed << endl;
			cout << "사거리: " << _champ[0].range << endl;
			cout << "포지션: " << _champ[0].position << endl;
			++* _check;
		}
		if (*_check == 0)
			cout << "그런 챔피언은 없습니다." << endl;
	}
	else
	{
		if (_Name == _champ[_length - 1].name)
		{
			cout << "체력: " << _champ[_length - 1].hp << endl;
			cout << "마법력: " << _champ[_length - 1].mp << endl;
			cout << "이동속도: " << _champ[_length - 1].speed << endl;
			cout << "사거리: " << _champ[_length - 1].range << endl;
			cout << "포지션: " << _champ[_length - 1].position << endl;
			++* _check;
		}
		search_r(_champ, _length - 1, _Name, _check);
	}
}
void insert_r(champion_bt* _champ, int* _length, string* _newcham, int* _check)
{
	// 2. Insert : 새로운 챔피언의 정보를 입력받아삽입한다.
	for (int i = 0; i < *_length; ++i)
	{
		if (*_newcham == _champ[i].name)
		{
			cout << "이미 있는 챔피언입니다." << endl;
			cout << "새로운 챔피언의 정보를 입력하세요" << endl;
			cin >> *_newcham;
			break;
		}
	}
	if (*_check == 1)
	{
		_champ[*_length].name = *_newcham;
		cout << "체력: ";
		cin >> _champ[*_length].hp;
		cout << "마법력: ";
		cin >> _champ[*_length].mp;
		cout << "이동속도: ";
		cin >> _champ[*_length].speed;
		cout << "사거리: ";
		cin >> _champ[*_length].range;
		cout << "포지션: ";
		cin >> _champ[*_length].position;
		++* _length;
	}
	else
	{
		--* _check;
		insert_r(_champ, _length, _newcham, _check);
	}
}
void delChamp_r(champion_bt* _champ, int* _length, string _delName, int* _check)
{
	// 3. Delete[챔피언이름] : 주어진 챔피언에 대한 정보를 삭제한다.
	if (*_check == 1)
	{
		if (_delName == _champ[0].name)
		{
			_champ[0].name = _champ[*_length - 1].name;
			_champ[0].hp = _champ[*_length - 1].hp;
			_champ[0].mp = _champ[*_length - 1].mp;
			_champ[0].speed = _champ[*_length - 1].speed;
			_champ[0].range = _champ[*_length - 1].range;
			_champ[0].position = _champ[*_length - 1].position;
			--* _length;
		}
	}
	else
	{
		if (_delName == _champ[*_check - 1].name)
		{
			_champ[*_check - 1].name = _champ[*_length - 1].name;
			_champ[*_check - 1].hp = _champ[*_length - 1].hp;
			_champ[*_check - 1].mp = _champ[*_length - 1].mp;
			_champ[*_check - 1].speed = _champ[*_length - 1].speed;
			_champ[*_check - 1].range = _champ[*_length - 1].range;
			_champ[*_check - 1].position = _champ[*_length - 1].position;
			--* _length;
		}
		--* _check;
		delChamp_r(_champ, _length, _delName, _check);
	}
}
void delPosition_r(champion_bt* _champ, int* _length, string _delPosition, int* _check)
{
	// 4. DeleteAll[position] : 주어진 위치의 모든 챔피언 정보를 삭제한다.
	if (*_check == 1)
	{
		if (_delPosition == _champ[0].position)
		{
			_champ[0].name = _champ[*_length - 1].name;
			_champ[0].hp = _champ[*_length - 1].hp;
			_champ[0].mp = _champ[*_length - 1].mp;
			_champ[0].speed = _champ[*_length - 1].speed;
			_champ[0].range = _champ[*_length - 1].range;
			_champ[0].position = _champ[*_length - 1].position;
			--* _length;
		}
	}
	else
	{
		if (_delPosition == _champ[*_check - 1].position)
		{
			_champ[*_check - 1].name = _champ[*_length - 1].name;
			_champ[*_check - 1].hp = _champ[*_length - 1].hp;
			_champ[*_check - 1].mp = _champ[*_length - 1].mp;
			_champ[*_check - 1].speed = _champ[*_length - 1].speed;
			_champ[*_check - 1].range = _champ[*_length - 1].range;
			_champ[*_check - 1].position = _champ[*_length - 1].position;
			--* _length;
			delPosition_r(_champ, _length, _delPosition, _check);
		}
		else
		{
			--* _check;
			delPosition_r(_champ, _length, _delPosition, _check);
		}
	}
}
void printAll_r(champion_bt* _champ, int _length, int* _check)
{
	// 5. PrintAll : 모든 챔피언의 정보를 배열에 저장된 순서대로 출력한다.
	if (_length == 1)
	{
		if (_champ[*_check].hp > -1)
		{
			cout << "이름: " << _champ[*_check].name << endl;
			cout << "체력: " << _champ[*_check].hp << endl;
			cout << "마법력: " << _champ[*_check].mp << endl;
			cout << "이동속도: " << _champ[*_check].speed << endl;
			cout << "사거리: " << _champ[*_check].range << endl;
			cout << "포지션: " << _champ[*_check].position << endl;
			cout << endl;
		}
	}
	else
	{
		if (_champ[*_check].hp > -1)
		{
			cout << "이름: " << _champ[*_check].name << endl;
			cout << "체력: " << _champ[*_check].hp << endl;
			cout << "마법력: " << _champ[*_check].mp << endl;
			cout << "이동속도: " << _champ[*_check].speed << endl;
			cout << "사거리: " << _champ[*_check].range << endl;
			cout << "포지션: " << _champ[*_check].position << endl;
			cout << endl;
		}
		++* _check;
		printAll_r(_champ, _length - 1, _check);
	}
}
void findMaxHp_sl(champion_bt* _champ, int _length, int* _max)
{
	// 6. FindMaxHp : 가장 체력이 큰 챔피언의 정보를 출력한다.
	for (int i = 0; i < _length; ++i)
	{
		if (*_max < _champ[i].hp)
			*_max = _champ[i].hp;
	}
	if (_length == 1)
	{
		if (*_max == _champ[0].hp)
		{
			cout << "이름: " << _champ[0].name << endl;
			cout << "체력: " << _champ[0].hp << endl;
			cout << "마법력: " << _champ[0].mp << endl;
			cout << "이동속도: " << _champ[0].speed << endl;
			cout << "사거리: " << _champ[0].range << endl;
			cout << "포지션: " << _champ[0].position << endl;
			cout << endl;
		}
	}
	else
	{
		if (*_max == _champ[_length - 1].hp)
		{
			cout << "이름: " << _champ[_length - 1].name << endl;
			cout << "체력: " << _champ[_length - 1].hp << endl;
			cout << "마법력: " << _champ[_length - 1].mp << endl;
			cout << "이동속도: " << _champ[_length - 1].speed << endl;
			cout << "사거리: " << _champ[_length - 1].range << endl;
			cout << "포지션: " << _champ[_length - 1].position << endl;
			cout << endl;
		}
		findMaxHp_sl(_champ, _length - 1, _max);
	}
}
void sortByHp_r(champion_bt* _champ, int _length, int _tmpLength, int* _check)
{
	// 7. SortByHp : 체력이 큰 챔피언부터 순서대로 저장한다.  
	string tempname;
	int temphp = 0;//체력
	int tempmp = 0;//마법력
	int tempspeed = 0;//이동속도
	int temprange = 0;//사거리
	string tempposition;//탑 미드 봇

	if (_length == 2)
	{
		if (_champ[0].hp < _champ[1].hp)
		{
			tempname = _champ[0].name;
			temphp = _champ[0].hp;
			tempmp = _champ[0].mp;
			tempspeed = _champ[0].speed;
			temprange = _champ[0].range;
			tempposition = _champ[0].position;

			_champ[0].name = _champ[1].name;
			_champ[0].hp = _champ[1].hp;
			_champ[0].mp = _champ[1].mp;
			_champ[0].speed = _champ[1].speed;
			_champ[0].range = _champ[1].range;
			_champ[0].position = _champ[1].position;

			_champ[1].name = tempname;
			_champ[1].hp = temphp;
			_champ[1].mp = tempmp;
			_champ[1].speed = tempspeed;
			_champ[1].range = temprange;
			_champ[1].position = tempposition;
		}
		else
			++* _check;
		if (*_check != _tmpLength - 1)
		{
			*_check = 0;
			sortByHp_r(_champ, _tmpLength, _tmpLength, _check);
		}
	}
	else
	{
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
		sortByHp_r(_champ, _length - 1, _tmpLength, _check);
	}
}
