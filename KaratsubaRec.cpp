#include "karatsubaRec.h"

void karatsubaRec(int* x, int* y, int n, int* c)
{
	if (n==1)
	{
		c[2 * n - 1] += (x[0] * y[0]) % 10;
		c[2 * n - 2] += (x[0] * y[0]) / 10;
		return;
	}

	if (n%2!=0)
	{
		addZeroes(x, n);
		addZeroes(y, n);
		n++;
	}
	int* p1 = new int[n]; //a*c
	int* p2 = new int[n]; //b*d
	int* aSb = sum(x,x+n/2,n/2);//a+b
	int* cSd = sum(y,y+n/2,n/2);//c+d
	int* p3 = new int[n + 2];//(a+b)*(c+d)

	karatsubaRec(x, y, n / 2, p1);//a*c
	karatsubaRec(x+n/2, y+n/2, n / 2, p1);//b*d
	karatsubaRec(aSb, cSd, n / 2 + 1, p3);//(a+b)*(c+d)

	shiftLeft(p1, c, n,n);//put p1 in correct place of c
	shiftLeft(p2, c, n, 0);//put p2 in correct place of c
	makeEqual(p1, n);//add one left 0 to p1
	makeEqual(p2, n);//add one left 0 to p1
	subtract(p3, p1, n + 1);//p3-p1
	subtract(p3, p2, n + 1);//(p3-p1)-p2
	addZeroes(p3, n + 1);//make p3 even length
	shiftLeft(p3, c, n + 2, n / 2 + 1);//put p3 in correct place of c
	fixDigits(c, n);//correct the array so each place has a single digit

	delete[] p1;
	delete[] p2;
	delete[] p3;
	delete[] aSb;
	delete[] cSd;
}


int* sum(int* a, int* b, int n)
{
	int* res = new int [n+1];
	for (int i = 0; i < n+1; i++)
	{
		res[i] = 0;
	}
	for (int i = n-1; i >= 0; i--)
	{
			res[i] += (a[i] + b[i]) % 10;
			res[i - 1] += (a[i] + b[i]) / 10;
	}
	return res;
}

int* subtract(int* a, int* b, int n)
{
	int* res = new int[n];
	for (int i = 0; i < n; i++)
	{
		res[i] = 0;
	}
	for (int i = n-1; i >= 0; i--)
	{
		if (a[i]-b[i]<0)
		{
			a[i - 1]--;
			a[i] *= 10;
		}
		res[i] = a[i] - b[i];
	}
	return res;
}

void addZeroes(int* a, int n)
{
	int* res = new int[n + 1];
	res[0] = 0;
	for (int i = 1; i < n+1; i++)
	{
		res[i] = a[i - 1];
	}
	delete[] a;
	a = res;
}

void shiftLeft(int* a, int* c, int n, int shift)
{
	int s = shift + n;
	for (int i = 0; i < n-1; i++)
	{
		c[2 * n - s-i] += a[i];
	}
}

void fixDigits(int* c, int n)
{
	for (int i = 2*n-1; i > 0; i--)
	{
		if (c[i]>10)
		{
			c[i - 1] += c[i] / 10;
			c[i] = c[i] % 10;
		}
	}
}

void makeEqual(int* a, int n)
{
	int* tmp = new int[n + 1];
	tmp[0] = 0;
	for (int i = 1; i < n+1; i++)
	{
		tmp[i] = a[i - 1];
	}
	delete[] a;
	a = tmp;
}