#include <iostream>
#include<Windows.h>
using namespace std;
struct node
{
	node* next;
	node* prev;
	int info;
};
class dlist
{
public:
	node* head;
	node* current;
	node* temp;
	int key;
	int del;
public:
	dlist()
	{
		head = NULL;
		current = NULL;
		temp = NULL;
		key = 0;
		del = 0;
	}
	void insert();
	void print();
	void addrand();
	void delet();
};
void dlist::insert()
{
	if (head == NULL)
	{
		head = new node;
		cout << "Enter the value for head:" << endl;
		cin >> head->info;
		head->next = NULL;
		head->prev = NULL;
		current = head;
	}
	else
	{
		temp = new node;
		cout << "Enter data for new node" << endl;
		cin >> temp->info;
		temp->next = NULL;
		temp->prev = current;
		current->next = temp;
		current = temp;
	}
}
void dlist::addrand()
{
	cout << "Enter the element after which you want to enter any new node" << endl;
	cin >> key;
	current = head;
	while (current->info != key)
	{
		current = current->next;
	}
	if (current->next == NULL)
	{
		cout << "Enter value for the new node:" << endl;
		temp = new node;
		cin >> temp->info;
		temp->next = current->next;
		temp->prev = current;
		current->next = temp;
	}
	else
	{
		cout << "Enter Value for the new nodes:" << endl;
		temp = new node;
		cin >> temp->info;
		temp->next = current->next;
		current->next->prev = temp;
		temp->prev = current;
		current->next = temp;
	}
}
void dlist::delet()
{
	cout << "Enter the value of the node that you want to delete:" << endl;
	cin >> del;
	current = head;
	temp = head;
	if (head->info == del)
	{
		head = head->next;
		head->prev = NULL;
		delete current;
	}
	else
	{
		while (current->info != key)
		{
			current = current->next;
		}
		if (current->next->next == NULL)
		{
			temp = current->next;
			current->next = NULL;
			temp->prev = NULL;
			delete temp;
		}
		else
		{
			current = current->next;
			current->prev->next = current->next;
			current->next->prev = current->prev;
			delete current;
		}
	}
}
void dlist::print()
{
	cout << "The values are following:" << endl;
	current = head;
	while (current->next != NULL)
	{
		cout << current->info << '\t';
		current = current->next;
	}
	cout << current->info << endl;

}

int main()
{
	dlist d;
	d.insert();
	d.insert();
	d.insert();
	d.insert();
	d.insert();
	d.print();
	d.addrand();
	d.print();
	d.delet();
	d.print();
	system("Pause");
}