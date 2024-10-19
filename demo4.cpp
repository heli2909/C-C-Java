//Phonebook managament

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_LENGTH 20

class Contact {
public:
    string name;
    int number;

    Contact(string n, int num) {
        name = n;
        number = num;
    }
};

vector<Contact> phonebook;

void AddContact() {
    if (phonebook.size() >= 10) {
        cout << "Phonebook is full" << endl;
    } else {
        string name;
        int number;
        cout << "\nEnter the contact name:" << endl;
        cin >> name;
        cout << "\nEnter the contact number:" << endl;
        cin >> number;
        phonebook.push_back(Contact(name, number));
        cout << "NEW CONTACT ADDED!!!!" << endl;
    }
}

void DeleteContact() {
    if (phonebook.empty()) {
        cout << "\nPhonebook is empty" << endl;
        return;
    }

    string name;
    cout << "\nEnter the name you want to delete:" << endl;
    cin >> name;

    auto it = remove_if(phonebook.begin(), phonebook.end(),
                        [name](Contact& contact) { return contact.name == name; });

    if (it != phonebook.end()) {
        cout << "\nDeleted contact: Name=" << it->name << ", Number=" << it->number << endl;
        phonebook.erase(it, phonebook.end());
        cout << "CONTACT DELETED!!!!" << endl;
    } else {
        cout << "Contact not found." << endl;
    }
}

void DisplayContacts() {
    if (phonebook.empty()) {
        cout << "\nPhonebook is empty" << endl;
    } else {
        cout << "\nCONTACTS:\n";
        for (const auto& contact : phonebook) {
            cout << "Name: " << contact.name << ", Number: " << contact.number << endl;
        }
    }
}

int main() {
    while (true) {
        int choice;
        cout << "\n1. ADD CONTACT\n2. DELETE CONTACT\n3. DISPLAY CONTACTS\n4. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                AddContact();
                break;
            case 2:
                DeleteContact();
                break;
            case 3:
                DisplayContacts();
                break;
            case 4:
                exit(0);
            default:
                cout << "\nInvalid choice" << endl;
        }
    }
}
