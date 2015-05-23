#include <bits/stdc++.h>
#define ll long long

using namespace std;

int a[101];
ll dp[10001];
ll val;

ll coun(int n, int k) {
		ll i,j,ans = 0;
		for (i = 0; i < n; i++) {
			for (j = 1; j <= k; j++) {
					if (j >= a[i])
						dp[j] = (dp[j] + dp[j - a[i]]) % 100000007;
			}
		}
		
		return dp[k];		
}



int main() {
	
	int tc, n, i,k;
	scanf ("%d", &tc);
	val = 0;

	for (int j = 1; j <= tc; j++) {

		memset(dp,0,sizeof(dp));
		dp[0] = 1;

		scanf ("%d%d", &n, &k);
		for(i = 0; i < n; i++) {
			scanf ("%d", &a[i]);
		}

		printf("Case %d: %lld\n",j,coun(n,k));
		
	}

	return 0;
}