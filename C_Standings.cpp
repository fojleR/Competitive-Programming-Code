#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const ll mx = 200005;
const ll mod = 1e9 + 7;

bool cmp(pair< pair< ll, ll >, ll > a, pair< pair< ll, ll >, ll > b){
    ll x = a.first.first * (b.first.first + b.first.second);
    ll y = b.first.first * (a.first.first + a.first.second);
    if(x == y){
        return a.second < b.second;
    }
    else{
        return x > y;
    }
}

void solve(){
    ll n;
    cin >> n;
    vector< pair< pair< ll, ll >, ll > > v;
    for(ll i = 0; i < n; i++){
        double a, b;
        cin >> a >> b;
        v.push_back({{a, b}, i + 1});
    }
    sort(v.begin(), v.end(), cmp);
    for(auto x: v){
        cout << x.second << " ";
    }
    cout << endl;
}


int main(){
    fast
    ll t = 1;
    //cin >> t;
    ll cse = 0;
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}