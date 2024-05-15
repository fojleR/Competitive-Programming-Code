#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

int n;
vector< pair< ll, ll > > v;

bool check(ll k){
    ll l = 0, r = 0;
    for(int i = 0; i < n; i++){
        if(v[i].first > r){
            if(r + k < v[i].first){
                return false;
            }
            else{
                l = v[i].first;
                r = min(v[i].second, r + k);
            }
        }
        else if(v[i].second < l){
            if(l - k > v[i].second){
                return false;
            }
            else{
                r = v[i].second;
                l = max(v[i].first, l - k);
            }
        }
        else{
            l = max(l - k, v[i].first);
            r = min(r + k, v[i].second);
        }
    }
    return true;
}

void solve(){
    cin >> n;
    v.clear();
    for(int i = 0; i < n; i++){
        ll l, r;
        cin >> l >> r;
        v.push_back({l, r});
    }
    ll lo = 0, hi = 1e10;
    ll ans = 0;
    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        if(check(mid)){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    cout << ans << endl;
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