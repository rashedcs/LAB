// A Dynamic Programming based C++ program to find minimum
// number operations to convert str1 to str2
#include<bits/stdc++.h>
using namespace std;
 
// Utility function to find minimum of three numbers
int min(int x, int y, int z)
{
    return min(min(x, y), z);
}
 
int editDistDP(string str1, string str2, int m, int n)
{
    // Create a table to store results of subproblems
    int dp[m+1][n+1];
 
    // Fill d[][] in bottom up manner
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            // If first string is empty, only option is to
            // isnert all characters of second string
            if (i==0)
                dp[i][j] = j;  // Min. operations = j
 
            // If second string is empty, only option is to
            // remove all characters of second string
            else if (j==0)
                dp[i][j] = i; // Min. operations = i
 
            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
 
            // If last character are different, consider all
            // possibilities and find minimum
            else
                dp[i][j] = 1 + min(dp[i][j-1],  // Insert
                                   dp[i-1][j],  // Remove
                                   dp[i-1][j-1]); // Replace
        }
    }
 
    return dp[m][n];
}
 
// Driver program
int main()
{
    // your code goes here
    string str1 = "sunday";
    string str2 = "saturday";
 
    cout << editDistDP(str1, str2, str1.length(), str2.length());
 
    return 0;
}



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
