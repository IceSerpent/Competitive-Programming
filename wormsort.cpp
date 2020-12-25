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

const int MN = 1e5 + 5;
bool visited [MN];
vector <pair<int,int>> adj [MN];

int dfs (int k, int bound) {
    if (visited[k]) {
        return 0;
    }
    visited[k] = true;
    for (int i = 0; i < adj[k].size(); i++) {
        if (adj[k][i].s >= bound) {
            dfs(adj[k][i].f, bound);
        }
    }
    return 0;
}

int main() {
    setIO("wormsort");

    bool none = true;
    int n; cin >> n;
    int m; cin >> m;
    int cows [n];
    int size [m];
    int start = 0;

    for (int i = 0; i < n; i++) {
        cin >> cows[i];
        cows[i]--;
        if (!(cows[i] == i)) {
            start = i;
            none = false;
        }
    }

    if (none) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < m; i++) {
            int a,b,w; cin >> a >> b >> w;
            adj[a-1].pb({b-1, w});
            adj[b-1].pb({a-1, w});
            size[i] = w;
        }
        
        sort(size, size + m);

        int low = 0;
        int high = m - 1;
        while (size[low] < size[high]) {
            int mid = (low + high + 1)/2;
            int bound = size[mid];

            dfs(start, bound);

            bool condition = true;

            for (int i = 0; i < n; i++) {
                if (!(cows[i] == i) && !visited[i]) {
                    condition = false;
                }
                visited[i] = false;
            }

            if (condition) {
                low = mid;
            } else {
                high = mid-1;
            }

        }

        cout << size[low] << endl;
    }


}