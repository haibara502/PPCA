#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 20;
int a[maxn][maxn], b[maxn], mj[(1 << 13)], f[1 << 13];
int show[maxn];

bool read()
{
	if (scanf("%d", & a[0][1]) == EOF) return false;
	for (int i = 2; i <= 5; ++i) scanf("%d", & a[0][i]);
	for (int i = 1; i <= 12; ++i)
		for (int j = 1; j <= 5; ++j) scanf("%d", & a[i][j]);
	return true;
}

int count(int v)
{
	int cnt = 0;
	for (; v; v >>= 1) cnt += (bool)(v & 1);
	return cnt;
}

int calc(int i, int k)
{
	int sum, j, same, bf;
	++i;
	for (j = 1; j < 6; ++j) b[j] = a[k][j];
//	for (j = 1; j < 6; ++j) cerr << b[j] << ' ' ;
//	cerr << endl;
	sort(b + 1, b + 6);
//	for (j = 1; j < 6; ++j) cerr << b[j] << ' ' ;
//	cerr << endl;
	switch (i)
	{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
			sum = 0;
			for (j = 1; j < 6; ++j) 
				if (a[k][j] == i) sum += i;
			return sum;
		case 7:
			sum = 0;
			for (j = 1; j < 6; ++j) sum += a[k][j];
			return sum;
		case 8:
		case 9:
		case 10:
			same = 1, bf = b[1], sum = 0;
			for (j = 2; j < 6; ++j) if (b[j] == b[j - 1])
			{
				if (bf != b[j]) 
					sum = max(sum, same), same = 1, bf = b[j];
				++same;
			}
			sum = max(sum, same);
			if (sum >= (i - 5))
			{
				if (i == 10) return 50;
				sum = 0;
				for (j = 1; j < 6; ++j) sum += a[k][j];
				return sum;
			}
			return 0;
		case 11:
			memset(show, 0, sizeof show);
			for (j = 1; j < 6; ++j) show[b[j]] = 1;
			bf = 1;
			for (j = 1; j < 5; ++j) if (!show[j]) 
			{
				bf = 0; break;
			}
			if (bf) return 25;
			bf = 1;
			for (j = 2; j < 6; ++j) if (!show[j])
			{
				bf = 0; break;
			}
			if (bf) return 25;
			bf = 1;
			for (j = 3; j < 7; ++j) if (!show[j])
			{
				bf = 0; break;
			}
			if (bf) return 25;
			return 0;
		case 12:
			bf = 1;
			for (j = 1; j < 6; ++j) if (b[j] != j) 
			{
				bf = 0; break;
			}
			if (bf) return 35;
			bf = 1;
			for (j = 2; j < 7; ++j) if (b[j - 1] != j)
			{
				bf = 0; break;
			}
			if (bf) return 35;
			return 0;
		case 13:
			memset(show, 0, sizeof show);
			for (j = 1; j < 6; ++j) ++show[b[j]];
			same = 0, sum = 0;
			for (j = 1; j <= 6; ++j) if (show[j] == 2) same = 1;
			else if (show[j] == 3) sum = 1;
			if (same && sum) return 40;
			same = 0;
			for (j = 1; j <= 6; ++j) if (show[j] == 5) same = 1;
			if (same) return 40;
			return 0;
	}
}

void getans()
{
	memset(f, 0, sizeof f);
	int l = 0;
	for (int i = 0; i <= 12; ++i)
	{
		int r = l;
		for (; (r < (1 << 13) - 1) && (count(mj[r + 1]) == count(mj[l])); ++r);
		for (int temp = l; temp <= r; ++temp)
		{
			int j = mj[temp];
			for (int k = 0; k < 13; ++k) if (!(j & (1 << k)))
			{
				int score = calc(i, k) + f[j];
				if ((i == 5) && (score >= 63)) score += 35;
				f[j | (1 << k)] = max(f[j | (1 << k)], score);
			}
		}
		l = r + 1;
	}
	
	cout << f[(1 << 13) - 1] << endl;
}

inline bool cmp(const int & i, const int & j)
{
	return count(i) < count(j);
}

int main()
{
	for (int i = 0; i < (1 << 13); ++i) mj[i] = i;
	sort(mj, mj + (1 << 13), cmp);
	while (read())
		getans();
}
