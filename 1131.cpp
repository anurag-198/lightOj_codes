#include <bits/stdc++.h>
#define ll long long 
using namespace std;

void mul(ll a[6][6], ll b[6][6], ll mod)
{
    ll c[6][6];
    int i;
    int j;
    for(i = 0; i < 6; i++) {
        for(j = 0; j < 6; j++) {
            c[i][j] = 0;
        }
    }
    int k;
    for(i = 0; i < 6; i++) {
        for(j = 0; j < 6; j++) {
            for(k = 0; k < 6; k++) {
                c[i][j] = (c[i][j]%mod + (a[i][k] % mod* b[k][j]%mod) % mod)%mod;
            }
        }
    }
    for(i = 0; i < 6; i++) {
        for(j = 0; j < 6; j++) {
            a[i][j] = c[i][j];
        }
    }
}  
void mat_mul(ll mat[6][6], ll n,ll a1,ll b1,ll c1,ll a2,ll b2,ll c2,ll mod)
{
    if(n == 0 || n == 1) {
        return;
    }
    mat_mul(mat,n/2,a1,b1,c1,a2,b2,c2,mod);
    ll m[6][6] = {{a1,b1,0,0,0,c1},{1,0,0,0,0,0},{0,1,0,0,0,0},{0,0,c2,a2,b2,0},{0,0,0,1,0,0},{0,0,0,0,1,0}};
    mul(mat,mat,mod);
    if(n % 2 != 0) {
        mul(mat,m,mod);
    }
}

void fibo(ll a1,ll b1,ll c1,ll a2,ll b2,ll c2,ll f0,ll f1,ll f2,ll g0,ll g1,ll g2,ll n,ll m,ll *ans1,ll *ans2)
{
    ll mod = m;
    ll mat[6][6] = {{a1,b1,0,0,0,c1},{1,0,0,0,0,0},{0,1,0,0,0,0},{0,0,c2,a2,b2,0},{0,0,0,1,0,0},{0,0,0,0,1,0}};
    mat_mul(mat,n,a1,b1,c1,a2,b2,c2,mod);
    int i;
    int j;
   
//	cout << mat[0][0] <<" "<<mat[0][1] <<" "<<mat[0][5]<<""<<endl;
    *ans1 = (((mat[0][0] * f2) % m) + ((mat[0][1] * f1) % m) + ((mat[0][2] * f0)%m) + ((mat[0][3]*g2)%m)+((mat[0][4]*g1)%m)+ ((mat[0][5] * g0)%m)) % m;
    if (*ans1 < 0) {
	*ans1 += m;
    }
    *ans2 = (((mat[3][0]*f2)%m) + ((mat[3][1]*f1)%m)+((mat[3][2] * f0) % m) + ((mat[3][3] * g2) % m) + ((mat[3][4] * g1)%m)+((mat[3][5]*g0)%m)) % m;
    if (*ans2 < 0) {
	*ans2 += m;
    }   
}
       
int main()
{
   std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    int k;
   
   
    for(k  = 1; k <= t; k++) {
       
        int i;
       
        ll a1,b1,c1,a2,b2,c2,f0,f1,f2,g0,g1,g2,q,n,m;
        cin >> a1 >> b1 >> c1;
	cin >> a2 >> b2 >> c2;
	cin >> f0 >> f1 >> f2;
	cin >> g0 >> g1 >> g2;
	cin >> m;
	cin >> q;
	f0 = f0 % m;
	g0 = g0 % m;
	f1 = f1 % m;
	g1 = g1 % m;
	g2 = g2 % m;
	f2 = f2 % m;
	
	ll ans[q][2];
       for (i = 0; i < q; i++) {
		cin >> n;
		if (n == 0) {
			ans[i][0] = f0;
			ans[i][1] = g0;
			continue;
		}
		if (n == 1) {
			ans[i][0] = f1;
			ans[i][1] = g1;
			continue;
		}
		if (n == 2) {
			ans[i][0] = f2;
			ans[i][1] = g2;
			continue;
		}

        	fibo(a1,b1,c1,a2,b2,c2,f0,f1,f2,g0,g1,g2,n - 2,m,&ans[i][0],&ans[i][1]);	
	}	
        	cout << "Case " << k << ":\n";
		for (i = 0; i < q; i++) {
			cout << ans[i][0] <<" "<<ans[i][1] << endl;
		}  
  }
   
	return 0;
}
