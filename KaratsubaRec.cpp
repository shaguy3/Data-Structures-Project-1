#include "karatsubaRec.h"
void karatsubaRec(int* x, int* y, int n, int** c)
{
	if (n == 1 || n == 0)
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
		delete[] * c;
		*c = t;
	}
	int* p1 = new int[n]; //a*c
	int* p2 = new int[n]; //b*d
	int* aSb = sum(x, x + (n / 2), n / 2);//a+b
	fixDigits(aSb, n / 2 + 1);
	int* cSd = sum(y, y + (n / 2), n / 2);//c+d
	fixDigits(cSd, n / 2 + 1);
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
	karatsubaRec(x + (n / 2), y + (n / 2), n / 2, &p2);//b*d
	karatsubaRec(aSb, cSd, (n / 2 + 1 - count), &p3);//(a+b)*(c+d)
	int s1, s2;
	if ((n / 2) % 2 != 0 && n / 2 != 1)
	{
		s1 = (n / 2 + 1) * 2;
	}
	else
	{
		s1 = n;
	}
	if ((n / 2 + 1 - count) % 2 != 0 && (n / 2 + 1 - count) != 1)
	{
		s2 = (n / 2 + 2 - count) * 2;
	}
	else
	{
		s2 = (n / 2 + 1 - count) * 2;
	}
	shiftLeft(p1, *c, s1, 2 * n, n);//put p1 in correct place of c
	shiftLeft(p2, *c, s1, 2 * n, 0);//put p2 in correct place of c
	subtract(&p3, p1, s2,s1);//p3-p1
	subtract(&p3, p2, s2,s1);//(p3-p1)-p2
	shiftLeft(p3, *c, s2, 2 * n, n / 2);//put p3 in correct place of c
	fixDigits(*c, 2 * n);//correct the array so each place has a single digit

	delete[] p1;
	delete[] p2;
	delete[] p3;
	delete[] aSb;
	delete[] cSd;
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

void subtract(int** a, int* b, int na, int nb)
{
	int* res = new int[na];
	for (int i = 0; i < na; i++)
	{
		res[i] = 0;
	}
	for (int i = nb - 1; i >= 0; i--)
	{
		if ((*a)[na-1] - b[i] < 0)
		{
			(*a)[na-1 - 1] -= 1;
			(*a)[na-1] += 10;
		}
		res[na-1] += (*a)[na-1] - b[i];
		na--;
	}
		delete[] * a;
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
		delete[] * a;
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
		int j = 0;
		int s = nc - 1 - shift;
		for (int i = na-1; i >= 0; i--)
		{
			c[s-j] += a[i];
			j++;
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
	delete[] * a;
	delete[] * b;
	*a = t1;
	*b = t2;
	return  s;
}
