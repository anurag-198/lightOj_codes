#include <bits/stdc++.h>
#define ll long long
using namespace std;

int partition (long long a[], long long p, ll r) {
        ll x = a[r];
        ll i = p - 1;
        ll j;

        for (j = p; j < r; j++) {
                if (a[j] <= x) {
                        i++;
                        swap(a[j],a[i]);
                }
        }
        swap(a[i + 1], a[r]);
        return (i + 1);
}

void quickselect(ll a[], ll p, ll r, ll k) {
        ll q;
        if (p < r) {
                q = partition(a, p, r);
		
		if (q == k) {
			cout << a[q] << endl;
		}
		 if (k < q) {
                	quickselect(a, p, q - 1,k);
		}
		if (k > q)
                	quickselect(a, q + 1, r,k);
        }
}

int main() {
     //   std::ios::sync_with_stdio(false);
        ll n,j, q, i;
        char ch;
        ll v1,v2;
        cin >> n;
        ll a[n];
        long long b[n];

        for (i = 0; i < n; i++) {
                cin >> a[i];
        }
        
        cin >> q;
        for (i = 0; i < q; i++) {
                cin >> ch;
                if (ch == 'U') {
                        cin >> v1 >> v2;
                        a[v1 - 1] = v2;
                        for (j = 0; j < n; j++) 
                                b[j] = a[j];
                       // cout << b[4];
                }
                if (ch == 'P') {
                        cin >> v1;
                       quickselect(b,0,n,v1-1);                       //for (j = 0; j < n; j++) {
                          //      cout << b[j];
                        //}
                }
                
        }

       // int i,a[] = {2,6,3,8,12,1,0};
        //int k = quickselect(a,0,6,5);
        //cout << k;
        return 0;
}

