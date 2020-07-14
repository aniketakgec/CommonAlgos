#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


// IF KNIGHT IS PRESENT AT COORDINATE (X,Y)

/*	
	POSSIBLE MOVES FOR KNIGHT FROM (X,Y) ARE:-
	. (X-2,Y-1)

	. (X-2,Y+1)
	
	. (X-1,Y-2)
	
	. (X-1,Y+2)
	
	. (X+1,Y-2)
	
	. (X+1,Y+2)
	
	. (X+2,Y-1)
	
	. (X+2,Y+1)

*/



int dx[]={-2,-1,1,2,2,1,-1,-2};
int dy[]={1,2,2,1,-1,-2,-2,-1};

int target_x,target_y;
int vis[21][21];
int dis[21][21];
bool isValid(int x,int y,int n)
{
	if(x<1 || x>n || y<1 || y>n)
		return false;
	if(vis[x][y]==1)
		return false;

	return true;
}


int BFS(int x,int y,int n)
{
	queue< pair<int,int> > q;
	dis[x][y]=0;
	vis[x][y]=1;
	q.push({x,y});
	if(x==target_x && y==target_y)
		return dis[x][y];

	while(!q.empty())
	{
		int curr_x=q.front().first;
		int curr_y=q.front().second;
		q.pop();
		

		for (int i = 0; i < 8; ++i)
		{
			if(isValid(curr_x+dx[i],curr_y+dy[i],n))
			{
				x=curr_x+dx[i];
				y=curr_y+dy[i];
				dis[x][y]=dis[curr_x][curr_y]+1;
				vis[x][y]=1;
				q.push({x,y});
				if(x==target_x && y==target_y)
					return dis[x][y];
			}
		}
	}

}





int main()
{
	#ifndef ONLINE_JUDGE


		 freopen("input.txt","r",stdin);
		 freopen("output.txt","w",stdout); 

	#endif
	fastio;
		
	
	ll t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a,b;
		memset(vis,0,sizeof(vis));
		memset(vis,0,sizeof(dis));

		cin>>a>>b;

		int x=a;
		int y=b;

		cin>>a>>b;

		target_x=a;
		target_y=b;

		cout<<BFS(x,y,n)<<endl;

	}

	return 0;
}






