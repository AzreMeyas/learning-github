#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> suits(n);
    for (int i = 0; i < n; ++i) {
        cin >> suits[i];
    }

    int cost = 0;
    for (int i = 0; i < n / 2; ++i) {
        int left = suits[i];
        int right = suits[n - i - 1];

        if (left == 2 && right == 2) {
            cost += 2 * min(a, b);
        } else if (left == 2) {
            cost += (right == 0) ? a : b;
        } else if (right == 2) {
            cost += (left == 0) ? a : b;
        } else if (left != right) {
            cout << -1 << endl;
            return 0;
        }
    }

    if (n % 2 == 1 && suits[n / 2] == 2) {
        cost += min(a, b);
    }

    cout << cost << endl;
    return 0;
}

