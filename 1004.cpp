#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll dp[1001][1001];
ll a[1001][1001];

int main() {
	std::ios::sync_with_stdio(false);
	int tc ,i,j, n,k;

	cin >> tc;
	for (k = 1; k <= tc; k++) {
		memset(a, 0, sizeof(a));
		memset(dp, 0, sizeof(dp));

		cin >> n;

		for (i = 0; i < n; i++) {
			for (j = 0; j <= i; j++)
				cin >> a[i][j];
		}

		for (i = n; i < (2 * n) - 1; i++) {
			for (j = 0; j < (2 * n) - 1 - i; j++) {
				cin >> a[i][j];
			}			
		}

		dp[0][0] = a[0][0];

		for (i = 1; i < n; i++) {
			for (j = 0; j <= i; j++)
				if (j == 0) {
					dp[i][j] = a[i][j] + dp[i - 1][j];
				}
				else {
					dp[i][j] = a[i][j] +  max(dp[i-1][j],dp[i-1][j-1]);
				}
		}

		for (i = n; i < (2 * n) - 1; i++) {
			for (j = 0; j < (2 * n) - 1 - i; j++) {
				dp[i][j] = a[i][j] +  max(dp[i - 1][j], dp[i - 1][j + 1]);
			}			

	}

/*	for (i = 0; i < 2 * n - 1; i++) {
		for (j = 0; j < n;j++) 
			cout << dp[i][j] <<" ";
		cout << endl;
		} */

	cout << "Case "<<k <<": " << dp[2 * n - 2][0] << endl;
	}
	return 0;
}
