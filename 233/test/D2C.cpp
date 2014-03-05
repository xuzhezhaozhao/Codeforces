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

int main()
{
#ifdef LOCAL_DEBUG
	freopen("in.txt", "r", stdin);
#endif

	long long a, b;

	cin >> a >> b;
	long long res = -1000000000000000000LL;
	if (a == 0 || b == 0) {
		if (a == 0) {
			res = -(b * b);
			cout << res << endl;
			for (int i = 0; i < b; i++) {
				printf("x");
			}
		} else {
			res = a * a;
			cout << res << endl;
			for (int i = 0; i < a; i++) {
				printf("o");
			}
		}
	} else {
		if (b == 1) {
			res = a * a - 1;
			cout << res << endl;
			for (int i = 0; i < a; i++) {
				printf("o");
			}
			printf("x");
			return 0;
		}

		int di = 0;
		long long t;
		int cnt1 = 0, cnt2 = 0;
		for (int i = 1; i <= a + 1 && i <= b; i++) {
			if (i == 1) {
				t = a * a - b * b;
			} else {
				// 将b分成i份
				int part = b / i;	// 每份
				int adds = b % i;	// 多余的
				int pre_a = a - (i - 2);			
				t = (pre_a) * (pre_a) + i - 2 - ( adds * (part + 1) * (part + 1) + (i-adds) * part * part );
			}

			if (res < t) {
				di = i;
				res = t;
			}
		}
		cout << res << endl;
		if (di == 1) {
			for (int i = 0; i < a; i++) {
				printf("o");
			}
			for (int i = 0; i < b; i++) {
				printf("x");
			}
			return 0;
		}
		int i = di;
		int part = b / i;	// 每份, 至少为1
		int adds = b % i;	// 多余的
		int pre_a = a - (i - 2);

		for (int j = 0; j < adds; j++) {
			for (int k = 0; k < part + 1; k++) {
				printf("x"); ++cnt1;
			}
			printf("o"); ++cnt2;
		}
		for (int j = 0; j < i - adds - 1; j++) {
			for (int k = 0; k < part; k++) {
				printf("x"); ++cnt1;
			}
			printf("o"); ++cnt2;
		}
		for (int j = 0; j < pre_a - 1; j++) {
			printf("o"); ++cnt2;
		}
		for (int k = 0; k < part; k++) {
			printf("x"); ++cnt1;
		}
		if (cnt1 != b || cnt2 != a) {
			exit(-1);

		}
	}


	return 0;
}


