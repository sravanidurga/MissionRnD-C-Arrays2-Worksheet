/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int to_date_1(char *dob, int date[])
{
	int  i = 0, flag = 0, num = 0;
	for (i = 0; *(dob + i); i++)
	{
		if (*(dob + i) >= '0' && *(dob + i) <= '9')
		{
			date[flag] *= 10;
			date[flag] += *(dob + i) - '0';

		}
		else if (*(dob + i) == '-' || *(dob + i) == '/')
			flag += 1;
		else
			return -1;

	}
	return 1;

}
int isvalid_1(int date[])
{
	if (date[2] == 0 || date[1] == 0 || date[0] == 0)
		return -1;
	if (date[1] <= 12)
	{
		if (date[1] == 2)
		{
			if ((date[2] % 4 == 0 && date[2] % 100 != 0) || (date[2] % 400 == 0))
			{
				if (date[0] <= 0 || date[0] > 29)
					return -1;
				else
					return 1;
			}
			else
			{
				if (date[0] <= 0 || date[0] > 28)
					return -1;
				else
					return 1;
			}

		}
		else if (date[1] == 1 || date[1] == 3 || date[1] == 5 || date[1] == 7 || date[1] == 8 || date[1] == 10 || date[1] == 12)
		{
			if (date[0] > 31 || date[0] <= 0)
				return -1;
		}
		else
		{
			if (date[0] <= 0 || date[0] > 30)
				return -1;
		}

		return 1;
	}
	else
		return -1;

}

int isGreater_1(char *dob1, char *dob2) {

	int v1 = 0, v2 = 0, date1[3] = { 0 }, date2[3] = { 0 };
	v1 = to_date_1(dob1, date1);
	v2 = to_date_1(dob2, date2);
	if (v1 == -1 || v2 == -1)
		return -1;
	v1 = isvalid_1(date1);
	v2 = isvalid_1(date2);
	if (v1 == -1 || v2 == -1)
		return -1;

	if (date1[2] < date2[2])
	{
		return 1;
	}
	else if (date1[2] > date2[2])
	{
		return 2;
	}
	else
	{
		if (date1[1] < date2[1])
		{
			return 1;
		}
		else if (date1[1] > date2[1])
		{
			return 2;
		}
		else
		{
			if (date1[0] < date2[0])
			{
				return 1;

			}
			else if (date1[0] > date2[0])
			{
				return 2;
			}
			else
			{
				return 0;
			}
		}
	}
	return 0;
}

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	struct transaction *result = NULL;
	int i = 0, j = 0, k = 0, temp;
	char s[20];
	if (A == NULL || B == NULL || ALen < 0 || BLen < 0)
		return NULL;
	result = (struct transaction *)malloc(sizeof(struct transaction)*(ALen + BLen));

	while (i < ALen && j < BLen)
	{

		if (isGreater_1((A + i)->date, (B + j)->date) == 1 || isGreater_1((A + i)->date, (B + j)->date) == 0)
		{
			strcpy((result + k)->date, (A + i)->date);
			strcpy((result + k)->description, (A + i)->description);
			(result + k)->amount = (A + i)->amount;
			i++;
			k++;
		}
		else
		{
			strcpy((result + k)->date, (B + j)->date);
			strcpy((result + k)->description, (B + j)->description);

			(result + k)->amount = (B + j)->amount;
			j++;
			k++;
		}
	}
	while (i < ALen)
	{
		strcpy((result + k)->date, (A + i)->date);
		strcpy((result + k)->description, (A + i)->description);

		(result + k)->amount = (A + i)->amount;
		i++;
		k++;
	}
	while (j < BLen)
	{
		strcpy((result + k)->date, (B + j)->date);
		strcpy((result + k)->description, (B + j)->description);

		(result + k)->amount = (B + j)->amount;
		j++;
		k++;
	}
	return result;
}