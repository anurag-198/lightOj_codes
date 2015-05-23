#include <bits/stdc++.h>

using namespace std;

#define size 26
#define forbidden -1
#define not_visited 0
#define visit 1

int x[] = {0,0,1,0,0,-1};	
int y[] = {0,1,0,0,-1,0};
int z[] = {1,0,0,-1,0,0};

int rows,columns,n;
int len[size][size][size];
int visited[size][size][size];

struct point {
	int x;
	int y;
	int z;

	point() {};
	point(int x, int y, int z) {this->y = y; this->x = x; this->z = z;}

};

int main() {
	int tc,m,i,j,k,t,a,b,c;
	bool flag;
	scanf ("%d",&tc);
	string str1,str2,s1,s2,s3;

	
	for(t = 1; t <= tc;t++)  {
		cin >> str1>>str2>>n;
		memset(visited,0,sizeof(visited));

		for(m = 0; m < n; m++) {
			cin >> s1 >> s2 >> s3;
			for (i = 0; i < s1.length();i++)
				for(j = 0; j < s2.length();j++)
					for(k = 0; k < s3.length(); k++) {
						visited[s1[i]-'a'][s2[j]-'a'][s3[k]-'a'] = forbidden;
					}
		}
		
		if (visited[str1[0]-'a'][str1[1]-'a'][str1[2]-'a'] == -1){
			printf("Case %d: %d\n",t, -1);
			continue;
		}
		len[str1[0]-'a'][str1[1]-'a'][str1[2]-'a'] = 0;
		point p;
		queue<point> q;
		q.push(point(str1[0]-'a',str1[1]-'a',str1[2]-'a'));
		flag = true;
		while(!q.empty() && flag) {
			p = q.front();
			q.pop();

			if (p.x == str2[0]-'a' && p.y == str2[1]-'a' && p.z ==str2[2]-'a') {
				flag = false;
				break;
			}
			
			for(m = 0; m < 6; m++){
				a = (p.x+x[m])%26;
				b = (p.y+y[m])%26;
				c = (p.z+z[m])%26;
				
				if(a < 0) a += 26;
				if(b < 0) b += 26;
				if(c < 0) c += 26;
			
				if (visited[a][b][c] == not_visited) {
					visited[a][b][c] = visit;
					len[a][b][c] = len[p.x][p.y][p.z] + 1;
					q.push(point(a,b,c));
				}
			}
		}

		if(!flag) printf("Case %d: %d\n",t,len[p.x][p.y][p.z]);
			else printf("Case %d: %d\n", t, -1);
		
	}
	return 0;
}
