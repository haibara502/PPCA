#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 300010;
int fa[maxn], d[maxn];
int N, M;

void read()
{
	scanf("%d%d", & N, & M);
	for (int i = 1; i <= N + 1; ++i) fa[i] = i;
}

inline int get(int v)
{
	if (fa[v] == v) return v;
	return fa[v] = get(fa[v]);
}

inline long long sqr(int v)
{
	return (long long)v * v;
}

void getans()
{
	long long ans = 0;
	while (M--)
	{
		int l, r;
		scanf("%d%d", & l, & r);
		int len = 0;
		int i = get(l);
		for (; i <= r; )
		{
			d[++len] = i;
			i = get(i + 1);
		}
		//for (int i = 1; i <= len; ++i) cerr << d[i] << ' ';
		//cerr << endl;
		i = 1;
		for (; i <= len;)
		{
			int j = i;
			for (; (j < len) && (d[j + 1] - 1 == d[j]);) ++j;
			//cerr << d[i] << ' ' << d[j] << ' ' << i << ' ' << j << ' ' << endl;
			ans += sqr(j - i + 1);
			for (int k = i; k <= j; ++k) fa[d[k]] = d[j] + 1;
			i = j + 1;
		}
	}
	cout << ans << endl;
}

int main()
{
	read();
	getans();
}
