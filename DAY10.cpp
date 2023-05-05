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
	for (int i = 0; i < n; ++i)
	{
		Node *temp = new Node(arr[n-i-1]);
		temp->next = head->next;
		head->next = temp;
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
