#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <sstream>
#include <iomanip>

#include <bitset>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <ctime>
#include <climits>

using namespace std;

#define LOCAL	// Ìá½»Ê±×¢ÊÍµô

bool v[55][55];
vector < pair<int, int> > vp[2505];
int dr[] = {0, 1, -1};
int dc[] = {1, 0,  0};

int main()
{
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	
	int n, m, k;
	cin >> n >> m >> k;
	int _k = k;
	int cnt = 0;
	memset(v, 0, sizeof(v));
	queue < pair<int, int> > q;

	q.push( make_pair(1, 1) );
	map < pair <int, int>,  vector <pair<int, int>> > mp;

	v[1][1] = true;
	vp[k].push_back( make_pair(1, 1) );
	mp[ make_pair(1, 1) ] = vp[k];
	cnt += vp[k].size();
	--k;
	while (k > 0) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		int next_r, next_c;
		for (int i = 0; i < 3; i++) {
			next_r = r + dr[i];
			next_c = c + dc[i];
			if (next_r < 1 || next_r > n ||
				next_c < 1 || next_c > m) {
				continue;
			}
			if (!v[next_r][next_c]) {
				v[next_r][next_c] = true;
				q.push( make_pair(next_r, next_c) );
				vp[k] = mp[ make_pair(r, c) ];
				vp[k].push_back( make_pair(next_r, next_c) );
				mp[ make_pair(next_r, next_c) ] = vp[k];
				cnt += vp[k].size();
				--k;
				if (k <= 0) {
					break;
				}
			}
		}
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= _k; i++) {
		int s = vp[i].size();
		for (int j = 0; j < s; j++) {
			printf("(%d, %d) ", vp[i][j].first, vp[i][j].second);
		}
		printf("\n");
	}

	return 0;
}