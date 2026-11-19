#include <iostream>
#include <string>
using namespace std;

struct Node {
    int seatNo;
    string name;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void reserveSeat() {
    Node* newNode = new Node();
    cout << "Enter Seat Number: ";
    cin >> newNode->seatNo;
    cout << "Enter Passenger Name: ";
    cin >> newNode->name;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    cout << "Seat reserved successfully.\n";
}

void displayForward() {
    if (head == NULL) {
        cout << "No reservations found.\n";
        return;
    }
    Node* temp = head;
    cout << "\nReservations:\n";
    while (temp != NULL) {
        cout << "Seat No: " << temp->seatNo << endl;
        cout << "Passenger: " << temp->name << endl;
        temp = temp->next;
    }
}

void displayBackward() {
    if (head == NULL) {
        cout << "No reservations found.\n";
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    cout << "\nReservations in Reverse:\n";
    while (temp != NULL) {
        cout << "Seat No: " << temp->seatNo << endl;
        cout << "Passenger: " << temp->name << endl;
        temp = temp->prev;
    }
}

void cancelReservation() {
    int seat;
    cout << "Enter Seat Number to cancel: ";
    cin >> seat;
    Node* temp = head;
    while (temp != NULL && temp->seatNo != seat)
        temp = temp->next;
    if (temp == NULL) {
        cout << "Reservation not found.\n";
        return;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    delete temp;
    cout << "Reservation cancelled successfully.\n";
}

int main() {
    int choice;
    do {
        cout << "1. Reserve Seat\n";
        cout << "2. Display Reservations\n";
        cout << "3. Display Reverse\n";
        cout << "4. Cancel Reservation\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: reserveSeat(); break;
        case 2: displayForward(); break;
        case 3: displayBackward(); break;
        case 4: cancelReservation(); break;
        case 5: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice.\n";
        }
    } while (choice != 5);
    return 0;
}
