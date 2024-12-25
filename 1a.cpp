#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long calculateMinimumWork(int n, vector<int>& wineDemands) {
    long long work = 0, balance = 0;
    for (int i = 0; i < n; ++i) {
        balance += wineDemands[i];
        work += abs(balance);
    }
    return work;
}

int main() {
    int n;
    cin >> n;
    vector<int> wineDemands(n);
    for (int i = 0; i < n; ++i) {
        cin >> wineDemands[i];
    }
    cout << calculateMinimumWork(n, wineDemands) << endl;
    return 0;
}
