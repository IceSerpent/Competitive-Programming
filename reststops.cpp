#include <bits/stdc++.h>
#include <array>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
 
void setIO(string name){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

bool cmp(pair<ll, ll> a, pair<ll,ll> b) {
    return a.f > b.f;
}

bool cmp2(pair<ll, ll> a, pair<ll,ll> b) {
    return a.s < b.s;
}

int main() {
    setIO("teleport");
 
    int n; cin >> n;
    vector<pair<ll, ll>> points;
    ll totalsum = 0;
    for (int i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        if (a > b) {
            ll temp = b;
            b = a;
            a = temp;
        }
        totalsum += b - a;
        points.pb({a,b});
    }


    sort(begin(points), end(points), cmp);

    vector<pair<ll, ll>> candidates;

    for (int i = 0; i < points.size(); i++) {
        if (points[i].f > 0 || points[i].s < 0) {

        } else {
            candidates.pb(points[i]);
        }
    }
    ll candidatesum1 = totalsum;
    ll prev = 0;

    for (int i = 0; i < candidates.size(); i++) {
        ll above = ((ll) candidates.size()) - ((ll) i);
        ll change = (above * (abs(candidates[i].f) - abs(prev)) - abs(prev));
        if (change < 0) {
            break;
        } else {
            candidatesum1 -= change;
        }
        prev = candidates[i].f;
    }

    sort(begin(points), end(points), cmp2);
    vector<pair<ll, ll>> candidates2;
    for (int i = 0; i < points.size(); i++) {
        if (points[i].s < 0 || points[i].f > 0) {

        } else {
            candidates2.pb(points[i]);
        }
    }

    ll candidatesum2 = totalsum;
    ll prev2 = 0;
    for (int i = 0; i < candidates2.size(); i++) {
        ll above = ((ll) candidates2.size()) - ((ll) i);
        ll change = (above * (candidates2[i].s - prev2) - prev2);

        if (change < 0) {
            break;
        } else {
            candidatesum2 -= change;
        }
        prev2 = candidates2[i].s;
    }

    ll answer = candidatesum1;
    if (candidatesum2 < candidatesum1) {
        answer = candidatesum2;
    }

    cout << answer << endl;

}