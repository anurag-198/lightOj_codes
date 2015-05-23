#include <bits/stdc++.h>
#define ll long long

using namespace std;

int a[55], c[55];
ll dp[1001][51];
ll val;

ll coun(int i, int n, int k) {
		//cout << ans <<"----";
		ll ans = 0;
		
		if (i == n) {
			if (k == 0) {
			//	cout <<"0yeh";
				return 1;
			}
			return 0;
		}

		if (k == 0) {
			//cout << "0yeh";
			return 1;
/*			val++;
			if (val >= 100000007)
				val = val % 100000007;
			return;*/
		}

		if (k < 0) {
//			cout << "hell\n";
			return 0;
		}

		if (dp[k][i] != -1) {
			return dp[k][i];
		}	
		ans = 0;
		for (int j = 0; j <= c[i]; j++) {
			//cout << ans << " "<< j <<endl;
			ans = (ans + coun(i + 1,n, k - a[i] * j)) % 100000007;
			//cout <<ans <<" " << j  << " " << i<< endl;
		}	
		dp[k][i] = ans;
		return ans;		

}



int main() {
	

	int tc, n, i,k;
	scanf ("%d", &tc);
	val = 0;
	for (int j = 1; j <= tc; j++) {
		ll ans = 0;
		memset(dp,-1,sizeof(dp));
		scanf ("%d%d", &n, &k);

		for(i = 0; i < n; i++) {
			scanf ("%d", &a[i]);
		}

		for (i = 0; i < n; i++) {
			scanf ("%d", &c[i]);
		}

		for (i = 1; i <= k; i++) {
			ans = (ans + coun(0,n,i))%100000007;
			cout << ans << endl;
		}
		printf("Case %d: %lld\n",j,ans);
		val = 0;

	}

	return 0;
}