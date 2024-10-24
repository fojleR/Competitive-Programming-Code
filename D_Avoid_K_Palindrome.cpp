#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 998244353;

// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================

int n, k;
string s;
vector< int > pos;

map< pair< string, int >, int > dp;

ll bigMod(ll x,ll p){
    long long int res=1,y=p;
    while(y>0)
    {
        if(y&1) res=((res%mod)*(x%mod))%mod;
        y=y>>1;
        x=((x%mod)*(x%mod))%mod;
    }
    return res;
}

ll dpSolve(string ss, int pos1){
    
    if(pos1 >= pos.size()){
        return 0;
    }
    int ind = pos[pos1];
    if(ind - k >= 0){
        int l = ind - k;
        int r = ind - 1;
        //cout << l << " " << r << endl;
        bool ok = 1;
        while(l < r){
            if(ss[l] != ss[r]){
                ok = 0;
                break;
            }
            l++, r--;
        }
        if(ok){
            ll p = pos.size() - pos1;
            return bigMod(2, p);
        }
    }
    if(dp.find({ss, pos1}) != dp.end()){
        return dp[{ss, pos1}];
    }
    ind = pos[pos1];
    string ss1 = ss;
    string ss2 = ss;
    ss1[ind] = 'A';
    ss2[ind] = 'B';
    ll ans = dpSolve(ss1, pos1 + 1) + dpSolve(ss2, pos1 + 1);
    ans %= mod;
    return dp[{ss, pos1}] = ans;
    
}

void solve(){
    cin >> n >> k;
    cin >> s;
    for(int i = 0; i < n - k + 1; i++){
        int l = i, r = i + k - 1;
        bool ok = 1;
        while(l < r){
            if(s[l] == '?' || s[r] == '?'){
                ok = 0;
                break;
            }
            if(s[l] != s[r]){
                ok = 0;
                break;
            }
            l++;
            r--;
        }
        if(ok){
            cout << 0 << endl;
            return;
        }
    }
    for(int i = 0; i < n; i++){
        if(s[i] == '?'){
            pos.push_back(i);
        }
    }
    cout << pos << endl;
    if(pos.size()){
        cout << dpSolve(s, 0) << endl;
    }
    else{
        cout << 1 << endl;
    }
    
}


int main(){
    fast
    int t = 1;
    //cin >> t;
    int cse = 0;
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}