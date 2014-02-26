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
int matrix[1001][1001];
int main()
{
#ifdef LOCAL_DEBUG
	freopen("in.txt", "r", stdin);
#endif
	
	int n, m;
	while (cin >> n >> m) {
		int cnt00 = 0, cnt01 = 0, cnt11 = 0;
		int nm = n * m;
		int d;
		memset(matrix, 0, sizeof(matrix));
		for (int i = 0; i < nm; i++) {
			scanf("%d", &d);
			if (d == 1 || d == 10) {
				++cnt01;
			} else if (d == 0) {
				++cnt00;
			} else {
				++cnt11;
			}
		}
		int row_10;
		int flag =false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (cnt11 != 0) {
					matrix[i][j] = 11;
					--cnt11; 
				} else {
					for (int k = j; k < m; k++) {
						if (cnt01 != 0) {
							matrix[i][k] = 1;
							--cnt01;
						}
					}
					row_10 = i + 1;
					flag = true;
					break;
				}
			}
			if (flag) {
				break;
			}
		}
		for (int i = row_10; i < n; i++) {
			for (int j = m - 1; j >= 0; j--) {
				if (cnt01 != 0) {
					if (i - 1 >= 0) { 
						if (matrix[i-1][j] == 1) {
							matrix[i][j] = 10;
						} else {
							matrix[i][j] = 1;
						}
					} else {
						matrix[i][j] = 1;
					}
					--cnt01;
				}
			}
		}



		int temp;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				temp = matrix[i][j];
				if (11 == temp) {
					printf("11 ");
				} else if (10 == temp) {
					printf("10 ");
				} else if (1 == temp) {
					printf("01 ");
				} else {
					printf("00 ");
				}
			}
			printf("\n");
		}
	}

	return 0;
}