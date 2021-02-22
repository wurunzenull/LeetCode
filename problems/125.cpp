#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool legalChar(char c) { return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'); }
    bool equalChar(char a, char b) {
        if (a >= 'A' && a <= 'Z') a = a + 'a' - 'A';
        if (b >= 'A' && b <= 'Z') b = b + 'a' - 'A';
        return a == b;
    }
    bool isPalindrome(string s) {
        if (s.length() == 0) return true;
        int i = 0, j = s.length() - 1;
        while (i < j) {
            while (i < j && !legalChar(s[i])) i++;
            while (i < j && !legalChar(s[j])) j--;
            if (equalChar(s[i], s[j])) {
                i++, j--;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string s;
    Solution mySolution;
    while (getline(cin, s)) {
        cout << mySolution.isPalindrome(s) << endl;
    }
    return 0;
}