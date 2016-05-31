#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;
typedef struct my_list {
	int data;
	struct my_list* next;
} MList;

int add(MList* &phead, int index, int data)
{
	MList *item = new MList;
	item->data = data;
	item->next = NULL;
	if (index == 0 || phead==NULL) { item->next = phead; phead = item; return 0; } 
	if (phead == phead->next) { phead->next = item; item->next = NULL; return 0; }
	int i = 0;
	while (phead->next != NULL && i < index-1) {
			i++;
			phead = phead->next;
		}
		item->next = phead->next;
		phead->next= item;
	     return 0;
}

int del(MList* &phead, int index)
{
	if (index == 0) { phead = phead->next; return 0; }
	int i = 0;
	while (phead->next != NULL && i < index - 1) {
		i++;
		phead = phead->next;
	}
	phead->next = phead->next->next;
	return 0;
}

int get(MList* &phead, int index, int pdata)
{
	MList* tmp = phead;
	int i = 0;
	if (index == 0) { pdata = tmp->data; 
	cout <<"Element= "<< pdata << endl;
	return 0;
	}
	while (tmp->next != NULL && i < index) {
		tmp = tmp->next;
		i++;
	}
	pdata = tmp->data;
	cout <<"Element= "<< pdata << endl;
	return 0;
}

int printlist(MList* &phead) {
	if (phead==NULL) cout << "Spisok pust \n";
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
	int data, size, ncommand;
	int pdata=0;
	cin >> ncommand;
	for (int i = 0; i<ncommand; i++) {
		cin >> command;
		if (!command.compare(0, 3, "add")) {
			int pos, dat;
			cin >> pos >> dat;
			add(head, pos, dat);
		}
		if (!command.compare(0, 3, "del")) {
			int pos;
			cin >> pos;
			del(head, pos);
		}
		if (!command.compare(0, 3, "get")) {
			int pos;
			cin >> pos;
			get(head, pos,pdata);
		}
	}
	printlist(head);
	system("pause");
	return 0;
}