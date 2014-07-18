#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1010, cs = 1000000007;
long long c[maxn][maxn], f[maxn];
int N;

void read()
{
	scanf("%d", & N);
}

void getans()
{
	c[1][0] = c[1][1] = 1;
	for (int i = 2; i <= N; ++i)
		for (int j = 0; j <= i; ++j)
		{
			c[i][j] = 0;
			if (j) c[i][j] = c[i - 1][j - 1];
			if (j < i) c[i][j] = (c[i][j] + c[i - 1][j]) % cs;
		}
		
	f[0] = f[1] = 1;
	for (int i = 2; i <= N; ++i)
	{
		int sub = 0;
		for (; 2 * ((1 << (sub + 1)) - 1) <= i; ++sub);
		int leftSub = (1 << sub) - 1;
		int remain = i - 2 * leftSub - 1;
		leftSub += min(remain, 1 << sub);
		int rightSub = i - 1 - leftSub;
		f[i] = f[leftSub] * f[rightSub] % cs * c[i - 1][leftSub] % cs;
	}
	
	if (N <= 1)
		cout << f[N] << endl;
	else
		cout << (f[N] * 2) % cs << endl;
}

int main()
{
	read();
	getans();
}
