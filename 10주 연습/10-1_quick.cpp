//13 17까지 12 54종료 통과
#include<iostream>
#include<fstream>
#include<time.h>
using namespace std;
class champion_bt
{
public:
	string position;
	string name;
	int hp;
	int attack;
	int defense;
	champion_bt* left;
};
class champion_dl
{
public:
	string position;
	string name;
	int hp;
	int attack;
	int defense;
	champion_dl* pre;
	champion_dl* next;
};
champion_bt* insert_sl(champion_bt* head, string position, string name, int hp, int attack, int defense);
champion_dl* insert_dl(champion_dl* head2, string position, string name, int hp, int attack, int defense);
void findTarget_sl(champion_bt* head, string name);
void findTarget_dl(champion_dl* head2, string name);
void printAll_sl(champion_bt* head);
void printAll_dl(champion_dl* head2);
champion_bt* sortByHp_sl(champion_bt* head);
champion_dl* sortByHp_dl(champion_dl* head2);
int main()
{
	ifstream fileSl("LOLDic.txt");
	ifstream fileDl("LOLDic.txt");
	string position, name;
	int hp, attack, defense;
	int choose = 0;
	champion_bt* head = nullptr;
	champion_dl* head2 = nullptr;
	clock_t start, end;
	double result = 0;

	if (fileSl.is_open())
	{
		//for (int i = 0; !lolDic.eof(); ++i)
		for (int i = 0; i < 1000; ++i)
		{
			fileSl >> position >> name >> hp >> attack >> defense;
			head = insert_sl(head, position, name, hp, attack, defense);
		}
		fileSl.close();
	}
	if (fileDl.is_open())
	{
		for (int i = 0; i < 1000; ++i)
		{
			fileDl >> position >> name >> hp >> attack >> defense;
			head2 = insert_dl(head2, position, name, hp, attack, defense);
		}
		fileDl.close();
	}

	while (choose != 11)
	{
		cout << endl << endl << "1. findTarget_sl" << endl;
		cout << "2. printAll_sl" << endl;
		cout << "3. sortByHp_sl" << endl;
		cout << "4. findTarget_dl" << endl;
		cout << "5. printAll_dl" << endl;
		cout << "6. sortByHp_dl" << endl;
		cout << "11. 종료" << endl;
		cout << "choose: ";
		if (!(cin >> choose))
		{
			cin.clear();
			cin.ignore(5, '\n');
		}
		switch (choose)
		{
		case 1:
			cout << "이름: ";
			cin >> name;
			start = clock();
			findTarget_sl(head, name);
			end = clock();
			result = (double)(end - start);
			cout << "findTarget_sl: " << result << endl;
			break;
		case 2:
			start = clock();
			printAll_sl(head);
			end = clock();
			result = (double)(end - start);
			cout << "printAll_sl: " << result << endl;
			break;
		case 3:
			start = clock();
			head = sortByHp_sl(head);
			end = clock();
			result = (double)(end - start);
			cout << "sortByHp_sl: " << result << endl;
			break;
		case 4:
			cout << "이름: ";
			cin >> name;
			start = clock();
			findTarget_dl(head2, name);
			end = clock();
			result = (double)(end - start);
			cout << "findTarget_dl: " << result << endl;
			break;
		case 5:
			start = clock();
			printAll_dl(head2);
			end = clock();
			result = (double)(end - start);
			cout << "printAll_dl: " << result << endl;
			break;
		case 6:
			start = clock();
			head2 = sortByHp_dl(head2);
			end = clock();
			result = (double)(end - start);
			cout << "sortByHp_dl: " << result << endl;
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
champion_bt* insert_sl(champion_bt* head, string position, string name, int hp, int attack, int defense)
{
	champion_bt* champ = new champion_bt;

	champ->position = position;
	champ->name = name;
	champ->hp = hp;
	champ->attack = attack;
	champ->defense = defense;
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
	return head;
}
champion_dl* insert_dl(champion_dl* head2, string position, string name, int hp, int attack, int defense)
{
	champion_dl* champ = new champion_dl;

	champ->position = position;
	champ->name = name;
	champ->hp = hp;
	champ->attack = attack;
	champ->defense = defense;
	if (head2 == NULL)
	{
		head2 = champ;
		champ->next = head2;
		champ->pre = head2;
	}
	else
	{
		champ->next = head2->next;
		champ->next->pre = champ;
		head2->next = champ;
		champ->pre = head2;
		head2 = champ;
	}
	return head2;
}
void findTarget_sl(champion_bt* head, string name)
{
	champion_bt* champ = nullptr;

	for (champ = head->left; champ != head; champ = champ->left)
	{
		if (champ->name == name)
		{
			cout << "포지션: " << champ->position << endl;
			cout << "체력: " << champ->hp << endl;
			cout << "공격력: " << champ->attack << endl;
			cout << "방어력: " << champ->defense << endl << endl;
		}
	}
	if (champ->name == name)
	{
		cout << "포지션: " << champ->position << endl;
		cout << "체력: " << champ->hp << endl;
		cout << "공격력: " << champ->attack << endl;
		cout << "방어력: " << champ->defense << endl << endl;
	}
}
void findTarget_dl(champion_dl* head2, string name)
{
	champion_dl* champ = nullptr;

	for (champ = head2->next; champ != head2; champ = champ->next)
	{
		if (champ->name == name)
		{
			cout << "포지션: " << champ->position << endl;
			cout << "체력: " << champ->hp << endl;
			cout << "공격력: " << champ->attack << endl;
			cout << "방어력: " << champ->defense << endl << endl;
		}
	}
	if (champ->name == name)
	{
		cout << "포지션: " << champ->position << endl;
		cout << "체력: " << champ->hp << endl;
		cout << "공격력: " << champ->attack << endl;
		cout << "방어력: " << champ->defense << endl << endl;
	}
}
void printAll_sl(champion_bt* head)
{
	champion_bt* champ = nullptr;

	for (champ = head->left; champ != head; champ = champ->left)
	{
		cout << "포지션: " << champ->position << endl;
		cout << "이름: " << champ->name << endl;
		cout << "체력: " << champ->hp << endl;
		cout << "공격력: " << champ->attack << endl;
		cout << "방어력: " << champ->defense << endl << endl;
	}
	cout << "포지션: " << champ->position << endl;
	cout << "이름: " << champ->name << endl;
	cout << "체력: " << champ->hp << endl;
	cout << "공격력: " << champ->attack << endl;
	cout << "방어력: " << champ->defense << endl << endl;
}
void printAll_dl(champion_dl* head2)
{
	champion_dl* champ = nullptr;

	for (champ = head2->next; champ != head2; champ = champ->next)
	{
		cout << "포지션: " << champ->position << endl;
		cout << "이름: " << champ->name << endl;
		cout << "체력: " << champ->hp << endl;
		cout << "공격력: " << champ->attack << endl;
		cout << "방어력: " << champ->defense << endl << endl;
	}
	cout << "포지션: " << champ->position << endl;
	cout << "이름: " << champ->name << endl;
	cout << "체력: " << champ->hp << endl;
	cout << "공격력: " << champ->attack << endl;
	cout << "방어력: " << champ->defense << endl << endl;
}
champion_bt* sortByHp_sl(champion_bt* head)
{
	champion_bt* pre = nullptr;
	champion_bt* tmplink2 = nullptr;
	int length = 1;
	int check = 1;

	for (champion_bt* count = head->left; count != head; count = count->left)
		++length;
	for (;;)
	{
		if (length == check)
			break;
		else
			check = 1;
		for (champion_bt* champ = head->left; champ != head; champ = champ->left)
		{
			if (champ->hp < champ->left->hp)
			{
				for (pre = champ; pre->left != champ; pre = pre->left)
				{
				}
				if (champ->left == head)
					head = champ;
				tmplink2 = champ->left;
				champ->left = champ->left->left;//누누->미포
				tmplink2->left = champ;//리신->누누
				pre->left = tmplink2;//유미->리신
				champ = tmplink2;
			}
			else
				++check;
		}
	}
	return head;
}
void swap(champion_dl* node1, champion_dl* node2)
{
	champion_dl* tmp = nullptr;

	tmp = node1;
	node1 = node2;
	node2 = tmp;
}
void quickSort(int left, int right, champion_dl* head2)
{
	int pivot = left;
	int j = pivot;
	int i = left + 1;
	champion_dl* champI = head2->next;
	champion_dl* champPivot = head2->next;
	champion_dl* champJ = head2->next;
	
	if (left < right)
	{
		for (; i <= right; ++i)
		{
			for (int count = 0; count < i; ++count)
				champI = champI->next;
			for (int count = 0; count < pivot; ++count)
				champPivot= champPivot->next;
			for (int count = 0; count < j; ++count)
				champJ = champJ->next;
			if (champI->hp < champPivot->hp)
			{
				++j;
				swap(champJ, champI);
			}
		}
		swap(champI->pre, champJ);
		pivot = j;

		quickSort(left, pivot - 1, head2);
		quickSort(pivot+1, right, head2);
	}
}
champion_dl* sortByHp_dl(champion_dl* head2)
{
	champion_dl* tmplink2 = nullptr;
	int length = 1;
	int check = 1;
	
	for (champion_dl* count = head2->next; count != head2; count = count->next)
		++length;
	for (;;)
	{
		if (length == check)
			break;
		else
			check = 1;
		for (champion_dl* champ = head2->next; champ != head2; champ = champ->next)
		{
			if (champ->hp < champ->next->hp)
			{
				if (champ->next == head2)
					head2 = champ;
				tmplink2 = champ->next;
				champ->next = champ->next->next;//누누->미포
				tmplink2->next->pre = champ;//미포p->누누
				tmplink2->next = champ;//리신->누누
				champ->pre->next = tmplink2;//유미->리신
				tmplink2->pre = champ->pre;//리신p->유미
				champ->pre = tmplink2;//누누p->리신
				champ = tmplink2;
			}
			else
				++check;
		}
	}
	return head2;
}
