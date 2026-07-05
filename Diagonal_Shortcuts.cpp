#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while ( t-- ) {
		ll x, k;
		cin >> x >> k;

		if ( x == 2 ) cout << min( 4LL, k ) << "\n";
		else {
			ll cur = ( x / 3 ) * 2LL;
			if ( x % 3 ) cur += 2;
			cout << min( cur, k ) << "\n";
		}
	}

	return 0;
}