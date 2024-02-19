#include <iostream>
#include <string>
#include <deque>
using namespace std;

template < class T >
class circular_buffer {
private:
    std::deque <T> my;
    int capacity;
public:
    circular_buffer(int n) {
        capacity = n;
    }
    void push_back(int num) {
        while(my.size() >= capacity) my.pop_front();
        my.push_back(num);
    }
    void pop_front() {
        my.pop_front();
    }
    int size() {
        return my.size();
    }
    T& operator [] (int n) {
        return my[n];
    }
};

int main()
{
    int capacity;
    cin >> capacity;
    circular_buffer<int> cbi(capacity);

    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        string cmd;
        cin >> cmd;
        if(cmd=="push_back"){
            int data;
            cin >> data;
            cbi.push_back(data);
        }else if(cmd=="pop_front"){
            cbi.pop_front();
        }else if(cmd=="print"){
            for(int j=0; j<cbi.size(); j++){
                cout << cbi[j] << endl;
            }
            cout << "----" << endl;
        }
    }
    return 0;
}
