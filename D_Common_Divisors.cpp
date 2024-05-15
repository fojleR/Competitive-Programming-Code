#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 1000001;
const int mod = 1e9 + 7;

int n;
int ans = 1;
int mp[mx];
void divisor(int xx){
    for(int i = 1; i * i <= xx; i++){
        if(xx % i == 0){
            //cout << xx << " " << i << endl;
            mp[i]++;
            if(i * i != xx){
                mp[xx / i]++;
            }
        }
    }
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        divisor(x);
    }

    for(int i = 1000000; i >= 1; i--){
        if(mp[i] >= 2){
            cout << i << endl;
            break;
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