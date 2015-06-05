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

//#define LOCAL

int sum[100005];
int should[100005];

int main()
{
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif

	int n, k, w;
	cin >> n >> k >> w;
	getchar();
	memset(sum, 0, sizeof(sum));
	memset(should, 0, sizeof(should));
	should[0] = 0;
	sum[0] = 0;
	char c;
	for (int i = 1; i < k; i++) {
		scanf("%c", &c);
		should[i] = c - '0';
		sum[i] = sum[i-1] + c - '0';
	}

	for (int i = k; i <= n; i++) {
		scanf("%c", &c);
		should[i] = should[i - k] + c - '0';
		sum[i] = sum[i-1] + c - '0';
	}

	for (int i = 0; i < w; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		int res = (sum[r] - sum[l-1]) - (should[r] - should[l-1]) + 
			(r - l + 1) / k - (should[r] - should[l-1]);
		printf("%d\n", res);
	}

	return 0;
}
