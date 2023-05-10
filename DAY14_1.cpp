#include<iostream>
#include<algorithm>
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
	int length(Node *head);
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

int LinkList::length(Node *head)
{
	int ret=0;
	for (Node *temp = head->next; temp != nullptr; temp = temp->next,ret++)
	{

	}
	return ret;
}

Node *LinkList::getSameNode(Node *ahead)
{
	Node *ret = NULL;
	Node *temp1 = head->next;
	Node *temp2 = ahead->next;
	if (this->length(ahead)==this->length(head))
	{		
		while (temp1 != temp2&&temp1 != NULL&&temp2 != NULL)
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		if (temp1 == temp2){
			ret = temp1;
		}
	}
	else{
		int difference = this->length(head) > this->length(ahead) ? this->length(head) - this->length(ahead) : this->length(ahead) - this->length(head);
		bool bigger = this->length(head) > this->length(ahead);
		if (bigger){
			for (; difference > 0; difference--)
			{
				temp1 = temp1->next;
			}
		}		
		else{
			for (; difference > 0; difference--)
			{
				temp2 = temp2->next;
			}
		}
		while (temp1 != temp2&&temp1 != NULL&&temp2 != NULL)
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		if (temp1 == temp2){
			ret = temp1;
		}
	}
	return ret;
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
	int arr[] = { 3, 4, 5 };
	LinkList l1(arr, 3);
	LinkList l2(arr, 2);
	l2.head->next->next->next = l1.head->next->next->next;
	cout<<l1.getSameNode(l2.head)->data;
	int c;
	cin >> c;
	return 0;
}
