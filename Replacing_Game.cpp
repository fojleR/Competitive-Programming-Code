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
    int n, k;
    cin >> n >> k;
    string s1, s2;
    cin >> s1 >> s2;
    bool ok = true;
    for(int i = 0; i < n; i++){
        if(s1[i] != s2[i]){
            ok = false;
            break;
        }
    }
    if(ok){
        cout << 0 << endl;
        return;
    }
    vector< pair< int, char > > ans;
    ok = false;
    int ind = -1;
    deque< char > dq;
    set< char > st;
    map< char, int > mp;
    for(int i = 0; i < k - 1; i++){
        dq.push_back(s2[i]);
        st.insert(s2[i]);
        mp[s2[i]]++;
    }
    for(int i = k - 1; i < n; i++){
        dq.push_back(s2[i]);
        st.insert(s2[i]);
        mp[s2[i]]++;
        if(st.size() == 1){
            ok = true;
            ind = i - k + 1;
            break;
        }
        mp[dq.front()]--;
        if(mp[dq.front()] == 0){
            st.erase(st.find(dq.front()));
        }
        dq.pop_front();
    }
    // cout << ind << endl;
    if(!ok){
        cout << -1 << endl;
        return;
    }
    for(int i = 0; i < ind; i++){
        ans.push_back({i + 1, s2[i]});
    }
    for(int i = n - 1; i >= ind + k; i--){
        int xxx = i - k + 1;
        ans.push_back({xxx + 1, s2[i]});
    }
    //cout << s1 << " " << s2 << endl;
    ans.push_back({ind + 1, s2[ind]});
    cout << ans.size() << endl;
    for(auto x: ans){
        cout << x << endl;
    }

    //cout << s1 << endl << s2 << endl;
    
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