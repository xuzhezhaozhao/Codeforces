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

//#define LOCAL	// 提交时注释掉

int main()
{
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	vector <long long> a(n), b(n);
	int x;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		a[i] = x;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		b[i] = x;
	}
	long long joy = 0;
	for (int i = 0; i < n; i++) {
		if (b[i] > 2 * a[i] || b[i] < 2) {
			--joy;
		} else {
			long long t = b[i] / 2;
			if (b[i] % 2 == 1) {		// 奇数
				joy += t * (t + 1);
			} else {
				joy += t * t;
			}
		}
	}
	cout << joy << endl;
	return 0;
}