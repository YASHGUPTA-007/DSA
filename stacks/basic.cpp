#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;
    stack<int> store;

    int n;
    int store;


    cout << "enter stack capacity :";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int temp;
        cout << "enter " << i << " element of stack :";
        cin >> temp;
        
        st.push(temp);
    };

    cout << "here's your stack :";
    cout << endl;



    //printing elements
    for (int i = 1; i <= n; i++)
    {
        int temp;
        
        cout << st.top();
        store.push(st.top());
        cout << endl;


        st.pop();
    };
}