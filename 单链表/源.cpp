#include <iostream>

using namespace std;

typedef struct node {
	node* next;
	int data;
}node;

node* create()
{
	node* head, * p, * q;
	head = new node;
	q = new node;
	head->next = NULL;
	int data;
	while (1)
	{
		cout << "����һ������:(0����)";
		cin >> data;
		if (data == 0)
		{
			break;
		}
		p = new node;
		p->data = data;
		if (head->next == NULL)
		{
			head->next = p;
		}
		else
		{
			q->next = p;
		}
		q = p;
	}
	q->next = NULL;
	return head;
}

int length(node* head)
{
	int index = 0;
	node* p;
	p = head->next;
	while (p != NULL)
	{
		index++;
		p = p->next;
	}
	return index;
}

node* search_node(node* head, int pos)
{
	node* p = head->next;
	if (pos < 0)
	{
		cout << "λ�ô���" << endl;
		return NULL;
	}
	if (pos == 0)
	{
		return head;
	}
	if (p == NULL)
	{
		cout << "����Ϊ��" << endl;
		return NULL;
	}
	while (--pos)
	{
		if ((p = p->next) == NULL)
		{
			cout << "��������Χ" << endl;
			return NULL;
		}
	}
	return p;
}

node* insert_node(node* head, int pos, int num)
{
	node *p = search_node(head,pos);
	if (p == NULL)
	{
		cout << "����ʧ��" << endl;
		return head;
	}
	node* q = new node;
	q->data = num;
	q->next = p->next;
	p->next = q;
	return head;
}

void print(node* head)
{
	int index = 0;
	if (head->next == NULL)
	{
		cout << "������Ϊ��" << endl;
		return;
	}
	node* p;
	p = head->next;
	while (p != NULL)
	{
		cout << "��" << ++index << "���ڵ���:" << p->data << endl;
		p = p->next;
	}
}

node* delete_node(node* head, int pos)
{
	node* p = search_node(head, pos-1);
	if (p == NULL || p->next == NULL)
	{
		cout << "ɾ��ʧ��" << endl;
		return head;
	}
	node* q = p->next;
	p->next = p->next->next;
	delete q;
	return head;
}

int main()
{
	node* head = create();							//����������
	cout << "������:" << length(head) << endl;		//������������
	cout << "�ڵڶ����ڵ�֮�����5" << endl;
	head = insert_node(head, 2, 5);					//�ڵڶ����ڵ�֮�����5
	print(head);									//��ӡ������
	cout << "ɾ���ڶ����ڵ�" << endl;
	head = delete_node(head, 2);					//ɾ���ڶ����ڵ�
	print(head);
	return 0;
}