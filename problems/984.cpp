#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string strWithout3a3b(int a, int b) {
        string res;
        while (a > 0 || b > 0) {
            bool writeA = false;
            int len = res.length();
            if (len >= 2 && res[len - 1] == res[len - 2]) {
                if (res[len - 1] == 'b') writeA = true;
            } else if (a >= b)
                writeA = true;
            if (writeA) {
                a--;
                res.push_back('a');
            } else {
                b--;
                res.push_back('b');
            }
        }
        return res;
    }
};

int main() {
    int a, b;
    Solution mySolution;
    while (cin >> a >> b) {
        cout << mySolution.strWithout3a3b(a, b) << endl;
    }
    return 0;
}