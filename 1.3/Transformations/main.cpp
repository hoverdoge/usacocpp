/*
ID: ltjosh22
LANG: C++
TASK: transform
*/
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int rotationCheck(string, string, int, int);
bool patternChanged(string, string, int);
string reflectCheck(string, string, int, bool=false);
bool comboCheck(string, string, int);

int main()
{
    /*
    input handling
    */
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    int squareLength; fin >> squareLength;
    int squareCharacters = squareLength * squareLength;

    string originalSquare; string afterSquare;
    string originalSqTemp; string afterSqTemp;

    bool notOriginal = false;
    for (int c = 0; c < 2; c++)
    {
        for (int i = 0; i < squareLength; i++)
        {
            if (notOriginal == true){fin >> afterSqTemp; afterSquare += afterSqTemp;}
            else{fin >> originalSqTemp; originalSquare += originalSqTemp;}
        }
        notOriginal = true;
    }

    /*
    3
    @-@
    ---
    @@-

    @-@
    @--
    --@


    first 3 become #3, 6, 9
    middle 3 become #2, 5, 8
    last 3 become #1, #4, #7


    */

    if (patternChanged(originalSquare, afterSquare, squareLength) == false) // if unchanged
    {
        fout << 6 << endl;
        return 0;
    }

    switch(rotationCheck(originalSquare, afterSquare, squareLength, 0))
    {
        case 0:
            fout << 1 << endl;
            return 0;
        case 1:
            fout << 2 << endl;
            return 0;
        case 2:
            fout << 3 << endl;
            return 0;
        default:
            break;
    }

    if (reflectCheck(originalSquare, afterSquare, squareLength) == "yes") // if reflected
    {
        fout << 4 << endl;
        return 0;
    }

    if (comboCheck(originalSquare, afterSquare, squareLength) == true)
    {
        fout << 5 << endl;
        return 0;
    }

    fout << 7 << endl;
    return 0;
}


int rotationCheck(string originalSquare, string afterSquare, int squareLength, int timesRotated) // checks for 90 and 180 deg and 270 rotation - 5 means not any. 0 means 90 1 is 180 2 270
{

    if (timesRotated >= 3) {
        return 5;
    }

    int sqArea = squareLength * squareLength;
    string rotatedArr;
    rotatedArr.reserve(sqArea);

    int counter = 0;
    for (int row = 0; row < squareLength; row++) // row number
    {
        int offset = squareLength - (row + 1);
        for (int column = 0; column < squareLength; column++) // column number
        {
            if (counter > squareLength * squareLength)
            {
                break;
            }
            cout << originalSquare[row * squareLength + column] << ' ' << offset << '\n';
            rotatedArr[offset] = originalSquare[row * squareLength + column];
            offset += squareLength;
            counter++;
        }
        if (counter > squareLength * squareLength)
        {
            break;
        }
        // orig   0, 1, 2, 3, 4, 5, 6, 7, 8
        // rotate 2, 5, 8, 1, 4, 7, 0, 3, 6
    }


    for (int i = 0; i < 9; i++)
    {
        if (rotatedArr[i] != afterSquare[i]) // if not 90deg
        {
            //rotate another 90 deg
            if (rotationCheck(rotatedArr, afterSquare, squareLength, timesRotated+1) != 5)
            {
                //if returns 1 for 180]
                return rotationCheck(rotatedArr, afterSquare, squareLength, timesRotated+1);

            } else { return 5; }
        }
    }
    return timesRotated;
}

bool patternChanged(string originalSquare, string afterSquare, int squareLength)
{
    if (originalSquare.compare(afterSquare) == 0)
    {
        return false;
    }
    return true;
}

string reflectCheck (string originalSquare, string afterSquare, int squareLength, bool comboChecking) // reverse order of each row, check against afterSquare
{
    string temp = "";
    string reflectedOriginal = "";
    for (int i = 0; i < squareLength * squareLength - 1; i += squareLength) // goes by row
    {
        for (int j = 0; j < squareLength; j++)
        {
            temp += originalSquare[j + i];
        }

        reverse(temp.begin(), temp.end());
        reflectedOriginal += temp;
        temp = "";
    }

    if (comboChecking == true)
    {
        return reflectedOriginal;
    }

    for (int i = 0; i < squareLength * squareLength - 1; i++)
    {
        if (reflectedOriginal[i] != afterSquare[i]) // if not reflected
        {
            return "no";
        }
    }
    return "yes";
}

bool comboCheck(string originalSquare, string afterSquare, int squareLength)
{
    string reflectedOriginal = reflectCheck(originalSquare, afterSquare, squareLength, true);

    switch(rotationCheck(reflectedOriginal, afterSquare, squareLength, 0))
    {
        case 0:
        case 1:
        case 2:
            return true;
        default:
            return false;
            break;
    }
}

/*
 Here are the respective outputs:
----- our output ---------
2
---- your output ---------
1
--------------------------

------ Data for Run 3 [length=62 bytes] ------
5
@@@@@
@---@
@@@@@
@@@@@
@@@@@

@@@@@
@@@@@
@@@@@
@---@
@@@@@
----------------------------

@_4
@_7
@_10
@_13
@_16
@_3
-_6
-_9
-_12
@_15
@_2
@_5
@_8
@_11
@_14
@_1
@_4
@_7
@_10
@_13
@_0
@_3
@_6
@_9
@_12
*/




/* old

bool reflectCheck (string originalSquare, string afterSquare, int squareLength, int timesRotated) // for even: checks last col of original against first col of after, progresses
{
	int sqArea = squareLength * squareLength;
	int offset = squareLength - 1; 
	if (squareLength % 2 == 0) // even number
	{
		for (int i = offset; i >= 0; i--) // goes backwards in columns
		{
			for (int j = i; j < i + squareLength * 2; j+=squareLength) // goes top down in rows for each column
			{

			}
		}
	}
}
*/