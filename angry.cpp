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


bool radius(int array [], int k, int r, int n) {
    int counter = 0;
    bool active = false;
    int upperbound = 0;
    int lawl = k;
    while (lawl > 0 || (lawl == 0 && active)) {
        if (counter > n-1) {
            break;
        }
        if (!active) {
            upperbound = array[counter] + 2*r;
            lawl--;
            active = true;
        }
        if (array[counter] <= upperbound) {
            counter++;
        } else {
            active = false;
        }
    }

    if (counter > n-1) {
        return true;
    } else {
        return false;
    }
}

int main() {
    setIO("angry");

    int n, k; cin >> n >> k;
    int bales [n];

    for (int i = 0; i < n; i++) {
        cin >> bales[i];
    }

    sort(bales, bales + n);

    int low = 1;
    int high = 1e9 + 16;

    
    while (low < high) {
        int mid = (low + high)/2;

        if (radius(bales, k, mid, n)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << low << endl;

}