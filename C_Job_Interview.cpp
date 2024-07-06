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
    int n, m;
    cin >> n >> m;
    int tn = n + m + 1;
    int a[tn], b[tn];
    for(int i = 0; i < tn; i++){
        cin >> a[i];
        cout << a[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < tn; i++){
        cin >> b[i];
        cout << b[i] << " ";
    }
    
    cout << endl;
    vector< int > test, prog;
    for(int i = 0; i < tn; i++){
        if(a[i] > b[i]){
            prog.push_back(i);
        }
        else{
            test.push_back(i);
        }
    }
    int cp = 0, ct = 0;
    ll prosum = 0; ll tessum = 0;
    vector< char > track;
    for(int i = 0; i < tn - 1; i++){
        if(a[i] > b[i]){
            if(cp < n){
                cp++;
                prosum += a[i];
                track.push_back('p');
            }
            else{
                ct++;
                tessum += b[i];
                track.push_back('t');
            }
        }
        else{
            if(ct < m){
                ct++;
                tessum += b[i];
                track.push_back('t');
            }
            else{
                cp++;
                prosum += a[i];
                track.push_back('p');
            }
        }
    }
    ll ans = prosum + tessum;
    vector< ll > vans;
    vans.push_back(ans);
    for(int i = tn - 2; i >= 0; i--){
        cout << track[i] << " ";
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