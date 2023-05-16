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


LinkList generateList(LinkList l1, LinkList l2)
{
	Node *it1 = l1.head->next;
	Node *it2 = l2.head->next;
	int arr[10] = {};
	int i = 0;
	while (it1 != NULL&&it2 != NULL)
	{
		while (it1->val<it2->val)
		{
			it1 = it1->next;
		}
		while (it2->val<it1->val)
		{
			it2 = it2->next;
		}
		if (it1->val == it2->val){
			arr[i++] = it1->val;
			it1 = it1->next;
			it2 = it2->next;
		}
	}
	int n = i;
	static LinkList l3(arr,n);
	return l3;
}



int main()
{
	int arr[] = { 1, 3,5};
	int arr1[] = { 1,2, 4, 5,6 };
	LinkList l1(arr, 3);
	LinkList l2(arr1, 5);
	LinkList l3 = generateList(l1, l2);
	for (Node *it = l3.head->next; it != NULL; it = it->next)
	{
		std::cout << it->val << " ";
	}
	int c;
	std::cin >> c;
	return 0;
}

