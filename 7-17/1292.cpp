#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1000100;
int a[maxn], f[maxn], d[maxn], t[maxn];
bool visit[maxn];
int N;

bool read()
{
	if (scanf("%d", & N) == EOF) return false;
	for (int i = 1; i <= N; ++i) scanf("%d", & a[i]);
}

void getans()
{
	int total = 0;
	memset(visit, false, sizeof visit);
	for (int i = 1; i <= N; ++i) if (!visit[i])
	{
		d[++total] = 0;
		int j = i;
		do
		{
			visit[j] = true;
			++d[total];
			j = a[j];
		} while (j != i);
	}

	int ans = 0;
	for (int i = 1; i <= total; ++i) ans += d[i] - 1;
	cout << ans << endl;
	
	ans = 0;
	for (int i = 1; i <= total; ++i) ans = max(ans, d[i]);
	if (ans > 2) cout << 2 << endl;
	else if (ans == 2) cout << 1 << endl;
	else cout << 0 << endl;
}

int main()
{
	while (read())
		getans();
}
