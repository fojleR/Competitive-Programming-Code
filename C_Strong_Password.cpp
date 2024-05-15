#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

void solve(){
    string s;
    cin >> s;
    int m;
    cin >> m;
    string l, r;
    cin >> l >> r;
    map< int, vector< int > > mp;
    map< int, int > track;
    for(int i = 0; i < s.size(); i++){
        int x = s[i] - '0';
        mp[x].push_back(i);
    }
    int pos = -1;
    for(int i = 0; i < m; i++){
        int mx = 0;
        for(char j = l[i]; j <= r[i]; j++){
            int x = j - '0';
            int ind = upper_bound(mp[x].begin(), mp[x].end(), pos) - mp[x].begin();
            //cout << x << " " << ind << endl;
            if(ind == mp[x].size()){
                cout << "YES" << endl;
                return;
            }
            mx = max(mx, mp[x][ind]);
        }
        pos = mx;
        //cout << i << " " << pos << endl;
    }
    cout << "NO" << endl;
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