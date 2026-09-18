#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> st;
    stack<int> gt;
    stack<int> rt;

    int n;

    cout << "enter stack capacity :";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int temp;
        cout << "enter " << i << " element of stack :";
        cin >> temp;

        st.push(temp);
    };

    cout << "\n========== STARTING REVERSE PROCESS ==========";
    cout << "\n";

    while (st.size() > 0)
    {

        gt.push(st.top());
        st.pop();
    }

    while (gt.size() > 0)
    {

        rt.push(gt.top());
        gt.pop();
    }

      while (rt.size() > 0)
    {

        st.push(rt.top());
        rt.pop();
    }

    // print

    cout << "\n========== REVERSED STACK ==========";
    cout << endl;
    cout << "here's your reversed stack:";
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        int temp;

        cout << st.top();

        cout << endl;

        st.pop();
    };

    return 0;
}
