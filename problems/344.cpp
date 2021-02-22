#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        if (len <= 1) return;
        for (int i = 0; i < len / 2; i++) {
            char c = s[i];
            s[i] = s[len - 1 - i];
            s[len - 1 - i] = c;
        }
    }
};

vector<char> readChars() {
    vector<char> s;
    string input;
    getline(cin, input);
    istringstream in(input);
    char c;
    while (in >> c) {
        s.push_back(c);
    }
    in.clear();
    return s;
}

int main() {
    vector<char> s;
    Solution mySolution;
    while (true) {
        s = readChars();
        mySolution.reverseString(s);
        for (auto c : s) cout << c << " ";
        cout << endl;
    }
}