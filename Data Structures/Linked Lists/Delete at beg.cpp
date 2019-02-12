// Author: Jatin Kumar
// Date:- Feb 12, 2019


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
void deletebeg(); 
void display();
int main()
{
	insert(10);
	insert(20);
	display();
	deletebeg();
	display();
	deletebeg();
	display();
	deletebeg();
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
void deletebeg()
{
	if(head==NULL)
	{
		cout<<"List is empty and deletion is not possible\n";
	}
	else if(head->next==NULL)
	{
		// there is only one node in the list
		free(head);
		head=NULL;
	}
	else
	{
		//  there are more than one nodes
		struct node *temp=head;
		head=head->next;
		free(temp);
	}
}
