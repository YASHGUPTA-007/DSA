#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

string RemoveDuplicateConsecutiveChar(string s) {
    stack<char> st;
    
    for (int i = 0; i < s.size(); i++) {
        if (st.empty()) {
            st.push(s[i]);
        }
        else if (st.top() != s[i]) {
            st.push(s[i]);
        }
        else {
            st.pop();
        }
    }

    string res = "";
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string s = "aabbccdd";
    cout << RemoveDuplicateConsecutiveChar(s) << endl;
    return 0;
}
