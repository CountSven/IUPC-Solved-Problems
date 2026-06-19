#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using i128 = unsigned __int128;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	vector<ll> seive( 1e7+5, 1 ), pr;

	for ( ll i = 2; i * i <= 1e7; i++ ) {
		for ( ll j = i * i; j <= 1e7; j += i ) seive[j] = 0;
	}

	for ( ll i = 2; i <= 1e7; i++ ) {
		if ( seive[i] ) pr.push_back( i );
	}

	// cout << pr.size() << "\n";
	// for ( int i = 0; i < 10; i++ ) cout << pr[i] << " ";
	// cout << "\n";

	while ( t-- ) {
		ll x, y;
		cin >> x >> y;

		ll val = x * y;

		map<ll, ll> mp;

		for ( int i = 0; i < pr.size(); i++ ) {
			ll cur = pr[i], cnt = 0;
			if ( cur > val ) break;
			while ( val % cur == 0 ) {
				cnt++;
				val /= cur;
			}
			if ( cnt ) mp[cur] = cnt;
		}

		if ( val > 1 ) mp[val]++;

		// for ( auto [x, y] : mp ) cout << x << " " << y << "\n";
		// cout << "\n";

		vector<ll> divs = { 1LL };

		for ( auto [x, y] : mp ) {
			ll pw = 1, sz = divs.size();
			for ( int i = 0; i < y; i++ ) {
				pw *= x;
				for ( int j = 0; j < sz; j++ ) {
					divs.push_back( divs[j] * pw );
				}
			}
		}

		// for ( auto u : divs ) cout << u << " ";
		// cout << "\n";
	
		vector<pair<string, string>> v;

		for ( auto u : divs ) {
			i128 p = u;
			p += x;
			i128 q = u;
			q += x;
			q *= y;
			q /= u;
			string s1 = "", s2 = "";
			while ( p ) {
				s1 += ( p % 10 ) + '0';
				p /= 10;
			}
			reverse( s1.begin(), s1.end() );
			while ( q ) {
				s2 += ( q % 10 ) + '0';
				q /= 10;
			}
			reverse( s2.begin(), s2.end() );
			v.push_back( { s1, s2 } );
		}

		cout << v.size() << "\n";
		for ( auto [x, y] : v ) cout << x << " " << y << "\n";
	}

	return 0;
}