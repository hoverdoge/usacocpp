/*
ID: ltjosh22
LANG: C++
TASK: milk2
*/
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
	/*
	input handling
	*/
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    int numOfFarmers;
    fin >> numOfFarmers;

	map<int, int> milkTimes; //tracks all milk times from input

	int startTime; int endTime; // for inputs
	vector <int> milkTimesArr; // array with keys for easy map print

	// if there is only one farmer/cow
	if (numOfFarmers == 1)
	{
		int edgeStart; int edgeEnd; fin >> edgeStart; fin >> edgeEnd;
		fout << edgeEnd - edgeStart << " " << 0 << "\n";
		return 0;
	}

    // puts in inputted values
	for (int timeSetsInserted = 0; timeSetsInserted <= numOfFarmers; timeSetsInserted++)
	{
		fin >> startTime; fin >> endTime;
        // if startTime already exists in map, replace milkTimes[startTime] with the max(endTime, milkTimes[startTime])
		if (milkTimes.count(startTime) > 0)
		{
            milkTimes[startTime] = max(endTime, milkTimes[startTime]);
        } else {
            milkTimes[startTime] = endTime;
        }
		milkTimesArr.push_back(startTime);
	}

	/*
	sorts array
	*/
	int n = sizeof(milkTimesArr) / sizeof(milkTimesArr[0]);
	sort(milkTimesArr.begin(), milkTimesArr.end());

    // for (int n : milkTimesArr) {
	// 	fout << n << " " << milkTimes[n] << "\n";
	// }

	int milkStart; int milkEnd;
    int prevMilkStart; int prevMilkEnd;

    // MERGE START
    int i = 0;
	while (i < milkTimesArr.size())
	{
		milkStart = milkTimesArr[i];
        milkEnd = milkTimes[milkTimesArr[i]];

		if (i != 0)
		{
			prevMilkStart = milkTimesArr[i-1];
			prevMilkEnd = milkTimes[milkTimesArr[i-1]];

            // if in middle of previous interval, remove redundant interval
			if (prevMilkEnd >= milkStart && milkStart >= prevMilkStart)
			{
					if (milkEnd > prevMilkEnd) //merge prevMilkStart -> milkEnd
					{
							milkTimes[prevMilkStart] = milkEnd;
					}
					// remove entire redundant interval from vector
					milkTimesArr.erase(milkTimesArr.begin() + i);
                    i--;
			}
		}
        i++;
    }// MERGE END

    /* FOR PRINTING MAP */
	for (int n : milkTimesArr) {
		cout << n << " " << milkTimes[n] << "\n\n";
	}

    int maxGap = 0;
    int maxInterval = 0 ;
    for (int i = 0; i < milkTimesArr.size(); i++)//prints map
	{
        if (milkTimes[milkTimesArr[i]] - milkTimesArr[i] > maxInterval) {
            maxInterval = milkTimes[milkTimesArr[i]] - milkTimesArr[i];
        }

        if (i > 0 && milkTimesArr[i] - milkTimes[milkTimesArr[i-1]] > maxGap) {
            maxGap = milkTimesArr[i] - milkTimes[milkTimesArr[i-1]];
        }
		cout << maxInterval << " " << maxGap << endl;
	}
    fout << maxInterval << " " << maxGap << "\n";
}