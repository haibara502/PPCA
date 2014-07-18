#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100010;
int a[maxn];
int N;

void read()
{
	scanf("%d", & N);
	for (int i = 1; i <= N; ++i) scanf("%d", & a[i]);
}

void getans()
{
	int ans = 0;
	sort(a + 1, a + 1 + N);
	for (int i = N; N + 1 - i < i; --i)
		ans += a[i] - a[N + 1 - i];
	cout << ans << endl;
}

int main()
{
	read();
	getans();
}
