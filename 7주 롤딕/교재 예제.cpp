#include<iostream>
#include<cstdio>
using namespace std;

typedef int element;
typedef struct champion_bt
{
	element data;
	class champion_bt* left;
}champion;
void error(char*);//오류 처리 함수
champion_bt* insert_first(champion_bt* head, int value);
champion_bt* insert(champion_bt* head, champion_bt* pre, element value);//노드 pre 뒤에 새로운 노드 삽입
champion_bt* delete_first(champion_bt* head);
champion_bt* delChamp_sl(champion_bt* head, champion_bt* pre);//pre가 가리키는 노드의 다음 노드를 삭제
void print_list(champion_bt* head);
int main()
{
	champion_bt* head = NULL;

	for (int i = 0; i < 5; ++i)
	{
		head = insert_first(head, i);//insert_first()가 반환된 헤드 포인터를 head에 대입
		print_list(head);
	}
	for (int i = 0; i < 5; ++i)
	{
		head = delete_first(head);
		print_list(head);
	}
	return 0;
}
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
champion_bt* insert_first(champion_bt* head, int value)
{
	champion_bt* p = new champion_bt;
	p->data = value;
	p->left = head;
	head = p;
	return head;
}
champion_bt* insert(champion_bt* head, champion_bt* pre, element value)//노드 pre 뒤에 새로운 노드 삽입
{
	champion_bt* p = new champion_bt;
	p->data = value;
	p->left = pre->left;
	pre->left = p;
	return head;
}
champion_bt* delete_first(champion_bt* head)
{
	champion_bt* removed;
	if (head == NULL)return NULL;
	removed = head;
	head = removed->left;
	delete removed;
	return head;
}
champion_bt* delChamp_sl(champion_bt* head, champion_bt* pre)//pre가 가리키는 노드의 다음 노드를 삭제
{
	champion_bt* removed;
	removed = pre->left;
	pre->left = removed->left;
	delete removed;
	return head;
}
void print_list(champion_bt* head)
{
	for (champion_bt* p = head; p != NULL; p = p->left)
		cout << p->data << "->";
	cout << "NULL " << endl;
}
