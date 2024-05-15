#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 300005;
const int mod = 1e9 + 7;
string s;
int n;
vector< int > lis[mx];
int cnt[mx];
bool vis[mx];
ll ans;
ll cntt = 0;
void dfs(int node){
    //cout << node << " " << cntt << endl;
    vis[node] = true;
    if(lis[node].size() <= 1 and node != 1){
        //cout << "xxx" << cntt << endl;
        ans = min(ans, cntt);
    }
    for(auto child: lis[node]){
        if(!vis[child]){
            if((cnt[child] == 0 and s[node - 1] != 'L') || (cnt[child] == 1 and s[node - 1] != 'R')){
                cntt++;
            }
            dfs(child);
            if((cnt[child] == 0 and s[node - 1] != 'L') || (cnt[child] == 1 and s[node - 1] != 'R')){
                cntt--;
            }
        }
    }
}

void solve(){
    cin >> n;
    cin >> s;
   //cout << s << endl;
    for(int i = 0; i <= n; i++){
        lis[i].clear();
        vis[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        if(x){
            lis[x].push_back(i);
            lis[i].push_back(x);
            cnt[x] = 0;
        }
        if(y){
            lis[y].push_back(i);
            lis[i].push_back(y);
            cnt[y] = 1;
        }
    }
    //cout << lis[7].size() << endl;
    ans = 1e19;
    cntt = 0;
    dfs(1);
    cout << ans << endl;
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