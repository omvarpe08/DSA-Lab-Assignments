#include <iostream>
#include <string>
using namespace std;

struct Node {
    string song;
    Node* next;
};

Node* head = NULL;

void addSong() {
    Node* newNode = new Node;
    cout << "Enter song name: ";
    cin >> newNode->song;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
    cout << "Song added successfully.\n";
}

void displaySongs() {
    if (head == NULL) {
        cout << "Playlist is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "\nPlaylist:\n";
    do {
        cout << temp->song << endl;
        temp = temp->next;
    } while (temp != head);
}

void deleteSong() {
    if (head == NULL) {
        cout << "Playlist is empty.\n";
        return;
    }
    string song;
    cout << "Enter song to delete: ";
    cin >> song;

    Node* temp = head;
    Node* prev = NULL;
    do {
        if (temp->song == song)
            break;
        prev = temp;
        temp = temp->next;
    } while (temp != head);

    if (temp->song != song) {
        cout << "Song not found.\n";
        return;
    }
    if (temp == head && temp->next == head) {
        head = NULL;
    } else if (temp == head) {
        Node* last = head;
        while (last->next != head)
            last = last->next;
        head = head->next;
        last->next = head;
    } else {
        prev->next = temp->next;
    }
    delete temp;
    cout << "Song deleted successfully.\n";
}

int main() {
    int choice;
    do {
        cout << "1. Add Song\n";
        cout << "2. Display Songs\n";
        cout << "3. Delete Song\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1: addSong(); break;
        case 2: displaySongs(); break;
        case 3: deleteSong(); break;
        case 4: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);
    return 0;
}
