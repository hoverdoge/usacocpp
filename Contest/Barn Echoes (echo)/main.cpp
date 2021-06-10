#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int main()
{
    string first_moo, second_moo;
    cin >> first_moo; cin >> second_moo;

    string lotext = "";



    // checks prefix of first string against suffix of last string
    // take one letter off the right side of 1st and cut off length of second to match new len of first from the left
    // check that, repeat
    int longest_overlap = 0;
    string temp_first_moo = first_moo; string temp_second_moo = second_moo;

    for (int amt_erase = 0; amt_erase < first_moo.size(); amt_erase++)
    {
        // erases off of first moo
        int amt_resize = first_moo.size() - amt_erase;
        temp_first_moo.resize(amt_resize);
        //temp_first_moo.erase(temp_first_moo.size() - amt_erase - 1, temp_first_moo.size() - 1);

        if (temp_first_moo.size() > temp_second_moo.size()) // larger -> impossible to match, so restarts cycle to erase
        {
            continue;
        }

        // if first's smaller, cuts off second moo from front to match
        if (temp_first_moo.size() < temp_second_moo.size())
        {
            int amt_erase_second = temp_second_moo.size() - temp_first_moo.size();
            // erases from 0 to amt to erase
            temp_second_moo.erase(temp_second_moo.begin(), temp_second_moo.end()-(temp_second_moo.size()-amt_erase_second));
        }

        // check first moo against last moo length chars in second moo
        //cout << "\n---------------------------\n Comparing [" << temp_first_moo << "] with [" << temp_second_moo << "]\n";
        if (temp_first_moo.compare(temp_second_moo) == 0) // if it is the same, checks max
        {
            if (temp_first_moo.size() > longest_overlap)
            {
                longest_overlap = temp_first_moo.size();
                lotext = temp_first_moo;
            }
        }
    }


    // checks suffix of first string against prefix of last string
    temp_second_moo = first_moo; temp_first_moo = second_moo;
    for (int amt_erase = 0; amt_erase < first_moo.size(); amt_erase++)
    {
        // erases off of first moo
        int amt_resize = first_moo.size() - amt_erase;
        temp_first_moo.resize(amt_resize);
        //temp_first_moo.erase(temp_first_moo.size() - amt_erase - 1, temp_first_moo.size() - 1);

        if (temp_first_moo.size() > temp_second_moo.size()) // larger -> impossible to match, so restarts cycle to erase
        {
            continue;
        }

        // if first's smaller, cuts off second moo from front to match
        if (temp_first_moo.size() < temp_second_moo.size())
        {
            int amt_erase_second = temp_second_moo.size() - temp_first_moo.size();
            // erases from 0 to amt to erase
            temp_second_moo.erase(temp_second_moo.begin(), temp_second_moo.end()-(temp_second_moo.size()-amt_erase_second));
        }

        // check first moo against last moo length chars in second moo
        //cout << "\n---------------------------\n Comparing [" << temp_first_moo << "] with [" << temp_second_moo << "]\n";
        if (temp_first_moo == temp_second_moo) // if it is the same, checks max
        {
            if (temp_first_moo.size() > longest_overlap)
            {
                longest_overlap = temp_first_moo.size();
                lotext = temp_first_moo;
            }
        }
    }

    cout << longest_overlap << endl; // << lotext
    /*
abcxxxxabcxabcd
abcdxabcxxxxabcx
     */
}