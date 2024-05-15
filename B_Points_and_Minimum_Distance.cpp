#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    int a[n * 2];
    for(int i = 0; i < 2 * n; i++){
        cin >> a[i];
    }

    sort(a, a + 2 * n);
    vector< int > v1, v2;

    for(int i = 0; i < n; i++){
        v1.push_back(a[i]);
    }
    for(int i = n; i < 2 * n; i++){
        v2.push_back(a[i]);
    }

    ll ans = 0;

    for(int i = 1; i < n; i++){
        ans += v1[i] - v1[i - 1];
    }

    for(int i = 1; i < n; i++){
        ans += v2[i] - v2[i - 1];
    }

    cout << ans << endl;
    for(int i = 0; i < n; i++){
        cout << v1[i] << " " << v2[i] << endl;
    }

}


int main(){
    fast
    int t = 1;
    cin >> t;
    int cse = 0;
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}