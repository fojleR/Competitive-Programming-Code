#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;

bool cmp(pair< int, int > a, pair< int, int > b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    else{
        return a.second < b.second;
    }
}

void solve(){
    int n;
    cin >> n;
    vector< pair<int, int> > meeting;
    for(int i = 0; i < n; i++){
        int s, e;
        cin >> s >> e;
        meeting.push_back({s, e});
    }
    sort(meeting.begin(), meeting.end(), cmp);
    int ans = 1;
    int end_pri = meeting[0].second;
    for(int i = 1; i < n; i++){
        if(meeting[i].first >= end_pri){
            ans++;
            end_pri = meeting[i].second;
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