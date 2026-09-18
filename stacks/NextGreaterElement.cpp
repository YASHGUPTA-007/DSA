#include <iostream>
#include <stack>
using namespace std;

int main() {
    int arr[] = {3, 1, 2, 7, 4, 6, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int nge[n]; // Array to store Next Greater Elements

    // Using a Stack: Pop -> Ans -> Push
    // Time Complexity: O(n), Space Complexity: O(n)
    stack<int> st;

    // Base condition: The last element has no next element to its right
    nge[n - 1] = -1;
    st.push(arr[n - 1]);

    // Traverse from right to left (second-to-last element down to 0)
    for (int i = n - 2; i >= 0; i--) {
        // 1. POP: remove all elements smaller than or equal to arr[i]
        while (st.size() > 0 && st.top() <= arr[i]) {
            st.pop();
        }

        // 2. ANS: mark the answer in nge array
        if (st.size() == 0) {
            nge[i] = -1;
        } else {
            nge[i] = st.top();
        }

        // 3. PUSH: push current element arr[i] to the stack
        st.push(arr[i]);
    }

    // Print the original array
    cout << "Original Array:       ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Print Next Greater Element array
    cout << "Next Greater Element: ";
    for (int i = 0; i < n; i++) {
        cout << nge[i] << " ";
    }
    cout << endl;

    return 0;
}
