#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int matrix[5][5];
    vector<int> ans;

    // Input dimensions
    int m = 5, n = 5;

    // Input matrix elements
    cout << "Enter 5x5 matrix elements:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int minr = 0;         // top boundary
    int maxr = m - 1;     // bottom boundary
    int minc = 0;         // left boundary
    int maxc = n - 1;     // right boundary

    while (minr <= maxr && minc <= maxc)
    {
        // Right
        for (int j = minc; j <= maxc; j++)
        {
            ans.push_back(matrix[minr][j]);
        }
        minr++;

        // Down
        for (int i = minr; i <= maxr; i++)
        {
            ans.push_back(matrix[i][maxc]);
        }
        maxc--;

        // Left
        if (minr <= maxr)
        {
            for (int j = maxc; j >= minc; j--)
            {
                ans.push_back(matrix[maxr][j]);
            }
            maxr--;
        }

        // Up
        if (minc <= maxc)
        {
            for (int i = maxr; i >= minr; i--)
            {
                ans.push_back(matrix[i][minc]);
            }
            minc++;
        }
    }

    // Output the spiral order
    cout << "\nSpiral Order: ";
    for (int num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
