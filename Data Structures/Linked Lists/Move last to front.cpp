// Author: Jatin Kumar
// Date:- Mar 19, 2019


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
void moveToFront();
int main()
{	
	insert(10);
	moveToFront();
	insert(20);
	insert(30);
	display();
	moveToFront();
	display();
}
void insert(int value)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=value;
	temp->next=NULL;
	if(!head)	
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
	while(temp)	
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}
void moveToFront()
{
	if(!head || !head->next)	// no node or only one node
	{
		cout<<"List is empty and operation is not possible\n";
	}
	else
	{
		// we are sure that at this point we havae atleast two nodes
		struct node *temp=head;
		while(temp->next->next)
		{
			temp=temp->next;
		}
		// temp is at second last node
		struct node *t=temp->next;
		temp->next=NULL;
		t->next=head;
		head=t;
	}
}
