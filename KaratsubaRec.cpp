#include "karatsubaRec.h"
void karatsubaRec(int* x, int* y, int n, int* c)
{
	if (n == 1)
	{
		c[1] += (x[0] * y[0]) % 10;
		c[0] += (x[0] * y[0]) / 10;
		return;
	}

	if (n % 2 != 0)
	{
		addZeroes(x, n);
		addZeroes(y, n);
		n++;
	}
	int* p1 = new int[n]; //a*c
	int* p2 = new int[n]; //b*d
	int* aSb = sum(x, x + n / 2, n / 2);//a+b
	int* cSd = sum(y, y + n / 2, n / 2);//c+d
	int* tmp1 = nullptr, * tmp2 = nullptr;
	int count = removeZeroes(aSb, cSd, n / 2 + 1, &tmp1, &tmp2);
	delete[] aSb;
	delete[] cSd;
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
	karatsubaRec(x, y, n / 2, p1);//a*c
	karatsubaRec(x + n / 2, y + n / 2, n / 2, p2);//b*d
	karatsubaRec(tmp1, tmp2, (n / 2 + 1 - count), p3);//(a+b)*(c+d)

	shiftLeft(p1, c, n, n);//put p1 in correct place of c
	shiftLeft(p2, c, n, 0);//put p2 in correct place of c
	int* p1t = nullptr, * p2t = nullptr;
	makeEqual(p1, n, count, &p1t);//add one left 0 to p1
	makeEqual(p2, n, count, &p2t);//add one left 0 to p1
	int* sub1, * sub2;
	sub1 = subtract(p3, p1t, (n / 2 + 1 - count) * 2);//p3-p1
	sub2 = subtract(sub1, p2t, (n / 2 + 1 - count) * 2);//(p3-p1)-p2
	//addZeroes(p3, n + 1);//make p3 even length
	shiftLeft(sub2, c, (n / 2 + 1 - count) * 2, n / 2);//put p3 in correct place of c
	fixDigits(c, n);//correct the array so each place has a single digit

	//delete[] p1;
	//delete[] p2;
	//delete[] p3;
	//delete[] tmp1;
	//delete[] tmp2;
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

int* subtract(int* a, int* b, int n)
{
	int* res = new int[n];
	for (int i = 0; i < n; i++)
	{
		res[i] = 0;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] - b[i] < 0)
		{
			a[i - 1] -= 1;
			a[i] += 10;
		}
		res[i] += a[i] - b[i];
	}
	return res;
}

void addZeroes(int* a, int n)
{
	int* res = new int[n + 1];
	res[0] = 0;
	for (int i = 1; i < n + 1; i++)
	{
		res[i] = a[i - 1];
	}
	delete[] a;
	a = res;
}

void shiftLeft(int* a, int* c, int n, int shift)
{
	int s = shift + n;
	for (int i = 0; i < n; i++)
	{
		c[2 * n - s + i] += a[i];
	}
}

void fixDigits(int* c, int n)
{
	for (int i = 2 * n - 1; i > 0; i--)
	{
		if (c[i] > 10)
		{
			c[i - 1] += c[i] / 10;
			c[i] = c[i] % 10;
		}
	}
}

void makeEqual(int* a, int n, int size, int** tmp1)
{
	int* tmp = new int[(n / 2 + 1 - size) * 2];
	for (int i = 0; i < 2 - 2 * size; i++)
	{
		tmp[i] = 0;
	}
	int j = 0;
	for (int i = 2 - 2 * size; i < (n / 2 + 1 - size) * 2; i++)
	{
		tmp[i] = a[j];
		j++;
	}
	*tmp1 = tmp;
}

int removeZeroes(int* a, int* b, int n, int** tmp1, int** tmp2)
{
	int i = 0;
	while (a[i] == b[i] && a[i] == 0)
	{
		i++;
	}
	int s = i;
	int* t1 = new int[n - s];
	int* t2 = new int[n - s];
	for (int j = 0; j < n - s; j++)
	{
		t1[j] = a[i];
		t2[j] = b[i];
		i++;
	}
	*tmp1 = t1;
	*tmp2 = t2;
	return  s;
}
