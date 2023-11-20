#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Student
{
    public:
        int id;
        double marks;
        vector<int>preference;
        bool allocated;
};

bool comp(Student* a, Student* b)
{
    if(a->marks != b->marks)
    {
        return a->marks > b->marks;
    }
    else
    {
        return a->id < b->id;
    }
}

int find_max(vector<int>&seats)
{
    int m = 0;
    int index = -1;
    for(int i = 0; i < seats.size(); i++)
    {
        if(seats[i] > m)
        {
            m = seats[i];
            index = i;
        }
    }
    return index;
}

int find_min(vector<double>&seats)
{
    double m = 101.0;
    int index = -1;
    for(int i = 0; i < seats.size(); i++)
    {
        if(seats[i] < m)
        {
            m = seats[i];
            index = i;
        }
    }
    return index;
}

int main()
{
    int colleges,students;
    cin >> colleges >> students;
    vector<int>seats(colleges);
    for(int i = 0; i < colleges; i++)
    {
        cin >> seats[i];
    }
    cin.ignore();
    vector<Student*> listOfStudents;
    for(int i = 0; i < students; i++)
    {
        string s,t;
        getline(cin,s);
        Student* student = new Student();
        listOfStudents.push_back(student);

        stringstream x(s);
        while(getline(x,t,','))
        {
            if(t[0] == 'S')
            {
                student->id = t[8]-'0';
            }
            else if(t[0] == 'C')
            {
                student->preference.push_back(t[2]-'0');
            }
            else
            {
                student->marks = stod(t);
            }
        }
    }

    sort(listOfStudents.begin(),listOfStudents.end(),comp);

    vector<vector<double>> ans(colleges);

    //round 1

    for(auto it_student : listOfStudents)
    {
        for(auto choice : it_student->preference)
        {
            if(seats[choice-1] > 0)
            {
                seats[choice-1]--;
                ans[choice-1].push_back(it_student->marks);
                it_student->allocated = true;
                break;
            }
        }
    }

   //round 2

    for(auto it_student : listOfStudents)
    {
        if(it_student->allocated != true)
        {
            int college = find_max(seats);
            if(college != -1) 
            {
                ans[college].push_back(it_student->marks);
                it_student->allocated = true;
                break;
            }
        }
    }

    vector<pair<double,int>> final;

    for(int i = 0; i < ans.size(); i++)
    {
        int val = find_min(ans[i]);
        if(val != -1)
        {
            final.push_back({ans[i][val],i+1});
        }
        else
        {
            final.push_back({0,i+1});
        }
    }

    sort(final.begin(),final.end(),greater<pair<double,int>>());

    for(auto it : final)
    {
        if(it.first == 0)
        {
            cout << "C-" << it.second << " n/a" << endl;
        }
        else
        {
            cout << "C-" << it.second << " " << it.first << endl;
        }
        
    }   

}
