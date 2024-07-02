#include <bits/stdc++.h>

using namespace std;

struct DSU {
    int N;
    vector<int> rank, par, mn, mx;
    DSU(int n) {
        N = n;
        par = vector<int>(N+1);
        iota(begin(par), end(par), 0);
        rank = vector<int>(N+1, 1);

        mn = vector<int>(N+1, 1);
        iota(begin(mn), end(mn), 0);

        mx = vector<int>(N+1, 1);
        iota(begin(mx), end(mx), 0);
    }

    int find(int x) {
        if(par[x] == x) {
            return x;
        }

        return par[x] = find(par[x]);
    }

    void merge(int x, int y) {
        int parx = find(x);
        int pary = find(y);

        if(parx != pary) {
            if(rank[parx] > rank[pary]) {
                swap(parx, pary);
            }

            par[parx] = pary;
            rank[pary] += rank[parx];
            mn[pary] = min(mn[pary], mn[parx]);

            mx[pary] = max(mx[pary], mx[parx]);

        }
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    DSU  dsu(n);
    while(q--) {
        string s;
        cin >> s;

        if(s == "union") {
            int u, v;
            cin >> u >> v;
            dsu.merge(u, v);
        } else {
            int u;
            cin >> u;
            int par = dsu.find(u);
            cout << dsu.mn[par] << " " << dsu.mx[par] << " " << dsu.rank[par] << endl;
        }
    }

}

int main() {
    solve();
    return 0;
}
