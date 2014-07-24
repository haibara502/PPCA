#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxm = 200010;
class Poi
{
	public:
	int x, y, id, ans;
	bool operator <(const Poi & Q) const
	{
		if (x != Q.x) return x < Q.x;
		return y < Q.y;
	}
	void read(int i)
	{
		scanf("%d%d", & x, & y);
		if (x > y) swap(x, y);
		id = i;
	}
} ques[maxm];
int s[maxm], next[maxm], g1[maxm];
int d[maxm], Max[maxm], Get[maxm];
int value[maxm];
bool p[maxm];
int N, M, total;

void init(int i, int j)
{
	s[++total] = j; next[total] = g1[i]; g1[i] = total;
}

void read()
{
	scanf("%d", & N);
	for (int i = 1; i <= N; ++i) scanf("%d", & value[i]);
	for (int i = 1; i < N; ++i)
	{
		int a, b; scanf("%d%d", & a, & b);
		init(a, b), init(b, a);
	}
	
	scanf("%d", & M);
	for (int i = 1; i <= M; ++i) ques[i].read(i);
}

int gs(int end)
{
	int closed = 0, open = 1;
	memset(p, false, sizeof p);
	p[d[1]] = true;
	Max[1] = Get[1] = value[d[1]];
	while (closed < open)
	{
		int t = d[++closed];
		for (int temp = g1[t]; temp; temp = next[temp]) if (!p[s[temp]])
		{
			d[++open] = s[temp];
			Get[open] = max(Get[closed], Max[closed] - value[s[temp]]);
			Max[open] = max(Max[open], value[s[temp]]);
			if (s[temp] == end)
				return Get[open];
		}
	}
	return -1;
}

inline bool cmp(const Poi & i, const Poi & j)
{
	return i.id < j.id;
}

void getans()
{
	sort(ques + 1, ques + 1 + M);
	
	for (int i = 1; i <= M; ++i)
	{
		if ((ques[i].x == ques[i - 1].x) && (ques[i].y == ques[i - 1].y))
		{
			ques[i].ans = ques[i - 1].ans; continue;
		}
		d[1] = ques[i].x;
		ques[i].ans = gs(ques[i].y);
	}
	
	sort(ques + 1, ques + 1 + M, cmp);
	for (int i = 1; i <= M; ++i) printf("%d\n", ques[i].ans);
}

int main()
{
	read();
	getans();
}
