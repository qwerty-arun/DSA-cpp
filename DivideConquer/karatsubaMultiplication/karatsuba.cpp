#include <iostream>
#include <string>
#include <algorithm>

// Utility function to make lengths equal by padding with zeros
std::string padZeros(const std::string& str, int newLength) {
    std::string padded = str;
    while ((int)padded.length() < newLength) {
        padded = "0" + padded;
    }
    return padded;
}

// Function to add two strings representing numbers
std::string addStrings(const std::string& a, const std::string& b) {
    std::string result = "";
    int carry = 0;
    int n = std::max(a.length(), b.length());
    std::string x = padZeros(a, n);
    std::string y = padZeros(b, n);

    for (int i = n - 1; i >= 0; --i) {
        int sum = (x[i] - '0') + (y[i] - '0') + carry;
        carry = sum / 10;
        result = char(sum % 10 + '0') + result;
    }
    if (carry) result = '1' + result;
    return result;
}

// Function to subtract two strings representing numbers (a > b)
std::string subtractStrings(const std::string& a, const std::string& b) {
    std::string result = "";
    int borrow = 0;
    int n = std::max(a.length(), b.length());
    std::string x = padZeros(a, n);
    std::string y = padZeros(b, n);

    for (int i = n - 1; i >= 0; --i) {
        int diff = (x[i] - '0') - (y[i] - '0') - borrow;
        if (diff < 0) {
            borrow = 1;
            diff += 10;
        } else {
            borrow = 0;
        }
        result = char(diff + '0') + result;
    }

    // Remove leading zeros
    result.erase(0, result.find_first_not_of('0'));
    return result.empty() ? "0" : result;
}

// Multiply single-digit numbers
std::string multiplySingleDigit(char a, char b) {
    int mul = (a - '0') * (b - '0');
    return std::to_string(mul);
}

// Karatsuba algorithm
std::string karatsuba(const std::string& X, const std::string& Y) {
    int n = std::max(X.size(), Y.size());
    
    // Base case: single digit multiplication
    if (n == 1) {
        return multiplySingleDigit(X[0], Y[0]);
    }

    // Pad numbers
    int m = n / 2;
    std::string X1 = padZeros(X, n).substr(0, n - m);
    std::string X0 = padZeros(X, n).substr(n - m);
    std::string Y1 = padZeros(Y, n).substr(0, n - m);
    std::string Y0 = padZeros(Y, n).substr(n - m);

    std::string Z2 = karatsuba(X1, Y1);
    std::string Z0 = karatsuba(X0, Y0);
    std::string Z1 = karatsuba(addStrings(X1, X0), addStrings(Y1, Y0));
    Z1 = subtractStrings(subtractStrings(Z1, Z2), Z0);

    // Multiply with powers of 10
    Z2.append(2 * m, '0');
    Z1.append(m, '0');

    return addStrings(addStrings(Z2, Z1), Z0);
}

int main() {
    std::string num1 = "314159265358979323846264338327950288419716939937510";
    std::string num2 = "271828182845904523536028747135266249775724709369995";
    
    std::string result = karatsuba(num1, num2);
    std::cout << "Karatsuba Multiplication Result:\n" << result << std::endl;
    return 0;
}
