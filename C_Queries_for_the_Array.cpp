#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              push_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;
char track[mx];
void solve(){
    track[0] = 's'; // sorted;
    track[1] = 's'; // sorted
    string s;
    cin >> s;

    for(int i = 2; i <= s.size(); i++){
        track[i] = 'u'; // undefined
    }

    int cnt = 0;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '+'){
            cnt++;
            if(cnt - 1 > 1 and track[cnt - 1] == 'n'){
                track[cnt] = 'n';
            }
        }
        else if(s[i] == '-'){
            if(track[cnt] == 's' and cnt > 2){
                track[cnt - 1] = 's';
                track[cnt] = 'u';
            }
            else if(cnt >= 2){
                track[cnt] = 'u';
            }
            cnt--;
        }
        else if(s[i] == '0'){
            if(track[cnt] == 's'){ // is this position is already sorted or not?
                cout << "NO" << endl; // if already sorted then we cannot unsort right now
                return;
            }
            track[cnt] = 'n';
        }
        else if(s[i] == '1'){
            if(track[cnt] == 'n'){ // is this position is already sorted or not?
                cout << "NO" << endl; // if it is already unsorted then we cannot sort right now
                return;
            }
            track[cnt] = 's';
        }
    }
    cout << "YES" << endl;
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