#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

int n, s;
vector< pair< int, int > > v;
int a[mx];

ll dp[mx][2];

ll remove_bracket(int ind, int turn){
    if(ind == 1){
        return a[0] * turn ? v[1].first : v[1].second; 
    }
    if(!turn){
        return dp[ind][turn] = v[ind].first * min(remove_bracket(ind - 1, 0), remove_bracket(ind - 1, 1));
    }
    else{
        return dp[ind][turn] = v[ind].second * min(remove_bracket(ind - 1, 0), remove_bracket(ind - 1, 1));
    }
}

void solve(){
    v.clear();
    cin >> n >> s;
    int a[n];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    v.push_back({0, a[1]});
    for(int i = 2; i < n; i++){
        int x = a[i];
        if(x <= s){
            v.push_back({0, x});
        }
        else{
            v.push_back({s, x - s});
        }
    }
    v.push_back({a[n], 0});

    cout << remove_bracket(n - 1, a[n]) << endl;
    // for(auto x: v){
    //     cout << x.first << " " << x.second << endl;
    // }
    // cout << endl;
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