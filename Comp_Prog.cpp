#include <bits/stdc++.h>
using namespace std;

#define int long long
#define testcase \
    int t;       \
    cin >> t;    \
    while (t--)

inline void cp() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve() {
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0;j<i;j++ ){cout<<" ";};
        for(int j=0;j<(2*(n-i))-1;j++ ){cout<<"*";};
        for(int j=0;j<i;j++ ){cout<<" ";};

        cout<<endl;
    }

}

signed main() {
    cp();
    testcase {
        solve();
    }
    return 0;
}