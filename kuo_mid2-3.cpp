#ifndef FUNCTION_H
#define FUNCTION_H

#include <cstdio>
#include <cstring>

namespace oj {
    class BigInt {
    private:
        char* _val;

        // Remove leading zeroes.
        void truncate() {
            if (strlen(_val) > 1 && _val[0] != '0') return;
            else if (strlen(_val) == 1) return;
            char* new_val = new char[strlen(_val) + 1];
            strcpy(new_val, _val + 1);
            delete _val;
            _val = new_val;
        }

        // Given the current digit position and the carry, add the carry to the digit and return the carry.
        int half_adder(const int pos, const int& c) {
            if (_val[pos] + c > '9') {
                _val[pos] = '0';
                return 1;
            }
            else {
                _val[pos]++;
                return 0;
            }
        }

        // Add 1 to _val.
        void add_one() {
            int carry = 1;
            for (int i = strlen(_val) - 1;i >= 0 && carry;i--)
                carry = half_adder(i, carry);
            if (carry) {
                char* new_val = new char[strlen(_val) + 2];
                new_val[0] = '1';
                strcpy(&new_val[1], _val);
                delete _val;
                _val = new_val;
            }
        }

        // Given the current digit position and the borrow, subtract the borrow from the digit and return the borrow.
        int half_subtractor(const int pos, const int& b) {
            if (_val[pos] - b < '0') {
                _val[pos] = '9';
                return 1;
            }
            else {
                _val[pos]--;
                return 0;
            }
        }

        // Subtract 1 from _val.
        void subtract_one() {
            if (_val[0] == '0') return;
            int borrow = 1;
            for (int i = strlen(_val) - 1;i >= 0 && borrow;i--)
                borrow = half_subtractor(i, borrow);
            truncate();
        }

    public:
        BigInt(char* s);
        ~BigInt();
        BigInt& operator++();
        BigInt operator++(int);
        BigInt& operator--();
        BigInt operator--(int);
        char* to_s();
    };

    BigInt::BigInt(char* s) {
        _val = new char[strlen(s) + 1];
        strcpy(_val, s);
    }

    BigInt::~BigInt() {
        delete _val;
    }

    BigInt& BigInt::operator++() {
        add_one();
        return (*this);
    }

    BigInt BigInt::operator++(int) {
        BigInt* copy = new BigInt(_val);
        add_one();
        return (*copy);
    }

    BigInt& BigInt::operator--() {
        subtract_one();
        return (*this);
    }

    BigInt BigInt::operator--(int) {
        BigInt* copy = new BigInt(_val);
        subtract_one();
        return (*copy);
    }

    char* BigInt::to_s() {
        return _val;
    }

}  // namespace oj

#endif

// By IntSys
