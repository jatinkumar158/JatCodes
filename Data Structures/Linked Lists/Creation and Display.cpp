// Author: Jatin Kumar
// Date:- Feb 2, 2019

#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
struct node *head;
void insert(int);
void display();
int main()
{
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	display();
}
void insert(int value)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=value;
	temp->next=NULL;
	if(!head)	// identifier is head, not *head
	{
		head=temp;
	}
	else
	{
		struct node *t=head;
		while(t->next)
		{
			t=t->next;
		}
		t->next=temp;
	}
}
void display()
{	
	struct node *temp=head;
	while(temp->next)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<temp->data<<"->NULL"<<endl;
}
