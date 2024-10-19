//PHONEBOOK MANAGEMENT SYSTEM
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10
#define MAX_LENGTH 20

int count = 0;

struct contact {
    char name[MAX_LENGTH];
    int number;
};

struct contact obj[SIZE];

void AddContact()           // Add contact to the phonebook
{
    if (count >= SIZE) 
    {
        printf("Phonebook is full\n");
    } 
    else
     {
        printf("\nEnter the contact name:\n");
        scanf("%s", obj[count].name); // Use count index to add new contact
        printf("\nEnter the contact number:\n");
        scanf("%d", &obj[count].number); // Store number directly
        count++;
        printf("NEW CONTACT ADDED!!!!\n");
    }
}

void DeleteContact()
 {
    if (count == 0) 
    {
        printf("\nPhonebook is empty\n");
        return;
    }
    
    char name[MAX_LENGTH];
    printf("\nEnter the name you want to delete:\n");
    scanf("%s", name);
    
    for (int i = 0; i < count; i++) 
    {
        if (strcmp(obj[i].name, name) == 0)  // Compare names correctly
        { 
            printf("\nDeleted contact: Name=%s, Number=%d\n", obj[i].name, obj[i].number);
            // Shift contacts to fill the deleted space
            for (int j = i; j < count - 1; j++)
             {
                obj[j] = obj[j + 1];
            }
            count--;
            printf("CONTACT DELETED!!!!\n");
            return; // Exit after deletion
        }
    }
    printf("Contact not found.\n"); // If the contact was not found
}

void DisplayContacts() 
{
    if (count == 0) 
    {
        printf("\nPhonebook is empty\n");
    }
     else 
    {
        printf("\nCONTACTS:\n");
        for (int i = 0; i < count; i++)
        {
            printf("Name: %s, Number: %d\n", obj[i].name, obj[i].number);
        }
    }
}

int main() {
    while (1) {
        int choice;
        printf("\n1. ADD CONTACT\n2. DELETE CONTACT\n3. DISPLAY CONTACTS\n4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
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
                printf("\nInvalid choice\n");
        } 
    }
}
