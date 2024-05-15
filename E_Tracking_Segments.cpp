#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;
vector< pair< int, int > > v;
int qr[mx];
int n, m, q; 
bool check(int move){
   // cout << "check" << endl;
    vector< int > vv;
    for(int i = 0; i < move; i++){
        vv.push_back(qr[i]);
        //cout << vv[i] << " ";
    }
    //cout << endl;
    sort(vv.begin(), vv.end());
    for(int i = 0; i < m; i++){
        int ind1 = lower_bound(vv.begin(), vv.end(), v[i].first) - vv.begin();
        int ind2 = upper_bound(vv.begin(), vv.end(), v[i].second) - vv.begin();
        ind2--;
        int tot = ((v[i].second - v[i].first + 1) / 2) + 1;
        if((ind2 - ind1 + 1) >= tot){
            // cout << ind1 << " " << ind2 << " " << tot << endl;
            // cout << v[i].first << " " << v[i].second << endl;
            return true;
        }
    }
    return false;
}
void solve(){
    v.clear();
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
        //cout << x << " " << y << endl;
    }
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> qr[i];
        //cout << qr[i] << " ";
    }
    //cout << endl;
    int ans = -1;
    int lo = 1, hi = q;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(check(mid)){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
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