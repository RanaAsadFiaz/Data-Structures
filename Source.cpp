#include <iostream>
using namespace std;
struct node
{
	node *next;
	int info;
};
class llist
{
public:
	node* temp;
	node* head;
	node* current;
	int key;
	int del;
public:
	llist()
	{
		head = NULL;
		temp = NULL;
		current = NULL;
		key = 0;
	}
	void insertion()
	{
		if (head == NULL)
		{
			head = new node;
			cout << "Enter Head's Infor:" << endl;
			cin >> head->info;
			head->next = NULL;
			current = head;
		}
		else
		{
			temp = new node;
			cout << "Enter Values for next nodes:" << endl;
			cin >> temp->info;
			temp->next = NULL;
			current->next = temp;
			current = current->next;
			current = temp;
		}
	}
	void show()
	{
		cout << "The values of nodes are" << endl;
		current = head;
		while (current->next != NULL)
		{
			cout << current->info << endl;
			current = current->next;
		}
	}
	void addrand()
	{
		cout << "Enter Value where you want to enter to the next node:" << endl;
		cin >> key;
		current = head;
		while (current->info != key)
		{
			current = current->next;
		}
		temp = new node;
		cout << "Enter Value of the new node that you want to add after" << key << endl;
		cin >> temp->info;
		temp->next = current->next;
		current->next = temp;
		current = temp;
	}
	void delet()
	{
		cout << "Enter Value That You want to delete:" << endl;
		cin >> del;
		current = head;
		temp = head;
		if (head->info == del)
		{
			head = head->next;
			delete current;
		}
		else
		{
			while (current->next->info != del)
			{
				current = current->next;
			}
			if (current->next->next == NULL)
			{
				temp = current;
				current = current->next;
				temp->next = NULL;
				delete current;
			}
			else
			{
				temp = current;
				current = current->next;
				temp->next = current->next;
				delete current;
			}
		}
	}
};
int main()
{
	llist a;

	a.insertion();
	a.insertion();
	a.insertion();
	a.insertion();
	a.insertion();
	a.insertion();
	a.insertion();
	a.insertion();
	a.insertion();
	a.insertion();
	a.insertion();
	a.show();
	a.addrand();
	a.show();
	a.delet();
	a.show();
	system("Pause");
}