// A C program to implement Manacher’s Algorithm
#include <bits/stdc++.h>

using namespace std;

string s;

int min(int a, int b)
{
    int res = a;
    if (b < a)
        res = b;
    return res;
}

void findLongestPalindromicString()
{
    int n = s.length();
    if (n == 0)
        return;
    n = 2 * n + 1; //Position count
    int L[n];      //LPS Length Array
    L[0] = 0;
    L[1] = 1;
    int C = 1;   //centerPosition
    int R = 2;   //centerRightPosition
    int i = 0;   //currentRightPosition
    int iMirror; //currentLeftPosition
    int maxLPSLength = 0;
    int maxLPSCenterPosition = 0;
    int start = -1;
    int end = -1;
    int diff = -1;

    for (i = 2; i < n; i++)
    {
        //get currentLeftPosition iMirror for currentRightPosition i
        iMirror = 2 * C - i;
        L[i] = 0;
        diff = R - i;
        //If currentRightPosition i is within centerRightPosition R
        if (diff > 0)
            L[i] = min(L[iMirror], diff);

        //Attempt to expand palindrome centered at currentRightPosition i
        //Here for odd positions, we compare characters and
        //if match then increment LPS Length by ONE
        //If even position, we just increment LPS by ONE without
        //any character comparison
        while (((i + L[i]) < n && (i - L[i]) > 0) &&
               (((i + L[i] + 1) % 2 == 0) ||
                (s[(i + L[i] + 1) / 2] == s[(i - L[i] - 1) / 2])))
        {
            L[i]++;
        }

        if (L[i] > maxLPSLength) // Track maxLPSLength
        {
            maxLPSLength = L[i];
            maxLPSCenterPosition = i;
        }

        //If palindrome centered at currentRightPosition i
        //expand beyond centerRightPosition R,
        //adjust centerPosition C based on expanded palindrome.
        if (i + L[i] > R)
        {
            C = i;
            R = i + L[i];
        }
    }
    start = (maxLPSCenterPosition - maxLPSLength) / 2;
    end = start + maxLPSLength - 1;
    cout << s.substr(start, end - start + 1) << endl;
}

int main(int argc, char *argv[])
{
    cin >> s;
    findLongestPalindromicString();

    return 0;
}
