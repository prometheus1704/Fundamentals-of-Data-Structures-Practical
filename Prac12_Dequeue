#include<iostream>
using namespace std;
#define size 5

class Dqueue {
    int arr[size];
    int front, rear;

public:
    Dqueue();
    void insertRear(int);
    void insertFront(int);
    int removeRear();
    int removeFront();
    int isFullrear();
    int isFullfront();
    int isEmpty();
    void display();
};

Dqueue::Dqueue() {
    front = rear = -1;
}

int Dqueue::isEmpty() {
    return (front == -1 && rear == -1);
}

int Dqueue::isFullrear() {
    return (rear == size - 1);
}

int Dqueue::isFullfront() {
    return (front == 0);
}

void Dqueue::insertRear(int x) {
    if (!isFullrear()) {
        if (rear == -1 && front == -1) {
            rear = front = 0;
            arr[rear] = x;
        } else {
            rear++;
            arr[rear] = x;
        }
    } else {
        cout << "Overflow Operation" << endl;
    }
}

void Dqueue::insertFront(int x) {
    if (!isFullfront()) {
        if (rear == -1 && front == -1) {
            rear = front = 0;
            arr[front] = x;
        } else {
            front--;
            arr[front] = x;
        }
    } else {
        cout << "Overflow Operation" << endl;
    }
}

int Dqueue::removeRear() {
    int x;
    if (!isEmpty()) {
        if (rear == front) {
            x = arr[rear];
            rear = front = -1;
        } else {
            x = arr[rear];
            rear--;
        }
    } else {
        cout << "Underflow Operation" << endl;
    }
    return x;
}

int Dqueue::removeFront() {
    int x;
    if (!isEmpty()) {
        if (rear == front) {
            x = arr[front];
            rear = front = -1;
        } else {
            x = arr[front];
            front++;
        }
    } else {
        cout << "Underflow Operation" << endl;
    }
    return x;
}

void Dqueue::display() {
    int i;
    cout << " ";
    for (i = front; i <= rear; i++) {
        cout << arr[i] << endl;
    }
}

int main() {
    Dqueue dq;
    int data, choice;
    do {
        cout << " 1. Insert From Rear" << endl;
        cout << " 2. Insert From Front" << endl;
        cout << " 3. Remove From Rear" << endl;
        cout << " 4. Remove From Front" << endl;
        cout << " 5. Show all" << endl;
        cout << " 6. Exit" << endl;
        cout << " Enter choice:" << endl;
        std::cin >> choice;

        switch (choice) {
            case 1:
                cout << "\n Enter data:" << endl;
                std::cin >> data;
                dq.insertRear(data);
                break;
            case 2:
                cout << "\n Enter data:" << endl;
                std::cin >> data;
                dq.insertFront(data);
                break;
            case 3:
                cout << "\n The element removed from rear of Q is : "
                          << dq.removeRear()<<endl;
                break;
            case 4:
                cout << "\n The element removed from Front of Q is : "
                          << dq.removeFront()<<endl;
                break;
            case 5:
                cout << "\n The element of Q are : " << endl;
                dq.display();
                break;
            case 6:
                cout << "\n Exit !!!\n";
                break;
            default:
                cout << "Invalid choice !";
        }
    } while (choice != 6);

    return 0;
}
