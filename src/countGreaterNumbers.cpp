/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<stdio.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int to_date(char *dob, int date[])
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
int isvalid(int date[])
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

int isGreater(char *dob1, char *dob2) {

	int v1 = 0, v2 = 0, date1[3] = { 0 }, date2[3] = { 0 };
	v1 = to_date(dob1, date1);
	v2 = to_date(dob2, date2);
	if (v1 == -1 || v2 == -1)
		return -1;
	v1 = isvalid(date1);
	v2 = isvalid(date2);
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


int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int date1[3] = { 0 }, date2[3] = { 0 },v1=0,v2=0,i,j,k,count=0;
	if (Arr==NULL || len<0)
		return -1;
	for (i = 0; i < len; i++)
	{
		k = isGreater(date, (Arr + i)->date);
		if (k == 0)
		{
			if (isGreater((Arr + i)->date, (Arr + (i + 1))->date) == 0)
				count = 0;
			else

			count = len - i - 1;
			break;
		}
		if (k == 1)
		{
				count = len - i;
			break;
		}

	}
	return count;
}
