// Fox and Box Accumulation

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

//#define LOCAL	// Ìá½»Ê±×¢ÊÍµô
int x[105];
int v[105];

int main()
{
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int n;
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> x[i];
			v[i] = 1;
		}
		sort(x, x + n);
		int ans = n;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (x[j] >= v[i]) {
					x[j] = min(x[j] - v[i], x[i]);
					v[j] += v[i];
					v[i] = 0;
					--ans;
					break;
				}
			}
		}
		cout << ans << endl;
	}



	return 0;
}