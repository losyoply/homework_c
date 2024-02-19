#include <iostream>
#include <cstring>
#include "function.h"
using namespace std;

Human::Human(string n, int m, int ski)
{
    name = n;
    money = m;
    skill = ski;
}
void Human::Draw()
{
    this->cards = 0;
    string res = "";
    while (res.size() <= 0)
        getline(cin, res);
    stringstream ss(res);
    while (ss >> res)
    {
        int temp = 0;
        for (auto i : res)
            temp = temp * 10 + i - '0';
        this->cards += temp;
    }
}
Human::~Human() {}

Casino::Casino()
{
    banker = nullptr;
    guard = nullptr;
    server = nullptr;
    player_num = 0;
    blacklist_num = 0;
    today_income = 0;
    total_income = 0;
}
Casino::~Casino()
{
}
void Casino::Enterance(int f, int u)
{
    fee = f;
    U = u;
}
void Casino::Guest(string s, int m, int ski)
{
    for (int i = 0; i < blacklist_num; i++)
    {
        if (blacklist[i] == s)
        {
            return;
        }
    }
    for (int i = 0; i < player_num; i++)
    {
        if (player[i]->name == s)
        {
            return;
        }
    }
    player[player_num] = new Player(s, m, ski);
    int prepare = min(fee, m);
    player[player_num]->money -= prepare;
    today_income += prepare;
    // cout << "+=" << prepare << endl;
    if (player[player_num]->Bankrupt())
    {
        blacklist[blacklist_num++] = s;
        today_income -= prepare;
    }
    player_num++;
}
void Casino::TwentyOne()
{
    int banker_ski;
    int guard_ski;
    int server_ski;
    int K;
    cin >> banker_ski >> guard_ski >> server_ski >> K;
    banker = new Banker(banker_ski);

    banker = new Banker(banker_ski);
    guard = new Guard(guard_ski);
    server = new Server(server_ski);

    string n;
    int record[1009];
    for (int i = 0; i < 1009; i++)
        record[i] = 0;
    for (int i = 0; i < K; i++)
    {
        cin >> n;
        int flag = 1;
        Player *new_player = new Player(n, 0, 0);
        new_player->Bet();
        new_player->Draw();

        for (int j = 0; j < this->blacklist_num; j++)
        {
            if (this->blacklist[j] == n)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            for (int j = 0; j < this->player_num; j++)
            {
                if (this->player[j]->name == n)
                {
                    record[j] = 1;
                    this->player[j]->bets = new_player->bets;
                    this->player[j]->cards = new_player->cards;
                }
            }
        }
        delete new_player;
    }
    // banker draw
    this->banker->Draw();

    // your twnety one rule
    for (int i = 0; i < this->player_num; i++)
    {
        if (record[i] == 1)
        {
            if (banker->Win(player[i]) == 1)
            {
                player[i]->Pay(banker);
                if (player[i]->Bankrupt())
                {
                    blacklist[blacklist_num++] = player[i]->name;
                    banker->Pay(guard);
                }
            }
            else if (banker->Win(player[i]) == 0)
            {
                banker->Pay(player[i]);
                if (player[i]->money >= server->skill)
                {
                    player[i]->money -= 3000;
                    server->money += 1000;
                    banker->money += 2000;
                }

                if (player[i]->Cheat(banker))
                {
                    blacklist[blacklist_num++] = player[i]->name;
                    guard->Pay(player[i]);
                    banker->Pay(guard);
                }
            }
        }
    }

    cout << banker->money << " " << guard->money << " " << server->money << endl;
    for (int i = 0; i < player_num; i++)
    {
        if (record[i] == 1)
            cout << player[i]->name << " " << player[i]->money << endl;
    }
    today_income += banker->money;

    delete dynamic_cast<Banker *>(banker);
    delete dynamic_cast<Guard *>(guard);
    delete dynamic_cast<Server *>(server);
    banker = guard = server = nullptr;
}

void Casino::EndDay()
{
    if (today_income >= U)
    {
        blacklist_num = 0;
    }
    total_income += today_income;
    // cout << "today_income = " << today_income << endl;
    today_income = 0;

    for(int i=0;i<player_num;++i) {
        delete dynamic_cast<Player *>(player[i]);
        player[i] = nullptr;
    }
    player_num = 0;
}

void Casino::Result()
{
    cout<<total_income<<endl;
    for (int i = 0; i < blacklist_num; i++)
    {
        cout << blacklist[i] << endl;
    }
}

Player::Player(string name, int m, int ski) : Human(name, m, ski) {}
void Player::Pay(Human *human)
{
    int prepare = min(bets, money);
    human->money += prepare;
    money -= prepare;
}
void Player::Bet()
{
    cin >> bets;
}
bool Player::Bankrupt()
{
    return money <= 0;
}
bool Player::Cheat(Human *human)
{
    return 3 * skill < human->bets;
}
void Player::Order(Human *banker, Human *server) {}
Player::~Player() {}

Guard::Guard(int ski) : Human("name", 0, ski) {}
void Guard::Pay(Human *human)
{
    if (human->Bankrupt())
    {
        return;
    }
    if (skill < human->skill)
    {
        money -= human->skill - skill;
        human->money += human->skill - skill;
    }
}

Banker::Banker(int ski) : Human("name", 0, ski) {}
void Banker::Pay(Human *human)
{
    if (auto guard = dynamic_cast<Guard *>(human))
    {
        guard->money += 100;
        money -= 100;
        return;
    }
    int prepare = human->bets;
    if (human->skill < skill)
    {
        prepare += 10 * human->cards;
    }

    if (human->cards == 21)
    {
        prepare *= 2;
    }
    human->money += prepare;
    money -= prepare;
    bets = prepare;
}
int Banker::Win(Human *human)
{
    if (human->cards > 21 && cards > 21)
    {
        return -1;
    }
    if (human->cards <= 21 && (cards > 21 || human->cards > cards))
    {
        return 0;
    }
    else
        return 1;
}
Banker::~Banker() {}

Server::Server(int ski) : Human("name", 0, ski) {}
Server::~Server() {}
