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
ll n, x;
ll a[mx];

ll cal(ll msb){
    ll msk = INT_MAX - ((1 << (msb + 1)) - 1);
    int cnt = 0;
    ll Xor = 0;
    ll Or = 0;
    int lst = -1;
    for(int i = 0; i < n; i++){
        Xor = Xor ^ a[i];
        if((Xor & msk) == (x & msk & Xor) and (Xor & (1 << msb)) == 0){
            cnt++;
            Or |= Xor;
            Xor = 0;
            lst = i;
        }
    }
    if(lst != n - 1 || Or > x) cnt = 0;
    return cnt;
}

void solve(){
    cin >> n >> x;
    ll xr = 0;
    for(int i = 0; i < n; i++){
        int xx;
        cin >> a[i];
        xr ^= a[i];
    }
    if(xr > x){
        cout << -1 << endl;
        return;
    }
    ll ans = 1;
    // x = 31;
    for(int i = 30; i >= 0; i--){
        ans = max(ans, cal(i));
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