#include <bits/stdc++.h>
#include <array>
using namespace std;
using ll = long long;
#define pb push_back
#define f first
#define s second

void setIO(string name){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

const int MN = 10e+5;
vector<pair<int, int>> adj [MN];
int answer = 0;

int dfs (int root, int k, int parent, int relevance) {
    if (relevance >= k) {
        answer++;
    }
    int newRelevance = relevance;
    if (newRelevance == -1) {
        newRelevance = 1e9 + 5;
    }

    for (int i = 0; i < adj[root].size(); i++) {
        int nextNode = adj[root][i].f;
        if (nextNode == parent) {
            continue;
        }
        dfs(nextNode, k, root, min(newRelevance, adj[root][i].s));
    }

    return 0;
}

int main() {
    setIO("mootube");
    int n, q; cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int a, b, r; cin >> a >> b >> r;
        adj[a-1].pb({b-1,r});
        adj[b-1].pb({a-1,r});
    }

    for (int i = 0; i < q; i++) {
        int k, root; cin >> k >> root;
        dfs(root - 1, k, -1, -1);
        cout << answer << endl;
        answer = 0;
    }


}