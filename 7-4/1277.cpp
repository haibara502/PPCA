#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 210;
int N, W, F;
int a[maxn];

void read()
{
	scanf("%d%d%d", & N, & W, & F);
	for (int i = 1; i <= N; ++i) scanf("%d", & a[i]);	
}

void getans()
{
	sort(a + 1, a + 1 + N);
	int ans = ceil(W / (N + 1.0));
	cout << ans << endl;
}

int main()
{
	read();
	getans();
}
