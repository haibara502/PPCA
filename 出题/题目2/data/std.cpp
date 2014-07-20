#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100010, maxm = 200010;
int s[maxm], next[maxm], g1[maxn];
int s2[maxm], next2[maxm], g2[maxn];
int s3[maxn][2], next3[maxn], g3[maxn], f3[maxn];
int fa[maxn], a[maxn], d[maxn]; 
int maxw[maxn], maxup[maxn], maxdown[maxn], minw[maxn], ans[maxn];
bool vis[maxn];
int N, M, tot;

void read()
{
	scanf("%d", & N);
	for (int i = 1; i <= N; ++i) scanf("%d", & a[i]);
	
	tot = 1;
	for (int i = 1; i < N; ++i)
	{
		int a, b;
		scanf("%d%d", & a, & b);
		s[++tot] = b; next[tot] = g1[a]; g1[a] = tot;
		s[++tot] = a; next[tot] = g1[b]; g1[b] = tot;
	}
	
	scanf("%d", & M);
	tot = 1;
	for (int i = 1; i <= M; ++i)
	{
		int a, b;
		scanf("%d%d", & a, & b);
		s2[++tot] = b; next2[tot] = g2[a]; g2[a] = tot; 
		s2[++tot] = a; next2[tot] = g2[b]; g2[b] = tot;
	}
}

void get(int v)
{
	int t = 0;
	for (; fa[v] != v; v = fa[v])
		d[++t] = v;
	for (; t; --t)
	{
		int x = d[t];
		int te = max(maxw[fa[x]] - minw[x], maxup[fa[x]]);
		maxup[x] = max(maxup[x], te);
		te = max(maxw[x] - minw[fa[x]], maxdown[fa[x]]);
		maxdown[x] = max(maxdown[x], te);
		minw[x] = min(minw[fa[x]], minw[x]);
		maxw[x] = max(maxw[fa[x]], maxw[x]);
		fa[x] = v;
	}
}

void dfs(int v, int fa1)
{
	vis[v] = true;
	for (int temp = g2[v]; temp; temp = next2[temp]) if (vis[s2[temp]])
	{
		int t = s2[temp];
		get(t);
		s3[++tot][0] = t, s3[tot][1] = v, next3[tot] = g3[fa[t]]; g3[fa[t]] = tot; f3[tot] = temp / 2;
		if ((temp & 1) == 0) swap(s3[tot][0], s3[tot][1]);
	}
	
	for (int temp = g1[v]; temp; temp = next[temp]) if ((temp ^ 1) != fa1)
		dfs(s[temp], temp);

	for (int temp = g3[v]; temp; temp = next3[temp])
	{
		int s = s3[temp][0], t = s3[temp][1];
		get(s), get(t);
		int an = max(maxup[s], maxdown[t]);
		an = max(an, maxw[t] - minw[s]);
		ans[f3[temp]] = an;
	}
	
	fa[v] = s[fa1 ^ 1];
	
}

void check()
{
	for (int i = 1; i <= N; ++i) 
	{
		fa[i] = i;
		minw[i] = maxw[i] = a[i];
		maxdown[i] = maxup[i] = 0;
	}
	
	for (int i = 1; i <= N; ++i) vis[i] = false;
	tot = 1;
	dfs(1, 0);
	
	for (int i = 1; i <= M; ++i) cout << ans[i] << endl;
}

int main()
{
	read();
	check();
}
