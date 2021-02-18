#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    //存在整数溢出
    long long factorial(int n) {
        long long res = 1;
        for (int i = 2; i <= n; i++) res *= i;
        return res;
    }
    int combination(int m, int n) { return factorial(m) / (factorial(n) * factorial(m - n)); }
    int uniquePaths(int m, int n) {
        long long res = 1;
        // if (m > n) return combination(m + n - 2, n - 1);
        // return combination(m + n - 2, m - 1);
        for (int x = n, y = 1; y < m; x++, y++) {
            res = res * x / y;
        }
        return res;
    }
};
int main() {
    int m, n;
    cin >> m >> n;
    Solution mySolution;
    cout << mySolution.uniquePaths(m, n) << endl;
    return 0;
}