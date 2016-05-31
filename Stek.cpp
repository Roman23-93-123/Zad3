#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;
typedef struct my_list {
	int data;
	struct my_list* next;
} MList;

int add(MList* &phead, int data)
{
	MList *item = new MList;
	item->data = data;
	item->next = NULL;
	item->next = phead; phead = item; 
	 return 0;
}

int del(MList* &phead)
{
	 phead = phead->next; return 0; 
}

int get(MList* &phead, int pdata)
{
	MList* tmp = phead;
	pdata = tmp->data; 
	cout << "Element= "<<pdata << endl;
	return 0;
	}

int printlist(MList* &phead) {
	if (phead == NULL) cout << "Spisok pust \n";
	else {
		cout << "Spisok: \n";
		while (phead != NULL) {
			cout << phead->data << " ";
			phead = phead->next;
		}
		cout << endl;
	}
	return 0;
}

int main()
{
	MList *head=0;
	string command;
	int ncommand;
	int data=0;
	cin >> ncommand;
	for (int i = 0; i<ncommand; i++) {
		cin >> command;
		if (!command.compare(0, 3, "add")) {
			int dat;
			cin >> dat;
			add(head, dat);
		}
		if (!command.compare(0, 3, "del")) {
			del(head);
		}
		if (!command.compare(0, 3, "get")) {
			get(head, data);
		}
	}
	printlist(head);
	system("pause");
	return 0;
}