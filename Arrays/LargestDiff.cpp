#include <iostream>
#include <climits>
using namespace std;

int main() {
    int arr[] = {2, 1, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int mn = INT_MAX;
    int mx = INT_MIN;

    for (int i = 0; i < n; i++) {
        mn = min(mn, arr[i]);
        mx = max(mx, arr[i]);
    }

    cout << mx - mn;

    return 0;
}
