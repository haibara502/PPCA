#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>

using namespace std;

const int maxn = 100010;
class Poi
{
	public:
	int id, x;
	bool operator <(const Poi & Q) const
	{
		return x < Q.x;
	}
} com[maxn];

int main()
{
	srand(time(0));
	int N; cin >> N;
	cout << N << endl;
	for (int i = 1; i <= N; ++i)
		cout << ((long long)rand() * rand()) % 100000 <<  ' ';
	cout << endl;
	for (int i = 1; i <= N; ++i) com[i].x = rand(), com[i].id = i;
	sort(com + 1, com + 1 + N);
	int hua = rand () % 5 + 1;
	for (int i = 1; i <= hua; ++i)
		cout << com[i].id << ' ' << com[hua + 1].id << endl;
	for (int i = hua + 1; i < N - hua; ++i)
		cout << com[i].id << ' ' << com[i + 1].id << endl;
	for (int i = 1; i <= hua; ++i)
		cout << com[N + 1 - i].id << ' ' << com[N - hua].id << endl;
	
	int M;	
	cin >> M;
	cout << M << endl;	
	for (int j = 1; j <= 3 * M / 4; ++j)
		cout << com[rand() % hua + 1].id << ' ' << com[N - rand() % hua].id << endl;
	for (int j = 3 * M / 4 + 1; j <= M; ++j)
		cout << rand() % N + 1 << ' ' << rand() % N + 1 << endl;
}
