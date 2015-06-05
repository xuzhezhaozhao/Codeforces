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
#define mkp make_pair

int main(int argc, char *argv[])
{

#ifdef TEST_OJ
	if (!freopen("test.txt", "r", stdin)) {
		printf("Can't open test.txt!\n");
	}
#endif

	int n, k;
	while (scanf("%d %d", &n, &k) != EOF) {
		int maxK = 0;
		if (n % 2 == 0) {
			maxK = (n * n) / 2;
		} else {
			maxK = n * (n / 2) + (n + 1) / 2;
		}
		int cnt = 0;
		if (maxK < k) {
			printf("NO\n");
		} else {
			printf("YES\n");
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (cnt < k && (i + j) % 2 == 0) {
						++cnt;
						printf("L");
					} else {
						printf("S");
					}
				}
				printf("\n");
			}
		}
	}

	return 0;
}

