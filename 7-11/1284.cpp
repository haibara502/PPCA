#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 210, maxv = 5010, maxk = 51;
int a[maxn], b[maxn];
int f[maxv][maxk], d[maxk * maxn];
int N, V, K;

void read()
{
	scanf("%d%d%d", & K, & V, & N);
	for (int i = 1; i <= N; ++i) scanf("%d%d", & a[i], & b[i]);
}

void getans()
{
	memset(f, -1, sizeof f);
	f[0][1] = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = V; j >= 1; --j) if (j - a[i] >= 0)
		{
			int len = 0;
			for (int k = 1; k <= K; ++k) if (f[j - a[i]][k] != -1)
				d[++len] = f[j - a[i]][k] + b[i];
			for (int k = 1; k <= K; ++k) d[++len] = f[j][k];
			sort(d + 1, d + 1 + len);
			for (int k = 1; k <= K; ++k) if (len - k + 1 > 0)
				f[j][k] = d[len - k + 1];
//			cerr << j << endl;
//			for (int k = 1; k <= K; ++k) cerr << f[j][k] << ' ';
//			cerr << endl;
		}
	}
	int ans = 0;
	for (int i = 1; i <= K; ++i) ans += f[V][i];
	cout << ans << endl;
}

int main()
{
	read();
	getans();
}
