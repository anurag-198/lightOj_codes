#include <bits/stdc++.h>

using namespace std;

int flag = 0;
int coun = 0;

void permute(char *a, int i, int n, int k) {
	int j;
	if (coun == k) {
		return;
	}
	if (i == n) {
		cout << a << endl;
		coun++;
		if (coun == k) {	
			return;
		}
	}
	else {
		for (j = i; j <= n; j++) {
			swap (a[i], a[j]);
			permute (a, i + 1, n, k);
			swap(a[j], a[i]);
		}
	}
}

int main() {
	int tc;
	scanf ("%d", &tc);
	int n, k;
	while (tc--) {
		char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		scanf ("%d%d", &n, &k);
		a[n] = '\0';
		permute(a, 0, n - 1, k);
	}
	return 0;
}
