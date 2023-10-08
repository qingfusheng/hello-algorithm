#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct BigInt {
private:
    bool signal = true; // 私有成员变量
    string value;

public:
    BigInt(string s) {
        if (s.empty() || (s[0] != '-' && !isdigit(s[0])))
            throw invalid_argument("Invalid input");
        if (s[0] == '-')
            signal = false, s = s.substr(1); // 移除负号
        else
            signal = true;
        s.erase(0, s.find_first_not_of('0'));
        value = s;
    }
    
    bool operator == (const BigInt& x) const {
        return signal == x.signal && value == x.value;
    }
    bool operator < (const BigInt& x) const {
        if (signal != x.signal)
            return !signal; // 不同号的情况
        if (value.length() != x.value.length())
            return (value.length() < x.value.length()) ^ !signal; // 长度不同的情况
        return (signal ? value < x.value : value > x.value); // 同号且长度相同的情况
    }
    BigInt operator + (const BigInt& x) const {
        if (signal == x.signal) {
            BigInt result("0");
            int carry = 0;
            int maxLength = max(value.length(), x.value.length());
            string resultValue;

            for (int i = 0; i < maxLength || carry; ++i) {
                int aDigit = (i < value.length()) ? (value[value.length() - 1 - i] - '0') : 0;
                int bDigit = (i < x.value.length()) ? (x.value[x.value.length() - 1 - i] - '0') : 0;
                int sum = aDigit + bDigit + carry;
                carry = sum / 10;
                resultValue.insert(resultValue.begin(), sum % 10 + '0');
            }
            resultValue.erase(0, resultValue.find_first_not_of('0'));
            result.value = resultValue;
            result.signal = signal;
            return result;
        }
        else {
            // 处理不同号的情况，转换为减法
            BigInt y = x;
            y.signal = signal;
            return *this - y;
        }
    }

    BigInt operator - (const BigInt& x) const {
        if (signal == x.signal) {
            if (abs() < x.abs()) {
                // 如果被减数的绝对值较小，交换操作数并将结果的信号置反
                return x - *this;
            }
            BigInt result("0");
            int borrow = 0;
            string resultValue;
            for (int i = 0; i < value.length(); ++i) {
                int aDigit = value[value.length() - 1 - i] - '0';
                int bDigit = (i < x.value.length()) ? (x.value[x.value.length() - 1 - i] - '0') : 0;
                int diff = aDigit - bDigit - borrow;
                if (diff < 0)
                    diff += 10, borrow = 1;
                else
                    borrow = 0;
                resultValue.insert(resultValue.begin(), diff + '0');
            }
            resultValue.erase(0, resultValue.find_first_not_of('0'));
            result.value = resultValue;
            result.signal = signal;
            return result;
        }
        else {
            // 处理不同号的情况，转换为加法
            BigInt y = x;
            y.signal = signal;
            return *this + y;
        }
    }
    // 辅助函数，返回绝对值
    BigInt abs() const {
        BigInt result = *this;
        result.signal = true;
        return result;
    }
    friend std::ostream& operator<<(std::ostream& os, const BigInt& obj) {
        string pre_signal = obj.signal ? "" : "-";
        os << pre_signal << obj.value;
        return os;
    }
};


int main() {
    try {
        BigInt a = BigInt("-123");
        BigInt b = BigInt("122");

        BigInt add = a + b;
        cout << "a+b:" << add << endl;
        BigInt minus1 = a - b;
        BigInt minus2 = b - a;
        cout << "a-b:" << minus1 << endl;
        cout << "b-a:" << minus2 << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
