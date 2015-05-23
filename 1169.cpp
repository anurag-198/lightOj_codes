#include <bits/stdc++.h>

using namespace std;

int main() {

	int tc,i,j,n;
	cin >> tc;
	int jmp[1001][2];
	int tim[1001][2];
	int dp[1001][2];
	for (i = 1; i <= tc; i++) {
		cin >> n;
		for (j = 0; j < n; j++) {
			cin >> tim[j][0];
		}		
		for (j = 0; j < n; j++) {
			cin >> tim[j][1];
		}
		for (j = 0; j < n - 1; j++) {
			cin >> jmp[j][0];
		}
		for (j = 0; j < n - 1; j++) {
			cin >> jmp[j][1];
		}
		dp[0][0] = tim[0][0];
		dp[0][1] = tim[0][1];

		for (j = 1; j < n; j++) {
			dp[j][0] = min(dp[j - 1][0] + tim[j][0], dp[j - 1][1] + tim[j][0] + jmp[j - 1][1]);
			dp[j][1] = min(dp[j - 1][1] + tim[j][1], dp[j - 1][0] + tim[j][1] + jmp[j - 1][0]);
		}
		
		cout << "Case "<< i << ": "<< min(dp[n - 1][0], dp[n - 1][1]) << endl;		
		
	}
	return 0;
}
