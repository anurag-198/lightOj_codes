#include <bits/stdc++.h>
#define ll long long
int seti[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
ll sum, n, l, r, mul ;
using namespace std;
void printPowerseti(int si)
{
    /*seti_size of power seti of a seti with seti_size
      n is (2**n -1)*/
    sum = 0;
    unsigned int pow_seti_size = pow(2, si);
    int counter, j, k;
    ll a1, a2, temp;
 
    /*Run from counter 000..0 to 111..1*/
    for(counter = 3; counter < pow_seti_size; counter++)
    {	
    	temp = 0;
    	for (k = 0; k < 15; k++) {
    		if (counter & (1 << k)) {
    				temp++;
    		}
    	}
    	if (temp != 1) {  		
    		mul = 1;
      for(j = 0; j < 15; j++)
       {

          /* Check if jth bit in the counter is seti
             If seti then pront jth element from seti */
          if(counter & (1<<j))
            mul = mul * seti[j];
       }
        a1 = l / mul;
    a2 = r / mul;
    //cout << mul << " " << a2 - a1  << endl;
    sum += a2 - a1;
   }
    
   


      
    }
}


int main () {
  std::ios::sync_with_stdio(false);
	
	int tc;
	
	ll b, ul;
	ll ans;
  ll sum1, sum2;
	
	cin >> tc;
	while (tc--) {
    sum1 = 0; sum2 = 0;
     ans  = 0;
		cin >> n >> l >> r;
		l = l - 1; 	
		int i = 0;
		for (i = 0; i < 15; i++) {
			if (seti[i] < n) {
				sum1 = l/seti[i];
			//cout << sum1 << 	endl;
				sum2 = r/seti[i];
				ans += sum2 - sum1;
      //    cout << sum2 - sum1 <<" " << seti[i] << endl;
			}
      else
        break;
		
		}
    //cout << ans << endl;
    //cout << i - 1 << endl;
    printPowerseti(i);
    //cout << sum << endl;
		cout << ans -  sum<< endl; 	
		
	}

	return 0;

}
