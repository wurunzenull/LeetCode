#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void reverse(string &s, int start, int len) {
        for (int i = 0; i < len / 2; i++) {
            char c = s[i + start];
            s[i + start] = s[start + len - 1 - i];
            s[start + len - 1 - i] = c;
        }
    }
    string reverseStr(string s, int k) {
        int len = s.length();
        for (int i = 0; i < len; i += 2 * k) {
            if (i + k > len) {
                reverse(s, i, len - i);
            } else
                reverse(s, i, k);
        }
        return s;
    }
};

int main() {
    string s;
    int k;
    Solution mySolution;
    while (cin >> s >> k) {
        cout << mySolution.reverseStr(s, k) << endl;
    }
    return 0;
}