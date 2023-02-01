/*

Divide and Print
Alex has an array 'ARR' of 'N' elements. He has been assigned to find if the array 'ARR' is a "flexible" array or not.
A "flexible" array is an array that can be divided into 3 possible subarrays :
1. A strictly increasing subarray (possibly empty).
2. A constant array (i.e all the elements are equal).
3. A strictly decreasing subarray (possibly empty).
More formally there exist indices 'i' and 'j' such that 'i' <= 'j' and i >=0 and j <= n - 1 such that the subarray [0, i] is strictly increasing, subarray [i, j] is a constant array and subarray [j, n - 1] is strictly decreasing.
As Alex is weak in calculating, he assigned this task to you, and you need to print if the array 'ARR' is "flexible" or not.
EXAMPLE:
[1, 3, 4, 4, 1] is a “flexible” array while [1, 3, 4, 2, 2] is not a “flexible” array.
Input Format :
The first line of input contains an integer ‘T’, denoting the number of test cases. 

The first line of each test case contains one integer, ‘N’, denoting the length of the array ‘ARR’.

The second line contains ‘N’ space-separated integers denoting the elements of array ‘ARR’.
Output format :
For each test case, print the string “YES” if the array ‘ARR’ is a “flexible” array else print “NO”.

Print the output of each test case in a new line.
Note :
You don’t need to print anything. It has already been taken care of. Just implement the given function.
Constraints :
1 <= ‘T’ <= 5
2 <= ‘N’ <= 10^5
1 <= ‘ARR[i]’ <= 10^9
Time Limit : 1 sec
Sample Input 1 :
2
3 
3 3 2
5 
2 3 3 1 1 
Sample Output 1 :
YES
NO
Explanation Of Sample Input 1 :
In the first test case, condition 1 is absent and the array ‘ARR’ remains constant till index 2 and then starts strictly decreasing. Hence, the array ‘ARR’ is “flexible”.

In the second test case, ‘ARR’ is strictly increasing till index 2 and then remains constant till index 3 and is strictly decreasing till index 4 but then becomes constant. Hence, the array ‘ARR’ is not “flexible”.
Sample Input 2 :
2
7 
10 34 12 14 54 12 15
4
1 1 1 1
Sample Output 2 :
NO
YES

*/
#include <bits/stdc++.h> 
using namespace std;
string isFlexible(int n, vector<int> a){
    if(n==1)return "NO";
    int i=1;
    int c=0;
    int inc=0,same=0,dec=0;
    while(i<n&&a[i]>a[i-1]){
        i++;
        inc++;
    }
    while (i < n && a[i] == a[i - 1]) {
      i++;
      same++;
    }

    while (i < n && a[i] < a[i - 1]) {
      i++;
      dec++;
    }
    if( i<n || !same)return "NO";
    return "YES";
}