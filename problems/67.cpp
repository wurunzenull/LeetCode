#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string addBinary(string a, string b) {
        int m = a.length(), n = b.length();
        int i = m - 1, j = n - 1;
        string res = "";
        char flag = 0;
        for (; i >= 0 && j >= 0; i--, j--) {
            char add = flag + a[i] + b[j] - 2 * '0';
            flag = add / 2;
            res.insert(res.begin(), '0' + add % 2);
        }
        for (; i >= 0; i--) {
            char add = flag + a[i] - '0';
            flag = add / 2;
            res.insert(res.begin(), '0' + add % 2);
        }
        for (; j >= 0; j--) {
            char add = flag + b[j] - '0';
            flag = add / 2;
            res.insert(res.begin(), '0' + add % 2);
        }
        if (flag) res.insert(res.begin(), '0' + flag);
        return res;
    }
};

int main() {
    string a, b;
    Solution mySolution;
    while (cin >> a >> b) {
        cout << mySolution.addBinary(a, b) << endl;
    }
    return 0;
}