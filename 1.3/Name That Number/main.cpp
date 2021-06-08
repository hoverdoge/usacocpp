/*
ID: ltjosh22
LANG: C++
TASK: namenum
*/
#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;


int main()
{
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    string givenNumber;
    fin >> givenNumber;
    map <char, int> characterNumbers;

    int amtLettersDone = 0;
    int phoneNumber = 2;
    for (char letter = 'A'; letter < 'Z'; letter++) // maps all characters to integers
    {
        if (letter == 'Q')
        {
            continue;
        }
        if (amtLettersDone < 3)
        {
            amtLettersDone++;
        }
        else if (amtLettersDone == 3) // new number
        {
            phoneNumber++;
            amtLettersDone = 1;
        }

        characterNumbers[letter] = phoneNumber;
    }

    ifstream dictIn ("dict.txt");
    string readName = "";
    string numName = "";

    // sets numName to length of given number
    for (int c = 0; c < givenNumber.length(); c++)
    {
        numName += "-";
    }

    bool validNameFound = false;
    for (int i = 0; i < 5001; i++) // gets number version of name, compares against given number
    {
        // Conditions for terminating loop (no results found/at end of loop)
        if ((i == 5000) && (validNameFound == false)) // if no results found
        {
            fout << "NONE\n"; break;
        }
        else if ((i == 5000) && (validNameFound == true)) // if results found and at end of loop
        {
            break;
        }

        // Gets and compares given dict names
        dictIn >> readName;
        if (readName.length() != givenNumber.length()) // doesn't check too long names
        {
            continue;
        }
        for (int j = 0; j < readName.length(); j++) // gets number version of name
        {
            numName[j] = '0' + characterNumbers[readName[j]];
        }
        if (numName == givenNumber) // if given name is same as current name
        {
            fout << readName << endl;
            validNameFound = true;
        }
    }




}
