#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> costs(n);
    for (int i = 0; i < n; ++i) {
        cin >> costs[i];
    }

    int m;
    cin >> m;
    vector<int> coupons(m);
    for (int i = 0; i < m; ++i) {
        cin >> coupons[i];
    }

    sort(costs.begin(), costs.end(), greater<int>());

    vector<int> results(m);
    for (int i = 0; i < m; ++i) {
        int q = coupons[i];
        int totalCost = 0;

        for (int j = 0; j < n; ++j) {
            if (j < q - 1 || j >= q) {
                totalCost += costs[j];
            }
        }
        results[i] = totalCost;
    }

    for (int result : results) {
        cout << result << " ";
    }
    cout << endl;

    return 0;
}

