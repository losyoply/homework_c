#include <iostream>
#include <queue> // For priority queue.

using namespace std;

int main() {
    string cmd;
    int arg;
    priority_queue<int> q;

    while (cin >> cmd) {
        if (cmd == "PUSH") {
            cin >> arg;
            q.push(arg);
            q.reverse();
        }
        else if (cmd == "POP") q.pop();
        else {
            if (q.empty()) cout << "Null\n";
            else cout << q.top() << '\n';
        }
    }

    return 0;
}


