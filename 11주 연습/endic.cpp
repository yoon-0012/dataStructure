#include<iostream>
using namespace std;
#include<cstdio>
#include<cstdlib>
#include<string>
#include<memory>

#define MAX_WORD_SIZE 100
#define MAX_MEANING_SIZE 200

//������ ����
class element
{
public:
	char word[MAX_WORD_SIZE];
	char meaning[MAX_MEANING_SIZE];
};
//����� ����
class TreeNode
{
public:
	element key;
	TreeNode* left, * right;
};

//���� e1<e2�̸� -1��ȯ
//���� e1==e2�̸� 0��ȯ
//���� e1>e2�̸� 1��ȯ
int compare(element e1, element e2)
{
	return strcmp(e1.word, e2.word);
}
//���� Ž�� Ʈ�� ��� �Լ�
void display(TreeNode* p)
{
	if (p != NULL)
		cout << "(";
	display(p->left);
	cout << p->key.word << ":" << p->key.meaning;
	display(p->right);
	cout << ")";
}

//���� Ž�� Ʈ�� Ž�� �Լ�
TreeNode* search(TreeNode* root, element key)
{
	TreeNode* p = root;
	while (p != NULL)
	{
		if (compare(key, p->key) == 0)
			return p;
		else if (compare(key, p->key) < 0)
			p = p->left;
		else if (compare(key, p->key) > 0)
			p = p->right;
	}
	return p;//Ž���� �������� ��� NULL��ȯ
}
TreeNode* new_node(element item)
{
	TreeNode* temp = new TreeNode;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
TreeNode* insert_node(TreeNode* node, element key)
{
	//Ʈ���� �����̸� ���ο� ��带 ��ȯ�Ѵ�.
	if (node == NULL)
		return new_node(key);

	//�׷��� ������ ��ȯ������ Ʈ���� ��������.
	if (compare(key, node->key) < 0)
		node->left = insert_node(node->left, key);
	else if (compare(key, node->key) > 0)
		node->right = insert_node(node->right, key);
	//��Ʈ �����͸� ��ȯ�Ѵ�.
	return node;
}
TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;
	//�� ���� �ܸ� ��带 ã���� ������
	while (current->left != NULL)
		current = current->left;
	return current;
}

//���� Ž�� Ʈ���� Ű�� �־����� Ű�� ����� ��带 �����ϰ� ���ο� ��Ʈ ��带 ��ȯ�Ѵ�.
TreeNode* delete_node(TreeNode* root, element key)
{
	if (root == NULL)
		return root;
	//���� Ű�� ��Ʈ���� ������ ���� ���� Ʈ���� �ִ� ����
	if (compare(key, root->key) < 0)
		root->left = delete_node(root->left, key);
	//���� Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ���� �ִ� ����
	if (compare(key, root->key) > 0)
		root->right = delete_node(root->right, key);
	//Ű�� ��Ʈ�� ������ �� ��带 �����ϸ� ��
	else
	{
		//ù ��°�� �� ��° ���
		if (root->left == NULL)
		{
			TreeNode* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL)
		{
			TreeNode* temp = root->left;
			delete root;
			return temp;
		}
		//�� ��° ���
		TreeNode* temp = min_value_node(root->right);

		//���� ��ȸ�� �İ� ��带 �����Ѵ�.
		root->key = temp->key;
		//���� ��ȸ�� �İ� ��带 �����Ѵ�.
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}
void help()
{
	cout << endl << "**** i: �Է�, d: ����, s: Ž��, p: ���, q: ���� ****";
}

//���� Ž�� Ʈ���� ����ϴ� ���� ���� ���α׷�
int main()
{
	char command;
	element e;
	TreeNode* root = NULL;
	TreeNode* tmp;

	do
	{
		help();
		command = getchar();
		getchar();//����Ű ����
		switch(command)
		{
		case 'i':
			cout << "�ܾ�:";
			gets_s(e.word);
			cout << "�ǹ�:";
			gets_s(e.meaning);
			root = insert_node(root, e);
			break;
		case 'd':
			cout << "�ܾ�:";
			gets_s(e.word);
			root = delete_node(root, e);
			break;
		case 'p':
			display(root);
			cout << endl;
			break;
		case 's':
			cout << "�ܾ�:";
			gets_s(e.word);
			tmp = search(root, e);
			if (tmp != NULL)
				cout << "�ǹ�:" << e.meaning << endl;
			break;
		}
	} while (command != 'q');
	return 0;
}