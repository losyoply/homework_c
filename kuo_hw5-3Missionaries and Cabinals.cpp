#include <iostream>
#include <vector>
#include <list>
#include <set>

using std::vector;
using std::set;
using std::list;
using std::cout;
using std::endl;

// A state contains five components:
// The first two components denote the current numbers of
// missionaries and cannibals at the left bank of the river.
// The third and fourth components denote the current numbers
// of missionaries and cannibals at the right bank.
// The fifth component denotes the location of the boat:
// 1 means "left bank" and -1 means "right bank".
using State = vector<int>;
class Crossing
{
private:
    vector<int> _npeople;  // how many missionaries and cannibals
                           // we use vector<int> as a tuple (int, int)
                           // the first integer indicate the number of missionaries
                           // the second integer indicates the number of cannibals
    set<list<State>> _paths;  // trial paths in progress
    set<State> _explored;     // explored states
    set<list<State>> _solutions;
public:
    // specify the numbers of missionaries and cannibals
    Crossing(vector<int> np): _npeople {np} { }
    // the starting porint of your implementation
    void solve();
    // extend to other possible states from a certain state
    set<State> extend(State s);
    // may use s[4] to indicate the direction of move
    State Go(State s, int missionary, int cannibal);
    // check the validity of a state
    bool valid(State s);
    // check if all people are at the right bank
    bool found(State s);
    void show_solutions() {
        for (auto path : _solutions) {
            for (auto s : path) {
                if (!s.empty()) {
                    cout << "(" << s[0] << ", " << s[1] << ")";
                    cout << "(" << s[2] << ", " << s[3] << ")";
                    if (s[4]==1) cout << " left\n";
                    else cout << " right\n";
                }
            }
            cout << "done" << endl;
        }
    }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#include <stack>
#include <cstddef>

void Crossing::solve() {
	std::ios_base::sync_with_stdio(false);
	State root{ _npeople[0], _npeople[1], 0, 0, 1 };

	// Insert root.
	_paths.insert(list<State>{ root });

	// Stack to denote the current branch(es)' parent's validity.
	// Initialized as the number of branches, and reduced by 1 for every invalid branch.
	// If the parent becomes invalid, then the parent state is invalid as well.
	std::stack<int> parent_valid;
	int min_solution_length = INT32_MAX;
	parent_valid.push(1);
	for (auto path : _paths) { // In Python: for path in _paths: ... (DFS)
		if (path.size() <= min_solution_length) {
			if (found(path.back())) {
				_solutions.insert(path); // Insert a solution. Solutions don't need to be extended.
				min_solution_length = path.size();
			}
			else if (path.size() != min_solution_length && (_explored.insert(path.back())).second && valid(path.back())) {
				// Only extend valid paths. Invalid paths are implicitly discarded.
				parent_valid.push(5); // Suppose that this state is valid for all paths.
				for (auto s : extend(path.back())) {
					list<State> path_base(path);
					path_base.push_back(s);
					_paths.insert(path_base);
				}
				continue;
			}
		}

		while (--parent_valid.top() == 0) {
			parent_valid.pop();
			path.pop_back();
			if (!path.empty()) _explored.erase(path.back()); // Remove parent from explored as well.
			else break;
		}
	}
}

set<State> Crossing::extend(State s) {
	return { Go(s, 0, 1), Go(s, 1, 0), Go(s, 1, 1), Go(s, 2, 0), Go(s, 0, 2) };
}

State Crossing::Go(State s, int missionary, int cannibal) {
	if (s[4] == 1) { // Boat on the left.
		return { s[0] - missionary, s[1] - cannibal, s[2] + missionary, s[3] + cannibal, -1 };
	}
	else { // Boat on the right.
		return { s[0] + missionary, s[1] + cannibal, s[2] - missionary, s[3] - cannibal, +1 };
	}
}

bool Crossing::valid(State s) {
	return !((s[0] != 0 && s[0] < s[1]) || (s[2] != 0 && s[2] < s[3])) \
		&& s[0] >= 0 && s[1] >= 0 \
		&& s[2] >= 0 && s[3] >= 0;
}

bool Crossing::found(State s) {
	return (s[0] == 0 && s[1] == 0);
}
*/
// By IntSys

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    int X, Y; //Number of missionaries and cannibals
    cin >> X >> Y;
    Crossing p({X, Y});
    p.solve();
    p.show_solutions();
}
/////////////////////////////////////////////////////////////////////////////////////
//or




