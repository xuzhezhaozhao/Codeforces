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

//#define LOCAL	// Ìá½»Ê±×¢ÊÍµô
int a[105][105];
int main()
{
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	
	int n;
	cin >> n;
	memset(a, 0, sizeof(a));
	for (int i = 0; i < n; i++) {
		int p1, p2;
		cin >> p1 >> p2;
		a[p1][p2] = true;
	}
	int ans1 = 0;
	int ans2 = 0;
	for (int i = 0; i <= 100; i++) {
		bool flag1 = false;
		bool flag2 = false;
		for (int j = 0; j <= 100; j++) {
			if (a[i][j]) {
				flag1 = true;
			}
			if (a[j][i]) {
				flag2 = true;
			}
		}
		if (flag1) {
			++ans1;
		}
		if (flag2) {
			++ans2;
		}
	}
	cout << min(ans1, ans2) << endl;

	return 0;
}