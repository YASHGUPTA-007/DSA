/*
================================================================================
                     RECURSION IN C++ — COMPLETE NOTES
================================================================================

TABLE OF CONTENTS
  1.  What is Recursion?
  2.  How the Call Stack Works
  3.  Anatomy of a Recursive Function
  4.  Types of Recursion
  5.  Tail Recursion & Optimization
  6.  Head Recursion vs Tail Recursion
  7.  Common Patterns
  8.  Tree Recursion
  9.  Backtracking via Recursion
  10. Memoization (Top-Down DP)
  11. Classic Problems — with full solutions
  12. Complexity Analysis
  13. Common Mistakes & Traps

================================================================================
  1. WHAT IS RECURSION?
================================================================================

  A function that calls itself to solve a smaller version of the same problem.
  Every recursive solution needs:
    a) Base Case  — the stopping condition (no more calls)
    b) Recursive Case — the function calls itself with a smaller/simpler input

  Rule of thumb: "Trust the recursion. Assume it works for n-1, solve for n."

================================================================================
  2. HOW THE CALL STACK WORKS
================================================================================

  Each function call pushes a new "frame" onto the call stack.
  When a base case is hit, frames start popping (unwinding) in reverse order.

  Example: factorial(3)
    factorial(3)
      └── factorial(2)
            └── factorial(1)
                  └── factorial(0) → returns 1   [BASE CASE — stack unwinds]
                returns 1*1 = 1
          returns 2*1 = 2
    returns 3*2 = 6

  IMPORTANT: Each call has its OWN local variables on its own stack frame.

  Stack overflow occurs when recursion is too deep (default ~1MB stack in C++).
  Depth limit is roughly ~10,000–100,000 calls depending on frame size.

================================================================================
  3. ANATOMY OF A RECURSIVE FUNCTION
================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

// ----- TEMPLATE -----
// returnType solve(params) {
//     if (base_case) return base_value;   // STOP
//     // optional: process current step
//     return solve(smaller_problem);       // RECURSE
// }

// ----- EXAMPLE: Factorial -----
int factorial(int n) {
    if (n == 0) return 1;          // base case
    return n * factorial(n - 1);  // recursive case
}

// ----- EXAMPLE: Sum 1 to N -----
int sumN(int n) {
    if (n == 0) return 0;
    return n + sumN(n - 1);
}

/*
================================================================================
  4. TYPES OF RECURSION
================================================================================

  a) DIRECT RECURSION   — function calls itself directly
  b) INDIRECT RECURSION — A() calls B(), B() calls A()
  c) TAIL RECURSION     — recursive call is the LAST operation
  d) HEAD RECURSION     — recursive call is the FIRST operation
  e) TREE RECURSION     — function makes MORE than one recursive call
  f) NESTED RECURSION   — argument of recursive call is itself recursive
                          e.g., f(f(n-1))

================================================================================
  5. TAIL RECURSION & OPTIMIZATION
================================================================================

  Tail call: the return value is directly the result of the recursive call.
  No computation happens AFTER the call.

  The compiler (with -O2) can optimize tail calls into a loop (no stack growth).
  This is called TCO (Tail Call Optimization).
*/

// NOT tail-recursive (multiply happens after the call)
int fact_normal(int n) {
    if (n == 0) return 1;
    return n * fact_normal(n - 1);  // <-- multiply AFTER return
}

// Tail-recursive version using accumulator
int fact_tail(int n, int acc = 1) {
    if (n == 0) return acc;
    return fact_tail(n - 1, n * acc);  // <-- nothing left to do after call
}

/*
================================================================================
  6. HEAD vs TAIL — VISUAL DIFFERENCE
================================================================================

  HEAD RECURSION: recurse first, process on the way BACK UP
  TAIL RECURSION: process first, recurse last

  Example: Print 1 to N
*/

void printHead(int n) {   // prints N down to 1 (processes on unwind)
    if (n == 0) return;
    printHead(n - 1);     // recurse FIRST
    cout << n << " ";     // then print (on the way back up)
}

void printTail(int n) {   // prints N down to 1 (processes before recurse)
    if (n == 0) return;
    cout << n << " ";     // print FIRST
    printTail(n - 1);     // recurse after
}

/*
  Output of printHead(3): 1 2 3   (small to large — unwinds forward)
  Output of printTail(3): 3 2 1   (large to small — direct order)

================================================================================
  7. COMMON PATTERNS
================================================================================

  PATTERN 1 — Process on the WAY DOWN (before recursive call)
  PATTERN 2 — Process on the WAY UP   (after recursive call)
  PATTERN 3 — Use return value of subproblem to build current answer
  PATTERN 4 — Pass extra state via parameters (accumulator, index)

================================================================================
  8. TREE RECURSION
================================================================================

  When a function makes 2 or more recursive calls — forms a binary tree of calls.
  Time complexity: O(2^n) in the worst case without memoization.
*/

// Fibonacci — classic tree recursion
int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);  // TWO recursive calls
}
// fib(5) call tree has 15 nodes → exponential growth

