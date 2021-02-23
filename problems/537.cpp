#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    struct Complex {
        int real;
        int imag;
    };
    Complex getComplex(string a) {
        int real = 0, imag = 0;
        bool realPart = true;
        int positive = 1;
        for (auto c : a) {
            if (realPart) {
                if (c == '-')
                    positive = -1;
                else if (c == '+') {
                    realPart = false;
                    real = positive * real;
                    positive = 1;
                } else
                    real = real * 10 + c - '0';
            } else {
                if (c == '-')
                    positive = -1;
                else if (c == 'i')
                    imag = positive * imag;
                else
                    imag = imag * 10 + c - '0';
            }
        }
        return (Complex){real, imag};
    }
    string toString(Complex complex) {
        string res;
        res.append(to_string(complex.real));
        res.push_back('+');
        res.append(to_string(complex.imag));
        res.push_back('i');
        return res;
    }
    Complex multiply(Complex a, Complex b) {
        int real = a.real * b.real - a.imag * b.imag;
        int imag = a.real * b.imag + a.imag * b.real;
        return (Complex){real, imag};
    }
    string complexNumberMultiply(string a, string b) { return toString(multiply(getComplex(a), getComplex(b))); }
};

int main() {
    string a, b;
    Solution mySolution;
    while (cin >> a >> b) {
        cout << mySolution.complexNumberMultiply(a, b) << endl;
    }
    return 0;
}