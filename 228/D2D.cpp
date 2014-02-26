// Fox and Minimal path

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

bool G[1001][1001];
int b[32];

inline void addEdge(int i, int j) { G[i][j] = G[j][i] = true; }

int main()
{
//#define LOCAL	// Ìá½»Ê±×¢ÊÍµô
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	
	int k;
	while (cin >> k) {
		memset(G, 0, sizeof(G));
		int temp = k;
		for (int i = 0; i < 32; i++) {
			b[i] = temp & 1;
			temp >>= 1;
		}
		int mxbit = 0;
		for (int i = 31; i >= 0; i--) {
			if (b[i]) {
				mxbit = i;
				break;
			}
		}
		int layers = mxbit + 2;
		addEdge(1, 3);
		addEdge(1, 4);
		int id = 3;
		int last_id = 3;

		for (int i = 2; i < layers; i++) {
			for (int j = 0; j < i; j++) {
				addEdge(id + j, id + j + i);
				addEdge(id + j, id + i + i);
			}
			id += i;
			last_id = id;
		}
		for (int i = 0; i <= mxbit; i++) {
			if (b[i]) {
				addEdge(last_id + i + 1, 2);
			}
		}
		printf("%d\n", last_id + layers - 1);
		for (int i = 1; i <= last_id + layers - 1; i++) {
			for (int j = 1; j <= last_id + layers - 1; j++) {
				if (G[i][j] ) {
					printf("Y");
				} else {
					printf("N");
				}
			}
			printf("\n");
		}
	}

	return 0;
}