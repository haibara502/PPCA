#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1100;
class Poi
{
	int l, number[2010];
	void jin()
	{
		for (int i = 1; i <= l; ++i)
		{
			number[i + 1] += number[i] / 10;
			number[i] %= 10;
		}
		while (number[l + 1]) 
		{
			++l;
			number[l + 1] += number[l] / 10;
			number[l] %= 10;
		}
	}
	public:
	Poi():l(1)
	{
		memset(number, 0, sizeof number);
		number[1] = 1;
	}
	void operator *=(const int & Q)
	{
		for (int i = 1; i <= l; ++i) number[i] *= Q;
		jin();
	}
	void print()
	{
		for (int i = l; i; --i) cout << number[i]; 
		cout << endl;
	}
};
int s[maxn * maxn], next[maxn * maxn], g1[maxn];
bool show[maxn];
int N, total, M;

void init(int i, int j)
{
	s[++total] = j; next[total] = g1[i]; g1[i]  = total;
}

void read()
{
	total = 1;
	scanf("%d%d", & N, & M);
	for (int i = 1; i <= M; ++i)
	{
		int a, b;
		scanf("%d%d",  & a, & b);
		init(a, b);
		init(b, a);
	}
}

void dfs(int v)
{
	show[v] = true;
	for (int temp = g1[v]; temp; temp = next[temp]) if ((s[temp]) && (!show[s[temp]]))
		dfs(s[temp]);
}

void getans()
{
	memset(show,false, sizeof show);
	Poi ans;
	total = 0;
	for (int i = 1; i <= N; ++i) if (!show[i])
	{
		dfs(i); ++total;
	}
	for (int i = 1; i <= N - total; ++i) ans *= 2;
	ans.print();
}

int main()
{
	read();
	getans();
}
