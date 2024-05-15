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
int n;
string s;

bool check(int l){
    if(n % l != 0)return false;
    map<string, int> mp;
    string tm = "";
    string taken = "";
    string untaken = "";
    int tcnt = 0;
    for(int i = 0; i < n; i++){
        tm += s[i];
        if(tm.size() == l){
            mp[tm]++;
            if(mp[tm] > tcnt){
                tcnt = mp[tm];
                taken = tm;
            }
            tm = "";
        }
    }
    if(mp.size() == 1)return true;
    if(mp.size() > 2)return false;
    for(auto x: mp){
        if(x.first != taken){
            untaken = x.first;
        }
    }
    if(mp[untaken] > 1)return false;
    int cnt = 0;
    for(int i = 0; i < taken.size(); i++){
        if(taken[i] != untaken[i])cnt++;
    }
    return cnt <= 1;

}


void solve(){
    cin >> n;
    cin >> s;
    int ans = n;
    for(int i = 1; i * i<= n; i++){
        int xx = i;
        if(check(xx)){
            ans = min(ans,xx);
        }
        int yy = n / i;
        if(check(yy)){
            ans = min(ans,yy);
        }
    }
    cout << ans << endl;
    // cout << check(1) << endl;
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