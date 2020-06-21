#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int vis[1001][1001];
char a[1001][1001];
int n,m;
bool isValid(int x,int y)
{
	if(vis[x][y]==1 || a[x][y]=='#')
		return false;
	if(x<0||x>n-1||y<0||y>m-1)
		return false;

		return true;
}
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void dfs(int x,int y)
{
	vis[x][y]=1;
	
	for (int i = 0; i < 4; ++i)
	{
		if(isValid(x+dx[i],y+dy[i]))
			dfs(x+dx[i],y+dy[i]);
	}
	
}

int main()
{

	
	// #ifndef ONLINE_JUDGE

	// 	 freopen("input.txt","r",stdin);
	// 	 freopen("output.txt","w",stdout); 

	// #endif
	 fastio;
	 
	 cin>>n>>m;
	 for (int i = 0; i < n; ++i)
	 {
	 	for (int j=0;j<m;++j)
	 	{
	 		cin>>a[i][j];
	 	}
	 }
	 int count=0;
	  for (int i = 0; i < n; i++)
	 {
	 	for (int j=0;j<m;j++)
	 	{
	 		if(a[i][j]=='.' && vis[i][j]==0)
	 		{
	 			
	 			dfs(i,j);
	 			count++;
	 		}
	 	}
	 }
		
    cout<<count;

	return 0;
}


//INPUT TEST CASE
/*

10 10
##..###..#
..#.#.....
..#...####
#.....##..
...

*/
// THIS QUESTION IS COUNTING ROOMS FORM CSES WEBSITE