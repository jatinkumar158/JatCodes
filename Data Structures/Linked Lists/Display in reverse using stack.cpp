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
void reversedisplay();
int size=0; 
int main()
{	
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	reversedisplay();
}
void insert(int value)
{	
	size++;
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
void reversedisplay()
{
	struct node *stack[size];
	int top=-1;
	struct node *temp=head;
	// push all the addresses of the nodes on the top of the stack
	while(temp)
	{	
		top++;
		stack[top]=temp;
		temp=temp->next;
	}
	// till now all the node addresses are stored in the stack
	// now pop all the elements and retrieve their data
	while(top!=-1)
	{
		cout<<stack[top--]->data<<" ";
	}
	cout<<endl;
}
