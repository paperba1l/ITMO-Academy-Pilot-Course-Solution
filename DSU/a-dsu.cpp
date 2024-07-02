#include <bits/stdc++.h>

using namespace std;

struct DSU {
    int N;
    vector<int> rank, par;
    DSU(int n) {
        N = n;
        par = vector<int>(N+1);
        iota(begin(par), end(par), 0);
        rank = vector<int>(N+1, 1);
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
            if(rank[parx] < rank[pary]) {
                swap(parx, pary);
            }

            par[pary] = parx;
            rank[parx] += rank[pary];
        }
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    DSU  dsu(n);
    while(q--) {
        string s;
        int u, v;
        cin >> s >> u >> v;

        if(s == "union") {
            dsu.merge(u, v);
        } else {
            cout << ((dsu.find(u) == dsu.find(v)) ? "YES" : "NO" )<< endl;
        }
    }

}

int main() {
    solve();
    return 0;
}
