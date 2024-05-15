#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

bool cmp(pair<int, int > a, pair< int, int > b){
    if(a.second != b.second) return a.second > b.second;
    else return a.first < b.first;
}

void solve(){
    int n;
    cin >> n;
    vector< pair< int, int > > v;
    int mx = 0;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int cnt = 0;
        for(int j = 0; j < s.size(); j++){
            if(s[j] == 'o'){
                cnt++;
            }
        }
        mx = max(mx, cnt);
        v.push_back({i, cnt});
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < n; i++){
        cout << v[i].first  + 1<< " ";
    }
    cout << endl;
    
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