#include <bits/stdc++.h>
#define SIZE 30005
#define MOD 20071027
#define clr(a) memset(a, 0, sizeof a)
#define reset(a) memset(a, -1, sizeof a)

#define BOUNDARY(i, j) ((i >= 0 && i < row) && (j >= 0 && j < column))

#define max3(x, y, z) max(max(x, y), max(y, z)) 

using namespace std;

int n, m, row, column;

int max1[SIZE];
int max2[SIZE];
bool visited[SIZE];
list<pair<int, int> > children[SIZE];
int mx;

int solve(int node)
{
	int weight;
	visited[node] = true;
	for(list<pair<int, int> >::iterator it = children[node].begin(); it != children[node].end(); it++)
	{
		if(!visited[it->first])
		{
			weight = it->second + solve(it->first);
			if(weight >= max1[node])
			{
				max2[node] = max1[node];
				max1[node] = weight;
			}
			else if(weight > max2[node])
				max2[node] = weight;
		}
	}
	mx = max(max1[node] + max2[node], mx);
	return max1[node];
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int i, j, k, l, sum = 0;
	int tc, t, d, x, y, a, b, r, current, first;
	bool flag;
	unsigned long long ln;

	scanf("%d", &tc);
	for(t = 1; t <= tc; t++)
	{
		scanf("%d", &n);
		for(i = 0; i < n; i++)
			children[i].clear();
		clr(max1);
		clr(max2);
		clr(visited);
		mx = 0;
		
		for(i = 1; i < n; i++)
		{
			scanf("%d %d %d", &a, &b, &r);
			children[a].push_back(make_pair(b, r));
			children[b].push_back(make_pair(a, r));
		}
		
		solve(0);
		/*for(i = 0; i < n; i++)
			printf("%d\t%d\n", max1[i], max2[i]);*/
		
		printf("Case %d: %d\n", t, mx);
	}
	
	return 0;
}

