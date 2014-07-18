#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 262150;
class Poi
{
	public:
	int t;
	long long x;
	void read()
	{
		scanf("%lld%d", & x, & t);
	}
	bool operator <(const Poi & Q) const
	{
		return x < Q.x;
	}
} wangba[maxn];
int d[2][maxn], total[2];
int N;
long long T;

void read()
{
	scanf("%d%lld", & N, & T);
	for (int i = 1; i <= N; ++i) wangba[i].read();
}

void shang(int o, int v)
{
	for (; v > 1; v >>= 1)
	{
		int t = v >> 1;
		if (o == 0)
		{
			if (d[o][t] >= d[o][v]) return;
			swap(d[o][t], d[o][v]);
		}
		else
		{
			if (d[o][t] <= d[o][v]) return;
			swap(d[o][t], d[o][v]);
		}
	}
}

void xia(int o, int v)
{
	for (; (v << 1) <= total[o]; )
	{
		int t = v << 1;
		if (o == 0)
		{
			if ((t < total[o]) && (d[o][t + 1] > d[o][t])) ++t;
			if (d[o][v] >= d[o][t]) return;
			swap(d[o][v], d[o][t]);
		}
		else
		{
			if ((t < total[o]) && (d[o][t + 1] < d[o][t])) ++t;
			if (d[o][v] <= d[o][t]) return;
			swap(d[o][v], d[o][t]);
		}
		v = t;
	}
}

void getans()
{
	sort(wangba + 1, wangba + 1 + N);
	total[0] = total[1] = 0;
	long long sumTotal = 0;
	long long time = 0;
	int ans = 0;
	wangba[0].x = 0;
	for (int i = 1; i <= N; ++i)
	{
		time += wangba[i].x - wangba[i - 1].x;
		if (time > T) break;
		d[0][++total[0]] = wangba[i].t;
		shang(0, total[0]);
		sumTotal += wangba[i].t;
		while (sumTotal + time > T)
		{
			sumTotal -= d[0][1];
			d[1][++total[1]] = d[0][1];
			shang(1, total[1]);
			d[0][1] = d[0][total[0]--];
			xia(0, 1);
		}
		while ((total[1]) && (sumTotal + time + d[1][1] <= T))
		{
			sumTotal += d[1][1];
			d[0][++total[0]] = d[1][1];
			shang(0, total[0]);
			d[1][1] = d[1][total[1]--];
			xia(1, 1);
		}
		ans = max(ans, total[0]);
	}
	cout << ans << endl;
}

int main()
{
	read();
	getans();
}
