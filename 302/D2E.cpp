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

typedef pair<int, int> pii;
#define mkp make_pair

const int N = 20;
int dp[1 << N];
int exmask[N + 1][N + 1];
int excost[N + 1][N + 1];
int main(int argc, char *argv[])
{

#ifdef TEST_OJ
	if (!freopen("test.txt", "r", stdin)) {
		printf("Can't open test.txt!\n");
	}
#endif

	int n, m;
	char s[21][21];
	int cost[21][21];
	while (scanf("%d %d", &n, &m) != EOF) {
		for (int i = 0; i < n; i++) {
			if (scanf("%s", s[i])) {}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (scanf("%d", &cost[i][j])) {}
			}
		}
		memset(exmask, 0, sizeof(exmask));
		memset(excost, 0, sizeof(excost));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int sumcost = 0;
				int maxcost = 0;
				for (int k = 0; k < n; k++) {
					if (s[k][j] == s[i][j]) {
						sumcost += cost[k][j];
						maxcost = max(maxcost, cost[k][j]);
						exmask[i][j] = (exmask[i][j] | (1 << k));
					}
				}
				excost[i][j] = sumcost - maxcost;
			}
		}

		dp[0] = 0;
		for (int i = 1; i < (1 << n); i++) dp[i] = 1000000000;
		for (int mask = 1; mask < (1 << n); mask++) {
			int lowbit = -1;
			for (int j = 0; j < n; j++) {
				if ( (mask & (1 << j)) ) {
					lowbit = j;
					break;
				}
			}

			for (int j = 0; j < m; j++) {
				dp[mask] = min(dp[mask], dp[ mask ^ (1 << lowbit) ] + cost[lowbit][j]);
				dp[mask] = min(dp[mask], dp[ mask & (mask ^ exmask[lowbit][j]) ] + excost[lowbit][j]);
			}
		}
		printf("%d\n", dp[(1<<n) - 1]);
	}

	return 0;
}

