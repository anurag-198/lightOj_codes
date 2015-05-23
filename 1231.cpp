#include <bits/stdc++.h>

using namespace std;

int a[55], c[55];
int val;
void coun(int i, int n, int k) {
		//cout << ans <<"----";
		int ans = 0;
		if (k == 0) {
			val++;
			return;
		}
		if (k < 0) {
//			cout << "hell\n";
			return;
		}
		if (i <= n - 1) {
			for (int j = 0; j <= c[i]; j++) {
				//cout << ans << " "<< j <<endl;
				coun(i + 1,n, k - a[i] * j);
				//cout <<ans <<" " << j  << " " << i<< endl;
			}	
		}
		else 
			return;

}



int main() {
	std::ios::sync_with_stdio(false);
	int tc, n, i,k;
	cin >> tc;
	val = 0;
	while (tc--) {
		cin >> n >> k;
		for(i = 0; i < n; i++) {
			cin >> a[i];
		}

		for (i = 0; i < n; i++) {
			cin >> c[i];
		}

		coun(0,n,k);
		cout << val << endl;
	}

	return 0;
}