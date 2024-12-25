#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> groups(n);
    for (int i = 0; i < n; ++i) {
        cin >> groups[i];
    }

    vector<int> count(5, 0);
    for (int group : groups) {
        count[group]++;
    }

    int rickshaws = count[4];
    int pairThreeOne = min(count[3], count[1]);
    rickshaws += pairThreeOne;
    count[3] -= pairThreeOne;
    count[1] -= pairThreeOne;
    rickshaws += count[3];
    rickshaws += count[2] / 2;
    if (count[2] % 2 != 0) {
        rickshaws++;
        count[1] -= min(2, count[1]);
    }
    if (count[1] > 0) {
        rickshaws += (count[1] + 3) / 4;
    }

    cout << rickshaws << endl;
    return 0;
}
