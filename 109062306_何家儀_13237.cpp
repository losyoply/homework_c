#include <stack>
#include <list>
#include <string>
#include"function.h"

using std::list;
using std::stack;
using std::string;

void Crossing::solve()
{
  stack<State> state_stack;
  State now_state;
  set<State> next_states;
  list<State> now_paths;

  this->_items.emplace_back(0);
  this->_items.emplace_back(0);
  this->_items.emplace_back(0);
  this->_items.emplace_back(1);
  state_stack.emplace(this->_items);

  while (!state_stack.empty())
  {
    now_state = state_stack.top();
    if (this->_explored.find(now_state) != this->_explored.end())
    {
      state_stack.pop();
      this->_explored.erase(now_state);
      now_paths.pop_back();
      continue;
    }

    this->_explored.emplace(now_state);
    now_paths.emplace_back(now_state);

    if (found(now_state))
    {
      this->_solutions.emplace(now_paths);
    }
    else
    {
      next_states = extend(now_state);
      for (State iter : next_states)
      {
        if (valid(iter))

          state_stack.emplace(iter);
      }
    }
  }

}

set<State> Crossing::extend(State s)
{
    return set<State>({Go(s, 1, 0, 0), Go(s, 0, 1, 0), Go(s, 0, 0, 1), Go(s, 0, 0, 0), Go(s, 0, 0, 0)});
}

State Crossing::Go(State s, int wolf, int goat, int cabbage)
{
    if (s[6] == 1)
    {
        s[0] -= wolf;
        s[1] -= goat;
        s[2] -= cabbage;
        s[3] += wolf;
        s[4] += goat;
        s[5] += cabbage;
        s[6] = -(s[6]);
    }
    else if (s[6] == -1)
    {
        s[0] += wolf;
        s[1] += goat;
        s[2] += cabbage;
        s[3] -= wolf;
        s[4] -= goat;
        s[5] -= cabbage;
        s[6] = -(s[6]);
    }
    return s;
}

bool Crossing::valid(State s)
{
    if (this->_explored.find(s) != this->_explored.end()) return false;
    if (s[0] < 0 || s[1] < 0 || s[2] < 0 || s[3] < 0 || s[4] < 0 || s[5] < 0) return false;
    if (s[1] != 0 && s[0] > s[1] && s[6]==-1) return false;
    if (s[4] != 0 && s[3] > s[4] && s[6]== 1) return false;
    if (s[2] != 0 && s[1] > s[2] && s[6]==-1) return false;
    if (s[5] != 0 && s[4] > s[5] && s[6]== 1) return false;
    return true;
}

bool Crossing::found(State s)
{
    if (s[0] == s[1] && s[1]==s[2] && s[0] == 0) return true;

    return false;
}
