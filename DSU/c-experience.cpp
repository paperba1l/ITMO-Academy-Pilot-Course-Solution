
#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> par, rank, max_e, min_e, score, extra_score;
    DSU(int n) {
        par = vector<int>(n);
        iota(begin(par), end(par), 0);

        rank = vector<int>(n, 1);

        // max_e = vector<int>(n);
        // iota(begin(min_e), end(max_e), 0);

        // max_e = vector<int>(n);
        // iota(begin(max_e), end(min_e), 0);

        score = vector<int>(n, 0);
        extra_score = vector<int>(n, 0);
    }

    int find(int x) {
        if(par[x] == x) return x;
        return find(par[x]);
    }
    void merge(int x, int y) {
        int px = find(x);
        int py = find(y);

        if(px == py) return;

        if(rank[px] < rank[py]) {
            swap(px, py);
        }
        rank[px] += rank[py];
        par[py] = px;
        // min_e[px] = min(min_e[px], min_e[py]);
        // max_e[px] = max(max_e[px], max_e[py]);

        extra_score[py] = score[px];
    }
    void add(int x, int val) {
        int px = find(x);
        score[px] += val;
    }
    int get_score(int x) {
        int scr = score[x];
        if (par[x] == x) {
            return scr;
        }
        scr += get_score(par[x]) - extra_score[x];
        return scr;
    }
};


void solve() {
    int n, q;
    cin >> n >> q;

    DSU dsu(n+2);

    while(q--) {
        string t;
        cin >> t;

        if(t=="join") {
            int u, v;
            cin >> u >> v;
            dsu.merge(u, v);
        } else if(t=="add") {
            int u, val;
            cin >> u >> val;
            dsu.add(u, val);
        } else {
            int u;
            cin >> u;
            cout << dsu.get_score(u) << '\n';
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
