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
    int n, x;
    cin >> n >> x;
    int a[n];
    int ind = -1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == x){
            ind = i;
        }
    }
    int l = 0, r = n;
    int tm = 10;
    set< int > st;
    st.insert(a[0]);
    while(r - l > 1){
        int mid = (l + r) / 2;
        // cout << l << " " << r << endl;
        if(a[mid] <= x){
            l = mid;
            st.insert(a[mid]);
        }
        else{
            r = mid;
        }
        // cout << l << " " << r << endl;
    }

    if(a[l] == x){
        cout << 0 << endl;
        return;
    }

    if(a[l] < x){
        cout << 1 << endl;
        cout << l + 1 << " " << ind + 1 << endl;
    }
    else{
        if(st.count(x) == 0){
            cout << 1 << endl;
            cout << l + 1 << " " << ind + 1 << endl;
        }
        else{
            cout << 2 << endl;
            cout << l + 1 << " " << ind + 1 << " " << x << endl;
            for(int i = 0; i < n; i++){
                if(a[i] < x and st.count(a[i]) == 0){
                    cout << ind + 1 << " " << i + 1 << endl;
                    return;
                }
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