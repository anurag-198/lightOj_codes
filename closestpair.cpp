#include <bits/stdc++.h>

using namespace std;

int a,b;
double mm = FLT_MAX;

typedef struct point {
	int x, y, z;
}point;

double dis(point p1, point p2) {
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}

double bf(point p[], int n) {
	double min = FLT_MAX;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (dis(p[i],p[j]) < min) {
				min = dis(p[i],p[j]);
				if (mm > min) {
					mm = min;
					a = p[i].z;
					b = p[j].z;
					cout << a <<" " <<b <<".. "<<p[j].z<< " " << mm << endl;
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

double stripclosest (point strip[], int size, double d) {
	double min = d;
	//cout << min;
	qsort(strip, size,sizeof(point),compy);
		for (int i = 0; i < size; i++) {
	//cout << strip[i].x <<" "<< strip[i].y << endl;
	}
	//cout << endl << endl;
   
	for (int i = 0; i < size; i++) 
		for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; j++) {
	//		cout <<"hi\n";
			if (dis(strip[i],strip[j]) < min)
				min = dis(strip[i], strip[j]);
				if (mm > min) {
						mm = min;
						a = strip[i].z;
						b = strip[j].z;
						cout << a <<" " <<b << " " << mm << endl;
				}
	//			cout <<min<<" "<<strip[i].x <<" "<<strip[i].y<<" "<<strip[j].x<<" "<<strip[j].y <<endl ;

		}
	//cout << min << endl;
		return min;
}
double closestu(point p[], int n) {
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
	int j = 0;
	for (int i = 0; i < n; i++) {
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

	int i,n;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
		p[i].z = i;
	}

	printf ("%d %d %.6f\n",a,b,closest(p,n)); 
	for (i = 0; i < n; i++) {
		cout << p[i].x <<" " << p[i].y <<" "<< p[i].z<<endl;
		
	}

	return 0;
}