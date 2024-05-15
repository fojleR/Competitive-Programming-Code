#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;


class Code352E {
public:
    int N, M, parent[200001], rank[200001], cnt = 0;
    ll ans = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;


    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }


    void merge(int x, int y) {
        x = find(x);
        y= find(y);
        if (x == y) return;

        if (rank[x] > rank[y]) {
            parent[y] = x;
            rank[x] += rank[y];
        } else {
            parent[x] = y;
            rank[y] += rank[x];
        }
    }


    void solve() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);


        cin >> N >> M;
        for (int i = 1; i <= N; i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        for (int i = 0; i < M; i++) {
            int K, C, A[200001];
            cin >> K >> C;
            for (int j = 0; j < K; j++) {
                cin >> A[j];

                if (j > 0) {
                    pq.push({C, A[0], A[j]});
                }
            }
        }

        while (!pq.empty()) {
            auto [c, x, y] = pq.top();
            pq.pop();

            if (find(x) != find(y)) {
                ans += c;
                merge(x, y);
                cnt++;
            }

            if (cnt == N - 1) break;
        }

        if (cnt != N - 1) cout << -1;
        else cout << ans;
    }
};


int main() {
    Code352E code;
    code.solve();
    return 0;
}