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
    int mp[7][50];
    for(int i = 0; i <= 5; i++){
        for(int j = 0; j < 50; j++){
            mp[i][j] = 0;
        }
    }

    
    vector< string > v;
    for(int i = 0; i < n; i++){
        string x;
        cin >> x;
        v.push_back(x);
        int tot = 0;
        for(int j = 0; j < x.size(); j++){
            tot += int(x[j] - '0');
        }
        int sz = x.size();
        mp[sz][tot]++;
    }


    // for(int i = 1; i <= 5; i++){
    //     for(int j = 1; j <= 45; j++){
    //         cout << mp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(v[i].size() == 1){
            int tot = 0;
            tot += int(v[i][0] - '0');
            ans += (mp[1][tot]);
        }
        else if(v[i].size() == 2){
            int tot = 0;
            for(int j = 0; j < v[i].size(); j++){
                tot += int(v[i][j] - '0');
            }
            ans += (mp[2][tot]);
        }
        else if(v[i].size() == 3){
            int tot = 0;
            for(int j = 0; j < v[i].size(); j++){
                tot += int(v[i][j] - '0');
            }
            ans += (mp[3][tot]);

            tot = 0;
            //cout << v[i] << endl;
            for(int j = 0; j < v[i].size(); j++){
                if(j < 2){
                    tot += int(v[i][j] - '0');
                }
                else{
                    tot -= int(v[i][j] - '0');
                }
            }
            //cout << tot << endl;
            ans += (mp[1][tot]) * 2;
            // tot = 0;
            // for(int j = 0; j < v[i].size(); j++){
            //     if(j > 0){
            //         tot += int(v[i][j] - '0');
            //     }
            //     else{
            //         tot -= int(v[i][j] - '0');
            //     }
            // }
            // ans += (mp[1][tot]) * 2;
        }
        else if(v[i].size() == 4){
            int tot = 0;
            for(int j = 0; j < v[i].size(); j++){
                tot += int(v[i][j] - '0');
            }
            ans += (mp[4][tot]);

            tot = 0;
            for(int j = 0; j < v[i].size(); j++){
                if(j < 3){
                    tot += int(v[i][j] - '0');
                }
                else{
                    tot -= int(v[i][j] - '0');
                }
            }
            ans += (mp[2][tot]) * 2;

            // tot = 0;
            // for(int j = 0; j < v[i].size(); j++){
            //     if(j > 0){
            //         tot += int(v[i][j] - '0');
            //     }
            //     else{
            //         tot -= int(v[i][j] - '0');
            //     }
            // }
            // ans += (mp[2][tot]) * 2;
        }
        else if(v[i].size() == 5){
            int tot = 0;
            for(int j = 0; j < v[i].size(); j++){
                tot += int(v[i][j] - '0');
            }
            ans += (mp[5][tot]);

            tot = 0;
            for(int j = 0; j < v[i].size(); j++){
                if(j < 4){
                    tot += int(v[i][j] - '0');
                }
                else{
                    tot -= int(v[i][j] - '0');
                }
            }
            ans += (mp[3][tot]) * 2;

            // tot = 0;
            // for(int j = 0; j < v[i].size(); j++){
            //     if(j > 0){
            //         tot += int(v[i][j] - '0');
            //     }
            //     else{
            //         tot -= int(v[i][j] - '0');
            //     }
            // }
            // ans += (mp[3][tot]) * 2;

            tot = 0;
            for(int j = 0; j < v[i].size(); j++){
                if(j < 3){
                    tot += int(v[i][j] - '0');
                }
                else{
                    tot -= int(v[i][j] - '0');
                }
            }
            ans += (mp[1][tot]) * 2;

            // tot = 0;
            // for(int j = 0; j < v[i].size(); j++){
            //     if(j > 1){
            //         tot += int(v[i][j] - '0');
            //     }
            //     else{
            //         tot -= int(v[i][j] - '0');
            //     }
            // }
            // ans += (mp[1][tot]) * 2;
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