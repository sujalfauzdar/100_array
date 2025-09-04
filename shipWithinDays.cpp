#include <bits/stdc++.h>
using namespace std;

bool canShipWithinDays(vector<int> &weights, int days, int limit) {
    int currWeight = 0;
    int totalDays = 1;

    for (int i : weights) {
        if (i + currWeight <= limit)
            currWeight += i;
        else {
            currWeight = i;
            totalDays++;
        }
    }
    return totalDays <= days;
}

int shipWithinDays(vector<int>& weights, int days) {
    int left = *max_element(weights.begin(), weights.end());
    int right = accumulate(weights.begin(), weights.end(), 0);
    int minWeight = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canShipWithinDays(weights, days, mid)) {
            minWeight = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return minWeight;
}

int main() {
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;

    cout << "Minimum ship capacity: " << shipWithinDays(weights, days) << endl;
    return 0;
}
