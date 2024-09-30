class Solution {
public:
    string removeDigit(string number, char digit) {
        for (int i = 0; i < number.size() - 1; i++) {
            if (number[i] == digit && number[i + 1] > number[i])
                return number.substr(0, i) + number.substr(i + 1);
        }
        int last_digit = number.rfind(digit);
        return number.substr(0, last_digit) + number.substr(last_digit + 1);
    }
};
