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

int time(int array [], int k, int n) {
    int currIndex = k - 1;
    int queue [k];
    int t = 0;
    for (int i = 0; i < k; i++) {
        queue[i] = array[i];
    }
    while (currIndex < n-1) {
        sort(queue, queue + k);
        int sub = queue[0];
        t += sub;
        for (int i = 0; i < k; i++) {
            queue[i] -= sub;
        }
        queue[0] = array[currIndex + 1];
        currIndex++;
    }

    sort (queue, queue + k);
    t += queue[k-1];
    return t;
}

int main() {
    setIO("cowdance");

    int n, t; cin >> n >> t;

    int cows [n];

    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }

    int low = 1;
    int high = n;

    while (low < high) {
        int mid = (low + high - 1)/2;

        int time1 = time(cows, mid, n);

        if (time1 > t) {
            low = mid + 1;
        }

        if (time1 <= t) {
            high = mid;
        }
    }

    cout << low << endl;

}