/*
================================================================================
  9. BACKTRACKING VIA RECURSION
================================================================================

  Make a choice → recurse → UNDO the choice (backtrack)
  Used when you explore all possibilities (subsets, permutations, maze, etc.)

  Template:
    void solve(state, choices) {
        if (done) { record answer; return; }
        for each choice:
            make choice
            solve(next state)
            undo choice          // BACKTRACK
    }
*/

// ----- Subsets of an array -----
void subsets(vector<int>& arr, int idx, vector<int>& current, vector<vector<int>>& result) {
    if (idx == (int)arr.size()) {
        result.push_back(current);
        return;
    }
    // INCLUDE arr[idx]
    current.push_back(arr[idx]);
    subsets(arr, idx + 1, current, result);
    current.pop_back();           // UNDO

    // EXCLUDE arr[idx]
    subsets(arr, idx + 1, current, result);
}

// ----- Permutations of a string -----
void permutations(string& s, int start, vector<string>& result) {
    if (start == (int)s.size()) {
        result.push_back(s);
        return;
    }
    for (int i = start; i < (int)s.size(); i++) {
        swap(s[start], s[i]);                     // make choice
        permutations(s, start + 1, result);
        swap(s[start], s[i]);                     // UNDO
    }
}

/*
================================================================================
  10. MEMOIZATION (TOP-DOWN DYNAMIC PROGRAMMING)
================================================================================

  Problem: tree recursion recomputes the same subproblems.
  Fix: store results in a cache (map or array). Return cached result if seen.

  Steps:
    1. Write the naive recursive solution.
    2. Add a memo table.
    3. Before computing, check if result is already in memo.
    4. After computing, store result in memo.
*/

// Fibonacci with memoization — O(n) time, O(n) space
unordered_map<int, long long> memo;
long long fib_memo(int n) {
    if (n <= 1) return n;
    if (memo.count(n)) return memo[n];           // cache hit
    return memo[n] = fib_memo(n-1) + fib_memo(n-2); // store & return
}

// Array-based memo (faster)
long long fib_arr(int n, vector<long long>& dp) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fib_arr(n-1, dp) + fib_arr(n-2, dp);
}

/*
================================================================================
  11. CLASSIC PROBLEMS — FULL SOLUTIONS
================================================================================
*/

// ---- 1. Power (x^n) ----
// Naive: O(n) | Fast: O(log n) using divide & conquer
double power(double x, int n) {
    if (n == 0) return 1;
    if (n < 0) return 1.0 / power(x, -n);
    if (n % 2 == 0) {
        double half = power(x, n / 2);
        return half * half;                 // reuse result — O(log n)
    }
    return x * power(x, n - 1);
}

// ---- 2. Binary Search (recursive) ----
int binarySearch(vector<int>& arr, int low, int high, int target) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) return mid;
    if (arr[mid] < target) return binarySearch(arr, mid + 1, high, target);
    return binarySearch(arr, low, mid - 1, target);
}

// ---- 3. Merge Sort ----
void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < (int)left.size() && j < (int)right.size())
        arr[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
    while (i < (int)left.size())  arr[k++] = left[i++];
    while (j < (int)right.size()) arr[k++] = right[j++];
}
void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

// ---- 4. Tower of Hanoi ----
// Move n disks from src to dest using aux
void hanoi(int n, char src, char dest, char aux) {
    if (n == 0) return;
    hanoi(n - 1, src, aux, dest);           // move top n-1 to aux
    cout << "Move disk " << n << " from " << src << " to " << dest << "\n";
    hanoi(n - 1, aux, dest, src);           // move n-1 from aux to dest
}
// Requires 2^n - 1 moves

// ---- 5. Check if array is sorted ----
bool isSorted(vector<int>& arr, int idx) {
    if (idx == (int)arr.size() - 1) return true;      // base case
    if (arr[idx] > arr[idx + 1]) return false;
    return isSorted(arr, idx + 1);
}

// ---- 6. Reverse a string ----
void reverseStr(string& s, int l, int r) {
    if (l >= r) return;
    swap(s[l], s[r]);
    reverseStr(s, l + 1, r - 1);
}

// ---- 7. Count occurrences of x in array ----
int countOcc(vector<int>& arr, int idx, int x) {
    if (idx == (int)arr.size()) return 0;
    return (arr[idx] == x ? 1 : 0) + countOcc(arr, idx + 1, x);
}

// ---- 8. Flood Fill (2D grid) ----
void floodFill(vector<vector<int>>& img, int r, int c, int newColor, int oldColor) {
    if (r < 0 || r >= (int)img.size()) return;
    if (c < 0 || c >= (int)img[0].size()) return;
    if (img[r][c] != oldColor) return;
    img[r][c] = newColor;
    floodFill(img, r+1, c, newColor, oldColor);
    floodFill(img, r-1, c, newColor, oldColor);
    floodFill(img, r, c+1, newColor, oldColor);
    floodFill(img, r, c-1, newColor, oldColor);
}

