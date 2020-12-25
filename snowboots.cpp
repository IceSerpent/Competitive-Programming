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

int bestNum = 1e9;
const int MN = 255;
vector<pair<int,int>> boots;
int snow [MN];
bool visited [MN][MN];

int dfs(int pos, int boot, int n, int b) {

    if (pos > n - 1 || boot > b - 1) {
        return 0;
    }
    if (visited[pos][boot]) {
        return 0;
    }
    if (pos == n - 1) {
        bestNum = min(bestNum, boot);
        return 0;
    }
    if (boots[boot].f < snow[pos]) {
        return 0;
    }
    visited[pos][boot] = true;

    int stepDist = boots[boot].s;
    
    for (int i = 1; i <= stepDist; i++) {
        dfs(pos + i, boot, n, b);
    }

    for (int i = boot + 1; i < b; i++) {
        dfs(pos, i, n, b);
    }

    return 0;

}

int main() {
    setIO("snowboots");
    int n, b; cin >> n >> b;

    for (int i = 0; i < n; i++) {
        cin >> snow[i];
    }
    for (int i = 0; i < b; i++) {
        int a,b; cin >> a >> b;
        boots.pb({a,b});
    }


    dfs(0,0,n,b);

    cout << bestNum << endl;


}