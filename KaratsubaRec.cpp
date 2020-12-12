#include "karatsubaRec.h"
void karatsubaRec(int* x, int* y, int n, int** c)
{
	if (n == 1)
	{
		(*c)[1] += (x[0] * y[0]) % 10;
		(*c)[0] += (x[0] * y[0]) / 10;
		return;
	}

	if (n % 2 != 0)
	{
		addZeroes(&x, n);
		addZeroes(&y, n);
		n++;
		int* t = new int[2 * n];
		t[0] = 0;
		t[1] = 0;
		for (int i = 2; i < 2 * n; i++)
		{
			t[i] = (*c)[i - 2];
		}
		//delete[] * c;
		*c = t;
	}
	int* p1 = new int[n]; //a*c
	int* p2 = new int[n]; //b*d
	int* aSb = sum(x, x + n / 2, n / 2);//a+b
	fixDigits(aSb, n);
	int* cSd = sum(y, y + n / 2, n / 2);//c+d
	fixDigits(cSd, n);
	int count = removeZeroes(&aSb, &cSd, n / 2 + 1);
	int* p3 = new int[(n / 2 + 1 - count) * 2];//(a+b)*(c+d)
	for (int m = 0; m < n; m++)
	{
		p1[m] = 0;
		p2[m] = 0;
	}
	for (int m = 0; m < (n / 2 + 1 - count) * 2; m++)
	{
		p3[m] = 0;
	}
	karatsubaRec(x, y, n / 2, &p1);//a*c
	karatsubaRec(x + n / 2, y + n / 2, n / 2, &p2);//b*d
	karatsubaRec(aSb, cSd, (n / 2 + 1 - count), &p3);//(a+b)*(c+d)
	int s;
	if ((n / 2 + 1 - count) % 2 != 0 && (n / 2 + 1 - count) != 1)
	{
		s = (n / 2 + 2 - count) * 2;
	}
	else
	{
		s = (n / 2 + 1 - count) * 2;
	}
	shiftLeft(p1, *c, n, 2 * n, n);//put p1 in correct place of c
	shiftLeft(p2, *c, n, 2 * n, 0);//put p2 in correct place of c
	makeEqual(&p1, n, count);//add one left 0 to p1
	makeEqual(&p2, n, count);//add one left 0 to p1
	subtract(&p3, p1, s);//p3-p1
	subtract(&p3, p2, s);//(p3-p1)-p2
	shiftLeft(p3, *c, s, 2 * n, n / 2);//put p3 in correct place of c
	fixDigits(*c, 2 * n);//correct the array so each place has a single digit

	//delete[] p1;
	//delete[] p2;
	//delete[] p3;
	//delete[] aSb;
	//delete[] cSd;
}


int* sum(int* a, int* b, int n)
{
	int* res = new int[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		res[i] = 0;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		res[i + 1] += (a[i] + b[i]) % 10;
		res[i] += (a[i] + b[i]) / 10;
	}
	return res;
}

void subtract(int** a, int* b, int n)
{
	int* res = new int[n];
	for (int i = 0; i < n; i++)
	{
		res[i] = 0;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if ((*a)[i] - b[i] < 0)
		{
			(*a)[i - 1] -= 1;
			(*a)[i] += 10;
		}
		res[i] += (*a)[i] - b[i];
	}
	//	delete[] * a;
	*a = res;
}

void addZeroes(int** a, int n)
{
	int* res = new int[n + 1];
	res[0] = 0;
	for (int i = 1; i < n + 1; i++)
	{
		res[i] = (*a)[i - 1];
	}
	//	delete[] * a;
	*a = res;
}

void shiftLeft(int* a, int* c, int na, int nc, int shift)
{
	if (na == nc)
	{
		int j = 0;
		for (int i = shift; i < na; i++)
		{
			c[j] += a[i];
			j++;
		}
	}
	else
	{
		int s = shift + na;
		for (int i = 0; i < na; i++)
		{
			c[nc - s + i] += a[i];
		}
	}
}

void fixDigits(int* c, int n)
{
	for (int i = n - 1; i > 0; i--)
	{
		if (c[i] > 9)
		{
			c[i - 1] += c[i] / 10;
			c[i] = c[i] % 10;
		}
	}
}

void makeEqual(int** a, int n, int size)
{
	int s;
	if ((n / 2 + 1 - size)%2!=0&& (n / 2 + 1 - size)!=1)
	{
		s = (n / 2 + 2 - size) * 2;
	}
	else
	{
		s = (n / 2 + 1 - size) * 2;
	}
	int* tmp = new int[s];
	for (int i = 0; i < s-n; i++)
	{
		tmp[i] = 0;
	}
	int j = 0;
	for (int i = s-n; i < s; i++)
	{
		tmp[i] = (*a)[j];
		j++;
	}
	//delete[] * a;
	*a = tmp;
}

int removeZeroes(int** a, int** b, int n)
{
	int i = 0;
	while ((*a)[i] == (*b)[i] && (*a)[i] == 0)
	{
		i++;
	}
	int s = i;
	int* t1 = new int[n - s];
	int* t2 = new int[n - s];
	for (int j = 0; j < n - s; j++)
	{
		t1[j] = (*a)[i];
		t2[j] = (*b)[i];
		i++;
	}
	//delete[] * a;
	//delete[] * b;
	*a = t1;
	*b = t2;
	return  s;
}
