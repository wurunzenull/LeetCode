#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int strStr(string haystack, string needle) {
        int m = haystack.length(), n = needle.length();
        if (n == 0) return 0;
        for (int i = 0; i <= m - n; i++) {
            int j = 0;
            for (; j < n; j++) {
                if (haystack[i + j] == needle[j])
                    continue;
                else
                    break;
            }
            if (j == n) return i;
        }
        return -1;
    }
};

int main() {
    string haystack, needle;
    Solution mySolution;
    while (cin >> haystack >> needle) {
        cout << mySolution.strStr(haystack, needle);
    }
    return 0;
}