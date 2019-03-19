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
void deletenode(int);
void deletebeg();
void deleteend();
int main()
{	
	int choice,v,flag=0;
	menu:
	cout<<"\n\n****************MENU***************\n";
	cout<<"1.)Insert a value\n";
	cout<<"2.)Delete a value\n";
	cout<<"3.)Display list\n";
	cout<<"4.)Exit\n\n";
	cout<<"Enter your coice=";
	cin>>choice;
	switch(choice)
	{
		case 1: cout<<"enter value=";
				cin>>v;
				insert(v);
				break;
		case 2: cout<<"enter value=";
				cin>>v;
				deletenode(v);
				break;
		case 3: display();
				break;
		case 4: flag=1;
				break;
		default: cout<<"ALERT: WRONG INPUT\n";
				break;
	}
	if(flag!=1)
	{
		goto menu;
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
void deletenode(int value)
{
	if(!head)
	{
		cout<<"List is empty and deletion is not possible\n";
	}
	else
	{	
		struct node *temp=head;
		while(temp->data!=value && temp->next)
		{
			temp=temp->next;
		}
		if(temp->data==value)
		{
			if(!head->next)
			{
				// there is only one node in list
				if(head->data==value)
				{
					// value found at head
					deletebeg();
				}
				else
				{
					cout<<"\nvalue not found\n\n";
				}
			}
			else
			{
				// there are more than one nodes in the link list
				struct node *temp=head;
				if(temp->data==value)
				{
					deletebeg();
				}
				else
				{
					while(temp->next->data!=value && temp->next)
					{
						temp=temp->next;
					}
					if(!temp->next)
					{
						// we are at last node
						if(temp->data==value)
						{
							deleteend();
						}
						else
						{
							cout<<"value not found\n";
						}
					}
					else
					{
						struct node *t=temp->next;
						temp->next=t->next;
						free(t);
					}
				}
			}
		}
		else
		{
			cout<<"Value not found\n";
		}
	}
}
