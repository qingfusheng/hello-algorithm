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
    int length() {
        return this->value.length();
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
    // 乘法使用Karatsuba算法，可以实现大整数的乘法（考虑负号）
    BigInt operator * (const BigInt& x) const {
        /*bool t_signal = signal == x.signal;*/
        string pre_signal = signal == x.signal ? "" : "-";
        int len1 = value.length();
        int len2 = x.value.length();
        if (len1 == 0 || len2 == 0 || value == "0" || x.value == "0") {
            return BigInt("0");
        }
        if (len1 <= 2 || len2 <= 2) {
            return BigInt(to_string(stoll(value) * stoll(x.value)));
        }
        int mid = max(len1, len2) / 2;
        // 这里应该从低位到高位划分，而不是从高位到低位，才能保证高位和10的幂的一致性。若选择第二种，则需要先把字符串reverse
        // 这里的分割使用BigInt内部定义的substr会报错，原因未知，因此改为字符串substr后转为BigInt
        BigInt high1 = BigInt(value.substr(0, len1 - mid));
        BigInt low1 = BigInt(value.substr(len1 - mid, len1));
        BigInt high2 = BigInt(x.value.substr(0, len2 - mid));
        BigInt low2 = BigInt(x.value.substr(len2 - mid, len2));
        cout << "h1h2l1l2:" << high1 << "," << low1 << "," << high2 << "," << low2 << endl;
        BigInt z0 = low1 * low2;
        BigInt z2 = high1 * high2;
        BigInt temp1 = high1 + low1;
        BigInt temp2 = high2 + low2;
        BigInt z1 = temp1 * temp2;
        cout << "temp1:temp2:z1:" << temp1 << " " << temp2 << "," << z1 << endl;
        z1 = z1 - z0 - z2;
        cout << "z0:z1:z2:" << z0 << "," << z1 << "," << z2 << endl;
        BigInt result = BigInt(z2.value + string(mid * 2, '0')) + BigInt(z1.value + string(mid, '0')) + z0;
        return result;
    }
    /*string value2() {
        string pre_signal = signal ? "" : "-";
        string result = pre_signal + value;
        return result;
    }
    bool signal2() {
        return signal;
    }
    long long to_long() {
        return stoll(value);
    }
    BigInt substr(int m, int n) {
        BigInt result = *this;
        result.value = result.value.substr(m, n);
        return result;
    }
    BigInt substr(int n) {
        BigInt result = *this;
        result.value = result.value.substr(n);
        return result;
    }*/
};

// 将乘法内嵌到了struct内部
//BigInt multi(BigInt& num1, BigInt& num2) {
//    bool signal = num1.signal2() == num2.signal2();
//    string pre_signal = signal ? "" : "-";
//    int len1 = num1.length();
//    int len2 = num2.length();
//    if (len1 == 0 || len2 == 0 || num1 == BigInt("0") || num2 == BigInt("0")) {
//        return BigInt("0");
//    }
//    if (len1 <= 2 || len2 <= 2) {
//        return BigInt(to_string(num1.to_long() * num2.to_long()));
//    }
//    int mid = max(len1, len2) / 2;
//    // 这里应该从低位到高位划分，而不是从高位到低位，才能保证高位和10的幂的一致性。若选择第二种，则需要先把字符串reverse
//    BigInt high1 = num1.substr(0, len1 - mid).abs();
//    BigInt low1 = num1.substr(len1 - mid, len1).abs();
//    BigInt high2 = num2.substr(0, len2 - mid).abs();
//    BigInt low2 = num2.substr(len2 - mid, len2).abs();
//    cout << "h1h2l1l2:" << high1 << "," << low1 << "," << high2 << "," << low2 << endl;
//    BigInt z0 = multi(low1, low2);
//    BigInt z2 = multi(high1, high2);
//    BigInt temp1 = high1 + low1;
//    BigInt temp2 = high2 + low2;
//    BigInt z1 = multi(temp1, temp2);
//    cout << "temp1:temp2:z1:" << temp1 << " " << temp2 << "," << z1 << endl;
//    z1 = z1 - z0 - z2;
//    cout << "z0:z1:z2:" << z0 << "," << z1 << "," << z2 << endl;
//    BigInt result = BigInt(z2.value2() + string(mid * 2, '0')) + BigInt(z1.value2() + string(mid, '0')) + z0;
//    return result;
//}

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
        BigInt num1 = BigInt("123456789");
        BigInt num2 = BigInt("987654321");
        BigInt result = num1 * num2;
        // Question: 123456789 * 987654321
        // result: 121932631112635269
        cout << "num1*num2:" << result << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
