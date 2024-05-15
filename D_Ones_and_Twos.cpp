#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

int n;
int ar[mx];
ll tree[mx*4];
 
void build(int node, int l, int r){
    if(l == r){
        tree[node] = ar[l];
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
        ar[l] = v;
        tree[node] = v;
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
    set< int > st;
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
        if(ar[i] == 1){
            st.insert(i);
        }
    }

    build(1, 1, n);
    // for(int i = 1; i <= 10; i++){
    //     cout << i << " " << tree[i] << endl;
    // }
    // cout << endl;
    while(q--){
        int ch;
        cin >> ch;
        if(ch == 2){
            int i, v;
            cin >> i >> v;
            if(ar[i] == 1){
                st.erase(i);
            }
            ar[i] = v;
            if(ar[i] == 1){
                st.insert(i);
            }
            //cout << "x " << i << " " << v << endl;
            update(1, 1, n, i, i, v);
            // for(int i = 1; i <= 10; i++){
            //     cout << i << " " << tree[i] << endl;
            // }
            // cout << endl;
        }
        else{
            int x;
            cin >> x;
            //cout << x << endl;
            int sum = query(1, 1, n, 1, n);
            if(sum < x){
                cout << "NO" << endl;
                continue;
            }
            if((sum - x) % 2 == 0){
                cout << "YES" << endl;
                continue;
            }
            if(st.empty()){
                cout << "NO" << endl;
                continue;
            }
            int fo = *(st.begin());
            int mx = 0;
            if(fo + 1 <= n){
                mx = query(1, 1, n, fo + 1, n);
            }
            int lo = *(st.rbegin());
            if(lo - 1>= 1){
                mx = max(mx, query(1, 1, n, 1, lo - 1));
            }
            if(mx >= x){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
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