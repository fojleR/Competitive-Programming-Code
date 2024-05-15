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
    int n = s.size();
    int cnt[n + 1] = {0};
    stack< pair< char, int > > lo, up;
    for(int i = 0; i < n; i++){
        if(s[i] == 'b'){
            cnt[i] = 1;
            if(lo.empty())continue;
            int id = lo.top().second;
            lo.pop();
            cnt[id] = 1;
        }
        else if(s[i] == 'B'){
            cnt[i] = 1;
            if(up.empty())continue;
            int id = up.top().second;
            up.pop();
            cnt[id] = 1;
        }
        else if(s[i] >= 'a' and s[i] <= 'z'){
            lo.push({s[i], i});
        }
        else if(s[i] >= 'A' and s[i] <= 'Z'){
            up.push({s[i], i});
        }
    }
    for(int i = 0; i < n; i++){
        if(cnt[i] == 1)continue;
        else{
            cout << s[i];
        }
    }
    cout << endl;
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