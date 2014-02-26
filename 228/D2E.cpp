// Fox and Card Game

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

//#define LOCAL	// Ìá½»Ê±×¢ÊÍµô  /*******************************************/

#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	
	int n;
	vector <int> middle;
	while (cin >> n) {
		middle.clear();
		int cnt1, cnt2;
		cnt1 = cnt2 = 0;
		for (int i = 0; i < n; i++) {
			int s;
			cin >> s;
			int t = s / 2;
			int c;
			for (int j = 0; j < t; j++) {
				scanf("%d", &c);
				cnt1 += c;
			}
			if (s & 1) {	// odd
				scanf("%d", &c);
				middle.push_back(c);
			}
			for (int j = 0; j < t; j++) {
				scanf("%d", &c);
				cnt2 += c;
			}
		}
		sort(middle.begin(), middle.end(), greater <int>() );
		for (int i = 0; i < middle.size(); i += 2) {
			cnt1 += middle[i];
			if (i + 1 < middle.size()) {
				cnt2 += middle[i + 1];		
			}
		}
		cout << cnt1 << " " << cnt2 << endl;
	}

	return 0;
}