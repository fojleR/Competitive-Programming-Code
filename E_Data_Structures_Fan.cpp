#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

struct Node{
    ll zero, one;
};

Node tree[4 * mx];
int lazy[4 * mx];
int n;
int a[mx];
string s;


 
void build(int node, int l, int r){
    if(l == r){
        int i = l - 1;
        if(s[i] == '0'){
            tree[node].zero = a[l];
            tree[node].one = 0;
        }
        else{
            tree[node].zero = 0;
            tree[node].one = a[l];
        }
        //cout << node << " " << tree[node].zero << " " << tree[node].one << endl;
        return;
    }
    int mid = (l + r) / 2;
    int Lnode = 2 * node;
    int Rnode = 2 * node + 1;
    build(Lnode, l, mid);
    build(Rnode, mid + 1, r);
    tree[node].zero = tree[Lnode].zero ^ tree[Rnode].zero;
    tree[node].one = tree[Lnode].one^ tree[Rnode].one;
}

void update(int node, int l, int r, int a, int b){
    //cout << l << " " << r << endl;
    if(lazy[node] != 0){
        int tm = tree[node].zero;
        tree[node].zero = tree[node].one;
        tree[node].one = tm;
        lazy[node] = 0;
        if(l != r){
            lazy[node * 2] = lazy[node * 2] ^ 1;
            lazy[node * 2 + 1] = lazy[node * 2  + 1] ^ 1;
        }
    }
    if(r < a || l > b){ // out of range
        return;
    }
    if(l >= a and r <= b){ // in range
        //cout << l << " " << r << endl;
        int tm = tree[node].zero;
        tree[node].zero = tree[node].one;
        tree[node].one = tm;
        if(l != r){
            lazy[node * 2] = lazy[node * 2] ^ 1;
            lazy[node * 2 + 1] = lazy[node * 2  + 1] ^ 1;
        }
        return;
    }
 
    int  mid = (l + r) / 2;
    int Lnode = 2 * node;
    int Rnode = Lnode + 1;
    update(Lnode, l, mid, a, b);
    update(Rnode, mid + 1, r, a, b);
    tree[node].zero = tree[Lnode].zero ^ tree[Rnode].zero;
    tree[node].one = tree[Lnode].one^ tree[Rnode].one;
}
 

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < 4 * n; i++){
        tree[i].one = tree[i].zero = lazy[i] = 0;
    }
    cin >> s;
    int q;
    cin >> q;
    build(1, 1, n);
    // for(int i = 1; i <= 10; i++){
    //      cout << i << " zero: " << tree[i].zero << " one: " << tree[i].one << endl;
    // }
    while(q--){
        int ch;
        cin >> ch;
        if(ch == 2){
            int x;
            cin >> x;
            if(x == 0){
                cout << tree[1].zero << " ";
            }
            else{
                cout << tree[1].one << " ";
            }
        }
        else{
            int l, r;
            cin >> l >> r;
            update(1, 1, n, l, r);
            // for(int i = 1; i <= 10; i++){
            //     cout << i << " zero: " << tree[i].zero << " one: " << tree[i].one << endl;
            // }
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