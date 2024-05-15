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
    string s1, s2;
    cin >> s1 >> s2;
    map< char, vector< int > > v;
    for(int i = 0; i < s1.size(); i++){
        v[s1[i]].push_back(i);
    }
    int ans = 1;
    int pos = -1;
    //cout << v['a'].size() << endl;
    for(int i = 0; i < s2.size(); i++){
        auto it = upper_bound(v[s2[i]].begin(), v[s2[i]].end(), pos);
        int ind = it - v[s2[i]].begin();
        //cout << pos << " " << ind << endl;
        if(ind == v[s2[i]].size()){
            ans++;
            pos = -1;
            i--;
        }
        else{
            pos = v[s2[i]][ind];
        }
    }
    cout << ans << endl;
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