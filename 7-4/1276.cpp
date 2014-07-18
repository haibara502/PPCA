#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

const int maxn = 1010;
int N, M, min_length, max_length;
string s[maxn];

void read()
{
	scanf("%d%d", & N, & M);
	for (int i = 0; i < N; ++i) cin >> s[i];
}

bool can(int l1, int l2, int len, int j)
{
	for (int i = 0; i < len; ++i)
		if (s[j][l1 + i] != s[j][l2 + i]) return false;
	return true;
}

bool check(int limit)
{
//	cerr << "limit  " << limit << endl;
	for (int begin = 0; begin <= min_length - limit; ++begin)
	{
		int cnt = 0;
		
			for (int i = begin; i <= s[j].size() - limit;)
				if (can(i, begin, limit, j))
				{
		//			cerr << "cnt " << cnt + 1 << endl;
			//		cerr << i << endl;
					++cnt, i += limit;
				//	cerr << i << ' ' << begin << endl;
					if (cnt >= M) return true;
				}
				else ++i;
	}
	return false;			
}

void getans()
{
	max_length = s[0].size();
	for (int i = 1; i < N; ++i) max_length = max(max_length, (int)s[i].size());
	min_length = s[0].size();
	for (int i = 1; i < N; ++i) min_length = min(min_length, (int)s[i].size());
	int l = 1, r = min_length, ans = 0;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid))
			l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	cout << ans << endl;
}

int main()
{
	read();
	getans();
}
