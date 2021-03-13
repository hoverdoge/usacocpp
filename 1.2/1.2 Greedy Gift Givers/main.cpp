/*
ID: ltjosh22
LANG: C++
TASK: gift1
*/

#include <bits/stdc++.h>
#include <map>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");

    map <string, int> people;
    int numOfPeople; fin >> numOfPeople;
    string name;
    vector<string> nameArr;
    for (int i = 0; i < numOfPeople; i++)
    {
        fin >> name;
        nameArr.push_back(name);
        people[name] = 0;
    }

    for (int i = 0; i < numOfPeople; i++)
    {
        string gifter; int amount; int numPeople;
        fin >> gifter >> amount >> numPeople;

        if (amount == 0 || numPeople == 0)
        {
            continue;
        }

        //takes money from giver
        people[gifter] -= amount;

        // gets amount to give to each
        int amountToGive = amount / numPeople;
        if (amount%numPeople != 0) // if remainder
        {
            //give gifter remainder
            people[gifter] += amount%numPeople;
        }


        for (int j = 0; j < numPeople; j++) // get names of people to gift
        {
            string personToGift;
            fin >> personToGift;
            people[personToGift] += amountToGive;
        }
    }

    for (auto person : nameArr)
    {
        fout << person << " " << people[person] << endl;
    }

}

