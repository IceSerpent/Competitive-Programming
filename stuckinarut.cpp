#include <bits/stdc++.h>
#include <array>
using namespace std;
using ll = long long;
#define pb push_back
#define f first
#define s second

bool cmpNorth (pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    return a.s.f < b.s.f;
}

bool cmpEast (pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    return a.s.s < b.s.s;
}


int main() {

    int n; cin >> n;
    vector<pair<int, pair<int,int>>> east;
    vector<pair<int, pair<int,int>>> north; 
    int blame [n];
    bool stopped [n];
    for (int i = 0; i < n; i++) {
        char a;
        int b,c;
        blame[i] = 0;
        stopped[i] = false;
        cin >> a >> b >> c;
        if (a == 'N') {
            north.pb({i, {b,c}});
        } else {
            east.pb({i, {b, c}});
        }
    }

    sort(begin(north), end(north), cmpNorth);
    sort(begin(east), end(east), cmpEast);

    for (int i = 0; i < east.size(); i++) {
        for (int j = 0; j < north.size(); j++) {
            pair<int, int> intersection;
            intersection.f = north[j].s.f;
            intersection.s = east[i].s.s;
            if (!(north[j].s.s > intersection.s) && !(east[i].s.f > intersection.f) && !stopped[east[i].f] && !stopped[north[j].f]) {
                int eastTime = intersection.f - east[i].s.f;
                int northTime = intersection.s - north[j].s.s;
                if (eastTime < northTime) {
                    blame[east[i].f] += blame[north[j].f] + 1;
                    stopped[north[j].f] = true;
                }
                if (northTime < eastTime) {
                    blame[north[j].f] += blame[east[i].f] + 1;
                    stopped[east[i].f] = true;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << blame[i] << endl;
    }
    return 0;
}