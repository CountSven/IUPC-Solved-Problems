#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int n, m, a, b, c, same = 0, distA = 1e9, distB = 1e9;
vector<int> adj[N];
vector<int> vis( N, 0 );

void dfsA( int u, int cnt )
{
	if ( u == c ) distA = cnt;
	else if ( u == b ) same = 1;
	vis[u] = 1;

	for ( int v : adj[u] ) {
		if ( !vis[v] ) dfsA( v, cnt+1 );
	}
}

void dfsB( int u, int cnt )
{
	if ( u == c ) {
		distB = cnt;
		return;
	}
	vis[u] = 1;

	for ( int v : adj[u] ) {
		if ( !vis[v] ) dfsB( v, cnt+1 );
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while ( t-- ) {
		cin >> n >> m >> a >> b >> c;

		for ( int i = 0, u, v; i < m; i++ ) {
			cin >> u >> v;
			adj[u].push_back( v );
			adj[v].push_back( u );
		}

		dfsA( a, 0 );

		for ( int i = 1; i <= n; i++ ) vis[i] = 0; 

		dfsB( b, 0 );

		for ( int i = 1; i <= n; i++ ) vis[i] = 0;
	
		if ( distA == 1e9 && distB == 1e9 ) {
			if ( same ) cout << "Alice" << "\n";
			else cout << "Tie" << "\n";
		}
		else if ( distA != 1e9 && distB != 1e9 ) {
			if ( distA < distB ) cout << "Alice" << "\n";
			else if ( distA > distB ) cout << "Bob" << "\n";
			else cout << "Tie" << "\n";
		}
		else {
			if ( distB == 1 ) cout << "Tie" << "\n";
			else cout << "Alice" << "\n";
		}

		distA = 1e9, distB = 1e9, same = 0;

		for ( int i = 1; i <= n; i++ ) adj[i].clear();
	}

	return 0;
}