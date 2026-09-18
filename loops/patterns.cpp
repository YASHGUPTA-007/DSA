#include <iostream>
using namespace std;

// Pattern 1: 5x5 rectangle of stars
void pattern1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << "*";
        cout << endl;
    }
}

// Pattern 2: Right-angled triangle (increasing stars)
void pattern2(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
            cout << "*";
        cout << endl;
    }
}

// Pattern 3: Number triangle (1, 12, 123, ...)
void pattern3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << j;
        cout << endl;
    }
}

// Pattern 4: Same digit repeated per row (1, 22, 333, ...)
void pattern4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
            cout << i;
        cout << endl;
    }
}

// Pattern 5: Inverted triangle (decreasing stars)
void pattern5(int n)
{
    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
            cout << "*";
        cout << endl;
    }
}

// Pattern 6: Inverted number triangle (12345, 1234, 123, 12, 1)
void pattern6(int n)
{
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
            cout << j;
        cout << endl;
    }
}

void pattern7(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
            cout << " ";

        for (int j = 0; j < 2 * i - 1; j++)
            cout << "*";

        cout << endl;
    }
}
int main()

{
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "\nPattern 7" << endl;
    pattern7(n);

    return 0;
}
