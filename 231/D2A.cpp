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
	
	int A, B, C;
	int cnt = 0;
	char c;
	while (cin >> c) {
		if ('|' == c) {
			cnt++;
		} else if ('+' == c) {
			A = cnt;
			cnt = 0;
		} else if ('=' == c) {
			B = cnt;
			cnt = 0;
		}
	}
	C = cnt;

	if (A + B != C) {
		if (A + B - 1 == C + 1) {
			C = C + 1;
			if (A != 1) {
				A = A - 1;
			} else {
				B = B - 1;
			}
		} else if (A + B + 1 == C - 1) {
			C = C - 1;
			A = A + 1;
		} else {
			cout << "Impossible";
			return 0;
		}
	}
	for (int i = 0; i < A; i++) {
		cout << "|";
	}
	cout << "+";
	for (int i = 0; i < B; i++) {
		cout << "|";
	}
	cout << "=";
	for (int i = 0; i < C; i++) {
		cout << "|";
	}
	return 0;
}