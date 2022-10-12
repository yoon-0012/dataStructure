#include"10�� �ѵ�.h"
champion_bt* Insert_SL(champion_bt* head,int* lengthSl, char position[], char name[], int hp, int attack, int defense)
{
	struct champion_bt* champ = (champion_bt*)malloc(sizeof(struct champion_bt));

	strcpy_s(champ->position, 13, position);
	strcpy_s(champ->name, 13, name);
	champ->hp = hp;
	champ->attack = attack;
	champ->defense = defense;

	if (head == NULL)
	{
		head = champ;
		champ->left = head;
		++*lengthSl;
	}
	else
	{
		champ->left = head->left;
		head->left = champ;
		head = champ;
		++*lengthSl;
	}
	return head;
}
champion_dl* Insert_dl(champion_dl* head2,int* lengthDl, char position[], char name[], int hp, int attack, int defense)
{
	struct champion_dl* champ = (champion_dl*)malloc(sizeof(struct champion_dl));

	strcpy_s(champ->position, 13, position);
	strcpy_s(champ->name, 13, name);
	champ->hp = hp;
	champ->attack = attack;
	champ->defense = defense;

	if (head2 == NULL)
	{
		head2 = champ;
		champ->next = head2;
		champ->pre = head2;
		++*lengthDl;
	}
	else
	{
		champ->next = head2->next;
		head2->next = champ;
		champ->pre = head2;
		champ->next->pre = champ;
		head2 = champ;
		++*lengthDl;
	}
	return head2;
}
void Search_SL(champion_bt* head, char name[])
{
	champion_bt* champ = nullptr;

	for (champ = head->left; champ != head; champ = champ->left)
	{
		if (!strcmp(name, champ->name))
		{
			cout << "������: " << champ->position << endl;
			cout << "ü��: " << champ->hp << endl;
			cout << "���ݷ�: " << champ->attack << endl;
			cout << "����: " << champ->defense << endl << endl;
		}
	}
	if (!strcmp(name, champ->name))
	{
		cout << "������: " << champ->position << endl;
		cout << "ü��: " << champ->hp << endl;
		cout << "���ݷ�: " << champ->attack << endl;
		cout << "����: " << champ->defense << endl << endl;
	}
}
void Search_DL(champion_dl* head2, char name[])
{
	champion_dl* champ = nullptr;

	for (champ = head2->next; champ != head2; champ = champ->next)
	{
		if (!strcmp(name, champ->name))
		{
			cout << "������: " << champ->position << endl;
			cout << "ü��: " << champ->hp << endl;
			cout << "���ݷ�: " << champ->attack << endl;
			cout << "����: " << champ->defense << endl << endl;
		}
	}
	if (!strcmp(name, champ->name))
	{
		cout << "������: " << champ->position << endl;
		cout << "ü��: " << champ->hp << endl;
		cout << "���ݷ�: " << champ->attack << endl;
		cout << "����: " << champ->defense << endl << endl;
	}
}
void PrintAll_SL(champion_bt* head)
{
	champion_bt* champ = nullptr;
	int count = 0;

	for (champ = head->left; champ != head; champ = champ->left)
	{
		if (count % 1000 == 0)
		{
			cout << "������: " << champ->position << endl;
			cout << "�̸�: " << champ->name << endl;
			cout << "ü��: " << champ->hp << endl;
			cout << "���ݷ�: " << champ->attack << endl;
			cout << "����: " << champ->defense << endl << endl;
		}
		++count;
	}
	if (count % 1000 == 0)
	{
		cout << "������: " << champ->position << endl;
		cout << "�̸�: " << champ->name << endl;
		cout << "ü��: " << champ->hp << endl;
		cout << "���ݷ�: " << champ->attack << endl;
		cout << "����: " << champ->defense << endl << endl;
	}
}
void PrintAll_dl(champion_dl* head2)
{
	champion_dl* champ = nullptr;
	int count = 0;

	for (champ = head2->next; champ != head2; champ = champ->next)
	{
		if (count % 1000 == 0)
		{
			cout << "������: " << champ->position << endl;
			cout << "�̸�: " << champ->name << endl;
			cout << "ü��: " << champ->hp << endl;
			cout << "���ݷ�: " << champ->attack << endl;
			cout << "����: " << champ->defense << endl << endl;
		}
		++count;
	}
	if (count % 1000 == 0)
	{
		cout << "������: " << champ->position << endl;
		cout << "�̸�: " << champ->name << endl;
		cout << "ü��: " << champ->hp << endl;
		cout << "���ݷ�: " << champ->attack << endl;
		cout << "����: " << champ->defense << endl << endl;
	}
}
champion_bt* SortByHp_SL(champion_bt* head)
{
	champion_bt* champ = nullptr;
	champion_bt* pre = nullptr;
	champion_bt* tmplink2 = nullptr;
	int check = 1;
	int length = 1;

	for (champion_bt* i = head->left; i != head; i = i->left)
		++length;
	for (;;)
	{
		if (check == length)
			break;
		else
			check = 1;
		for (champ = head->left; champ != head; champ = champ->left)
		{
			if (champ->hp < champ->left->hp)
			{
				for (pre = champ; pre->left != champ; pre = pre->left)
				{
				}
				if (champ->left == head)
					head = champ;
				tmplink2 = champ->left;//����
				champ->left = champ->left->left;//����->����
				tmplink2->left = champ;//����->����
				pre->left = tmplink2;//����->����
				champ = tmplink2;
			}
			else
				++check;
		}
	}
	return head;
}
champion_dl* SortByHp_dl(champion_dl* head2)
{
	champion_dl* champ = nullptr;
	champion_dl* tmplink2 = nullptr;
	int check = 1;
	int length = 1;

	for (champion_dl* i = head2->next; i != head2; i = i->next)
		++length;
	for (;;)
	{
		if (check == length)
			break;
		else
			check = 1;
		for (champ = head2->next; champ != head2; champ = champ->next)
		{
			if (champ->hp < champ->next->hp)
			{
				if (champ->next == head2)
					head2 = champ;
				tmplink2 = champ->next;//����
				champ->next = champ->next->next;//����->����
				tmplink2->next->pre = champ;//����p->����
				tmplink2->next = champ;//����->����
				champ->pre->next = tmplink2;//����->����
				tmplink2->pre = champ->pre;//����p->����
				champ->pre = tmplink2;//����p->����
				champ = tmplink2;
			}
			else
				++check;
		}
	}
	return head2;
}
