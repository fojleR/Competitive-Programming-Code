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
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    deque< pair< int , int > > dq1, dq2;
    map< pair< int, int >, int > mp1, mp2;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        dq1.push_back({x, y});
        dq2.push_back({y, x});
        mp1[{x, y}] = 1;
        mp2[{x, y}] = 1;
    }
    sort(dq1.begin(), dq1.end());
    sort(dq2.begin(), dq2.end());
    int alice = 0, bob = 0;
    int l = 1, r = b, u = 1, d = a;
    bool al = true;
    while(m--){
        char x;
        int y;
        cin >> x >> y;
        if(l > r || u > d)break;
        if(x == 'U'){
            while(!dq1.empty()){
                pair< int, int > p = dq1.front();
                if(p.first >= u + y)break;
                dq1.pop_front();
                if(mp2[p]){
                    if(al){
                        alice++;
                    }
                    else{
                        bob++;
                    }
                    mp1[p] = 0;
                }
            }
            u = u + y;   
        }
        else if(x == 'D'){
            while(!dq1.empty()){
                pair< int, int > p = dq1.back();
                //cout << p << endl;
                //cout << d << endl;
                if(p.first <= d - y)break;
                dq1.pop_back();
                if(mp2[p]){
                    if(al){
                        alice++;
                    }
                    else{
                        bob++;
                    }
                    mp1[p] = 0;
                }
            }
            d = d - y;
            
        }
        else if(x == 'L'){
                while(!dq2.empty()){
                    pair< int, int > p = dq2.front();
                    if(p.first >= l + y)break;
                    p = {p.second, p.first};
                    dq2.pop_front();
                    if(mp1[p]){
                        if(al){
                            alice++;
                        }
                        else{
                            bob++;
                        }
                        mp2[p] = 0;
                    }
                }
                l = l + y;
        }
        else if(x == 'R'){
            while(!dq2.empty()){
                pair< int, int > p = dq2.back();
                if(p.first <= r - y)break;
                p = {p.second, p.first};
                dq2.pop_back();
                if(mp1[p]){
                    if(al){
                        alice++;
                    }
                    else{
                        bob++;
                    }
                    mp2[p] = 0;
                }
            }
            r = r - y;
        }
        al = !al;
    }
    cout << alice << " " << bob << endl;
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