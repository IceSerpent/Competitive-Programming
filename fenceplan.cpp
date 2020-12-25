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

bool visited[MN];
vector <int> adj[MN];
vector<pair<int,int>> pos;
int minPerimeter = 1e9;
int minX = 1e9;
int maxX = -1e9;
int minY = 1e9;
int maxY = -1e9;

int dfs (int k) {
    if (visited[k]) {
        return 0;
    }
    visited[k] = true;

    maxX = max(pos[k].f, maxX);
    minX = min(pos[k].f, minX);
    maxY = max(pos[k].s, maxY);
    minY = min(pos[k].s, minY);

    for (int i = 0; i < adj[k].size(); i++) {
        dfs(adj[k][i]);
    }

    return 0;
}

int main() {
    setIO("fenceplan");

    int n, m; cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int a,b; cin >> a >> b;
        pos.pb({a,b});
    }

    for (int i = 0; i < m; i++) {
        int a,b; cin >> a >> b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }

    int counter = 0;
    while (counter <= n-1) {
        if (visited[counter]) {
            counter++;
        } else {
            dfs(counter);
            int perimeter = 2*(maxX - minX) + 2*(maxY - minY);
            minPerimeter = min(minPerimeter, perimeter);
            minX = 1e9;
            maxX = -1e9;
            minY = 1e9;
            maxY = -1e9;
        }
    }

    cout << minPerimeter << endl;

}