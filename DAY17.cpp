#include<iostream>


struct Node{
	int val;
	Node *next;
	Node() :next(nullptr){}
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


void DeleteRepeats(LinkList &l)
{	
	for (Node *it = l.head; it->next != NULL; it = it->next)
	{
		if (it->next->val == it->val){
			Node *temp = it->next;
			while (temp->val == it->val)
			{
				it->next = temp->next;
				delete temp;
				temp = it->next;
			}
		}
	}
}



int main()
{
	int arr[] = { 1, 2, 3, 3, 5, 6 };
	LinkList l(arr, 6);
	DeleteRepeats(l);
	for (Node *it = l.head->next; it != NULL; it = it->next)
	{
		std::cout << it->val;
	}
	int c;
	std::cin >> c;
	return 0;
}


