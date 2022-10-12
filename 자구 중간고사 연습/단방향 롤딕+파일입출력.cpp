
//449   549까지
#include<iostream>
#include"Windows.h"
#include<cstdio>
using namespace std;
class champion_arr
{
public:
	string name;
	int hp;//체력
	int mp;//마법력
	int speed;//이동속도
	int range;//사거리
	string position;//탑 미드 봇
};
champion_arr champion[40] = { {"누누와월럼프" , 540,32,340, 125, "정글"},
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
class champion_link
{
public:
	string name;
	int hp;//체력
	int mp;//마법력
	int speed;//이동속도
	int range;//사거리
	string position;//탑 미드 봇
	champion_link* link;
};
champion_link* Array2LinkedList(champion_link* head);
void Search_SL(champion_link* head, string name);
champion_link* Insert_SL(champion_link* head, string name, int hp, int mp, int speed, int range, string position);
champion_link* Delete_SL(champion_link* head, string name);
champion_link* DeleteAll_SL(champion_link* head, string position);
void PrintAll_SL(champion_link* head);
void FindMaxHp_SL(champion_link* head);
champion_link* SortByHp_SL(champion_link* head);

int main()
{
	int choose = -1;
	string name;
	int hp = 0;
	int mp = 0;
	int speed = 0;
	int range = 0;
	string position;
	champion_link* head = nullptr;
	head = Array2LinkedList(head);
	FILE* in = nullptr;
	FILE* out = nullptr;
	//int cham[10];

	while (choose != 0)
	{
		cout << endl << endl << "1.검색" << endl;
		cout << "2.삽입" << endl;
		cout << "3.챔피언삭제" << endl;
		cout << "4.포지션삭제" << endl;
		cout << "5.출력" << endl;
		cout << "6.최대체력챔피언" << endl;
		cout << "7.정렬" << endl;
		cout << "8.저장" << endl;
		cout << "9.불러오기" << endl;
		cout << "0.종료" << endl;

		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "이름: ";
			cin >> name;
			Search_SL(head, name);
			break;
		case 2:
			cout << "이름: ";
			cin >> name;
			cout << "체력: ";
			cin >> hp;
			cout << "마법력: ";
			cin >> mp;
			cout << "속도: ";
			cin >> speed;
			cout << "사정거리: ";
			cin >> range;
			cout << "포지션: ";
			cin >> position;
			head = Insert_SL(head, name, hp, mp, speed, range, position);
			break;
		case 3:
			cout << "이름: ";
			cin >> name;
			head = Delete_SL(head, name);
			break;
		case 4:
			cout << "포지션: ";
			cin >> position;
			head = DeleteAll_SL(head, position);
			break;
		case 5:
			PrintAll_SL(head);
			break;
		case 6:
			FindMaxHp_SL(head);
			break;
		case 7:
			head = SortByHp_SL(head);
			break;
		case 8://저장
			if (fopen_s(&in, "game.txt", "wb") == 0)
				fwrite(head, sizeof(champion_link),40,in);
			fclose(in);
			break;
		case 9://불러오기
			if (fopen_s(&out, "game.txt", "rb") == 0)
				fread(head, sizeof(champion_link), 40, out);
			fclose(out);
			break;
		default:
			break;
		}
	}
	return 0;
}
champion_link* Array2LinkedList(champion_link* head)
{
	for (int i = 0; i < 29; ++i)
	{
		if (champion[i].hp > 0)
		{
			champion_link* champ = new champion_link;

			champ->name = champion[i].name;
			champ->hp = champion[i].hp;
			champ->mp = champion[i].mp;
			champ->speed = champion[i].speed;
			champ->range = champion[i].range;
			champ->position = champion[i].position;

			if (head == NULL)
			{
				head = champ;
				champ->link = head;
			}
			else
			{
				champ->link = head->link;
				head->link = champ;
				head = champ;
			}
		}
	}
	return head;
}
void Search_SL(champion_link* head, string name)
{
	champion_link* champ = nullptr;

	for (champ = head->link; champ != head; champ = champ->link)
	{
		if (champ->name == name)
		{
			cout << "체력: " << champ->hp << endl;
			cout << "마법력: " << champ->mp << endl;
			cout << "속도: " << champ->speed << endl;
			cout << "사정거리: " << champ->range << endl;
			cout << "포지션: " << champ->position << endl << endl;
		}
	}
	if (champ->name == name)
	{
		cout << "체력: " << champ->hp << endl;
		cout << "마법력: " << champ->mp << endl;
		cout << "속도: " << champ->speed << endl;
		cout << "사정거리: " << champ->range << endl;
		cout << "포지션: " << champ->position << endl << endl;
	}
}
champion_link* Insert_SL(champion_link* head, string name, int hp, int mp, int speed, int range, string position)//정렬 상태를 유지하며 삽입
{
	champion_link* champ = new champion_link;

	champ->name = name;
	champ->hp = hp;
	champ->mp = mp;
	champ->speed = speed;
	champ->range = range;
	champ->position = position;

	if (head == NULL)
	{
		head = champ;
		champ->link = head;
	}
	else
	{
		if (champ->hp >= head->link->hp)
		{
			champ->link = head->link;
			head->link = champ;
		}
		else if (champ->hp <= head->hp)
		{
			champ->link = head->link;
			head->link = champ;
			head = champ;
		}
		else
		{
			for (champion_link* i = head->link; i != head; i = i->link)
			{
				if (i->hp >= champ->hp && champ->hp >= i->link->hp)
				{
					champ->link = i->link;
					i->link = champ;
					break;
				}
			}
		}
	}
	return head;
}
champion_link* Delete_SL(champion_link* head, string name)
{
	champion_link* champ = nullptr;
	champion_link* pre = nullptr;

	for (champ = head->link; champ != head;)
	{
		if (champ->link == champ)
		{
			delete champ;
			return NULL;
		}
		if (champ->link == champ)
		{
			delete champ;
			return NULL;
		}

		champion_link* remove = nullptr;
		if (champ->name == name)
		{
			for (pre = champ; pre->link != champ; pre = pre->link)
			{
			}
			remove = pre->link;
			pre->link = remove->link;
			champ = champ->link;
			delete remove;
		}
		else
			champ = champ->link;
	}
	if (champ->link == champ)
	{
		delete champ;
		return NULL;
	}
	champion_link* remove = nullptr;
	if (champ->name == name)
	{
		for (pre = champ; pre->link != champ; pre = pre->link)
		{
		}
		remove = pre->link;
		pre->link = remove->link;
		head = pre;
		champ = champ->link;
		delete remove;
	}
	return head;
}
champion_link* DeleteAll_SL(champion_link* head, string position)
{
	champion_link* champ = nullptr;
	champion_link* pre = nullptr;

	for (champ = head->link; champ != head;)
	{
		if (champ->link == champ)
		{
			delete champ;
			return NULL;
		}

		champion_link* remove = nullptr;
		if (champ->position == position)
		{
			for (pre = champ; pre->link != champ; pre = pre->link)
			{
			}
			remove = pre->link;
			pre->link = remove->link;
			champ = champ->link;
			delete remove;
		}
		else
			champ = champ->link;
	}
	if (champ->link == champ)
	{
		delete champ;
		return NULL;
	}

	champion_link* remove = nullptr;
	if (champ->position == position)
	{
		for (pre = champ; pre->link != champ; pre = pre->link)
		{
		}
		remove = pre->link;
		pre->link = remove->link;
		head = pre;
		champ = champ->link;
		delete remove;
	}
	return head;
}
void PrintAll_SL(champion_link* head)
{
	champion_link* champ = nullptr;

	if (head == NULL)
		cout << "챔피언 정보가 없습니다" << endl;
	else
	{
		for (champ = head->link; champ != head; champ = champ->link)
		{
			cout << "이름: " << champ->name << endl;
			cout << "체력: " << champ->hp << endl;
			cout << "마법력: " << champ->mp << endl;
			cout << "속도: " << champ->speed << endl;
			cout << "사정거리: " << champ->range << endl;
			cout << "포지션: " << champ->position << endl << endl;
		}
		cout << "이름: " << champ->name << endl;
		cout << "체력: " << champ->hp << endl;
		cout << "마법력: " << champ->mp << endl;
		cout << "속도: " << champ->speed << endl;
		cout << "사정거리: " << champ->range << endl;
		cout << "포지션: " << champ->position << endl << endl;
	}
}
void FindMaxHp_SL(champion_link* head)
{
	int max = 0;
	champion_link* champ = nullptr;

	for (champ = head->link; champ != head; champ = champ->link)
	{
		if (max < champ->hp)
			max = champ->hp;
	}
	if (max < champ->hp)
		max = champ->hp;

	for (champ = head->link; champ != head; champ = champ->link)
	{
		if (champ->hp == max)
		{
			cout << "이름: " << champ->name << endl;
			cout << "체력: " << champ->hp << endl;
			cout << "마법력: " << champ->mp << endl;
			cout << "속도: " << champ->speed << endl;
			cout << "사정거리: " << champ->range << endl;
			cout << "포지션: " << champ->position << endl << endl;
		}
	}
	if (champ->hp == max)
	{
		cout << "이름: " << champ->name << endl;
		cout << "체력: " << champ->hp << endl;
		cout << "마법력: " << champ->mp << endl;
		cout << "속도: " << champ->speed << endl;
		cout << "사정거리: " << champ->range << endl;
		cout << "포지션: " << champ->position << endl << endl;
	}
}
champion_link* SortByHp_SL(champion_link* head)
{
	champion_link* champ = nullptr;
	champion_link* pre = nullptr;
	champion_link* tmp = nullptr;
	champion_link* tmp2 = nullptr;

	for (champion_link* i = head->link; i != head; i = i->link)
	{
		for (champ = head->link; champ != head; champ = champ->link)
		{
			if (champ->hp < champ->link->hp)
			{
				for (pre = champ; pre->link != champ; pre = pre->link)
				{
				}
				tmp = champ;//nunu
				tmp2 = champ->link;//lisin
				champ->link = champ->link->link;//nunu->mipo
				tmp2->link = champ;//lisin->nunu
				pre->link = tmp2;//yumi->lisin
				champ = tmp2;//champ=lisin
			}
		}
	}
	for (champ = head->link; champ != head; champ = champ->link)
	{
		if (champ->hp < champ->link->hp)
		{
			for (pre = champ; pre->link != champ; pre = pre->link)
			{
			}
			tmp = champ;//nunu
			tmp2 = champ->link;//lisin
			champ->link = champ->link->link;//nunu->mipo
			tmp2->link = champ;//lisin->nunu
			pre->link = tmp2;//yumi->lisin
			champ = tmp2;//champ=lisin
		}
	}
	return head;
}