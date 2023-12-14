#include <iostream>
#include <cstring>

using namespace std;

class ClubMember
{
public:
    int prn;
    char name[50];
    ClubMember *next;

    ClubMember(int prn, const char *name)
    {
        this->prn = prn;
        strcpy(this->name, name); // string copy
        next = nullptr;
    }
};

class PinnacleClub
{
private:
    ClubMember *president;
    ClubMember *secretary;

public:
    PinnacleClub()
    {
        president = nullptr;
        secretary = nullptr;
    }

    void addMember(int prn, const char *name)
    {
        ClubMember *newMember = new ClubMember(prn, name);

        if (president == nullptr)
        {
            // If president is not assigned, assign the new member as president
            president = newMember;
            secretary = newMember; // Since there's only one member, assign as secretary too
        }
        else
        {
            // Add the new member at the end
            secretary->next = newMember;
            secretary = newMember;
        }

        cout << "Member added successfully." << endl;
    }

    void deleteMember(int prn)
    {
        ClubMember *current = president;
        ClubMember *previous = nullptr;

        while (current != nullptr && current->prn != prn)
        {
            previous = current;
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Member with PRN " << prn << " not found." << endl;
            return;
        }

        if (previous == nullptr)
        {
            // Deleting the president
            president = current->next;
        }
        else
        {
            previous->next = current->next;
        }

        delete current;

        cout << "Member with PRN " << prn << " deleted successfully." << endl;
    }

    int getTotalMembers()
    {
        int count = 0;
        ClubMember *current = president;

        while (current != nullptr)
        {
            count++;
            current = current->next;
        }

        return count;
    }

    void displayMembers()
    {
        if (president == nullptr)
        {
            cout << "No members in the club." << endl;
            return;
        }

        ClubMember *current = president;

        while (current != nullptr)
        {
            cout << "PRN: " << current->prn << ", Name: " << current->name << endl;
            current = current->next;
        }
    }

    void concatenateLists(PinnacleClub &otherClub)
    {
        if (this->secretary != nullptr && otherClub.president != nullptr)
        {
            this->secretary->next = otherClub.president;
            this->secretary = otherClub.secretary;
            cout << "Lists concatenated successfully." << endl;
        }
        else
        {
            cout << "One or both lists are empty. Concatenation failed." << endl;
        }
    }
};

int main()
{
    PinnacleClub division1;
    PinnacleClub division2;

    int choice, prn, p;
    char name[50];

    do
    {
        cout << "\n1. Add Member\n";
        cout << "2. Delete Member\n";
        cout << "3. Compute Total Members\n";
        cout << "4. Display Members\n";
        cout << "5. Concatenate Lists\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "1.Add member in division 1" << endl;
            cout << "2.Add member in division 2" << endl;
            cin >> p;
            switch (p)
            {
            case 1:
                cout << "Enter PRN: ";
                cin >> prn;
                cout << "Enter Name: ";
                cin.ignore(); // To consume the newline character left in the buffer
                cin.getline(name, 50);
                division1.addMember(prn, name);
                break;
            case 2:
                cout << "Enter PRN: ";
                cin >> prn;
                cout << "Enter Name: ";
                cin.ignore(); // To consume the newline character left in the buffer
                cin.getline(name, 50);
                division2.addMember(prn, name);
                break;
            }
            break;
        case 2:
            cout << "Enter PRN to delete: ";
            cin >> prn;
            division1.deleteMember(prn);
            break;
        case 3:
            cout << "Total Members of div 1: " << division1.getTotalMembers() << endl;
            cout<<"Total Members of div 2: "<<division2.getTotalMembers()<<endl;
            break;
        case 4:
            cout << "1.To display division 1 members: " << endl;
            cout << "2.To display division 2 members: " << endl;
            cin>>p;
            switch (p)
            {
            case 1:
                cout << "Members:\n";
                division1.displayMembers();
                break;
            case 2:
                cout << "Members:\n";
                division2.displayMembers();
                break;
            }
            break;
        case 5:
            division1.concatenateLists(division2);
            break;
        case 6:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
