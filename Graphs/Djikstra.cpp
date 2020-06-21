#include <bits/stdc++.h>
#include <cstddef>
using namespace std;
#define INF INT_MAX
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int t,n,m,r,x,y,s;
    cin>>t;
    
    // adjacency list declaration
    vector<pair<int,int>> adj[3001];

        while(t--)
    {
        cin>>n>>m;
        bool visited[n+1];
        while(m--)
        {
            cin>>x>>y>>r;
            adj[x].push_back({y,r});
            adj[y].push_back({x,r});
        }
        cin>>s;

    memset(visited,false,sizeof(visited));


 // In the pair =first parameter is distance and second one is node/vertex number
priority_queue< pair<int,int>, vector< pair<int,int> >,greater<pair<int,int> > > pq;

vector<int> dist(n+1,INF);

// intialize the details for starting vertex
pq.push({0,s});
dist[s]=0;
visited[s]=true;

//DJIKSTRA ALGORITHM STARTS HERE

 while(!pq.empty())
 {
     int curr=pq.top().second; //current node/vertix
     int curr_d=pq.top().first; // current distance of this node  from vertex 1
     pq.pop();
     
     visited[curr]=true;
     for(pair<int,int> edge:adj[curr])
     {
         if(!visited[edge.first])
         {
                 if(curr_d+edge.second<dist[edge.first])
                {
                    dist[edge.first]=curr_d+edge.second;
                    pq.push({dist[edge.first],edge.first});
                }
         }
        
     }


 }

 for(int i=1;i<=n;i++)
 {
     if(i==s)
     continue;
     else 
     {
         if(dist[i]==INF)
         cout<<-1<<" ";
         else
         cout<<dist[i]<<" ";
     }
 }


cout<<endl;


     for(int i=1;i<=n;i++)
     {
          adj[i].clear();
          
          
     }

        dist.clear();
        
        
    }


    return 0;
}
