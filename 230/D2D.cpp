// Tower of Hanoi

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
typedef long long llong;
typedef pair<llong, llong> pll;
#define mkp make_pair

#define CHECKTIME() printf("%.2lf\n", (double)clock() / CLOCKS_PER_SEC)

long long dp[41][3][3];
int t[3][3];
int n;

int main()
{
#ifdef LOCAL_DEBUG
	freopen("in.txt", "r", stdin);
#endif
	
	while ( cin >> t[0][0] >> t[0][1] >> t[0][2] ) {
		cin >> t[1][0] >> t[1][1] >> t[1][2];
		cin >> t[2][0] >> t[2][1] >> t[2][2];
		cin >> n;
		memset(dp, 0, sizeof(dp));
		for (int cur = 1; cur <= n; cur++) {
			for (int p1 = 0; p1 < 3; p1++) {
				for (int p3 = 0; p3 < 3; p3++) {
					int p2 = 3 - p1 - p3;
					if (p1 == p3) {
						continue;
					}
					dp[cur][p1][p3] = min(
						dp[cur-1][p1][p2] + t[p1][p3] + dp[cur-1][p2][p3],
						dp[cur-1][p1][p3] + t[p1][p2] + dp[cur-1][p3][p1] +
						t[p2][p3] + dp[cur-1][p1][p3]
					);
				}
			}
		}
		cout << dp[n][0][2] << endl;
	}
	return 0;
}