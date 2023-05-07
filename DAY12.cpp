#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node* next;
	Node(){}
	Node(int n):data(n){}
};

class LinkList
{
private:
	void insert_rear(int arr[],int n);
public:
Node* head;

	void reverse_list();
	void reverse_list(Node *cur,Node *pre);
	LinkList(int arr[],int n)
	{
		head = new Node();
		head->next = NULL;
		insert_rear(arr,n);
	}
	~LinkList()
	{
		Node *temp = head;
		while (head)
		{
			head = head->next;
			delete temp;
			temp = head;
		}
	}
};

void LinkList::insert_rear(int arr[],int n)
{
	Node *rear = head;
	Node *temp;
	for (int i = 0; i < n; ++i)
	{
		temp = new Node(arr[i]);
		rear->next = temp;
		rear = temp;
		rear->next = nullptr;
	}
}
//反转链表的双指针写法
void LinkList::reverse_list()
{
	Node *cur = head->next;
	Node *next = cur->next;
	Node *temp;
	cur->next = NULL;
	while (next)
	{
		temp = next->next;
		next->next = cur;
		cur = next;
		next = temp;
	}
	head = cur;
}

//递归的写法
void LinkList::reverse_list(Node *cur,Node *pre)
{
	if (cur == NULL){
		return;
	}
	if (cur->next == NULL){
		head->next->next = NULL;
		Node *temp = head;
		head = cur;
		delete temp;
	}
	reverse_list(cur->next,cur);
	cur->next = pre;
}


int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	LinkList l(arr, 5);
	l.reverse_list(l.head->next->next, l.head->next);
	int c;
	cin >> c;
	return 0;
}
