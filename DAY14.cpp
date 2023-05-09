#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node* next;
	Node(){}
	Node(int n) :data(n){}
};

class LinkList
{
private:
	void insert_rear(int arr[], int n);
public:
	Node* head;

	void reverse_list();
	void reverse_list(Node *cur, Node *pre);
	void deleteNode(int begin, int end);
	Node *getSameNode(Node *ahead);
	LinkList(int arr[], int n)
	{
		head = new Node();
		head->next = NULL;
		insert_rear(arr, n);
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

void LinkList::insert_rear(int arr[], int n)
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
void LinkList::reverse_list(Node *cur, Node *pre)
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
	reverse_list(cur->next, cur);
	cur->next = pre;
}

Node *LinkList::getSameNode(Node *ahead)
{
	if (head == ahead){
		return head;
	}
	for (Node *temp = head; temp != nullptr; temp = temp->next)
	{
		for (Node *it = ahead; it != nullptr; it = it->next)
		{
			if (temp->next == it->next){
				return it->next;
			}
		}
	}
	return NULL;
}

void LinkList::deleteNode(int begin, int end)
{
	Node *cur = head->next;
	Node *pre = head;
	while (cur)
	{
		if (cur->data > begin&&cur->data < end){
			Node *temp = cur;
			cur = cur->next;
			delete temp;
			pre->next = cur;
		}
		cur = cur->next;
		pre = pre->next;
	}
}

int main()
{
	int arr[] = { 3, 4, 5, 2, 1 };
	LinkList l(arr, 5);
	cout<<l.getSameNode(l.head->next->next)->data;
	int c;
	cin >> c;
	return 0;
}
