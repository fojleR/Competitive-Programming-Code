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
    int n, m;
    cin >> n >> m;
    map< int, multiset< int > > mp;
    int score[m];
    for(int i = 0; i < m; i++) cin >> score[i];
    int mx = 0;
    int curscore[n];
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int tms = i + 1;
        for(int j = 0; j < m; j++){
            if(s[j] == 'o'){
                tms += score[j];
            }
            else{
                mp[i].insert(score[j] * -1);
            }
        }
        curscore[i] = tms;
        mx = max(mx, tms);
    }
    for(int i = 0; i < n; i++){
        int cnt = 0;
        while(curscore[i] < mx){
            auto it = mp[i].begin();
            int x = *it;
            curscore[i] += (x * -1);
            cnt++;
            mp[i].erase(it);
        }
        cout << cnt << endl;
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