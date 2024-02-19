
//排除重複的State只能用三維陣列，Set會TLE。題目給的記憶體夠你開這麼大的陣列。
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool explored[15][301][401] = { false };

class Game {
	using State = vector<int>; // { level, player HP, enemy HP, Round }
private:
	int levelTable[15][2]; // [level] { DMG, HL }
	int maxLevel;
	int maxPlayerHP;
	int monsterDMG;

	queue<State> search_queue;

	bool isSolution(State& curState) {
		return curState[2] - levelTable[curState[0]][0] <= 0;
	}

	void extend(State& curState) { // Only valid states are pushed.
		if (curState[1] - monsterDMG > 0)
		{ // Attack, Level-Up.
			search_queue.push(State{ curState[0], curState[1] - monsterDMG, \
				curState[2] - levelTable[curState[0]][0], curState[3] + 1 });
			if (curState[0] + 1 != maxLevel)
				search_queue.push(State{ curState[0] + 1, curState[1] - monsterDMG, \
				curState[2], curState[3] + 1 });
		} // Heal.
		if (min(maxPlayerHP, curState[1] + levelTable[curState[0]][1]) - monsterDMG > 0)
			search_queue.push(State{ curState[0], min(maxPlayerHP, \
				curState[1] + levelTable[curState[0]][1]) - monsterDMG,
				curState[2], curState[3] + 1 });
	}


public:
	Game(int L, int HP, int MHP, int MDMG) : maxLevel(L), maxPlayerHP(HP), monsterDMG(MDMG) {
		for (int i = 0; i < maxLevel; i++)
			cin >> levelTable[i][0] >> levelTable[i][1];
		search_queue.push(State{ 0, HP, MHP, 1 }); // Root State (always valid)
	}

	void solve() {
		while (!search_queue.empty()) {
			State curState = search_queue.front();
			search_queue.pop();
			if (explored[curState[0]][curState[1]][curState[2]])
				continue;
			else explored[curState[0]][curState[1]][curState[2]] = true;
			if (isSolution(curState)) {
				cout << curState[3] << '\n';
				return;
			}
			extend(curState);
		}
		cout << "-1\n"; // Impossible.
	}
};

int main() {
	int L, HP, MHP, MDMG;
	cin >> L >> HP >> MHP >> MDMG;
	Game G(L, HP, MHP, MDMG);
	G.solve();

	return 0;
}

// By IntSy



/////////////////////////////////////////////////////////////////////////////////////////////////
/*
#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

struct State
{
  int l;
  int hp;
  int mhp;
  int step;
  State(int l, int hp, int mhp, int step) : l(l), hp(hp), mhp(mhp), step(step){};
  State(){};
  bool operator<(const State &rhs) const
  {
    if (this->l != rhs.l)
      return this->l < rhs.l;
    if (this->hp != rhs.hp)
      return this->hp < rhs.hp;
    if (this->mhp != rhs.mhp)
      return this->mhp < rhs.mhp;
    return 0;
  }
  bool operator==(const State &rhs) const
  {
    if (this->l == rhs.l && this->hp == rhs.hp && this->mhp == rhs.mhp)
      return 1;
    return 0;
  }
};

int DMG[20];
int HL[20];

int main()
{
  set<State> exist_state;
  queue<State> q;
  int MAX_L, HP, MHP, MDMG;
  bool found = false;
  State current_state, next_state;

  cin >> MAX_L >> HP >> MHP >> MDMG;
  for (int i = 1; i <= MAX_L; ++i)
    cin >> DMG[i] >> HL[i];

  // init state
  q.push(State(1, HP, MHP, 0));
  exist_state.emplace(q.front());

  // calc
  while (!q.empty())
  {
    current_state = q.front();
    q.pop();

    // add step
    current_state.step += 1;

    // attack
    next_state = current_state;
    next_state.mhp -= DMG[next_state.l];
    if (next_state.mhp <= 0)
    {
      found = true;
      break;
    }
    next_state.hp -= MDMG;
    if (next_state.hp > 0 && exist_state.find(next_state) == exist_state.end())
    {
      exist_state.emplace(next_state);
      q.push(next_state);
    }

    // hl
    if (HL[next_state.l] > MDMG && next_state.hp < HP)
    {
      next_state = current_state;
      next_state.hp = min(HP, next_state.hp + HL[next_state.l]);
      next_state.hp -= MDMG;
      if (next_state.hp > 0 && exist_state.find(next_state) == exist_state.end())
      {
        exist_state.emplace(next_state);
        q.push(next_state);
      }
    }

    // level up
    if (next_state.l < MAX_L)
    {
      next_state = current_state;
      next_state.l += 1;
      next_state.hp -= MDMG;
      if (next_state.hp > 0 && exist_state.find(next_state) == exist_state.end())
      {
        exist_state.emplace(next_state);
        q.push(next_state);
      }
    }
  }

  if (found)
    cout << current_state.step;
  else
    cout << -1;
  cout << '\n';

  return 0;
}
*/
// by Alan
