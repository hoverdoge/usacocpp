#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
    int cow_num, advance_num;
    cin >> cow_num; cin >> advance_num;

    int first_round_votes [cow_num]; int second_round_votes [cow_num]; int advancing_cows [advance_num]; int first_round_votes_original [cow_num]; int second_round_votes_original [cow_num];

    for (int i = 0; i < cow_num; i++)
    {
        cin >> first_round_votes[i]; cin >> second_round_votes[i];
        first_round_votes_original[i] = first_round_votes[i];
        second_round_votes_original[i] = second_round_votes[i];
    }

    // sort first_round_votes

    sort(first_round_votes, first_round_votes + sizeof(first_round_votes) / sizeof(first_round_votes[0]), greater<>());

    // find original indexes of sorted array

    for (int i = 0; i < advance_num; i++)
    {
        int number_to_find = first_round_votes[i];
        for (int j = 0; j < cow_num; j++)
        {
            if (first_round_votes_original[j] == number_to_find)
            {
                advancing_cows[i] = j; // adds original index of number to advancing_cows array
            }
        }
    }

    // make array with only highest second votes of advancing cows
    int advancing_second_votes [advance_num];
    for (int i = 0; i < advance_num; i++)
    {
        advancing_second_votes[i] = second_round_votes[advancing_cows[i]];
    }
    // sorts decreasing
    sort(advancing_second_votes, advancing_second_votes + sizeof(advancing_second_votes) / sizeof(advancing_second_votes[0]), greater<>());
    int winner_second_vote_amt = advancing_second_votes[0];

    // find index from second vote amount
    for (int i = 0; i < advance_num; i++)
    {
        if (second_round_votes[advancing_cows[i]] == winner_second_vote_amt)
        {
            cout << advancing_cows[i] + 1 << endl;
            return 0;
        }
    }


}

/*
5 3
3 10
9 2
5 6
8 4
6 5
 */