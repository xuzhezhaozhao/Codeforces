// Fox and Cross

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

//#define LOCAL	// 提交时注释掉

int main()
{
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	getchar();	// read '\n'
	vector <string> board(n);
	for (int i = 0; i < n; i++) {
		getline(cin, board[i]);
	}
	string res = "YES";
	for (int i = 0; i < n; i++) {	// 行
		bool flag = true;
		for (int j = 0; j < n; j++) {	// 列
			if ('#' == board[i][j]) {
				if (j - 1 < 0 || j + 1 > n - 1 ||
					i + 2 > n - 1) {
					res = "NO";
					flag = false;
					break;
				}
				char & a = board[i+1][j-1];
				char & b = board[i+1][j];
				char & c = board[i+1][j+1];
				char & d = board[i+2][j];
				
				if ('.' == a || '.' == b || '.' == c || '.' == d) {
					res = "NO";
					flag = false;
					break;
				}
				board[i][j] = '.';
				a = b = c = d = '.';
			}
		}
		if (!flag) {
			break;
		}
	}
	cout << res << endl;
	return 0;
}