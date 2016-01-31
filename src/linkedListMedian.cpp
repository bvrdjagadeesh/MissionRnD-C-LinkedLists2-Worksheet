/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
int length(struct node *);
int linkedListMedian(struct node *head) {
	if (head != NULL)
	{
		int med, j, res;
		int len = length(head);
		if (len % 2 != 0)
		{
			for (j = 0; j<len / 2 - 1; j++)
			{
				head = head->next;
			}
			res = (head->num + head->next->num) / 2;
			return res ;
		}
		else
		{
			for (j = 0; j<len / 2 - 1; j++)
			{
				head = head->next;
			}
			return head->num;
		}
	}
	return -1;
}
int length(struct node * head)
{
	struct node * a = head;
	int i;
	for (i = 0; a->next != NULL; i++)
		a = a->next;
	return i + 2;

}
