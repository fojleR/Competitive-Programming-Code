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

void solveEven(int n){
    string s;
    cin >> s;
    int even[26] = {0}, odd[26] = {0};
    for(int i = 0; i < n; i++){
        int x = s[i] - 'a';
        if(i % 2 == 0){
            odd[x]++;
        }
        else{
            even[x]++;
        }
    }
    int tot = n / 2;
    int mxeven = 0, mxodd = 0;
    for(int i = 0; i < 26; i++){
        mxeven = max(mxeven, even[i]);
        mxodd = max(mxodd, odd[i]);
    }
    int ans = (tot - mxodd) + (tot - mxeven);
    cout << ans << endl;
}

void solveOdd(int n){
    string s;
    cin >> s;
    int preEven[26] = {0}, postEven[26] = {0}, preOdd[26] = {0}, postOdd[26] = {0};
    for(int i = 0; i < n; i++){
        
    }
    for(int i = n - 1; i >= 0; i--){
        int x = s[i] - 'a';
        if(i % 2 == 0){
            postOdd[x]++;
        }
        else{
            postEven[x]++;
        }
    }
    int tot = n / 2;
    int ans = n;
    for(int i = 0; i < n; i++){
        int x = s[i] - 'a';
        if(i % 2 == 0){
            postOdd[x]--;
        }
        else{
            postEven[x]--;
        }
        int ans1 = n, ans2 = n;
        for(int j = 0; j < 26; j++){
            int tm1 = tot - preEven[j] - postOdd[j];
            ans1 = min(ans1, tm1);
        }
        for(int j = 0; j < 26; j++){
            int tm2 = tot - preOdd[j] - postEven[j];
            ans2 = min(ans2, tm2);
        }
        int tm = ans1 + ans2;
        ans = min(ans, tm);
        if(i % 2 == 0){
            preOdd[x]++;
        }
        else{
            preEven[x]++;
        }
    }
    // for(int i = 0; i < 26; i++){
    //     cout << preOdd [i] << " ";
    // }
    // cout << endl;
    // for(int i = 0; i < 26; i++){
    //     cout << preEven[i] << " ";
    // }
    // cout << endl;
    cout << ans + 1 << endl;
}

void solve(){
    int n;
    cin >> n;
    if(n % 2){
        solveOdd(n);
    }
    else{
        solveEven(n);
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