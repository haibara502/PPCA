#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

const int maxn = 13;
string s[maxn], way[1 << (maxn + 1)][maxn];
int cong[maxn][maxn];
int f[1 << (maxn + 1)][maxn];
int N;

void read()
{
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> s[i];
}

void getans()
{
	memset(cong, 0, sizeof cong);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) if (i != j)
			for (int k = 0; k < s[i].size(); ++k)
			{
				bool ff = true;
				int length = 0;
				//if (i == 0) cerr << k << endl;
				for (int l = k; l < s[i].size() && (l - k) < s[j].size(); ++l)
				{
					//if (i == 0) cerr << s[i][l] << ' ' << s[j][l - k] << endl;
					if (s[i][l] != s[j][l - k]) 
					{
						ff = false; break;
					}
					++length;
				}
				if (ff) cong[i][j] = max(cong[i][j], length);
			}
			
//	cerr << cong[0][1] << ' ' << cong[1][0] << endl;
	for (int i = 0; i < (1 << N); ++i)
		for (int j = 0; j < N; ++j) f[i][j] = 1073741824;
	for (int i = 0; i < N; ++i) f[(1 << i)][i] = s[i].size(), way[(1 << i)][i] = s[i];
	
	for (int i = 0; i < (1 << N); ++i)
		for (int j = 0; j < N; ++j) if ((i & (1 << j)) && (f[i][j] != 1073741824))
		{
			for (int k = 0; k < N; ++k) if (!(i & (1 << k)))
			{
				
				string temp = way[i][j];
				for (int l = cong[j][k]; l < s[k].size(); ++l) temp += s[k][l];
				if (f[i | (1 << k)][k] > f[i][j] + (int)s[k].size() - cong[j][k])
				{
					f[i | (1 << k)][k] = f[i][j] + (int)s[k].size() - cong[j][k];
					way[i | (1 << k)][k] = temp;
				}
				else if ((f[i | (1 << k)][k] == f[i][j] + (int)s[k].size() - cong[j][k]) && (temp < way[i | (1 << k)][k]))
					way[i | (1 << k)][k] = temp;
			}
		}
	int ans = 1073741824;
	string an = "";
	for (int i = 0; i < N; ++i) if (f[(1 << N) - 1][i] < ans)
		ans = f[(1 << N) - 1][i], an = way[(1 << N) - 1][i];
	else if ((f[(1 << N) - 1][i] == ans) && (way[(1 << N) - 1][i] < an))
		an = way[(1 << N) - 1][i];
	cout << an << endl;
}

int main()
{
	read();
	getans();
}
