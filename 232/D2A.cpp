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
bool v[105];
int main()
{
#ifdef LOCAL_DEBUG
	freopen("in.txt", "r", stdin);
#endif
	
	int n, p1, p2, t1, t2;
	cin >> n >> p1 >> p2;
	memset(v, 0, sizeof(v));
	for (int i = 0; i < n - 1; i++) {
		cin >> t1 >> t2;
		for (int j = t1; j < t2; j++) {
			v[j] = true;
		}
	}
	int cnt = 0;
	for (int i = p1; i < p2; i++) {
		if (!v[i]) {
			++cnt;
		}
	}
	cout << cnt << endl;
	return 0;
}