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
int arrays[3][100000];	// a, b, c
int main()
{
#ifdef LOCAL_DEBUG
	freopen("in.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arrays[i][j]);
		}
	}
	set <int> setA(arrays[0], arrays[0] + n), setB(arrays[1], arrays[1] + n), setC(arrays[2], arrays[2] + n);
	for (int i = n; i >= 0; i--) {
		
	}

	return 0;
}