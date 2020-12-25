#include <bits/stdc++.h>
#include <array>
using namespace std;
using ll = long long;
#define pb push_back
#define f first
#define s second

const int MN = 1e5+30;

bool visited [MN];
vector<int> adj[MN];
int days = 0;
int virus [MN];

int dfs (int k) {
    if (visited[k]) {

    } else {
        visited[k] = true;
        int neighbors = 0;
        for (int i = 0; i < adj[k].size(); i++) {
            if (!visited[adj[k][i]]) {
                neighbors++;
            }
        }
        int thing = 1;
        while (thing < neighbors + 1) {
            thing *= 2;
            days++;
        }
        virus[k] = thing;
        for (int i = 0; i < adj[k].size(); i++) {
            if (!(virus[adj[k][i]] >= 1) && !visited[adj[k][i]]) {

                dfs(adj[k][i]);
                days++;
            }
        }
    }

    return 0;
}

int main() {
    
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int c, d; cin >> c >> d;
        adj[c].pb(d);
        adj[d].pb(c);
    }

    for (int i = 0; i < MN; i++) {
        visited[i] = false;
        virus[i] = 0;
    }   

    virus[1] = 1;
    dfs(1);
    cout << days << endl;
    return 0;
}