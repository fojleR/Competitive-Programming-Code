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
    map< ll, ll > mp;
    for(int i = 0; i < n; i++){
        ll s, c;
        cin >> s >> c;
        mp[s] = c;
    }

    for(auto it = mp.begin(); it != mp.end(); it++){
        ll vl = it->first, cnt = it->second;
        while(cnt > 0){
            mp[vl] = 0;
            if(cnt % 2) mp[vl]++;
            vl *= 2;
            cnt /= 2;
        }
    }
    for(auto it = mp.begin(); it != mp.end(); it++){
        cout << it->first << " " << it->second << endl;
    }

    cout << mp.size() << endl;
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