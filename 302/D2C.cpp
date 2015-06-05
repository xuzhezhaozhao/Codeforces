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

int dp[501][501];
int main(int argc, char *argv[])
{

#ifdef TEST_OJ
	if (!freopen("test.txt", "r", stdin)) {
		printf("Can't open test.txt!\n");
	}
#endif

	int n, m, b, mod;
	int a;
	while (scanf("%d %d %d %d", &n, &m, &b, &mod) != EOF) {
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int k = 0; k < n; k++) {
			if (scanf("%d", &a)) { }
			for (int r = 1; r <= m; r++) {
				for (int c = a; c <= b; c++) {
					dp[r][c] += dp[r - 1][c - a];
					dp[r][c] %= mod;
				}
			}
		}

		int res = 0;
		for (int i = 0; i <= b; i++) {
			res += dp[m][i];
			res %= mod;
		}
		printf("%d\n", res);
	}

	return 0;
}

