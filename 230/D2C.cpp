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

int main()
{
#ifdef LOCAL_DEBUG
	freopen("in.txt", "r", stdin);
#endif

	int  _n;
	while (cin >> _n) {
		if (0 == _n) {
			cout << "1" << endl;
			return 0;
		}
		long long n = _n;
		long long res = 4;
		long long t = (long long)n * (long long)n;
		long long sum;
		long long y = sqrt( ( t - 1 ) * 1.0 + 0.5 );
		long long next_y = y;
		for (long long i = 1; i < n; i++) {
			sum = 1;
			y = next_y;
			next_y = y;
			while ( next_y * next_y + (i+1) * (i+1) > t ) {
				--next_y;
			}
			if (next_y >= 0 && y > next_y) {
				sum += y - next_y - 1;
			}
			res += (sum << 2);
		}
		printf("%d\n", res);
	}
	//CHECKTIME();
	return 0;
}