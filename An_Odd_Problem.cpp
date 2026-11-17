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
        ll n, m, k;
        cin >> n >> m >> k;
        
        if ( k <= n ) {
            cout << k << "\n";
            continue;
        }
        
        ll dv = k / n;
        if ( dv % 2 == 0 ) dv--;
        ll mul = dv * n;
        k -= mul;
        m -= dv;
        if ( m > 1 ) {
            ll dv1 = k / 2;
            ll mul1 = dv1 * 2;
            k -= mul1;
        }
        cout << n - k << "\n";
    }
    
    return 0;
}