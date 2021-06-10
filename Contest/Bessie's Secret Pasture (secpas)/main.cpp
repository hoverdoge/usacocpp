// Square pieces of grass with int side lens cut from pasture (0 sided square possible)
// She needs to get 4 grass squares to carve into 1x1 sections to tile her pasture's N square sections

#include <iostream>
#include <cmath>
using namespace std;

int square(int num) {return num * num;}

int main()
{
    int n; int final;
    cin >> n;

    for (int i = 0; square(i) <= n; i++) // i increment as long as i^2 <= n
    {
        for (int j = 0; square(j) + square(i) <= n; j++) // j increment as long as j^2 + i^2 <= n
        {
            for (int k = 0; square(k) + square(i) + square(j) <= n; k++) // k increment as long as k^2 + j^2 + i^2 <= n
            {
                int x = n - square(i) - square(j) - square(k);
                if (square((int)sqrt((double)x))==x) {final++;}
            }
        }
    }

    cout << final << endl;
    return 0;
}