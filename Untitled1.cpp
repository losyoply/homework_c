#include <iostream>
#include <cmath>
template<typename T, typename Func> void
ForEach(T _begin, T _end, Func _func) {
for (; _begin != _end; _begin++) {
_func(*_begin);
}
};
void Power(int &a)
{
    a = pow(a, 2);
}

 int main() { double A[] = {1,
2, 3, 4, 5}; ForEach(A, A
+ 5, Power);
return 0;
}
