#include<bits/stdc++.h>


using namespace std;


#define ll              long long
#define pb              insert_back
#define PI              acos(-1.0)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define fast           ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int mx = 200005;
const int mod = 1e9 + 7;
struct Node{
    int ti, id;
};

void solve(){
    string s1, s2;
    cin >> s1 >> s2;
    int t, q;
    cin >> t >> q;
    set< pair< int, int > > qq;
    int unmatched = 0;
    for(int i = 0; i < s1.size(); i++){
        if(s1[i] != s2[i]){
            unmatched++;
        }
    } 
    // cout << unmatched << endl;
    int time = 0;
    while(q--){
        int ch;
        cin >> ch;
        time++;
        if(ch == 1){
            int id;
            cin >> id;
            id--;
            if(s1[id] != s2[id])unmatched--;
            //cout << "jjj " << unmatched << endl;
            qq.insert({time, id});
            if(qq.size() >= t){
                auto it = qq.begin();
                int id = it->second;
                if(id != -1){
                    if(s1[id] != s2[id])unmatched++;
                }
                qq.erase(it);
                //cout << "kkk " << unmatched << endl;
            }
        }
        else if(ch == 2){
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            b--, d--;
            qq.insert({time, -1});
            if(qq.size() >= t){
                auto it = qq.begin();
                int id = it->second;
                if(id != -1){
                    if(s1[id] != s2[id])unmatched++;
                }
                qq.erase(it);
            }
            if(a == 1 and c == 1){
                if(s1[b] != s2[b])unmatched--;
                if(s1[d] != s2[d])unmatched--;
                swap(s1[b], s1[d]);
                if(s1[b] != s2[b])unmatched++;
                if(s1[d] != s2[d])unmatched++;
            }
            else if(a == 2 and c == 2){
                if(s1[b] != s2[b])unmatched--;
                if(s1[d] != s2[d])unmatched--;
                swap(s2[b], s2[d]);
                if(s1[b] != s2[b])unmatched++;
                if(s1[d] != s2[d])unmatched++;
            }
            else if(a == 1 and c == 2){
                if(s1[b] != s2[b])unmatched--;
                if(s1[d] != s2[d])unmatched--;
                swap(s1[b], s2[d]);
                if(s1[b] != s2[b])unmatched++;
                if(s1[d] != s2[d])unmatched++;
            }
            else{
                if(s1[b] != s2[b])unmatched--;
                if(s1[d] != s2[d])unmatched--;
                swap(s2[b], s1[d]);
                if(s1[b] != s2[b])unmatched++;
                if(s1[d] != s2[d])unmatched++;
            }
        }
        else if(ch == 3){
            if(unmatched == 0){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
            qq.insert({time, -1});
            if(qq.size() >= t){
                auto it = qq.begin();
                int id = it->second;
                if(id != -1){
                    if(s1[id] != s2[id])unmatched++;
                }
                qq.erase(it);
                
            }
        }
        //cout << "#3 " << unmatched << endl;
        //cout << unmatched << endl;
    }
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