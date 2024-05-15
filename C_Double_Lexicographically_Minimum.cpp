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
    int cnt[26] = {0};
    for(int i = 0; i < s.size(); i++){
        cnt[s[i] - 'a']++;
    }
    string s1 = "", s2 = "";
    s = "";
    for(int i = 0; i < 26; i++){
        while(cnt[i] > 1){
            s1 += 'a' + i;
            s2 += 'a' + i;
            cnt[i] -= 2;
        }
        if(cnt[i]){
            vector< int > hvs;
            for(int j = i + 1; j < 26; j++){
                if(cnt[j])hvs.push_back(j);
            }
            if(hvs.empty()){
                s1 += 'a' + i;
                cnt[i]--;
                break;
            }
            else if(hvs.size() == 1){
                int j = hvs[0];
                while(cnt[j] > 1){
                    s1 += 'a' + j;
                    s2 += 'a' + j;
                    cnt[j] -= 2;
                }
                if(cnt[j]){
                    s1 += 'a' + j;
                    s2 += 'a' + i;
                    cnt[i]--;
                    cnt[j]--;
                    break;
                }
                else{
                    s1 += 'a' + i;
                    cnt[i]--;
                    break;
                }
            }
            else{
                s = "";
                s2 += 'a' + i;
                for(int j = i + 1; j < 26; j++){
                    while(cnt[j]){
                        s += 'a' + j;
                        cnt[j]--;
                    }
                }

            }
        }
    }
    reverse(s2.begin(), s2.end());
    cout << s1 + s + s2 << endl;
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