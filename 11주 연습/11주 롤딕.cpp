#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<cstdio>
#include <cstdlib>
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
	struct champion_bt* left,*right;
};
champion_bt* search_bt(champion_bt* champ, string name);
champion_bt* insert_bt(champion_bt* champ, string name, int hp, int mp, int speed, int range, string position);
champion_bt* delete_bt(champion_bt* root, string name);

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
			search_bt(champ,name);
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
			head = insert_bt(champ, name, hp, mp, speed,range,position);
			break;
		case 3:
			cout << "이름: ";
			cin >> name;
			head = delete_bt(root, name);
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

champion_bt* search_bt(champion_bt* champ, string name)
{
	while (champ != NULL)
	{
		if (name == champ->name)
			return champ;
		else if (name < champ->name)
			champ = champ->left;
		else
			champ = champ->right;
	}
	return NULL;
}
champion_bt* new_node(string name,int hp,int mp,int speed,int range,string position)
{
	champion_bt* temp = new champion_bt;
	temp->name = name;
	temp->hp = hp;
	temp->mp = mp;
	temp->speed =speed;
	temp->range = range;
	temp->position = position;
	temp->left = temp->right = NULL;
	return temp;
}
champion_bt* insert_bt(champion_bt* champ,string name, int hp, int mp, int speed, int range, string position)
{
	if (champ == NULL)
		return new_node(name,hp,mp,speed,range,position);
	
	if (name < champ->name)
		champ->left = insert_bt(champ->left, name,hp,mp,speed,range,position);
	else if (name > champ->name)
		champ->right = insert_bt(champ->right, name, hp, mp, speed, range, position);

	return champ;
}
champion_bt* min_value_node(champion_bt* node)
{
	champion_bt* current = node;

	while (current->left != NULL)
		current = current->left;

	return current;
}
champion_bt* delete_bt(champion_bt* root, string name)
{
	if (root == NULL)
		return root;

	if (name< root->name)
		root->left = delete_bt(root->left, name);
	else if (name > root->name)
		root->right = delete_bt(root->right,name);
	else
	{
		if (root->left == NULL)
		{
			champion_bt* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL)
		{
			champion_bt* temp = root->left;
			delete root;
			return temp;
		}
		champion_bt* temp = min_value_node(root->right);

		root->name = temp->name;

		root->right = delete_bt(root->right, temp->name);
	}
	return root;
}
