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
	
	int n, p, k;
	while (cin >> n >> p >> k) {
		int L, R;
		L = p - k;
		R = p + k;
		bool LL = true, RR = true;
		if (L <= 1) {
			L = 1;
			LL = false;
		}
		if (R >= n) {
			R = n;
			RR = false;
		}
		if (LL) {
				cout << "<< ";
		}
		for (int i = L; i <= R; i++) {

			if (i == p) {
				printf("(%d) ", i);
			} else {
				printf("%d ", i);
			}
		}
		if (RR) {
			cout << ">>";
		}
		cout << endl;
	}
	


	return 0;
}