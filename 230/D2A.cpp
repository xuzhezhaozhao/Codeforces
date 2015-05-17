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


int main()
{
#ifdef LOCAL_DEBUG
	freopen("in.txt", "r", stdin);
#endif
	
	string s;
	getline(cin, s);
	int n = s.size();
	int cn = 0, ci = 0, ce = 0, ct = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'n') {
			++cn;
		} else if (s[i] == 'i') {
			++ci;
		} else if (s[i] == 'e') {
			++ce;
		} else if (s[i] == 't') {
			++ct;
		}
	}
	ce /= 3;
	int res = min(ci, ce);
	res = min(res, ct);

	cn = (cn - 1) / 2;
	res = min(res, cn);

	cout << res << endl;

	return 0;
}
