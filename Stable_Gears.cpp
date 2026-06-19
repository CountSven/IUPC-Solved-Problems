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

	while ( t-- ) {
		ll n;
		cin >> n;

		i128 res = n;
		res *= n;
		res /= 4;

		string s = "";
		while ( res ) {
			s += ( res % 10 ) + '0';
			res /= 10;
		}
		reverse( s.begin(), s.end() );
		if ( !s.size() ) s = "0";
		cout << s << "\n";
	}

	return 0;
}