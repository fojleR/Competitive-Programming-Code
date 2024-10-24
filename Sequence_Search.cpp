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


void solve(){
    ll a, b, k;
    cin >> a >> b >> k;
    vector< ll > v;
    v.push_back(0);
    v.push_back(a);
    v.push_back(b);
    for(int i = 0; i <= 1000; i++){
        ll x = v[v.size() - 1] + v[v.size() - 2] - v[v.size() - 3];
        v.push_back(x);
        cout << x << endl;
    }
    sort(v.begin(), v.end());
    for(k = 7; k <= 999; k++){
        if(k <= 4){
            cout << v[k - 1] << endl;
        }
        else{
            ll frq0 = k / 2 - 1;
            ll frq = (k + 1) / 2 - 1;
            ll frq1 = (k + 2) / 2 - 1;
            ll kth, kth1, kth0;
            if(k % 2 == 0){
                kth0 = b * frq0;
                kth = (b * frq) + a;
                kth1 = (b * frq1);
            }
            else{
                kth0 = b * frq0 + a;
                kth = (b * frq);
                kth1 = (b * frq1) + a;
            }
            // cout << frq << " " << frq1 << endl;
            // cout << kth << " " << kth1 << endl;
            if(v[k - 1] != max(kth0, min(kth, kth1))){
                cout << v[k - 1] << " " << max(kth0, min(kth, kth1)) << endl;
            }
            
        }
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