#include <bits/stdc++.h>
#define ll long long 
using namespace std;

typedef struct point {
	ll x, y;
}point;

ll a1,b1,a2,b2;

double mm = FLT_MAX;

double dis(point p1, point p2) {
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}

double bf(point p[], ll n) {
	double min = FLT_MAX;
	for (ll i = 0; i < n; i++)
		for (ll j = i + 1; j < n; j++)
			if (dis(p[i],p[j]) < min) {
				min = dis(p[i],p[j]);
				if (mm > min) {
						mm = min;
						a1 = p[i].x;
						b1 = p[i].y;
						a2 = p[j].x;
						b2 = p[j].y;												
				}
			}
		
	return min;
}

int compx(const void *a, const void *b) {
	point *p1 = (point *)a, *p2 = (point *)b;
	return (p1->x - p2->x); 
}

int compy(const void *a, const void *b) {
	point *p1 = (point *)a, *p2 = (point *)b;
	return (p1->y - p2->y); 
}

double stripclosest (point strip[], ll size, double d) {
	double min = d;
	//cout << min;
	qsort(strip, size,sizeof(point),compy);
		for (ll i = 0; i < size; i++) {
	//cout << strip[i].x <<" "<< strip[i].y << endl;
	}
	//cout << endl << endl;
   
	for (ll i = 0; i < size; i++) 
		for (ll j = i+1; j < size && (strip[j].y - strip[i].y) < min; j++) {
	//		cout <<"hi\n";
			if (dis(strip[i],strip[j]) < min)
				min = dis(strip[i], strip[j]);
				if (mm > min) {
						mm = min;
						a1 = strip[i].x;
						b1 = strip[i].y;
						a2 = strip[j].x;
						b2 = strip[j].y;												
				}
	//			cout <<min<<" "<<strip[i].x <<" "<<strip[i].y<<" "<<strip[j].x<<" "<<strip[j].y <<endl ;

		}
	//cout << min << endl;
		return min;
}
double closestu(point p[], ll n) {
	if (n <= 3) {
		return bf(p, n);
	}

	int mid = n / 2;
	point midp = p[mid];
	double dl = closestu(p, mid);
	double dr = closestu(p+mid,n - mid);
	//cout << dl <<" "<< dr << endl;
	double d = min(dl,dr);
	//cout << d;

	point strip[n];
	ll j = 0;
	for (ll i = 0; i < n; i++) {
		if (abs(p[i].x - midp.x) < d) {
			strip[j].x = p[i].x;
			strip[j].y = p[i].y;
			j++;
		}
	}
	
	//cout <<d <<" "<< stripclosest(strip,j,d) <<" "<< min(d,stripclosest(strip,j,d))<<endl;
	return min(d, stripclosest(strip,j,d) );
}

double closest(point p[], int n) {
	qsort(p, n, sizeof(p), compx);
/*		for (int i = 0; i < n; i++) {
		cout << p[i].x <<" "<< p[i].y << endl;
	}*/
	//	cout << closestu(p,n) << endl;
	return closestu(p,n);
}

int main() {
	point p[30003];
	map <pair<ll , ll>, ll> mi;
	ll i,n;
	ll ans1;
	ll ans2;
	double ans = 0;
	cin >> n;
	int flag = 0;
	for (i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;

		if (mi.find(make_pair(p[i].x,p[i].y)) != mi.end()) {
				
				flag = 1;
				ans1 = mi[make_pair(p[i].x,p[i].y)];
				ans2 = i;
		}
		else {
			mi[make_pair(p[i].x,p[i].y)] = i;
		}
	}
	

	if (flag) {
		cout << ans1<<" "<< ans2<<" "<< fixed<<setprecision(6) << ans<<endl;
		return 0;
	}
	ans = closest(p,n);
    ans1 = mi[make_pair(a1,b1)];
	ans2 = mi[make_pair(a2,b2)];
	
	if (ans1 < ans2){
		cout << ans1<<" "<< ans2<<" "<< fixed<<setprecision(6) << ans<<endl;
	} 
	else {
		cout << ans2 <<" "<< ans1 <<" "<<fixed <<setprecision(6) << ans <<endl;
	}
	
	return 0;
}
