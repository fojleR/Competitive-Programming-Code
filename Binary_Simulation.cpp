#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 100005;
const int mod = 1e9 + 7;

// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================


string s;
int tree[4 * mx];

void update(int node, int b, int e, int i, int j){
    if(i > e || j < b) return;
    if(b >= i && e <= j){
        tree[node]++;
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(left, b, mid, i, j);
    update(right, mid + 1, e, i, j);
}

int query(int node, int b, int e, int i){
    if(i > e || i < b) return 0;
    if(b == e and i == b){
        return tree[node];
    }
    if(b != e){
        tree[node * 2] += tree[node];
        tree[node * 2 + 1] += tree[node];
        tree[node] = 0;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(left, b, mid, i);
    int p2 = query(right, mid + 1, e, i);
    return p1 + p2;
}

void solve(){
    cin >> s;
    int n = s.size();
    for(int i = 0; i <= 4 * n; i++){
        tree[i] = 0;
    }
    int q;
    cin >> q;
    while(q--){
        char ch;
        cin >> ch;
        if(ch == 'I'){
            int l, r;
            cin >> l >> r;
            //cout << l << " " << r << endl;
            update(1, 1, n, l, r);
        }
        else{
            int x;
            cin >> x;
            int ans = query(1, 1, n, x);
            if(ans % 2 == 0){
                cout << s[x - 1] << endl;
            }
            else{
                if(s[x - 1] == '0'){
                    cout << "1\n";
                }
                else{
                    cout << "0\n";
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
        cout << "Case " << ++cse << ":" << endl;
        solve();
    }
    return 0;
}