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

bool cmp(pair< int, int > a, pair< int, int > b){
    return a.second > b.second;
}

void solve(){
    int n, k;
    cin >> n >> k;
    map< int, int > mp1, mp2;
    int a[2 * n];
    for(int i = 0; i < 2 * n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        mp1[a[i]]++;
        mp2[a[i + n]]++;
    }
    vector< pair< int, int > > v1, v2;
    for(auto it = mp1.begin(); it != mp1.end(); it++){
        v1.pb({it->first, it->second});
    }
    for(auto it = mp2.begin(); it != mp2.end(); it++){
        v2.pb({it->first, it->second});
    }
    sort(v1.begin(), v1.end(), cmp);
    sort(v2.begin(), v2.end(), cmp);
    vector< int > ans1, ans2;
    int i = 0;
    while(ans1.size() < 2 * k){
        if(v1[i].second > 1){
            ans1.pb(v1[i].first);
            ans1.pb(v1[i].first);
            ans2.pb(v2[i].first);
            ans2.pb(v2[i].first);
            if(ans1.size() > 2 * k){
                ans1.pop_back();
                ans2.pop_back();
            }
            
        }
        else{
            ans1.pb(v1[i].first);
            ans2.pb(v1[i].first);
        }
        i++;
    }
    for(auto x: ans1){
        cout << x << " ";
    }
    cout << endl;
    for(auto x: ans2){
        cout << x << " ";
    }
    cout << endl;

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