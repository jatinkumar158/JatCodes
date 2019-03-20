// Author: Jatin Kumar
// Date:- Mar 20, 2019


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
void descending();
int main()
{	
	insert(10);
	insert(9);
	insert(80);
	display();
	descending();
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
void descending()
{
	struct node *temp=head;
	int flag=1;
	if(!temp)
	{
		cout<<"list is empty\n";
	}
	else if(!temp->next)
	{
		cout<<"List is in descending order\n";
	}
	else
	{
		// we are sure that there are more than one nodes in list
		while(temp->next)
		{
			if(temp->data<temp->next->data)
			{
				flag=0;
				break;
			}
			temp=temp->next;
		}
		if(flag)
		{
			cout<<"List is in descending order\n";
		}
		else
		{
			cout<<"List isn't in descending order\n";
		}
	}
}
