   #include<bits/stdc++.h>
   using namespace std;

   #define inf 999999
   #define pb push_back
//  ideone.com/1piMER




   void dijkstra(int node, int source, vector<int>cost[], vector<int>G[])
   {
     queue<int>x;
       //int distance[100000];
       //int prev[100000];
      // memset(distance,inf,sizeof(distance));
     // memset(prev,-1,sizeof(prev));
     vector<int>dist(100, inf);
     vector<int>prev(100, -1);


     vector<int>path;


     dist[source] = 0;
     x.push(source);


     while(!x.empty())
     {
        int u = x.front();
        x.pop();
        for(int i=0; i<G[u].size(); i++)
        {
            int c = cost[u][i];
            int p = G[u][i];

            if(dist[u] + c < dist[p])
            {
                dist[p] = dist[u] + cost[u][i];
                x.push(p);
                prev[p] = u;
            }
            else continue;
        }
     }

     cout<<"Minimum distance : "<<dist[node]<<endl;

     int start = node;

     if(prev[node]==-1)
     {
        cout<<"-1"<<endl;
     }

     else
     {
        while(start!=-1)
        {
          path.push_back(start);
          start = prev[start];
        }

        for(int i=path.size()-1; i>=0; i--)
        {
           cout<<path[i]<<" ";
        }
     }
  }


int main()
{
     int node, edge, a,b,c;

     cin>>node>>edge;

     vector<int> graph[node+1];
     vector<int> cost[node+1];

     while(edge--)
     {
        cin>>a>>b>>c;
        graph[a].push_back(b);
        graph[b].push_back(a);     ///Ata na dile shudhu directed ar moto kaz korbe
        cost[a].push_back(c);
        cost[b].push_back(c); ///Ata na dile shudhu directed ar moto kaz korbe
     }

     int source = 1;
     dijkstra(node, source, cost, graph);

     return 0;
}

/*
input
4 5
1 2 5
1 3 10
2 3 4
2 4 11
3 4 5
output
1 2 3 4
*/
















/*
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
#define INF 1000000;
struct edge {
	int u;
	int w;
};
bool operator <( edge a, edge b ) {
	return a.w < b.w;
}
void dijkstra( vector< edge > graph[], int dist[], int N, int s ) {
	dist[ s ] = 0;
	priority_queue< edge > q;
	q.push( ( edge ) { s, 0 } );
	while ( !q.empty() ) {
		edge p = q.top();
		q.pop();
		for ( int i = 0; i < graph[ p.u ].size(); ++i ) {
			int u = p.u;
			int v = graph[ p.u ][ i ].u;
			if ( dist[ u ] + graph[ p.u ][ i ].w < dist[ v ] ) {
				dist[ v ] = dist[ u ] + graph[ p.u ][ i ].w;
				q.push( graph[ p.u ][ i ] );
			}
		}
	}
}
int main() {
	int t;
	int N, E;
	int S, T;
	int u, v, w, i;
	scanf( "%d", &t );
	while ( t > 0 ) {
		scanf( "%d%d", &N, &E );
		vector< edge > graph[ N + 1 ];
		int dist[ N + 1 ];
		for ( i = 0; i < E; ++i ) {
			scanf( "%d%d%d", &u, &v, &w );
			graph[ u ].push_back( ( edge ) { v, w } );
		}
		for ( i = 0; i <= N; ++i ) {
			dist[ i ] = INF;
		}
		scanf( "%d%d", &S, &T );
		dijkstra( graph, dist, N, S );
		if ( dist[ T ] != 1000000 ) {
			printf( "%d\n", dist[ T ] );
		}
		else {
			printf( "NO\n" );
		}
		--t;
	}
	return 0;
}
*/






 /*
  #include<bits/stdc++.h>
  using namespace std;

  const int MAX = 1e4 + 5;
  int id[MAX], nodes, edges;
  pair <long long, pair<int, int> > p[MAX];



    // Find the root of the set in which element k belongs
    int Find(int k)
    {
        // if k is root
        if(id[k] == k)
            return k;

        // recurse for parent until we find root
        return Find(id[k]);
    }


    // Perform Union of two subsets
    void Union(int a, int b)
    {
        // find root of the sets in which elements
        // x and y belongs
        int x = Find(a);
        int y = Find(b);

        id[x] = y;
    }


 long long kruskal(pair<long long, pair<int, int> > p[], int edges)
 {
    for(int i = 0;i < MAX;++i)  id[i] = i;
    sort(p, p + edges);

    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0; i<edges; ++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;

        // Check if the selected edge is creating a cycle or not
        if(Find(x) != Find(y))
        {
            minimumCost += cost;
            Union(x, y);
        }
    }
    return minimumCost;
 }

 int main()
 {
    ios::sync_with_stdio(false);
    int x, y;
    long long weight, cost, minimumCost;
    //initialize();
    cin>>nodes>>edges;
    for(int i = 0;i < edges;++i)
    {
        cin>>x>>y>>weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    // Sort the edges in the ascending order

    minimumCost = kruskal(p,edges);

    cout << minimumCost << endl;
    return 0;
 }
*/

/*
Input :
4 5
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4

Output : 19





/*
void initialize()
{
      for(int i = 0;i < MAX;++i)
        id[i] = i;
}

int root(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}



void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];

}
*/
