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
const int MAX_C = 15001, MAX_N = 500;
long long C[MAX_C][MAX_N];

void calc()
{
	memset(C, 0, sizeof(C));
	for (int i = 1; i < MAX_C; i++) {
		C[i][0] = 1;
		if (i < 501) {
			C[i][i] = 1;
		}
		for (int j = 1; j < i && j < MAX_N; j++) {
			C[i][j] = C[i-1][j] + C[i-1][j-1];
			C[i][j] %= MOD;
		}
	}
}
vector <int> prime_factor;
void getPrimeFactor(int n)
{
	int lim = floor( sqrt(n * 1.0 + 0.5) );
	for (int i = 2; i <= lim; i++) {
		while (n % i == 0) {
			prime_factor.push_back(i);
			n /= i;
		}
	}
	if (n != 1) {
		prime_factor.push_back(n);
	}
}

int main()
{
#ifdef LOCAL_DEBUG
	freopen("in.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	prime_factor.clear();
	calc();

	for (int i = 0; i < n; i++) {
		int d;
		cin >> d;
		getPrimeFactor(d);
	}
	if (0 == prime_factor.size()) {
		printf("1");
		return 0;
	}
	sort(prime_factor.begin(), prime_factor.end());
	int cur = prime_factor[0];
	int cnt = 1;
	long long res = 1;
	for (int i = 1; i < prime_factor.size(); i++) {
		if (prime_factor[i] == cur) {
			++cnt;
		} else {
			cur = prime_factor[i];
			res *= C[n + cnt - 1][n - 1];
			cnt = 1;
			res %= MOD;
		}
	}
	res *= C[n + cnt - 1][n - 1];
	res %= MOD;
	cout << res;
	return 0;
}