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
    int n, x;
    cin >> n >> x;
    vector< int > v;
    for(int i = 0; i < n; i++){
        int xx;
        cin >> xx;
        v.push_back(xx);
    }
    v.push_back(0);
    sort(v.begin(), v.end());
    int mx = 0;
    for(int i = 1; i <= n; i++){
        mx = max(mx, v[i] - v[i - 1]);
    }
    mx = max(mx, 2* (x - v[n]));
    cout << mx << endl;
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