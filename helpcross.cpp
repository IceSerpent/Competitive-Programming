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

bool cmp2 (pair <int, int> a, pair <int, int> b) {
    if (a.s == b.s) {
        return a.f < b.f;
    } else {
        return a.s < b.s;
    }
}

int main() {
    setIO("helpcross");

    int c, n; cin >> c >> n;
    int chicken [c];
    vector <pair<int, int>> cow;
    for (int i = 0; i < c; i++) {
        cin >> chicken[i];
    }

    for (int i = 0; i < n; i++) {
        int a,b; cin >> a >> b;
        cow.pb({a,b});
    }

    sort (chicken, chicken + c);
    sort (begin(cow), end(cow), cmp2);

    int ans = 0;
    bool taken[c];

    for (int i = 0; i < c; i++) {
        taken[i] = false;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < c; j++) {
            if (chicken[j] >= cow[i].f && chicken[j] <= cow[i].s && !taken[j]) {
                taken[j] = true;
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;

}