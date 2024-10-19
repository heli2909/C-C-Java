
package project;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

class Contact {
    String name;
    String number;

    Contact(String name, String number) {
        this.name = name;
        this.number = number;
    }
}

class Phonebook {
    private ArrayList<Contact> contacts;

    public Phonebook() {
        contacts = new ArrayList<>();
    }

    public void addContact() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("\nEnter the contact name:\n");
        String name = scanner.nextLine();
        System.out.print("\nEnter the contact number:\n");
        String number = scanner.nextLine();
        contacts.add(new Contact(name, number));
        System.out.println("NEW CONTACT ADDED!!!!");
    }

    public void deleteContact() {
        if (contacts.isEmpty()) {
            System.out.println("\nPhonebook is empty\n");
            return;
        }

        Scanner scanner = new Scanner(System.in);
        System.out.print("\nEnter the name you want to delete:\n");
        String name = scanner.nextLine();

        Iterator<Contact> iterator = contacts.iterator();
        boolean found = false;

        while (iterator.hasNext()) {
            Contact contact = iterator.next();
            if (contact.name.equalsIgnoreCase(name)) { // Case-insensitive comparison
                System.out.printf("\nDeleted contact: Name=%s, Number=%s\n", contact.name, contact.number);
                iterator.remove();
                found = true;
                System.out.println("CONTACT DELETED!!!!");
            }
        }

        if (!found) {
            System.out.println("Contact not found.");
        }
    }

    public void displayContacts() {
        if (contacts.isEmpty()) {
            System.out.println("\nPhonebook is empty\n");
        } else {
            System.out.println("\nCONTACTS:");
            for (Contact contact : contacts) {
                System.out.printf("Name: %s, Number: %s\n", contact.name, contact.number);
            }
        }
    }
}

public class pro1 {
    public static void main(String[] args) {
        Phonebook phonebook = new Phonebook();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("\n1. ADD CONTACT\n2. DELETE CONTACT\n3. DISPLAY CONTACTS\n4. EXIT");
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            switch (choice) {
                case 1:
                    phonebook.addContact();
                    break;
                case 2:
                    phonebook.deleteContact();
                    break;
                case 3:
                    phonebook.displayContacts();
                    break;
                case 4:
                    System.exit(0);
                default:
                    System.out.println("\nInvalid choice\n");
            }
        }
    }
        
}
