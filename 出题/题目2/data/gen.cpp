#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));
	int N; scanf("%d", & N);
	int l_lian; scanf("%d", & l_lian);
	int tuo; scanf("%d", & tuo);
	
	cout << N << endl;
	for (int i = 1; i <= N; ++i) 
	{
		cout << rand() % 100000;
		if (i < N) cout << ' ' ;
		else cout << endl;
	}
	
	for (int i = 1; i < l_lian; ++i) cout << i << ' ' << i + 1 << endl;
	for (int i = l_lian + 1; i <= l_lian + tuo; ++i) cout << 1 << ' ' << i << endl;
	for (int i = l_lian + tuo + 1; i <= l_lian + tuo + tuo; ++i) cout << l_lian << ' ' << i << endl;
	for (int i = l_lian + tuo + tuo + 1; i <= N; ++i)
		cout << i << ' ' << rand() % (l_lian + tuo + tuo) + 1 << endl;
		
	int M; scanf("%d", & M);
	cout << M << endl;
	int total = M / 8 * 3;
	for (int i = l_lian + 1; i <= l_lian + tuo; ++i)
	{
		for (int j = l_lian + tuo + 1; j <= l_lian + tuo + tuo; ++j)
		{
			cout << i << ' ' << j << endl;
			if (--total == 0) break;
		}
		if (total <= 0) break;
	}
	total = M / 8 * 3;
	for (int j = l_lian + tuo + 1; j <= l_lian + tuo + tuo; ++j)
	{
		for (int i = l_lian + 1; i <= l_lian + tuo; ++i)
		{
			cout << j << ' ' << i << endl;
			if (--total == 0) break;
		}
		if (total <= 0) break;
	}
	M -= 2 * (M / 8 * 3);
	while (M--)
		cout << rand() % N + 1 << ' ' << rand() % N + 1 << endl;
}
