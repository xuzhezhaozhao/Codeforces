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
		printf("open test.txt error!\n");
	}
#endif

	int k;
	while (scanf("%d", &k) != -1) {
		char q[101];
		if (scanf("%s", q)) {}

		bool v[27] = {false};
		int pos[27];
		int cnt = 0;
		int len = strlen(q);
		for (int i = 0; i < len; i++) {
			if (!v[ q[i] - 'a' ]) {
				v[ q[i] - 'a' ] = true;
				pos[cnt] = i;
				++cnt;
			}
		}
		if (cnt < k) {
			printf("NO\n");
		} else {
			printf("YES\n");
			int start = 0;
			for (int i = 1; i < k; i++) {
				for (int j = start; j < pos[i]; j++) {
					printf("%c", q[j]);
				}
				printf("\n");
				start = pos[i];
			}
			// last one
			for (int i = start; i < len; i++) {
				printf("%c", q[i]);
			}
			printf("\n");
		}
	}

	return 0;
}
