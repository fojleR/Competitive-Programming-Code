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

ll stringToInt(string s){
    ll ans = 0;
    for(int i = 0; i < s.size(); i++){
        char x= s[i];
        ans *= 10;
        ans += int(x - '0');
    }
    return ans;
}

void solve(){
    string n;
    cin >> n;
    string dif = "";
    int m = n.size();
    vector< pair< ll, ll > >ans;
    for(int i = 5; i <= 5; i++){
        dif = "";
        string ss = n;
        reverse(ss.begin(), ss.end());
        for(int j = 0; j < i; j++){
            dif += ss[j % m];
        }
        reverse(dif.begin(), dif.end());
        cout << dif << endl;
        if(dif.size() >= 15)break;
        ll difint = stringToInt(dif);
        ll nint = stringToInt(n);

        for(ll a = 1; a <= 10000; a++){
            ll b = a * nint - difint;
            if(b > 0  and (a * m - b) == i){
                // cout << dif << endl;
                ans.push_back({a, b});
            }
        }

    }
    cout << ans.size() << endl;
    for(auto x: ans){
        cout << x.first << " " << x.second << endl;
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