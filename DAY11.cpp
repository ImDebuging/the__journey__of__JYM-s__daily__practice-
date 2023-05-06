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
	Node* head;
	void insert_head(int arr[],int n);
public:
	LinkList(int arr[],int n)
	{
		head = new Node();
		head->next = NULL;
		insert_head(arr,n);
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

void LinkList::insert_head(int arr[],int n)
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

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	LinkList l(arr, 5);
	int c;
	cin >> c;
	return 0;
}
