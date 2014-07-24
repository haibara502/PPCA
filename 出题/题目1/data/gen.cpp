#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100010;
int fa[maxn];

int get(int v)
{
	if (fa[v] == v) return v;
	return fa[v] = get(fa[v]);
}

int main()
{
	int N, C; scanf("%d%d", & N, & C);
	cout << N << ' ' << C << endl;
	for (int i = 1; i <= N; ++i) fa[i] = i;
	for (int i = 1; i < N; ++i)
	{
		int a = rand() % N + 1, b = rand() % N + 1;
		while (get(a) == get(b))
			a = rand() % N + 1, b = rand() % N + 1;
		fa[get(a)] = get(b);
		cout << a << ' ' << b << endl;
	}
}
