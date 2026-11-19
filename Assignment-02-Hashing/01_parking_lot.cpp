#include <iostream>
using namespace std;
int main() {
    int slots, n;
    cout << "Enter number of parking slots: ";
    cin >> slots;
    int parking[slots];
    for (int i = 0; i < slots; i++) parking[i] = -1;

    cout << "Enter number of vehicles: ";
    cin >> n;
    // Hashing with linear probing
    for (int i = 0; i < n; i++) {
        int carNumber;
        cout << "Enter vehicle registration number: ";
        cin >> carNumber;
        int index = carNumber % slots;
        int start = index;
        while (parking[index] != -1) {
            index = (index + 1) % slots;
            if (index == start) {
                cout << "Parking lot is full!" << endl;
                break;
            }
        }
        if (parking[index] == -1) {
            parking[index] = carNumber;
            cout << "Vehicle parked at slot " << index + 1 << endl;
        }
    }
    cout << "\n--- Parking Lot ---" << endl;
    for (int i = 0; i < slots; i++) {
        if (parking[i] == -1) cout << "Slot " << i + 1 << ": Empty" << endl;
        else cout << "Slot " << i + 1 << ": " << parking[i] << endl;
    }
    return 0;
}
