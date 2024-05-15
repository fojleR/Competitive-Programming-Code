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
    int n, m , k;
    cin >> n >> m >> k;
    map< int, vector< int > > mp;
    for(int i = 0; i <= m; i++){
        int tm = i;
        int cnt = 0;
        set< int > st;
        st.insert(tm);
        for(int j = n; j >= 1; j--){
            tm = tm % j;
            st.insert(tm);
        }
        int sz = st.size();
        mp[sz].push_back(i);
    }
    cout << mp[k].size() << endl;
    for(auto it = mp.begin(); it != mp.end(); it++){
        cout << it->first << " " << it->second.size() << endl;
    }
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