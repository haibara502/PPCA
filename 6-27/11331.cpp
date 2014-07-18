#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1010;
int ch[maxn];
long long f[maxn];
char ss[maxn];

void read()
{
	gets(ss);
}

void getans()
{
	int len = strlen(ss);	
	memset(f, 0, sizeof f);
	memset(ch, -1, sizeof ch);
	
	for (int i = 0; i < len; ++i)
	{
		int j = -1;
		switch (ss[i])
		{
			case 'S' : j = 0; break;
			case 'T' : j = 1; break;
			case 'A' : j = 2; break;
			case 'R' : j = 3; break;
		}
		ch[i] = j;
	}
	
	long long ans = 1073741824;
	long long ans1 = 1;
	for (int i = 0; i < 4; ++i)
	{
		int sum = 0;
		for (int j = 0; j < len; ++j) if (ch[j] == i) ++sum;
		ans = min(ans, (long long)sum);
		ans1 *= sum;
	}
	cout << ans1 << ' ' << ans << ' ';
	
	
}

int main()
{
	read();
	getans();
}
