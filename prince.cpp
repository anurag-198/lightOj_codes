#include <bits/stdc++.h>
# define MAX 405
using namespace std;
int flag=0;
vector <int>G[MAX];
set <int> s;
set< int > :: iterator it;
map<int , int > m;
int visited[MAX];

unsigned bfs(int sor)
{
    queue<int> q;
    q.push(sor);

    int count = 1;
    visited[sor]=1;
  
    while(!q.empty())
    {
            int u=q.front();
            q.pop();
       
            for(unsigned j=0;j<G[u].size();j++)
            {
               
		unsigned v=G[u][j];
                if(!visited[v])
                {
                    visited[v]=1;
                    q.push(v);
		    count++;
                }
            }
        }
    return count;
}

int main()
{
    int e,i,j=1,cas,l,k,m,count = 0;
    int rows, col;    
    scanf("%d",&cas);
    m = cas;
    while(cas--)
    {
	char set[21][21];

        memset(visited,0,sizeof(visited));
        scanf("%d%d",&col,&rows);

        for(i = 1; i <= rows; i++) {
		for (j = 1; j <= col; j++) {
			scanf(" %c", &set[i][j]);
		}
	} 
	 
	for (i = 1; i <= rows; i++) {
		for (j = 1; j <= col; j++) {
			if ((set[i][j] == '.') || (set[i][j] == '@')) {
				s.insert(col * (i - 1) + j);
				if ((set[i + 1][j] == '.') && ((i + 1) <= rows)) {
					G[(col * (i - 1) + j)].push_back((col * i) + j);
				}
				if ((set[i - 1][j] == '.') && ((i - 1) >= 1)) {
					G[(col * (i - 1) + j)].push_back((col * (i - 2) + j));
				}
				if ((set[i][j + 1] == '.') && ((j + 1) <= col)) {
					G[(col * (i - 1) + j)].push_back((col * (i - 1)) + (j + 1));
				}
				if ((set[i][j - 1] == '.') && ((j - 1) >= 1)) {
					G[(col * (i - 1) + j)].push_back((col * (i - 1)) + (j - 1));
				}				
			}
			if (set[i][j] == '@') {
				k = (col * (i - 1) + j);
			}
		}
	}
         
     	l = bfs(k);
        printf("Case %d: ",m - cas);
        printf("%d\n",l);
        int i = col * rows;
        while(i--)
            G[i].clear();
        s.clear();
    }
    return 0;
}
