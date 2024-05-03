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
		cout << "输入一个数字:(0结束)";
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
		cout << "位置错误" << endl;
		return NULL;
	}
	if (pos == 0)
	{
		return head;
	}
	if (p == NULL)
	{
		cout << "链表为空" << endl;
		return NULL;
	}
	while (--pos)
	{
		if ((p = p->next) == NULL)
		{
			cout << "超出链表范围" << endl;
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
		cout << "插入失败" << endl;
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
		cout << "单链表为空" << endl;
		return;
	}
	node* p;
	p = head->next;
	while (p != NULL)
	{
		cout << "第" << ++index << "个节点是:" << p->data << endl;
		p = p->next;
	}
}

node* delete_node(node* head, int pos)
{
	node* p = search_node(head, pos-1);
	if (p == NULL || p->next == NULL)
	{
		cout << "删除失败" << endl;
		return head;
	}
	node* q = p->next;
	p->next = p->next->next;
	delete q;
	return head;
}

int main()
{
	node* head = create();							//创建单链表
	cout << "链表长度:" << length(head) << endl;		//测量单链表长度
	cout << "在第二个节点之后插入5" << endl;
	head = insert_node(head, 2, 5);					//在第二个节点之后插入5
	print(head);									//打印单链表
	cout << "删除第二个节点" << endl;
	head = delete_node(head, 2);					//删除第二个节点
	print(head);
	return 0;
}