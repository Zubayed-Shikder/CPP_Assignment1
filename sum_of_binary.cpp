#include <iostream>
#include <string>

using namespace std;

string sumBinary(string x, string y) {
    int i = x.length() - 1, j = y.length() - 1, carry_bit = 0;
    string result = "";

    while (i >= 0 || j>= 0 || carry_bit) {
        int sum = carry_bit;
        if (i >= 0) {
            sum += x[i--] - '0';
        }
        if (j >= 0) {
            sum += y[j--] - '0';
        }
        carry_bit = sum / 2;
        result = to_string(sum % 2) + result;
    }

    return result;
}

int main() {
    string bi_num1, bi_num2;

    cout << "Enter your first binary number: ";
    cin >> bi_num1;

    cout << "Enter your second binary number: ";
    cin >> bi_num2;

    string sum = sumBinary(bi_num1, bi_num2);

    cout << "Value of Summation: " << sum << endl;

    return 0;
}