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
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    int a[n];
    priority_queue< pair< int, int > > q;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        q.push({a[i], i});
    }

    int small = min(s1, s2);
    int large = max(s1, s2);

    int track_large = 0;
    vector< int > large_v, small_v;
    while(!q.empty()){
        track_large += small;
        //cout << track_large << " " << large << endl;
        if(track_large >= large){
            large_v.push_back(q.top().second);
            q.pop();
            track_large %= large;
        }
        if(!q.empty()){
            small_v.push_back(q.top().second);
            q.pop();
        }
    }

    if(small == s1){
        cout << small_v.size() << " ";
        for(auto x: small_v){
            cout << x + 1 << " ";
        }
        cout << endl;
        cout << large_v.size() << " ";
        for(auto x: large_v){
            cout << x + 1 << " ";
        }
        cout << endl;
    }
    else{
        cout << large_v.size() << " ";
        for(auto x: large_v){
            cout << x + 1 << " ";
        }
        cout << endl;
        cout << small_v.size() << " ";
        for(auto x: small_v){
            cout << x + 1<< " ";
        }
        cout << endl;
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