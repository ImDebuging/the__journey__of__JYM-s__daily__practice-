#include<iostream>


struct Node{
	int val;
	Node *next;
	Node():next(nullptr){}
	Node(int n) :val(n){}
};

class LinkList{
private:
	void insert_rear(int arr[], int n);
public:
	Node *head;
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

Node* divideList(Node *&head)
{
	Node *new_head = new Node;
	Node *iter = head->next;
	Node *iter_1 = new_head;
	while (iter!= nullptr)
	{
		iter_1->next = iter->next;
		iter_1 = iter_1->next;
		iter->next = iter_1->next;
		iter = iter_1->next;
	}
	return new_head;
}


int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	LinkList l(arr,6);
	std::cout << divideList(l.head)->next->val;
	int c;
	std::cin >> c;
	return 0;
}



