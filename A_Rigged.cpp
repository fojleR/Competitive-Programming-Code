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
    vector< pair< int, int > > v;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    for(int i = 1; i < n; i++){
        if(v[i].first >= v[0].first and v[i].second >= v[0].second){
            cout << -1 << endl;
            return;
        } 
    }
    cout << v[0].first << endl;
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