#include<iostream>
using namespace std;

typedef int element;
typedef struct champion_bt
{
	element data;
	struct champion_bt* left;
}champion;

void print_list(champion_bt* head);
champion_bt* insert_first(champion_bt* head, element data);
champion_bt* insert_sl(champion_bt* head, element data);
int main()
{
	champion_bt* head = NULL;

	//list = 10->20->30->40
	head = insert_sl(head, 20);
	head = insert_sl(head, 30);
	head = insert_sl(head, 40);
	head = insert_first(head, 10);
	print_list(head);
	return 0;
}
void print_list(champion_bt* head)
{
	champion_bt* p;

	if (head == NULL)	return;
	p = head->left;
	do
	{
		cout << p->data << "->";
		p = p->left;
	} while (p != head);
	cout << p->data << "->";
}
champion_bt* insert_first(champion_bt* head, element data)
{
	champion_bt* node = new champion_bt;
	node->data = data;
	if (head == NULL)
	{
		head = node;
		node->left = head;
	}
	else
	{
		node->left = head->left;
		head->left = node;
	}
	return head;
}
champion_bt* insert_sl(champion_bt* head, element data)
{
	champion_bt* node = new champion_bt;
	node->data = data;
	if (head == NULL)
	{
		head = node;
		node->left = head;
	}
	else
	{
		node->left = head->left;
		head->left = node;
		head = node;
	}
	return head;
}
