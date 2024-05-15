#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define getbit(n, i) (((n) & (1LL << (i))) != 0) 
#define setbit0(n, i) ((n) & (~(1LL << (i)))) 
#define setbit1(n, i) ((n) | (1LL << (i))) 
#define togglebit(n, i) ((n) ^ (1LL << (i))) 
#define lastone(n) ((n) & (-(n))) 
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;



ll a[mx];
int bitarry[35][mx];
int n;

ll tree[mx*4];

void build(int node, int l, int r){
    if(l == r){
        tree[node] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    int Lnode = 2 * node;
    int Rnode = 2 * node + 1;
    build(Lnode, l, mid);
    build(Rnode, mid + 1, r);
    tree[node] = tree[Lnode] & tree[Rnode];
}

int query(int node, int l, int r, int a, int b){
    if(r < a || l > b){
        return (1LL << 32) - 1;
    }
    if(l >= a and r <= b){
        //cout << l << " " << r << " " << node << endl;
        return tree[node];
    }

    int  mid = (l + r) / 2;
    int Lnode = 2 * node;
    int Rnode = Lnode + 1;
    int p = query(Lnode, l, mid, a, b);
    int q = query(Rnode, mid + 1, r, a, b);
    return p & q;
}

bool check(ll xx, int l, int r){ 
    int sum = query(1, 1, n, l, r);
    if(sum >= xx){
        return true;
    }
    else{
        return false;
    }
}
void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    for(int i = 0; i <= 4 * n; i++){
        tree[i] = 0;
    }
    build(1, 1, n);
    // for(int i = 1; i <= 10; i++){
    //     cout << i << " " << tree[i] << endl;
    // }
    // cout << query(1, 1, n, 1, 3) << endl;
    int q;
    cin >> q;
    while(q--){
        ll l, x;
        cin >> l >> x;
        if(x > a[l]){
            cout << -1 << " ";
            continue;
        }
        int lo = l, hi = n;
        int ans = l;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(check(x, l, mid)){
                ans = max(mid, ans);
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        cout << ans << " ";
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