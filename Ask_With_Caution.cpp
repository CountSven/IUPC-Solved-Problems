#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while ( t-- ) {
        int l1, l2, l3, a, b;
        cout << "MUL 1" << endl;
        cin >> l1;
        cout << "MUL " << l1 << endl;
        cin >> l2;
        a = l2 / l1;
        cout << "DIV " << l2 << endl;
        cin >> l3;
        cout << "MUL 1" << endl;
        cin >> b;
        cout << "ANS " << a << " " << b << endl;
    }
    
    return 0;
}