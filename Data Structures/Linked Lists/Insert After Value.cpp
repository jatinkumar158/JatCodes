// Author: Jatin Kumar
// Date:- Feb 5, 2019


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
void insertAfterValue(int,int);	// first->element to be inserted and second -> after which the element is to be inserted
int main()
{
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	display();
	insertAfterValue(5,10);
	display();
	insertAfterValue(15,40);
	display();
	insertAfterValue(25,100);
	display();
}
void insert(int value)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=value;
	temp->next=NULL;
	if(!head)	// identifier is head not *head
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
void display() // This is bit modified but previously used is also fine
{	
	struct node *temp=head;
	while(temp)	
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
}
void insertAfterValue(int value,int target)
{
	struct node *temp=head;
	while(temp!=NULL)
	{
		if(temp->data==target)
		{
			break;
		}
		else
		{
			temp=temp->next;
		}
	}
	if(temp==NULL)
	{
		cout<<"value not found, no insertion performed"<<endl;
	}
	else
	{
		// check if target node is last node or not
		if(temp->next==NULL)
		{
			// target node is last node
			insert(value);	// smart one
		}
		else
		{
			struct node *newNode=(struct node*)malloc(sizeof(struct node));
			newNode->data=value;
			newNode->next=temp->next;
			temp->next=newNode;
		}
	}
}
