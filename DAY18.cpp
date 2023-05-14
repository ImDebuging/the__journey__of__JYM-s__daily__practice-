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


void mergeLinklist(LinkList &l1, LinkList &l2)
{
	Node *it1 = l1.head->next;
	Node *it2 = l2.head->next;
	l2.head->next = NULL;
	Node *rear = NULL;
	Node *temp;
	while (true)
	{
		if (it1 == NULL&&it2 == NULL){
			break;
		}
		if (it1 == NULL&&it2 != NULL){
			temp = it2;
			it2 = it2->next;
			temp->next = rear;
			rear = temp;
		}
		if (it2 == NULL&&it1 != NULL){
			temp = it1;
			it1 = it1->next;
			temp->next = rear;
			rear = temp;
		}
		if (it1 != NULL&&it2 != NULL&&it1->val < it2->val){
			temp = it1;
			it1 = it1->next;
			temp->next = rear;
			rear = temp;
		}
		else if (it1 != NULL&&it2 != NULL&&it1->val >= it2->val){
			temp = it2;
			it2 = it2->next;
			temp->next = rear;
			rear = temp;
		}
	}
	l1.head->next = rear;
}




int main()
{
	int arr[] = { 1, 3,5};
	int arr1[] = { 2, 4, 6 };
	LinkList l1(arr, 3);
	LinkList l2(arr1, 3);
	mergeLinklist(l1, l2);
	for (Node *it = l1.head->next; it != NULL; it = it->next)
	{
		std::cout << it->val;
	}
	int c;
	std::cin >> c;
	return 0;
}

