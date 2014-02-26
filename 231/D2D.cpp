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

const int MOD = 1e9 + 7;
int num[1001];

inline int absi(int a) {return (a > 0 ? a : -a); }

int main()
{
#ifdef LOCAL_DEBUG
	freopen("in.txt", "r", stdin);
#endif
	int n;
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &num[i]);
		}
		sort(num, num + n);
		int first, step, max_buns = 1000000;
		for (int d = 0; d <= 20000; d++) {
			int mn = num[0], mx = num[0];
			for (int i = 1; i < n; i++) {
				mn = min(mn, num[i] - i * d);
				mx = max(mx, num[i] - i * d);
			}
			int buns = (mx - mn + 1) / 2;
			if (max_buns > buns) {
				max_buns = buns;
				first = (mx + mn) / 2;
				step = d;
			}
		}
		cout << max_buns << endl;
		cout << first << " " << step;
	}
	return 0;
}