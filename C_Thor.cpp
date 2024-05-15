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
    int n, q;
    cin >> n >> q;
    int cnt[n + 1] = {0};
    int tot = 0;
    queue< int > qq;
    int pre = 0;
    for(int i = 0; i < q; i++){
        int  a, b;
        cin >> a >> b;
        if(a == 1){
            qq.push(b);
            cnt[b]++;
            tot++;
            cout << tot << endl;
        }
        else if(a == 2){
            tot -= cnt[b];
            cnt[b] = 0;
            cout << tot << endl;
        }
        else{
            if(b <= pre)continue;
            else{
                int need_pop = b - pre;
                pre = b;
                for(int j = 0; j < need_pop; j++){
                    int x = qq.front();
                    qq.pop();
                    if(cnt[x]){
                        tot--;
                        cnt[x]--;
                    }
                }
                cout << tot << endl;
            }
        }
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