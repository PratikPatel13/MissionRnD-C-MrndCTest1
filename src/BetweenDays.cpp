/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
void toDate(struct node *date, int dtarr[]);
int diff(int *date1, int *date2);

struct node{
	int data;
	struct node *next;
};


int between_days(struct node *date1head, struct node *date2head){
	if (date1head == NULL || date2head == NULL)
		return -1;
	int dtarr1[3], dtarr2[3];
	toDate(date1head, dtarr1);
	toDate(date2head, dtarr2);
	return diff(dtarr1, dtarr2);
}

void toDate(struct node *date, int dtarr[])
{
	int d = 0, m = 0, y = 0, temp;
	while (date != NULL)
	{
		temp = 2;
		while (temp > 0)
		{
			d = d * 10 + date->data;
			date = date->next;
			temp--;
		}
		temp = 2;
		while (temp > 0)
		{
			m = m * 10 + date->data;
			date = date->next;
			temp--;
		}
		temp = 4;
		while (temp > 0)
		{
			y = y * 10 + date->data;
			date = date->next;
			temp--;
		}
		dtarr[0] = d;
		dtarr[1] = m;
		dtarr[2] = y;
	}
}

int diff(int *date1, int *date2)
{
	int diff = 0, i;
	int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (date1[2] == date2[2])
	{
		if (date1[1] == date2[1])
		{
			if (date1[0] == date2[0])
				return 0;
			return date2[0] - date1[0] - 1;
		}
		else
		{
			diff = (days[date1[1] - 1] - date1[0]) + date2[0] - 1;
			if (date1[1] != date2[1] - 1)
			{
				for (i = date1[1] + 1; i < date2[1]; i++)
				{
					diff += days[i - 1];
				}
			}
			return diff;
		}
	}
}
