#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <sstream>

using namespace std;

const int maxn = 110;
int a[maxn][maxn], fa[maxn], last[maxn], next[maxn];
int N;
char ss[1000100];

void read()
{
	scanf("%d", & N);
	gets(ss);
	istringstream s;
	for (int i = 1; i <= N; ++i)
	{
		gets(ss);
		s.clear();
		s.str(ss);
		int number;
		a[i][0] = 0;
		while (s >> number)
			a[i][++a[i][0]] = number;
	}
}

inline int get(int v)
{
	if (fa[v] == v) return v;
	return fa[v] = get(fa[v]);
}

void getans()
{
	for (int i = 1; i <= N; ++i) last[i] = fa[i] = next[i] = i;
	
	for (int i = 1; i < N; ++i)
	{
		int x, y; scanf("%d%d", & x, & y);
		next[last[get(y)]] = get(x);
		last[get(y)] = last[get(x)];
		fa[get(x)] = get(y);
	}
	
	for (int i = 1; i <= N; ++i) if (get(i) == i)
	{
		while (1){
			for (int j = 1; j <= a[i][0]; ++j) cout << a[i][j] << ' ';
			if (i == next[i]) break;
			i = next[i];
		}
		break;
	}
}

int main()
{
	read();
	getans();
}
