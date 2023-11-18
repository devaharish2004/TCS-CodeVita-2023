#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Team 
{
public :
    string name;
    int matches;
    int points;
    int goals_for;
    int goals_against;
    int goals_diff;
    Team()
    {
        this->matches = 0;
        this->points = 0;
        this->goals_for = 0;
        this->goals_against = 0;
        this->goals_diff = 0;
    }
};

bool comp(Team* a, Team* b)
{
    if(a->points == b->points)
    {
        return a->name < b->name;
    }
    return a->points > b->points;
}

Team* find_team(string team, vector<Team*>&v)
{
    for(auto it : v)
    {
        if(it->name == team)
        {
            return it;
        }
    }
    return nullptr;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    string s,t;
    getline(cin,s);
    stringstream x(s);
    vector<Team*>v;
    while(getline(x,t,' '))
    {
        Team* team = new Team();
        v.push_back(team);
        team->name = t;
    }
    int m; //no. of matches
    cin >> m;
    int flag = 1;
    map<pair<string,string>,int> check;
    while(m--)
    {
        string team1,team2;
        int goal_team1, goal_team2;
        cin >> team1 >> team2;
        cin >> goal_team1 >> goal_team2;

        Team* team1_obj = find_team(team1,v);
        Team* team2_obj = find_team(team2,v);

        team1_obj->matches++;
        team2_obj->matches++;

        if(team1 == team2)
        {
            flag = 0;
            break;
        }

        if(team1 > team2)
        {
            check[{team1,team2}]++;
        }
        else
        {
            check[{team2,team1}]++;
        }
        

        team1_obj->goals_for += goal_team1;
        team1_obj->goals_against += goal_team2;
        team2_obj->goals_for += goal_team2;
        team2_obj->goals_against += goal_team1;

        team1_obj->goals_diff = team1_obj->goals_for - team1_obj->goals_against;
        team2_obj->goals_diff = team2_obj->goals_for - team2_obj->goals_against;

        if(goal_team1 > goal_team2)
        {
            team1_obj->points += 2;
        }
        else if(goal_team1 < goal_team2)
        {
            team2_obj->points += 2;
        }
        else //tie
        {
            team1_obj->points += 1;
            team2_obj->points += 1;
        }
    }

    for(auto it : check)
    {
        if(it.second > 2)
        {
            flag = 0;
            break;
        }
    }

    if(flag == 0)
    {
        cout << "Invalid input" << endl;
        return 0;
    }

    sort(v.begin(),v.end(),comp);

    for(auto it : v)
    {
        cout << it->name << endl;
    }

}