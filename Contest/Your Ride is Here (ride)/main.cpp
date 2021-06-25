#include <iostream>
#include <string>
using namespace std;

int main()
{
    string comet, group;
    cin >> comet;
    cin >> group;

    int last_comet = 1, new_comet = 0, last_group = 1, new_group = 0;

    for (int i = 0; i < comet.length(); i++)
    {
        new_comet = comet[i] - 64;
        last_comet *= new_comet;
    }
    for (int i = 0; i < group.length(); i++)
    {
        new_group = group[i] - 64;
        last_group *= new_group;
    }

    if ((last_group % 47) == (last_comet % 47))
    {
        cout << "GO";
    } else{cout << "STAY";}
}