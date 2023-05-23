#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next, *before;
};

bool isSymmetric(Node *head)
{
	Node *p = head->before, *q = head->next;
	while (p != q&&q->next != p)
	{
		if (p->data == q->data){
			p = p->before;
			q = q->next;
		}
		else{
			return false;
		}
	}
	return true;
}

int main()
{
	Node *head = new Node;
	Node *a = new Node;
	Node *a1 = new Node;
	a->data = 1;
	a1->data = 1;
	head->before = a1;
	head->next = a;
	if (isSymmetric(head)){
		cout << "TRUE";
	}
	else{
		cout << "FALSE";
	}
	int c;
	cin >> c;
	return 0;
}
