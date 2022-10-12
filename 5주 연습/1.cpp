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
int Search_R(champion_bt*,int,string,int*,int*,int);
void Insert_R(champion_bt*, int*, string,int*, int*,int);
void Delete_R(champion_bt*, int*, string,int*, int*,int);
void DeleteAll_R(champion_bt*, int*, string,int*, int*,int);
void PrintAll_R(champion_bt*, int, int, int);
void FindMaxHp_R(champion_bt*, int, int, int);
void SortByHp_R(champion_bt*, int, int, int);

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
	string name;
	int count = -1;
	int empty = 0;
	int length = 29;
	int location = -1;
	for (int i = 0; i < 40; ++i)
		if (champ[i].hp < 0)
			champ[i].name = " ";
	
	while (choose != 11)
	{
		cout << endl << endl << "1.검색" << endl;
		cout << "2.삽입" << endl;
		cout << "3.챔피언 삭제" << endl;
		cout << "4.포지션 삭제" << endl;
		cout << "5.전체 출력" << endl;
		cout << "6.최대 체력 챔피언 찾기" << endl;
		cout << "7.체력 순으로 정렬" << endl;
		cout << "11.종료" << endl;

		cin >> choose;
		switch (choose)
		{
		case 1:
			location = -1;
			empty = 0;
			cout << "이름: ";
			cin >> name;
			location=Search_R(champ, length, name, &count, &empty, choose);
			if (location == -1)
			{
				cout << "그런 챔피언은 없습니다." << endl;
				cout << "이름: ";
				cin >> name;
				Search_R(champ, length, name, &count, &empty, choose);
			}
			cout << "체력: "<<champ[location].hp << endl;
			cout << "마법력: " << champ[location].mp << endl;
			cout << "이동속도: " << champ[location].speed << endl;
			cout << "사정거리: " << champ[location].range << endl;
			cout << "포지션: " << champ[location].position << endl;
			break;
		case 2:
			
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
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
int Search_R(champion_bt* _champ, int _length,string _name, int*_count, int* _empty,int _choose)
{
	if (_choose == 1 || _choose == 2 || _choose == 3)
	{
		if (_length == 1)
		{
			if (_champ[0].name == _name)
				*_count = 0;
			else
			{
				if (_champ[0].name == " ")
					*_empty = 0;
				
			}
		}
		else
		{
			if (_champ[_length - 1].name != _name)
			{
				if (_champ[_length - 1].name == " ")
					*_empty = _length - 1;
				Search_R(_champ, _length - 1, _name, _count, _empty, _choose);
			}

			else
				*_count = _length - 1;
		}
	}
	else if (_choose == 4)
	{
		if (_length == 1)
		{
			if (_champ[0].position == _name)
				*_count = 0;
			else
				if (_champ[0].name == " ")
					*_empty = 0;
		}
		else
		{
			if (_champ[_length - 1].position != _name)
			{
				if (_champ[_length - 1].position == " ")
					*_empty = _length - 1;
				Search_R(_champ, _length - 1, _name, _count, _empty, _choose);
			}

			else
				*_count = _length - 1;
		}
	}
	
	return *_count;
}
void Insert_R(champion_bt* _champ, int* _length, string _name,int*_count, int*_empty,int _choose)
{
	if (Search_R(_champ, *_length - 1, _name, _count, _empty, _choose) != -1)
	{
		cout << "이미 있는 챔피언입니다." << endl;
		Insert_R(_champ, _length, _name, _count, _empty, _choose);
	}
	else
	{
		cout << "이름: ";
		cin >> _champ[*_empty].name;
		cout << "체력: ";
		cin >> _champ[*_empty].hp;
		cout << "마법력: ";
		cin >> _champ[*_empty].mp;
		cout << "이동속도: ";
		cin >> _champ[*_empty].speed;
		cout << "사정거리: ";
		cin >> _champ[*_empty].range;
		cout << "포지션: ";
		cin >> _champ[*_empty].position;
		++* _length;

	}
}
void Delete_R(champion_bt* _champ, int* _length, string _name,int* _count, int* _empty,int _choose)
{
	int count = Search_R(_champ, *_length - 1, _name, _count, _empty,_choose); 
	if (count == -1)
	{
		cout << "그런 챔피언은 없습니다." << endl;
		Delete_R(_champ, _length, _name, _count, _empty, _choose);

	}
	else
	{
		_champ[count].name = _champ[*_length - 1].name;
		_champ[count].hp = _champ[*_length - 1].hp;
		_champ[count].mp = _champ[*_length - 1].mp;
		_champ[count].speed = _champ[*_length - 1].speed;
		_champ[count].range = _champ[*_length - 1].range;
		_champ[count].position = _champ[*_length - 1].position;
		--* _length;
	}
}

void DeleteAll_R(champion_bt* _champ, int* _length,string _name, int* _count, int* _empty,int _choose)
{
	int count= Search_R(_champ, *_length - 1, _name, _count, _empty, _choose);
	if (count == -1)
	{
		cout << "그런 포지션은 없습니다." << endl;
		DeleteAll_R(_champ, _length, _name, _count, _empty, _choose);
	}
	else
	{
		_champ[count].name = _champ[*_length - 1].name;
		_champ[count].hp = _champ[*_length - 1].hp;
		_champ[count].mp = _champ[*_length - 1].mp;
		_champ[count].speed = _champ[*_length - 1].speed;
		_champ[count].range = _champ[*_length - 1].range;
		_champ[count].position = _champ[*_length - 1].position;
		--* _length;
		DeleteAll_R(_champ, _length, _name, _count, _empty, _choose);
	}
}
void PrintAll_R(champion_bt* _champ, int _length, int, int)
{
	//if()
}
void FindMaxHp_R(champion_bt*, int, int, int)
{

}
void SortByHp_R(champion_bt*, int, int, int)
{

}
