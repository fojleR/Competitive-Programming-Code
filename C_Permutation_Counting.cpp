#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================
ll n, k;
ll a[mx];

bool check(ll x){
    ll tot = 0; 
    for(int i = 0; i < n; i++){
        if(a[i] < x){
            tot += x - a[i];
        }
    }
    if(tot <= k)return true;
    else return false;
}

void solve(){
    cin >> n >> k;
    ll mx = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    ll ave = 0;
    ll lo = 0, hi = mx + k;
    while(lo <= hi){
        ll mid = (lo + hi)/2;
        if(check(mid)){
            ave = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    // cout << ave << endl;
    ll baki = k;
    
    for(int i = 0; i < n; i++){
        if(a[i] < ave){
            baki -= (ave - a[i]);
            a[i] = ave;
        }
    }
    //cout << baki << endl;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(i == 0) ans += ave;
        else{
            if(a[i - 1] > ave)ans += ave;
            else if(baki){
                ans += ave;
                baki--;
            }
            else ans += (ave - 1);
        }
    }
    if(a[n - 1] > ave)ans++;
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