#include <stack>
#include <list>
#include <string>

using std::list;
using std::stack;
using std::string;
string output_state(State s);

void Crossing::solve()
{
  stack<State> state_stack;
  State now_state;
  set<State> next_states;
  list<State> now_paths;
  int min_sz = 2147483647;

  this->_npeople.emplace_back(0);
  this->_npeople.emplace_back(0);
  this->_npeople.emplace_back(1);
  state_stack.emplace(this->_npeople);

  while (!state_stack.empty())
  {
    now_state = state_stack.top();

    // The state in the path will be leave in the stack, but set to be explored.
    // When we visit the second time, it means we have already gone throght all
    // the possible solutons after it. Hence, we can remove it safely.
    if (this->_explored.find(now_state) != this->_explored.end())
    {
      state_stack.pop();
      this->_explored.erase(now_state);
      now_paths.pop_back();
      continue;
    }

    // cout << "[info]=====now_state: " << output_state(now_state) << '\n';

    this->_explored.emplace(now_state);
    now_paths.emplace_back(now_state);

    if (found(now_state))
    {
      this->_solutions.emplace(now_paths);
      if (min_sz > now_paths.size())
        min_sz = now_paths.size();
    }
    else
    {
      next_states = extend(now_state);
      for (State iter : next_states)
      {
        if (valid(iter))
          // cout << "[info]insert state: " << output_state(iter) << '\n',
          state_stack.emplace(iter);
      }
    }
  }

  // [don't forget] filter out not best solution
  for (auto solution : this->_solutions)
  {
    if (solution.size() > min_sz)
      this->_solutions.erase(solution);
  }
}

set<State> Crossing::extend(State s)
{
  return set<State>({Go(s, 0, 1), Go(s, 1, 0), Go(s, 1, 1), Go(s, 2, 0), Go(s, 0, 2)});
}

State Crossing::Go(State s, int missionary, int cannibal)
{
  if (s[4] == 1)
  {
    s[0] -= missionary;
    s[1] -= cannibal;
    s[2] += missionary;
    s[3] += cannibal;
    s[4] = -(s[4]);
  }
  else if (s[4] == -1)
  {
    s[0] += missionary;
    s[1] += cannibal;
    s[2] -= missionary;
    s[3] -= cannibal;
    s[4] = -(s[4]);
  }
  return s;
}

bool Crossing::valid(State s)
{
  if (this->_explored.find(s) != this->_explored.end())
    return false;
  if (s[0] < 0 || s[1] < 0 || s[2] < 0 || s[3] < 0)
    return false;
  if (s[0] != 0 && s[0] < s[1])
    return false;
  if (s[2] != 0 && s[2] < s[3])
    return false;
  return true;
}

bool Crossing::found(State s)
{
  if (s[0] == s[1] && s[0] == 0)
    return true;
  return false;
}

string output_state(State s)
{
  cout << "\nret(" << s.size() << "): ";
  string ret;
  ret[0] = (char)(s[0] + '0');
  ret[1] = (char)(s[1] + '0');
  ret[2] = (char)(s[2] + '0');
  ret[3] = (char)(s[3] + '0');
  ret[4] = s[4] == 1 ? 'L' : 'R';
  for (int i = 0; i < s.size(); ++i)
  {
    cout << ret[i];
  }
  cout << '\n';
  return ret;
}
// by Alan
