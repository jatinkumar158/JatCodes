// Author: Jatin Kumar
// Date:- Mar 17, 2019


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
void deleteend();
int main()
{	
	int size=sizeof(struct node);
	cout<<"size is "<<size<<endl;
	insert(10);
	insert(20);
	display();
	deleteend();
	display();
	deleteend();
	display();
	deleteend();
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
void deleteend()
{	

	// if list is empty
	if(!head)
	{
		cout<<"List is empty and deletion is not possible\n";
	}
	else if(!head->next)
	{
		// there is only one node in the list
		// so first and last node are same
		free(head);
		head=NULL;
	}
	else
	{
		struct node *temp=head;
		while(temp->next->next)
		{
			temp=temp->next;
		}
		struct node *t=temp->next;
		free(t);
		temp->next=NULL;
	}
}
