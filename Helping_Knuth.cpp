#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while ( t-- ) {
		int n;
		cin >> n;
		vector<int> v(n), vis( n+1, 0 ), cur;

		for ( int i = 0; i < n; i++ ) {
			cin >> v[i];
			if ( v[i] != -1 ) vis[v[i]] = 1;
		}

		for ( int i = n; i >= 1; i-- ) {
			if ( !vis[i] ) cur.push_back( i );
		}

		for ( int i = 0, j = 0; i < n; i++ ) {
			if ( v[i] == -1 ) v[i] = cur[j++]; 
		}

		for ( auto u : v ) cout << u << " ";
		cout << "\n";
	}  

	return 0;
}