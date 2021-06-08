// circle shaped barn, with ring of N rooms numbered clockwise from 1...n around perimeter (>3)
// each room has doors to 2 neighboring rooms, door opening to exterior
// ri cows end up in each room 
// cows go through exterior door of a room, cows enter, and walk clockwise until reach suitable destination
// must find exterior door allowing cows to collectively walk minimum distance
// return minimum amt of distance

#include <iostream>

using namespace std;
int main()
{
    int amount_rooms;
    cin >> amount_rooms;
    int rooms[amount_rooms]; int sum = 0; int min = 100000000;

    for (int i = 0; i < amount_rooms; i++)
    {
        cin >> rooms[i];
    }

    for (int starting_room = 0; starting_room < amount_rooms; starting_room++)
    {
        sum = 0;
        int count = 0;
        for (int room_on = starting_room; room_on < starting_room + amount_rooms; room_on++)
        {
            int room_to_add = room_on;
            if (room_on >= amount_rooms) // wraps around
            {
                room_to_add -= amount_rooms;
            }
            //cout << "Room on: " << room_to_add << endl;
            //cout << "Adding " << rooms[room_to_add] << "*" << count << " to sum of " << sum;
            sum += rooms[room_to_add] * count;
            //cout << "-> " << sum << endl;
            count++;
        }
        //cout << "Final sum is " << sum << " and min is " << min << endl;
        if (sum < min)
        {
            //cout << "e";
            min = sum;
        }
        //cout << "-----------ROOM COMPLETED--------------" << endl;
    }
    cout << min << endl;
    return 0;
}

// 5 4 7 8 6 4