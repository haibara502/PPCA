#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100010, maxm = 200020, maxl = 110, cs = 1073741823;
int f[maxn][maxl];
int s[maxm], next[maxm], g1[maxn];
int g[maxn], sum[maxn], a[maxn], fa[maxn], b[maxl];
int L, N;

void dfs(int v)
{
	sum[v] = 1;
	g[v] = 0;
	for (int temp = g1[v]; temp; temp = next[temp]) if (s[temp] != fa[v])
	{
		int q = s[temp];
		fa[q] = v;
		dfs(q);
		sum[v] += sum[q];
		g[v] += g[q] + sum[q];
	}
}

void dp(int v)
{
	if (fa[v])
		a[v] = a[fa[v]] + g[fa[v]] - g[v] - sum[v] + (N - sum[v]);
	for (int j = 1; j <= L + 1; ++j) f[v][j] = g[v];
	for (int temp = g1[v]; temp; temp = next[temp]) if (s[temp] != fa[v])
	{
		int q = s[temp];
		dp(q);
		for (int j = L + 1; j > 1; --j)
			f[v][j] = min(f[v][j], f[q][j - 1] + g[v] - g[q] - sum[q]);
	}
	f[v][L + 1] += a[v];
	
	if (L >= 2)
	{
		for (int j = 1; j <= L + 1; ++j) b[j] = cs;
		for (int temp = g1[v]; temp; temp = next[temp]) if (s[temp] != fa[v])
		{
			int q = s[temp];
			for (int j = 1; j < L; ++j) 
				f[v][L + 1] = min(f[v][L + 1], b[j] + f[q][L - j] + g[v] - g[q] - sum[q] + a[v]);
			for (int j = 1; j <= L; ++j)
				b[j] = min(b[j], f[q][j] - sum[q] - g[q]);
		}
	}
}

int main()
{
	scanf("%d%d", & N, & L);
	int total = 0;
	for (int i = 1; i <= N; ++i) g1[i] = 0;
	for (int i = 1; i < N; ++i)
	{
		int a, b;
		scanf("%d%d", & a, & b);
		s[++total] = b, next[total] = g1[a]; g1[a] = total;
		s[++total] = a, next[total] = g1[b]; g1[b] = total;
	}
		
	for (int i = 1; i <= N; ++i) fa[i] = 0;
		
	dfs(1);
		
	dp(1);		
		
	int ans = cs;
	for (int i = 1; i <= N; ++i) ans = min(ans, f[i][L + 1]);
	printf("%d\n", ans);
}
