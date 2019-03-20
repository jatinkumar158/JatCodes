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
int ascending(struct node*);
int main()
{	
	insert(100);
	insert(20);
	insert(30);
	insert(40);
	display();
	int result=ascending(head);
	if(result)
	{
		cout<<"List is in ascending order\n";
	}
	else
	{
		cout<<"List is not in ascending order\n";
	}
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
int ascending(struct node *temp)
{
	if(!temp)
	{
		return 1;	// nothing in the list and hence in any order
	}
	else if(!temp->next)
	{
		return 1;	// only node can also be in any order
	}
	else
	{
		return ((temp->data<=temp->next->data) && ascending(temp->next));
	}

	// the entire code can be done in one line like this

	//	return (!temp || !temp->next || (temp->data<=temp->next->data && ascending(temp->next)))

}
