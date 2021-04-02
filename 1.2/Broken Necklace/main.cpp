/*
ID: ltjosh22
LANG: C++
TASK: beads
*/
#include <bits/stdc++.h>
#include <map>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");

    int beadNum; string beadString;
    fin >> beadNum; fin >> beadString;
    int maxResult = 0; // index of divider, blueamount, redamount

    for (int i = 0; i < beadNum; i++) // index on number in front of divider
    {
        int colorCount = 0;

        // color before the divider
        int b = ((i-1+beadString.size())) % beadString.size();
        char firstColor = beadString[b];

        // skip over initial white beads
        while (firstColor == 'w')
        {
            colorCount++;
            b = (b-1+beadString.size()) % beadString.size();
            firstColor = beadString[b];
            if (colorCount > beadNum){fout << beadNum << '\n'; return 0;}
        }

        bool foundThird = false;
        while(!foundThird) //behind the divider
        {
            if (beadString[b] != firstColor && beadString[b] != 'w') // when cross to other color, add to the count of colors crossed and sets new limit
            {
                foundThird = true;
            }
            else
            {
                colorCount++;
                if (colorCount > beadNum) {fout << beadNum << '\n'; return 0;}
            }
            b = (b-1+beadString.size()) % beadString.size();
        }

        // color after the divider
        b = i;
        firstColor = beadString[b];

        // skip over initial white beads
        while (firstColor == 'w')
        {
            colorCount++;
            b = (b+1) % beadString.size();
            firstColor = beadString[b];
        }

        foundThird = false;
        while(!foundThird) //in front of the divider
        {
            if (beadString[b] != firstColor && beadString[b] != 'w') // when cross to other color, add to the count of colors crossed and sets new limit
            {
                foundThird = true;
            }
            else
            {
                colorCount++;
                if (colorCount > beadNum) {fout << beadNum << '\n'; return 0;}
            }
            b = (b+1) % beadString.size();
        }
        maxResult = max(maxResult, colorCount);
        //cout << "\n\n" << maxResult << "\n\n";
    }
    fout << maxResult << '\n';
}
