#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

ll fast_exp(int base, int exp) {
    ll res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%MOD;
       base=(base*base)%MOD;
       exp/=2;
    }
    return res%MOD;
}

int main() {
	std::ios::sync_with_stdio(false);
	int tc, n;
	int i, j;
	ll ans , sub = 0;
	cin >> tc;
	while (tc--) {
		cin >> n;
		ans = fast_exp(3,n);	

		for (i = 2; i < n; i = i+3) {
			sub = sub + (n - i);
		}

		j = 1;
		for (i = 6; i < n; i = i+3) {
			sub = sub + fast_exp(3,j) * (n - i) % MOD;
		}

		sub = sub % MOD;

		ans = ans - sub;
		if (ans < 0) {
			ans += sub;
		}

		cout << ans << endl;
	}

	return 0;
}