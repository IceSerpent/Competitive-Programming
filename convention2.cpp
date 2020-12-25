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

bool cmp (pair <int, pair<int,int>> a, pair <int, pair<int,int>> b) {
    return a.s.f < b.s.f;
}

int main() {
    setIO("convention2");

    int n; cin >> n;

    vector<pair<int,int>> cows;
    vector<pair<int, pair<int,int>>> cowsort;

    for (int i = 0; i < n; i++) {
        int a,b; cin >> a >> b;
        cows.pb({a,b});
        cowsort.pb({n - i - 1,{a,b}});
    }

    sort(begin(cowsort), end(cowsort), cmp);

    priority_queue<int> pq;

    int maxWait = 0;

    int counter = 0;
    int nextTime = 0;
    int currTime = 0;

    while (counter <= n - 1) {

        while (true) {

            if (counter > n-1) {
                break;
            }

            if (cowsort[counter].s.f >= currTime && cowsort[counter].s.f <= nextTime) {
                pq.push(cowsort[counter].f);
                counter++;
            }

            if (cowsort[counter].s.f < currTime) {
                counter++;
            }

            if (cowsort[counter].s.f > nextTime) {
                
                break;
            }
        }
        bool lawl = false;
        if (pq.empty() && counter <= n-1) {
            pq.push(cowsort[counter].f);
            lawl = true;
        }

        int yumfirst = pq.top();
        int yum = n - yumfirst - 1;
        pq.pop();


        maxWait = max(maxWait, nextTime - cows[yum].f);
        currTime = max(cows[yum].f, nextTime);
        nextTime = currTime + cows[yum].s;

        if (lawl) {
            counter++;
        }

    }

    while (!pq.empty()) {
        int yumfirst = pq.top();
        int yum = n - yumfirst - 1;
        pq.pop();
     

        maxWait = max(maxWait, nextTime - cows[yum].f);
        currTime = max(cows[yum].f, nextTime);
        nextTime = currTime + cows[yum].s;
    }

    cout << maxWait << endl;


}