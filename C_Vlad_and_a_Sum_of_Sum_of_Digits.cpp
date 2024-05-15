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
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    int i = 0, j = 0;
    int cnt = 0;
    int taken = - 1;
    while(i < n && j < n){
        if(a[i] == b[j]){
            taken = i;
            i++;
            j++;
            cnt++;
        }
        else{
            i++;
        }
    }
    // cout << cnt << endl;
    
    i = n - 1;
    j = n - 1;
    while(i >= 0 and j >= 0 and i > taken){
        if(a[i] == b[j]){
            i--;
            j--;
            cnt++;
        }
        else{
            i--;
        }
    }
    // cout << cnt << endl;
    int ans1 = n - cnt;
    ans1 = max(0, ans1);
    i = n - 1;
    j = n - 1;
    cnt = 0;
    taken = n;
    while(i >= 0 and j >= 0){
        if(a[i] == b[j]){
            taken = i;
            //cout << i << " " << j << endl;
            i--;
            j--;
            cnt++;
        }
        else{
            i--;
        }
    }
    
    // cout << cnt << " " << taken << endl;
    i = 0, j = 0;
    while(i < n && j < n and i < taken){
        if(a[i] == b[j]){
            i++;
            j++;
            cnt++;
        }
        else{
            i++;
        }
    }
    // cout << cnt << endl;
    int ans2 = n - cnt;
    // ans2 = max(0, ans2);
    cout << min(ans1, ans2) << endl;
    // cout << n - cnt << endl;
}


int main(){
    fast
    int t = 1;
    cin >> t;
    int cse = 0;
    while(t--){
        cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}