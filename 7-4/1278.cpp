#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 300010;
bool a[maxn];
int N, M;

inline long long sqr(int v)
{
	return (long long)v * v;
}

void read()
{
	scanf("%d%d", & N, & M);
	memset(a, true, sizeof a);
	long long ans = 0;
	while (M--)
	{
		int l, r;
		scanf("%d%d", & l, & r);
		int i = l;
		for (; i <= r; )
		{
			while ((i <= r) && (!a[i])) ++i;
			if (i > r) break;
			int j = i;
			while ((j <= r) && (a[j])) ++j;
			ans += sqr(j - i);
			for (int k = i; k < j; ++k) a[k] = false;
			i = j;
		}
	}
	cout << ans << endl;
}

int main()
{
	read();
//	getans();
}
