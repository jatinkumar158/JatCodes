// Author: Jatin Kumar
// Date:- Mar 21, 2019

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
void reversedisplay(struct node*);
int main()
{	
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	reversedisplay(head);
	cout<<endl;
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
void reversedisplay(struct node *temp)
{
	if(temp)
	{
		reversedisplay(temp->next);
		cout<<temp->data<<" ";
	}
}
