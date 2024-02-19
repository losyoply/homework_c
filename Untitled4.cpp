#include <iostream>
#include <algorithm>
template<typename Iter, typename Func>
void Sort(Iter first, Iter last, Func Comp) {
 while (first++ != last) {
 Iter cur = first;
 while (++cur != last) {
 if (Comp(*first, *cur)) {
 std::swap(*first, *cur);
 }
 }
 }
}
bool CompFunc(int a, int b) {
 return a < b;
}
struct CompObj {
 bool operator() (int a, int b) {
 return a < b;
 }
};
int main() {
 int arr[] = {2, 1, 2, 7, 3};
 Sort(arr, arr + 4, CompFunc);
 std::cout << arr[0];
 return 0;
}
