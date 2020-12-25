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

const int MN = 1e5 + 30;
bool visited[MN];
vector<int> adj[MN];
int counter = 0;

int dfs(int i) {

    if (visited[i]) {
        return 0;
    }
    visited[i] = true;
    counter++;

    for (int j = 0; j < adj[i].size(); j++) {
        dfs(adj[i][j]);
    }

    return 0;
}

int main() {
    setIO("moocast");

    int n; cin >> n;
    vector<pair<pair<int, int>, int>> cows;
    for (int i = 0; i < n; i++) {
        int a,b,c; cin >> a >> b >> c;
        cows.pb({{a,b}, c});
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }

            int x1 = cows[i].f.f;
            int y1 = cows[i].f.s;
            int power = cows[i].s;
            int x2 = cows[j].f.f;
            int y2 = cows[j].f.s;

            if (((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) <= power*power) {
                adj[i].pb(j);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        counter = 0;
        for (int j = 0; j < n; j++) {
            visited[j] = false;
        }
        dfs(i);
        ans = max(ans, counter);
    }

    cout << ans << endl;

}