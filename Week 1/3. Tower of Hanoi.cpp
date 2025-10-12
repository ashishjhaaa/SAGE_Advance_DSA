/*
    Problem : Tower of Hanoi

    Statement :
    Given n disks placed on a source rod, the task is to move all disks
    to the destination rod following these rules:
        1. Only one disk can be moved at a time.
        2. A larger disk cannot be placed on top of a smaller disk.
        3. All disks must be moved using the helper rod.

    Example :
    Input  : n = 3
    Output :
             Move disk 1 from A to C
             Move disk 2 from A to B
             Move disk 1 from C to B
             Move disk 3 from A to C
             Move disk 1 from B to A
             Move disk 2 from B to C
             Move disk 1 from A to C
*/

#include <bits/stdc++.h>
using namespace std;

void solve(int n, char source, char helper, char destination)
{
    // Base case: when only one disk is left
    if (n == 1)
    {
        cout << "Move disk " << n << " from " << source << " to " << destination << endl;
        return;
    }

    // Move n-1 disks from source to helper using destination as auxiliary
    solve(n - 1, source, destination, helper);

    // Move the nth (largest) disk directly from source to destination
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;

    // Move the n-1 disks from helper to destination using source as auxiliary
    solve(n - 1, helper, source, destination);
}

int main()
{
    int n;
    cin >> n; // Example input: 3
    solve(n, 'A', 'B', 'C');
    return 0;
}

// TC: O(2^n)
// SC: O(n)
