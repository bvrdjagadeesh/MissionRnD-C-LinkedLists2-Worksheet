/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};
struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head==NULL||K<0)
		return NULL;
	int curind = 1;
	struct node* temp = head;
	while (head != NULL)
	{
		while (head->next != NULL&&curind%K!=0)
		{
			head = head->next;
			curind++;
		}
		if (head != NULL&&curind == K)
		{
			struct node *newnode = (struct node *)malloc(sizeof(struct node));
			newnode->num = K;
			newnode->next = head->next;
			head->next = newnode;
			head = newnode;
			curind = 1;
		}
		head = head->next;
	}
	return temp;
}
