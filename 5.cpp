#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a structure to represent an activity
struct Activity {
    char name;
    int start;
    int end;
};

vector<string> selectActivities(int n, int x, vector<Activity>& activities) {

    sort(activities.begin(), activities.end(), [](const Activity& a, const Activity& b) {
        return a.end < b.end;
    });

    vector<string> selectedActivities;
    int lastEndTime = -1 * 1e9;


    for (const auto& activity : activities) {
        if (activity.start >= lastEndTime + x) {
            selectedActivities.push_back(string(1, activity.name));
            lastEndTime = activity.end;
        }
    }

    return selectedActivities;
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<Activity> activities(n);

    for (int i = 0; i < n; ++i) {
        cin >> activities[i].name >> activities[i].start >> activities[i].end;
    }

    vector<string> selectedActivities = selectActivities(n, x, activities);


    for (const auto& activity : selectedActivities) {
        cout << activity << endl;
    }
    cout << selectedActivities.size() << endl;

    return 0;
}
