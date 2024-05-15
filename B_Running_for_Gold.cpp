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
    int lis[n][5];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 5; j++){
            cin >> lis[i][j];
        }
    }
    int win = 0;
    for(int i = 1; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < 5; j++){
            if(lis[i][j] < lis[win][j])cnt++;
        }
        if(cnt >= 3)win = i;
    }
    for(int i = 0; i < n; i++){
        if(i == win)continue;
        int cnt = 0;
        for(int j = 0; j < 5; j++){
            if(lis[i][j] < lis[win][j])cnt++;
        }
        if(cnt >= 3){
            cout << -1 << endl;
            return;
        }
    }
    cout << win + 1 << endl;

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