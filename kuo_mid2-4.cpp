#include <string>
using namespace std;
#include<iostream>
class Guest {
public:
	Guest();
	Guest(string s, int m, int ski);
	~Guest();
	string get_name();
	int get_money();
	int get_skill();
	void Win(int m);

private:
	string name;
	int money;
	int skill;
};
Guest::Guest()
{
    name = "";
    money = 0;
    skill = 0;
}
Guest::Guest(string s, int m , int ski)
{
    name = s;
    money = m;
    skill = ski;
}
Guest::~Guest() = default;
string Guest::get_name()
{
    return name;
}
int Guest::get_money()
{
    return money;
}
int Guest::get_skill()
{
    return skill;
}
void Guest::Win(int m)
{
    money+=m;
}
class Casino {
public:
	Casino();
	~Casino();
	void Enterance(int f);
	void GuestEnter(string s, int m, int ski);
	void Win(string s, int m);
	void EndDay();
	void Result();

private:
	int fee;

	int guest_num;
	Guest *guest[1009];

	int income;
	int list_num;
	string blacklist[1009];
};

Casino::Casino()
{
    fee = 0;
    guest_num = 0;
    income = 0;
    list_num = 0;
}
Casino::~Casino()
{
    for(int i = 0;i<guest_num;i++)
    {
        if(guest[i])
        {
            delete guest[i];
            guest[i] = nullptr;
        }
    }
}
void Casino::Enterance(int f)
{
    fee = f;
}
void Casino::GuestEnter(string s, int m, int ski)
{
    //check black
    for(int i = 0;i<list_num;i++)
    {
        if(s==blacklist[i]) return;
    }
    //check in casino
    for(int i = 0;i<guest_num;i++)
    {
        if(guest[i]&&s==guest[i]->get_name()) return;
    }
    //check money for fee
    if(m<=fee)
    {
        income+=m;
        blacklist[list_num] = s;
        list_num++;
        return;
    }
    //else qdd guest
    Guest *new_guest = new Guest(s, m-fee, ski);
    income+=fee;
    for(int i= 0;i<guest_num;i++)
    {
        if(!guest[i])
        {
            guest[i] = new_guest;
            return;
        }
    }
    guest[guest_num] = new_guest;
    guest_num++;
}
void Casino::Win(string s, int m)
{
    //check in casino
    for(int i = 0;i<guest_num;i++)
    {
        if(guest[i]&&guest[i]->get_name()==s)
        {
            //ban if bankrupt
            if(guest[i]->get_money()<=-m)
            {
                income = income+guest[i]->get_money();
                blacklist[list_num] = s;
                list_num++;
                delete guest[i];
                guest[i] = nullptr;
            }
            else if(m>2*guest[i]->get_skill())
            {
                blacklist[list_num]=s;
                list_num++;
                delete guest[i];
                guest[i] = nullptr;
                income-=m;
            }
            else
            {
                guest[i]->Win(m);
                income-=m;
            }
            return;
        }
    }
}
void Casino::EndDay()
{
    for(int i = 0;i<guest_num;i++)
    {
        if(guest[i])
        {
            delete guest[i];
            guest[i] = nullptr;
        }
    }
    guest_num = 0;
}
void Casino::Result()
{
    std::cout<<income<<std::endl;
    for(int i = 0;i<list_num;i++) std::cout<<blacklist[i]<<std::endl;
}
