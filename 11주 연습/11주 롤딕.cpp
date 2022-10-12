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
	int hp;//ü��
	int mp;//������
	int speed;//�̵��ӵ�
	int range;//��Ÿ�
	string position;//ž �̵� ��
};
struct champion_bt
{
	string name;
	int hp;//ü��
	int mp;//������
	int speed;//�̵��ӵ�
	int range;//��Ÿ�
	string position;//ž �̵� ��
	struct champion_bt* left,*right;
};
champion_bt* search_bt(champion_bt* champ, string name);
champion_bt* insert_bt(champion_bt* champ, string name, int hp, int mp, int speed, int range, string position);
champion_bt* delete_bt(champion_bt* root, string name);

int main()
{
	champion_arr origin[40] = { {"�����Ϳ�����" , 540,32,340, 125, "����"},
		{"����" , 575 , 32 , 345 , 125 , "����" },
		{"�̽�����" , 570 , 30 , 325 , 550 , "����" },
		{ "�����" , 530 , 30 , 325 , 550 , "����"},{" " },
		{ "������" , 575 , 32 , 345 , 125, "ž"},
		{ "������" , 561 ,32,350,125, "ž"},
		{ "������",  520,  30, 340,  525, "����" },{" "},{ " "},{ " "},{" "},
		{"����", 620, 32, 340,175, "ž"},
		{ "����", 560,  32,  345,  125, "ž"   },
		{ "����ũ��ũ", 583, 32,325, 125, "����"},
		{ "���׿�", 579, 28,  345,  150,  "�̵�"},
		{"����",515, 30, 330, 550, "����"},
		{"������",560,30, 335, 450,"����"},
		{ "�ƹ���",615, 32, 335,  125,  "����"},
		{ "�ֽ�",  539, 30, 325,  600, "����"},
		{ "�𸣰���",559,  30,  335, 450,  "����"},{ " "},
		{ "�Ƹ�",  526, 30,  330,  550, "�̵�"},{ " "},{ " "},
		{ "��Į��",  575,  37,  345,  125,  "�̵�" },
		{ "�̺�",620, 32, 335, 125, "����"},{ " "},
		{"����",  480,  25, 330,  500,  "����"},
		{ " "},{" "},{ " "},{ " "},{ " "},{ " "},
		{ " "},{ " "},{ " "},{ " "},{ " "} };
	//���� �̺� 620
	//����4 �̵�3 ����4 ž4 ����5
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
		cout << "3. Delete [ è�Ǿ� �̸� ]" << endl;
		cout << "4. DeleteAll [ position ]" << endl;
		cout << "5. PrintAll" << endl;
		cout << "6. FindMaxHp" << endl;
		cout << "7. SortByHp" << endl;
		cout << "11. ����" << endl;

		if (!(cin >> choose))
		{
			cin.clear();
			cin.ignore(5, '\n');
			cout << "�߸��� �Է��Դϴ�." << endl;
			break;
		}
		switch (choose)
		{
		case 1:
			cout << "�̸�: ";
			cin >> name;
			search_bt(champ,name);
			break;
		case 2:
			cout << "�̸�: ";
			cin >> name;
			cout << "ü��: ";
			cin >> hp;
			cout << "������: ";
			cin >> mp;
			cout << "�̵��ӵ�: ";
			cin >> speed;
			cout << "�����Ÿ�: ";
			cin >> range;
			cout << "������: ";
			cin >> position;
			head = insert_bt(champ, name, hp, mp, speed,range,position);
			break;
		case 3:
			cout << "�̸�: ";
			cin >> name;
			head = delete_bt(root, name);
			break;
		case 4:
			cout << "������ : ";
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
			cout << "�߸��� �Է��Դϴ�." << endl;
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
