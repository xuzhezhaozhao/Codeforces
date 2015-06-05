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
int num[1000000 + 5];
int main()
{
#ifdef LOCAL_DEBUG
	freopen("in.txt", "r", stdin);
#endif
	int p, x;
	while (cin >> p >> x) {
		int c;	//½øÎ»
		int temp;
		bool ok = false;
		for (int d = 1; d <= 9; d++) {
			num[0] = d;
			c = 0;
			if (p == 1) {
				if (x == 1) {
					ok = true;
					break;
				} else {
					break;
				}
			}
			for (int i = 1; i < p; i++) {
				temp = x * num[i-1] + c;
				num[i] = temp % 10;
				c = temp / 10;
				if (i == p - 1) {
					temp = x * num[i] + c;
					if (temp == d && num[i] != 0) {
						ok = true;
						break;
					}
				}
			}
			if (ok) {
				break;
			}
		}
		if (ok) {
			for (int i = p - 1; i >= 0; i--) {
				printf("%d", num[i]);
			}
			cout << endl;
		} else {
			cout << "Impossible" << endl;
		}
	}
	return 0;
}