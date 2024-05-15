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
    int n;
    cin >> n;
    vector< vector< int > > v;
    set< int > st;
    map< int, int > mp,mp2;
    for(int i = 0; i < n; i++){
        int nn;
        cin >> nn;
        vector< int > tm;
        for(int j = 0; j < nn; j++){
            int x;
            cin >> x;
            tm.push_back(x);
            st.insert(x);
            mp[x]++;
        }
        v.push_back(tm);
    }
    int ans = 0;

    for(auto it = st.begin(); it != st.end(); it++){
        int tot = st.size();
        int x = *it;
        mp2 = mp;
        for(int i = 0; i < n; i++){
            auto it2 = find(v[i].begin(), v[i].end(), x);
            if(it2 != v[i].end()){
                for(auto xx: v[i]){
                    mp2[xx]--;
                    if(mp2[xx] == 0)tot--;
                }
            }
            
        }
        if(tot != st.size()){
            ans = max(ans, tot);
        }
    }
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