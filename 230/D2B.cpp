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

int w[200][200];
double A[200][200];
double B[200][200];
void printD(double A[][200], int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%f ", A[i][j]);
		}
		printf("\n");
	}
}
int main()
{
#ifdef LOCAL_DEBUG
	freopen("in.txt", "r", stdin);
#endif
	
	int n;
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &w[i][j]);
			}
		}
		memset(A, -1, sizeof(A));
		memset(B, -1, sizeof(B));

		for (int i = 0; i < n; i++) {
			A[i][i] = w[i][i];
			B[i][i] = 0.0;
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				//A[i][j] + B[i][j] = w[i][j];
				//A[i][j] - B[i][j] = w[j][i];
				A[i][j] = (w[i][j] + w[j][i]) * 1.0 / 2;
				B[i][j] = (w[i][j] - w[j][i]) * 1.0 / 2;
				A[j][i] = A[i][j];
				B[j][i] = -B[i][j];
			}
		}
		printD(A, n);
		printD(B, n);
	}

	return 0;
}
