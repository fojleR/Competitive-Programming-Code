#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void solve() {
    int t;
    cin >> t;
    vector<pair<int, vector<int>>> results;
    
    while (t--) {
        int x;
        cin >> x;
        vector<int> result;
        
        while (x != 0) {
            if (x & 1) {
                if (x & 2) {
                    result.push_back(-1);
                    x = (x + 1) >> 1;
                } else {
                    result.push_back(1);
                    x >>= 1;
                }
            } else {
                result.push_back(0);
                x >>= 1;
            }
        }
        
        results.push_back({result.size(), result});
    }
    
    for (const auto& res : results) {
        cout << res.first << endl;
        for (int i = 0; i < res.first; ++i) {
            cout << res.second[i] << (i == res.first - 1 ? '\n' : ' ');
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
