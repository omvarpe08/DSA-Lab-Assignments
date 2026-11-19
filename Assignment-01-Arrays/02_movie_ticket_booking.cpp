#include <iostream>
using namespace std;
int main() {
    int seats[10] = {0};
    int choice, seatNo;
    do {
        cout << "\n--- Movie Ticket Booking System ---\n";
        cout << "1. Display Seats\n2. Book Ticket\n3. Cancel Ticket\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "\nSeat Status (0 = Available, 1 = Booked):\n";
            for (int i = 0; i < 10; i++)
                cout << "Seat " << i + 1 << ": " << seats[i] << endl;
            break;
        case 2:
            cout << "Enter seat number to book (1-10): ";
            cin >> seatNo;
            if (seatNo >= 1 && seatNo <= 10) {
                if (seats[seatNo - 1] == 0) {
                    seats[seatNo - 1] = 1;
                    cout << "Ticket booked successfully!\n";
                } else cout << "Seat is already booked.\n";
            } else cout << "Invalid seat number.\n";
            break;
        case 3:
            cout << "Enter seat number to cancel (1-10): ";
            cin >> seatNo;
            if (seatNo >= 1 && seatNo <= 10) {
                if (seats[seatNo - 1] == 1) {
                    seats[seatNo - 1] = 0;
                    cout << "Ticket cancelled successfully!\n";
                } else cout << "Seat is already available.\n";
            } else cout << "Invalid seat number.\n";
            break;
        case 4:
            cout << "Thank you!\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 4);
    return 0;
}
