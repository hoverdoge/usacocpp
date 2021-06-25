#include <iostream>

using namespace std;


int main() {
    // input handling
    int num_cows, bessie_index, swap_count = 0; bool found_wrong = false;
    cin >> num_cows;
    int cow_arr[num_cows];

    for (int i = 0; i < num_cows; i++) {
        cin >> cow_arr[i];
    }

    while (true) {
        found_wrong = false;
        // gets Bessie's location
        for (int i = 0; i < num_cows; i++) {
            if ((i - 1 >= 0) && cow_arr[i] < cow_arr[i - 1]) // if bigger than the next one || smaller than the previous one
            {
                found_wrong = true;
                bessie_index = i;
                cout << bessie_index;
            }
        }

        if (!found_wrong)
        {
            cout << swap_count;
            break;
        }

        for (int i = 0; i < num_cows; i++) { // finds which to swap with
            if (i - 1 >= 0 && i + 1 > 0) // if exists
            {
                if (cow_arr[i - 1] <= cow_arr[i] <= cow_arr[i + 1]) // if >= previous and <= next (if found a spot)
                {
                    int temp = cow_arr[i]; // swaps
                    cow_arr[i] = cow_arr[bessie_index];
                    cow_arr[bessie_index] = temp;
                    swap_count++;
                }
            }
        }
    }
}