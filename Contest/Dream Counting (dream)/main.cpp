#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    // input is inclusive
    long m, n;
    cin >> m; cin >> n;

    int digits_arr [10]; vector <int> number_storage;

    for (int & i : digits_arr)
    {
        i = 0;
    }


    for (int number_on = m; number_on <= n; number_on++) // put digits of all numbers into vector
    {
        int temp_number_on = number_on;

        int number_digits = log10(temp_number_on) + 1;
        //int number_digits = (to_string(temp_number_on_2)).length();



        for (int i = 0; i < number_digits; i++)
        {
            // number_storage.push_back(temp_number_on%10);
            int digit = temp_number_on%10;
            switch (digit)
            {
                case 0:
                    digits_arr[0]++;
                    break;
                case 1:
                    digits_arr[1]++;
                    break;
                case 2:
                    digits_arr[2]++;
                    break;
                case 3:
                    digits_arr[3]++;
                    break;
                case 4:
                    digits_arr[4]++;
                    break;
                case 5:
                    digits_arr[5]++;
                    break;
                case 6:
                    digits_arr[6]++;
                    break;
                case 7:
                    digits_arr[7]++;
                    break;
                case 8:
                    digits_arr[8]++;
                    break;
                case 9:
                    digits_arr[9]++;
                    break;
                default:
                    cout << "error";
                    break;
            }
            temp_number_on /= 10;
        }

    }



    for (int i : digits_arr)
    {
        cout << i << " ";
    }
    cout << endl;

}


// 204857327 205341273
