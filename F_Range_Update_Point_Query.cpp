#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;
int a[mx];

ll tree[mx*4];
ll lazy[mx * 4];

void update(int node, int l, int r, int a, int b){
    if(lazy[node] != 0){
        if(l != r){
            int dx = lazy[node];
            lazy[node] = 0;
            lazy[node * 2] += dx;
            lazy[node * 2 + 1] += dx;
        }
        
    }
    if(r < a || l > b){
        return;
    }
    if(l >= a and r <= b){
        lazy[node]++;
        return;
    }
    int  mid = (l + r) / 2;
    int Lnode = 2 * node;
    int Rnode = Lnode + 1;
    update(Lnode, l, mid, a, b);
    update(Rnode, mid + 1, r, a, b);
}
 
int query(int node, int l, int r, int a, int b){
    if(lazy[node] != 0){
        if(l != r){
            int dx = lazy[node];
            lazy[node] = 0;
            lazy[node * 2] += dx;
            lazy[node * 2 + 1] += dx;
        }
        
    }
    if(r < a || l > b){
        return 0;
    }
    if(l >= a and r <= b){
        //cout << l << " " << r << " " << node << endl;
        return lazy[node];
    }
 
    int  mid = (l + r) / 2;
    int Lnode = 2 * node;
    int Rnode = Lnode + 1;
    int p = query(Lnode, l, mid, a, b);
    int q = query(Rnode, mid + 1, r, a, b);
    return max(p, q);
}

void solve(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 0; i <= n * 4; i++){
        lazy[i] = 0;
    }
    while(q--){
        int ch;
        cin >> ch;
        if(ch == 1){
            int l, r;
            cin >> l >> r;
            //cout << l << " " << r << endl;
            update(1, 1, n, l, r);
            // for(int i = 1; i <= 10; i++){
            //     cout << i << " " << tree[i] << endl;
            // }
        }
        else{
            int x;
            cin >> x;
            //cout << x << endl;
            int cnt = query(1, 1, n, x, x);
            //cout << cnt << " ";
            for(int i = 0; i < min(3, cnt); i++){
                int sum = 0;
                while(a[x]){
                    sum += a[x] % 10;
                    a[x] /= 10;
                }
                a[x] = sum;
            }
            cout << a[x] << endl;
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