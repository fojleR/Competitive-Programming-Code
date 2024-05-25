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
    string s;
    cin >> s;
    int cntN = 0, cntS = 0, cntE = 0, cntW = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'N') cntN++;
        if(s[i] == 'S') cntS++;
        if(s[i] == 'E') cntE++;
        if(s[i] == 'W') cntW++;
    }
    if(cntN > cntS){
        cntN -= cntS;
        cntS = 0;
    }
    else{
        cntS -= cntN;
        cntN = 0;
    }
    if(cntE > cntW){
        cntE -= cntW;
        cntW = 0;
    }
    else{
        cntW -= cntE;
        cntE = 0;
    }
    int tot = cntN + cntS + cntE + cntW;
    if(n == 2 && tot == 0){
        cout << "NO\n";
        return;
    }
    else if(n == 1){
        cout << "NO\n";
        return;
    }
    else if(cntN % 2 || cntS % 2 || cntE % 2 || cntW % 2){
        cout << "NO\n";
        return;
    }
    bool RS = true, RE = false, RW = false, RN = true;
    for(int i = 0; i < n; i++){
        if(s[i] == 'N' && RS){
            RS = false;
            cout << "R";
            continue;
        }
        else{
            if(s[i] == 'N' && !RS){
                RS = true;
                cout << "H";
                continue;
            }
        }
        if(s[i] == 'S' && RN){
            RN = false;
            cout << "R";
            continue;
        }
        else{
            if(s[i] == 'S' && !RN){
                RN = true;
                cout << "H";
                continue;
            }
        }
        if(s[i] == 'E' && RW){
            RW = false;
            cout << "R";
            continue;
        }
        else if(s[i] == 'E' && !RW){
            RW = true;
            cout << "H";
            continue;
        }
        if(s[i] == 'W' && RE){
            RE = false;
            cout << "R";
            continue;
        }
        else if(s[i] == 'W' && !RE){
            RE = true;
            cout << "H";
            continue;
        }
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