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

void search(champion_bt*, int);
void insert(champion_bt*, int*);
void delChamp(champion_bt*, int*);
void delPosition(champion_bt*, int*);
void printAll(champion_bt*, int);
void findMaxHp(champion_bt*, champion_bt*, int);
void sortByHp(champion_bt*, int);

int main()
{
	champion_bt champ[40];
	int length = 29;
	champion_bt Maxchamp[10];
	int choose = 0;

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
		cout << endl << endl << endl;
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
			search(champ, length);
			break;
		case 2:
			// 2. Insert : 새로운 챔피언의 정보를 입력받아삽입한다.
			insert(champ, &length);
			break;
		case 3:
			// 3. Delete[챔피언이름] : 주어진 챔피언에 대한 정보를 삭제한다.
			delChamp(champ, &length);
			break;
		case 4:
			// 4. DeleteAll[position] : 주어진 위치의 모든 챔피언 정보를 삭제한다.
			delPosition(champ, &length);
			break;
		case 5:
			// 5. PrintAll : 모든 챔피언의 정보를 배열에 저장된 순서대로 출력한다.
			printAll(champ, length);
			break;
		case 6:
			// 6. FindMaxHp : 가장 체력이 큰 챔피언의 정보를 출력한다.
			findMaxHp(champ, Maxchamp, length);
			break;
		case 7:
			// 7. SortByHp : 체력이 큰 챔피언부터 순서대로 저장한다.  
			sortByHp(champ, length);
			break;
		case 11:
			break;
		default:
			cout << "잘못된 입력입니다." << endl;
		}
	}
	return 0;
}
void search(champion_bt* _champ, int _length)
{
	// 1. Search[챔피언이름] : 주어진 챔피언의 정보를 출력한다.
	string Name;
	cin >> Name;
	int check = 0;

	for (int i = 0; i < _length; ++i)
	{
		if (Name == _champ[i].name)
		{
			cout << "체력: " << _champ[i].hp << endl;
			cout << "마법력: " << _champ[i].mp << endl;
			cout << "이동속도: " << _champ[i].speed << endl;
			cout << "사거리: " << _champ[i].range << endl;
			cout << "포지션: " << _champ[i].position << endl;
			++check;
		}
		if (i == _length - 1 && check == 0)
			cout << "그런 챔피언은 없습니다." << endl;
	}
}
void insert(champion_bt* _champ, int* _length)
{
	// 2. Insert : 새로운 챔피언의 정보를 입력받아삽입한다.
	string newcham;
	int check = 0;

	while (true)
	{
		cout << "새로운 챔피언의 정보를 입력하세요" << endl;
		cin >> newcham;

		for (check = 0; check < *_length; ++check)
		{
			if (newcham == _champ[check].name)
			{
				cout << "이미 있는 챔피언입니다." << endl;
				break;
			}
		}
		if (check == *_length)
		{
			_champ[*_length].name = newcham;
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
			break;
		}
		else
			continue;
	}
}
void delChamp(champion_bt* _champ, int* _length)
{
	// 3. Delete[챔피언이름] : 주어진 챔피언에 대한 정보를 삭제한다.
	string delName;

	cout << "삭제할 챔피언의 이름을 입력하세요: ";
	cin >> delName;
	for (int i = 0; i < *_length; ++i)
	{
		if (delName == _champ[i].name)
		{
			for (int j = i; j < *_length - 1; ++j)
			{
				_champ[j].name = _champ[j + 1].name;
				_champ[j].hp = _champ[j + 1].hp;
				_champ[j].mp = _champ[j + 1].mp;
				_champ[j].speed = _champ[j + 1].speed;
				_champ[j].range = _champ[j + 1].range;
				_champ[j].position = _champ[j + 1].position;
			}
		
			break;
		}
		else
		{
			if (i == *_length - 1)
				cout << "그런 챔피언은 없습니다." << endl;
		}
	}
}
void delPosition(champion_bt* _champ, int* _length)
{
	// 4. DeleteAll[position] : 주어진 위치의 모든 챔피언 정보를 삭제한다.
	string delPosition;

	cout << "삭제할 챔피언의 포지션을 입력하세요 : ";
	cin >> delPosition;
	for (int i = 0; i < *_length; ++i)
	{
		if (delPosition == _champ[i].position)
		{
			for (int j = i; j < *_length - 1; ++j)
			{
				_champ[j].name = _champ[j + 1].name;
				_champ[j].hp = _champ[j + 1].hp;
				_champ[j].mp = _champ[j + 1].mp;
				_champ[j].speed = _champ[j + 1].speed;
				_champ[j].range = _champ[j + 1].range;
				_champ[j].position = _champ[j + 1].position;
			}
			--i;
			--* _length;
		}
		else
			continue;
	}
}
void printAll(champion_bt* _champ, int _length)
{
	// 5. PrintAll : 모든 챔피언의 정보를 배열에 저장된 순서대로 출력한다.
	for (int i = 0; i < _length; ++i)
	{
		if (_champ[i].hp > -1)
		{
			cout << "이름: " << _champ[i].name << endl;
			cout << "체력: " << _champ[i].hp << endl;
			cout << "마법력: " << _champ[i].mp << endl;
			cout << "이동속도: " << _champ[i].speed << endl;
			cout << "사거리: " << _champ[i].range << endl;
			cout << "포지션: " << _champ[i].position << endl;
			cout << endl;
		}
	}
}
void findMaxHp(champion_bt* _champ, champion_bt* _Maxchamp, int length)
{
	// 6. FindMaxHp : 가장 체력이 큰 챔피언의 정보를 출력한다.
	int Maxchampnum = 0;
	int max = 0;

	for (int i = 0; i < length; ++i)
	{
		if (max < _champ[i].hp)
			max = _champ[i].hp;
	}
	for (int j = 0; j < length; ++j)
	{
		if (max == _champ[j].hp)
		{
			_Maxchamp[Maxchampnum] = _champ[j];
			++Maxchampnum;
		}
	}
	for (int h = 0; h < Maxchampnum; ++h)
	{
		cout << "이름: " << _Maxchamp[h].name << endl;
		cout << "체력: " << _Maxchamp[h].hp << endl;
		cout << "마법력: " << _Maxchamp[h].mp << endl;
		cout << "이동속도: " << _Maxchamp[h].speed << endl;
		cout << "사거리: " << _Maxchamp[h].range << endl;
		cout << "포지션: " << _Maxchamp[h].position << endl;
		cout << endl;
	}
}
void sortByHp(champion_bt* _champ, int _length)
{
	// 7. SortByHp : 체력이 큰 챔피언부터 순서대로 저장한다.  
	string tempname;
	int temphp = 0;//체력
	int tempmp = 0;//마법력
	int tempspeed = 0;//이동속도
	int temprange = 0;//사거리
	string tempposition;//탑 미드 봇
	int clean = 0;

	while (true)
	{
		if (clean == _length - 1)
			break;
		else
			clean = 0;
		for (int j = 0; j < _length - 1; ++j)
		{
			if (_champ[j].hp < _champ[j + 1].hp)
			{
				tempname = _champ[j].name;
				temphp = _champ[j].hp;
				tempmp = _champ[j].mp;
				tempspeed = _champ[j].speed;
				temprange = _champ[j].range;
				tempposition = _champ[j].position;

				_champ[j].name = _champ[j + 1].name;
				_champ[j].hp = _champ[j + 1].hp;
				_champ[j].mp = _champ[j + 1].mp;
				_champ[j].speed = _champ[j + 1].speed;
				_champ[j].range = _champ[j + 1].range;
				_champ[j].position = _champ[j + 1].position;

				_champ[j + 1].name = tempname;
				_champ[j + 1].hp = temphp;
				_champ[j + 1].mp = tempmp;
				_champ[j + 1].speed = tempspeed;
				_champ[j + 1].range = temprange;
				_champ[j + 1].position = tempposition;
			}
			else
				++clean;
		}
	}
}