// ---- 9. N-Queens (classic backtracking) ----
bool isSafe(vector<string>& board, int row, int col, int n) {
    // check column above
    for (int i = row - 1; i >= 0; i--)
        if (board[i][col] == 'Q') return false;
    // check upper-left diagonal
    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q') return false;
    // check upper-right diagonal
    for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q') return false;
    return true;
}
void solveNQueens(vector<string>& board, int row, int n, vector<vector<string>>& res) {
    if (row == n) { res.push_back(board); return; }
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solveNQueens(board, row + 1, n, res);
            board[row][col] = '.';         // backtrack
        }
    }
}

// ---- 10. Rat in a Maze ----
void ratMaze(vector<vector<int>>& maze, int r, int c, int n,
             vector<vector<bool>>& visited, string path, vector<string>& res) {
    if (r == n-1 && c == n-1) { res.push_back(path); return; }
    // directions: Down, Left, Right, Up
    int dr[] = {1, 0, 0, -1};
    int dc[] = {0, -1, 1, 0};
    char dir[] = {'D', 'L', 'R', 'U'};
    for (int d = 0; d < 4; d++) {
        int nr = r + dr[d], nc = c + dc[d];
        if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
            maze[nr][nc] == 1 && !visited[nr][nc]) {
            visited[r][c] = true;
            ratMaze(maze, nr, nc, n, visited, path + dir[d], res);
            visited[r][c] = false;         // backtrack
        }
    }
}

/*
================================================================================
  12. COMPLEXITY ANALYSIS
================================================================================

  For a recursion with:
    T(n) = a * T(n/b) + f(n)
  Use the MASTER THEOREM to find Big-O.

  Common cases:
  ┌───────────────────────────────────────────────────────────────────────┐
  │ Problem             │ Recurrence          │ Time       │ Space        │
  ├───────────────────────────────────────────────────────────────────────┤
  │ Factorial           │ T(n) = T(n-1) + O(1)│ O(n)       │ O(n) stack  │
  │ Fibonacci (naive)   │ T(n) = 2T(n-1)      │ O(2^n)     │ O(n) stack  │
  │ Fibonacci (memo)    │ each state once      │ O(n)       │ O(n)        │
  │ Binary Search       │ T(n) = T(n/2) + O(1)│ O(log n)   │ O(log n)    │
  │ Merge Sort          │ T(n) = 2T(n/2)+O(n) │ O(n log n) │ O(n)        │
  │ Tower of Hanoi      │ T(n) = 2T(n-1) + O(1)│ O(2^n)   │ O(n) stack  │
  │ Subsets             │ 2 choices per elem   │ O(2^n)     │ O(n)        │
  │ Permutations        │ n! leaves            │ O(n * n!)  │ O(n)        │
  └───────────────────────────────────────────────────────────────────────┘

  Space complexity of recursion = O(max depth of call stack)

================================================================================
  13. COMMON MISTAKES & TRAPS
================================================================================

  1. MISSING BASE CASE → infinite recursion → stack overflow
     Fix: always write the base case FIRST.

  2. WRONG BASE CASE → wrong answer or off-by-one errors
     Fix: trace manually with small inputs (n=0, n=1).

  3. NOT SHRINKING THE PROBLEM → infinite recursion
     Fix: make sure each call moves toward the base case.

  4. MODIFYING GLOBAL STATE without undoing it in backtracking
     Fix: always undo changes after the recursive call.

  5. INT OVERFLOW in accumulators for large n
     Fix: use long long.

  6. RECOMPUTING SUBPROBLEMS (exponential time)
     Fix: add memoization.

  7. ASSUMING RECURSION IS ALWAYS SLOW — with memoization it can be O(n).

  8. FORGETTING that pass-by-VALUE creates a copy per call (expensive)
     Fix: use pass-by-reference (&) for large containers.

================================================================================
  QUICK CHEAT SHEET
================================================================================

  Writing a recursive function:
    Step 1: Identify the base case (smallest valid input).
    Step 2: Assume recursion works for smaller input (inductive hypothesis).
    Step 3: Use that smaller result to solve the current problem.
    Step 4: Add memoization if subproblems overlap.
    Step 5: Add undo step if doing backtracking.

  Debugging tips:
    - Add print statements showing n and the return value.
    - Draw the call tree for small n (n=3 or n=4).
    - Count the number of calls — if it's exponential, add memoization.

================================================================================
*/

int main() {
    // ---- Demo runs ----
    cout << "Factorial(5) = " << factorial(5) << "\n";
    cout << "SumN(10) = " << sumN(10) << "\n";
    cout << "Power(2,10) = " << power(2, 10) << "\n";

    // Fibonacci with memo
    int n = 10;
    vector<long long> dp(n + 1, -1);
    cout << "Fib(10) = " << fib_arr(10, dp) << "\n";

    // Subsets
    vector<int> arr = {1, 2, 3};
    vector<int> cur;
    vector<vector<int>> res;
    subsets(arr, 0, cur, res);
    cout << "Subsets of {1,2,3}: " << res.size() << " total\n";

    // Permutations
    string s = "ABC";
    vector<string> perms;
    permutations(s, 0, perms);
    cout << "Permutations of ABC: " << perms.size() << "\n";

    // Hanoi
    cout << "\nHanoi(3 disks):\n";
    hanoi(3, 'A', 'C', 'B');

    return 0;
}
