#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> prefixFunction(string s) {
        int n = s.length();
        vector<int> pi(n, 0);
        for (int i = 1; i < n; i++) {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j]) j = pi[j - 1];
            if (s[i] == s[j]) j++;
            pi[i] = j;
        }
        return pi;
    }
    int strStr2(string haystack, string needle) {
        int m = haystack.length(), n = needle.length();
        if (n == 0) return 0;
        vector<int> next = prefixFunction(needle);
        int j = next[0];
        for (int i = 0; i < m; i++) {
            while (j > 0 && haystack[i] != needle[j]) j = next[j - 1];
            if (haystack[i] == needle[j]) j++;
            if (j == n) return (i - n + 1);
        }
    }

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