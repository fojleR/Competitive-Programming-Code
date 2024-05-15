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


int ar[mx];
ll tree[mx*4];
 
void build(int node, int l, int r){
    if(l == r){
        tree[node] = 0;
        return;
    }
    int mid = (l + r) / 2;
    int Lnode = 2 * node;
    int Rnode = 2 * node + 1;
    build(Lnode, l, mid);
    build(Rnode, mid + 1, r);
    tree[node] = tree[Lnode] + tree[Rnode];
}

void update(int node, int l, int r, int a, int b, int v){
    if(r < a || l > b){
        return;
    }
    if(l >= a and r <= b){
        //cout << "update " << node<< " " << l << " " << r << " " << v << endl;
        tree[node] += v;
        return;
    }
    int mid = (l + r) / 2;
    int Lnode = 2 * node;
    int Rnode = 2 * node + 1;
    update(Lnode, l, mid, a, b, v);
    update(Rnode, mid + 1, r, a, b, v);
    tree[node] = tree[Lnode] + tree[Rnode];
}
 
int query(int node, int l, int r, int a, int b){
    if(r < a || l > b){
        return 0;
    }
    if(l >= a and r <= b){
        return tree[node];
    }
 
    int  mid = (l + r) / 2;
    int Lnode = 2 * node;
    int Rnode = Lnode + 1;
    int p = query(Lnode, l, mid, a, b);
    int q = query(Rnode, mid + 1, r, a, b);
    return p + q;
}

void solve(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
    }
    int nq = n + q;
    build(1, 1, nq);
    while(q--){
        char ch;
        cin >> ch;
        if(ch == 'c'){
            int ind;
            cin >> ind;
            // int tind = ind;
            // bool ok = false;
            // while(tind <= n){
            //     int removed = query(1, 1, nq, 1, tind);
            //     //cout << "#" << removed << " " << tind << endl;
            //     int tm = removed + ind;
            //     if(tm != tind){
            //         tind = tm;
            //     }
            //     else{
            //         cout << ar[tind] << endl;
            //         update(1, 1, nq, tind, tind, 1);
            //         //cout << tree[1] << endl;
            //         ok = true;
            //         break;
            //     }
            // }
            // if(!ok){
            //     cout << "none" << endl;
            // }
            int toremove = -1;
            int hi = n, lo = ind;
            int removed = 0;
            while(lo <= hi){
                int mid = (lo + hi) / 2;
                removed = query(1, 1, nq, 1, mid);
                if(removed + ind == mid){
                    toremove = mid;
                    break;
                }
                else if(removed + ind < mid){
                    hi = mid - 1;
                }
                else{
                    lo = mid + 1;
                }
            }
            if(toremove == -1){
                cout << "none" << endl;
            }
            else{
                // cout << "#" << removed << " " << toremove << endl;
                cout << ar[toremove] << endl;
                update(1, 1, nq, toremove, toremove, 1);
            }
        }
        else{
            int x;
            cin >> x;
            n++;
            ar[n] = x;
        }
    }
    build(1, 1, nq + 1);
}


int main(){
    fast
    int t = 1;
    cin >> t;
    int cse = 0;
    while(t--){
        cout << "Case " << ++cse << ": " << endl;
        solve();
    }
    return 0;
}