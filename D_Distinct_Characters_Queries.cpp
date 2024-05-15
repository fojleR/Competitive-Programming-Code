#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 100005;
const int mod = 1e9 + 7;
string s;
int n;
int Node[4 * mx][26];

int ans[26];

void query(int node, int l, int r, int a, int b){
    if(r < a || l > b){
        return;
    }
    if(l >= a and r <= b){
        int tot = 0;
        for(int i = 0; i < 26; i++){
            if(Node[node][i])ans[i]++;
        }
        return;
    }

    int left = 2 * node;
    int right = 2 * node + 1;
    int mid = (l + r) / 2;

    query(left, l, mid, a, b);
    query(right, mid + 1, r, a, b);
}

void update(int node, int l, int r, int a, int b, char ch){
    if(r < a || l > b){
        return;
    }
    if(l == r and l == a){
        //cout << "ghkjl" << endl;
        int x = s[a] - 'a';
        s[a] = ch;
        Node[node][x] = 0;
        x = ch - 'a';
        Node[node][x] = 1;
        return;
    }
    int left = 2 * node;
    int right = 2 * node + 1;
    int mid = (l + r) / 2;
    update(left, l, mid, a, b, ch);
    update(right, mid + 1, r, a, b, ch);
    Node[node][int(s[a] - 'a')]--;
    for(int i = 0; i < 26; i++){
        Node[node][i] = Node[left][i] + Node[right][i];
    }
}

void build(int node, int l, int r){
    if(r < 0 || l >= n){
        return;
    }
    if(l == r){
        int x = s[l] - 'a';
        Node[node][x] = 1;
        return;
    }

    int left = 2 * node;
    int right = 2 * node + 1;
    int mid = (l + r) / 2;
    build(left, l, mid);
    build(right, mid + 1, r);
    for(int i = 0; i < 26; i++){
        Node[node][i] += Node[left][i] + Node[right][i];
    }
}

void solve(){
    cin >> s;
    n = s.size();
    build(1, 0, n - 1);
    int q;
    cin >> q;
    while(q--){
        int ch;
        cin >> ch;
        if(ch == 1){
            int ind; 
            char x;
            cin >> ind >> x;
            ind--;
            update(1, 0, n - 1, ind, ind, x);
            // for(int i = 1; i <= 4 * n; i++){
            //     cout << i << " : ";
            //     for(int j = 0; j < 26; j++)cout << Node[i][j] << " ";
            //     cout << endl;
            // }
        }
        else{
            int l, r;
            cin >> l >> r;
            l--, r--;
            for(int i = 0; i < 26; i++) ans[i] = 0;
            query(1, 0, n - 1, l, r);
            int res = 0;
            for(int i = 0; i < 26; i++){
                if(ans[i])res++;
            }
            cout << res << endl;
        }
    }
    //update(1, 0, n - 1, 0, 0, 'b');
    
}


int main(){
    fast
    int t = 1;
    //cin >> t;
    int cse = 0;
    while(t--){
        //cout << "Case " << ++cse << ": ";
        solve();
    }
    return 0;
}