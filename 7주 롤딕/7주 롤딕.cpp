#include<iostream>
#include<string>
using namespace std;
struct champion_arr
{
	string name;
	int hp;//체력
	int mp;//마법력
	int speed;//이동속도
	int range;//사거리
	string position;//탑 미드 봇
};
struct champion_bt
{
	string name;
	int hp;//체력
	int mp;//마법력
	int speed;//이동속도
	int range;//사거리
	string position;//탑 미드 봇
	struct champion_bt* left;
};
champion_bt* Array2LinkedList(champion_bt* head, champion_arr* origin);
void search_sl(champion_bt* head, string name);
champion_bt* insert_sl(champion_bt* head, string name, int hp, int mp, int speed, int range, string position);
champion_bt* delChamp_sl(champion_bt* head, string name);//pre가 가리키는 노드의 다음 노드를 삭제
champion_bt* delPosition_sl(champion_bt* head, string position);
void printAll_sl(champion_bt* head);
void findMaxHp_sl(champion_bt* head);
champion_bt* sortByHp_sl(champion_bt* head);

int main()
{
	champion_arr origin[40] = { {"누누와월럼프" , 540,32,340, 125, "정글"},
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
	champion_bt* head = nullptr;
	head = Array2LinkedList(head, origin);

	int choose = 0;
	string name;
	int hp = 0;
	int mp = 0;
	int speed = 0;
	int range = 0;
	string position;

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

		if (!(cin >> choose))
		{
			cin.clear();
			cin.ignore(5, '\n');
			cout << "잘못된 입력입니다." << endl;
			break;
		}
		switch (choose)
		{
		case 1:
			cout << "이름: ";
			cin >> name;
			search_sl(head, name);
			break;
		case 2:
			cout << "이름: ";
			cin >> name;
			cout << "체력: ";
			cin >> hp;
			cout << "마법력: ";
			cin >> mp;
			cout << "이동속도: ";
			cin >> speed;
			cout << "사정거리: ";
			cin >> range;
			cout << "포지션: ";
			cin >> position;
			head = insert_sl(head, name, hp, mp, speed, range, position);
			break;
		case 3:
			cout << "이름: ";
			cin >> name;
			head = delChamp_sl(head, name);
			break;
		case 4:
			cout << "포지션 : ";
			cin >> position;
			head = delPosition_sl(head, position);
			break;
		case 5:
			printAll_sl(head);
			break;
		case 6:
			findMaxHp_sl(head);
			break;
		case 7:
			head = sortByHp_sl(head);
			break;
		case 11:
			break;
		default:
			cout << "잘못된 입력입니다." << endl;
		}
	}
	return 0;
}
champion_bt* Array2LinkedList(champion_bt* head, champion_arr* origin)
{
	for (int i = 0; i < 29; ++i)
	{
		if (origin[i].hp > 0)
		{
			champion_bt* champ = new champion_bt;
			champ->name = origin[i].name;
			champ->hp = origin[i].hp;
			champ->mp = origin[i].mp;
			champ->speed = origin[i].speed;
			champ->range = origin[i].range;
			champ->position = origin[i].position;
			if (head == NULL)
			{
				head = champ;
				champ->left = head;
			}
			else
			{
				champ->left = head->left;
				head->left = champ;
				head = champ;
			}
		}
	}
	return head;
}
void search_sl(champion_bt* head, string name)
{
	champion_bt* champ = nullptr;

	for (champ = head->left; champ != head; champ = champ->left)
	{
		if (name == champ->name)
		{
			cout << "체력: " << champ->hp << endl;
			cout << "마법력: " << champ->mp << endl;
			cout << "이동속도: " << champ->speed << endl;
			cout << "사정거리: " << champ->range << endl;
			cout << "포지션: " << champ->position << endl;
		}
	}
	if (name == head->name)
	{
		cout << "체력: " << head->hp << endl;
		cout << "마법력: " << head->mp << endl;
		cout << "이동속도: " << head->speed << endl;
		cout << "사정거리: " << head->range << endl;
		cout << "포지션: " << head->position << endl;
	}
}
champion_bt* insert_sl(champion_bt* head, string name, int hp, int mp, int speed, int range, string position)
{
	champion_bt* champ = new champion_bt;

	champ->name = name;
	champ->hp = hp;
	champ->mp = mp;
	champ->speed = speed;
	champ->range = range;
	champ->position = position;
	if (head == NULL)
	{
		head = champ;
		champ->left = head;
	}
	else
	{
		if (champ->hp >= head->left->hp)
		{
			champ->left = head->left;
			head->left = champ;
		}
		else if (champ->hp <= head->hp)
		{
			champ->left = head->left;
			head->left = champ;
			head = champ;
		}
		else
		{
			for (champion_bt* i = head->left; i != head; i = i->left)
			{
				if (i->hp >= champ->hp && i->left->hp <= champ->hp)
				{
					champ->left = i->left;
					i->left = champ;
					break;
				}
			}
		}
	}
	return head;
}
champion_bt* delChamp_sl(champion_bt* head, string name)//pre가 가리키는 노드의 다음 노드를 삭제
{
	champion_bt* pre = nullptr;
	champion_bt* i = nullptr;

	if (head == NULL)
		return NULL;
	for (i = head->left; i != head;)
	{
		champion_bt* removed = nullptr;
		if (name == i->name)
		{
			for (pre = i; pre->left != i; pre = pre->left)
			{
			}
			removed = pre->left;
			pre->left = removed->left;
			i = i->left;
			delete removed;
		}
		else
			i = i->left;
	}
	if (name == head->name)
	{
		for (pre = head; pre->left != head; pre = pre->left)
		{
		}
		pre->left = head->left;
		delete head;
		head = pre;
	}
	return head;
}
champion_bt* delPosition_sl(champion_bt* head, string position)
{
	champion_bt* pre = nullptr;
	champion_bt* i = nullptr;

	if (head == NULL)
		return NULL;
	for (i = head->left; i != head;)
	{
		champion_bt* removed = nullptr;
		if (position == i->position)
		{
			for (pre = i; pre->left != i; pre = pre->left)
			{
			}
			removed = pre->left;
			pre->left = removed->left;
			i = i->left;
			delete removed;
		}
		else
			i = i->left;
	}
	if (position == head->position)
	{
		for (pre = head; pre->left != head; pre = pre->left)
		{
		}
		pre->left = head->left;
		delete head;
		head = pre;
	}
	return head;
}
void printAll_sl(champion_bt* head)
{
	champion_bt* champ = nullptr;

	if (head == NULL)
		return;
	for (champ = head->left; champ != head; champ = champ->left)
	{
		cout << "이름: " << champ->name << endl;
		cout << "체력: " << champ->hp << endl;
		cout << "마법력: " << champ->mp << endl;
		cout << "이동속도: " << champ->speed << endl;
		cout << "사정거리: " << champ->range << endl;
		cout << "포지션: " << champ->position << endl << endl;
	}
	cout << "이름: " << champ->name << endl;
	cout << "체력: " << champ->hp << endl;
	cout << "마법력: " << champ->mp << endl;
	cout << "이동속도: " << champ->speed << endl;
	cout << "사정거리: " << champ->range << endl;
	cout << "포지션: " << champ->position << endl << endl << endl;
}
void findMaxHp_sl(champion_bt* head)
{
	int max = 0;
	champion_bt* champ = nullptr;

	for (champ = head->left; champ != head; champ = champ->left)
		if (max < champ->hp)
			max = champ->hp;
	if (max < champ->hp)
		max = champ->hp;
	for (champ = head->left; champ != head; champ = champ->left)
	{
		if (champ->hp == max)
		{
			cout << "이름: " << champ->name << endl;
			cout << "체력: " << champ->hp << endl;
			cout << "마법력: " << champ->mp << endl;
			cout << "이동속도: " << champ->speed << endl;
			cout << "사정거리: " << champ->range << endl;
			cout << "포지션: " << champ->position << endl << endl;
		}
	}
	if (champ->hp == max)
	{
		cout << "이름: " << champ->name << endl;
		cout << "체력: " << champ->hp << endl;
		cout << "마법력: " << champ->mp << endl;
		cout << "이동속도: " << champ->speed << endl;
		cout << "사정거리: " << champ->range << endl;
		cout << "포지션: " << champ->position << endl << endl;
	}
}
champion_bt* sortByHp_sl(champion_bt* head)
{
	champion_bt* champ = nullptr;
	champion_bt* pre = nullptr;
	champion_bt* tmplink2 = nullptr;
	champion_bt* tmplink1 = nullptr;
	for (champion_bt* i = head->left; i != head; i = i->left)
	{
		for (champ = head->left; champ != head; champ = champ->left)
		{
			if (champ->hp < champ->left->hp)
			{
				for (pre = champ; pre->left != champ; pre = pre->left)
				{
				}
				tmplink1 = champ;//누누
				tmplink2 = champ->left;//리신
				champ->left = champ->left->left;//누누->미포
				pre->left = tmplink2;//유미->리신
				tmplink2->left = tmplink1;//리신->누누
				champ = tmplink2;
			}
		}
	}
	for (champ = head->left; champ != head; champ = champ->left)
	{
		if (champ->hp < champ->left->hp)
		{
			for (pre = champ; pre->left != champ; pre = pre->left)
			{
			}
			tmplink1 = champ;//누누
			tmplink2 = champ->left;//리신
			champ->left = champ->left->left;//누누->미포
			pre->left = tmplink2;//유미->리신
			tmplink2->left = tmplink1;//리신->누누
			champ = tmplink2;
		}
	}
	return head;
}
