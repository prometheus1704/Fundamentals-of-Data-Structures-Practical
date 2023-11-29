#include<iostream>
#include<string>

#define MAX 10

using namespace std;

struct QueueStruct {
    string data[MAX];
    int front, rear;
};

class Queue {
    struct QueueStruct q;

public:
    Queue() {
        q.front = q.rear = -1;
    }

    int isEmpty() {
        return q.front == q.rear;
    }

    int isFull() {
        return q.rear == MAX - 1;
    }

    void enqueue(string x) {
        if (!isFull()) {
            q.data[++q.rear] = x;
        } else {
            cout << "\n Queue is full!";
        }
    }

    string dequeue() {
        if (!isEmpty()) {
            return q.data[++q.front];
        } else {
            cout << "\n Queue is empty!";
            return "";
        }
    }

    void display() {
        int i;
        cout<<endl;
        for (i = q.front + 1; i <= q.rear; i++) {
            cout << q.data[i] << " \n";
        }
    }
};

int main() {
    Queue obj;
    int ch;
    string x;
    do {
        cout << "\n 1.Insert Job\n 2.Delete job\n 3.Display\n 4.Exit\n Enter your choice : ";
        cin >> ch;
        switch (ch) {
            case 1:
                if (!obj.isFull()) {
                    cout << "\n Enter the job : ";
                    cin >> x;
                    obj.enqueue(x);
                } else {
                    cout << "\n Queue is full!";
                }
                break;
            case 2:
                if (!obj.isEmpty()) {
                    cout << "\n Deleted job : " << obj.dequeue();
                } else {
                    cout << "\n Queue is empty!";
                }
                cout << "\n Remaining jobs : ";
                obj.display();
                break;
            case 3:
                if (!obj.isEmpty()) {
                    cout << "\nJobs in queue are : ";
                    obj.display();
                } else {
                    cout << "\n Queue is empty!";
                }
                break;
            case 4:
                cout << "\n Exit !!!\n";
                break;
            default:
                cout << "Invalid choice!";
        }
    } while (ch != 4);

    return 0;
}

/*

Output :-

 g++ -o a jobqueue.cpp 
 ./a

 1.Insert Job
 2.Delete job
 3.Display
 4.Exit
 Enter your choice : 1

 Enter the job : Application

 1.Insert Job
 2.Delete job
 3.Display
 4.Exit
 Enter your choice : 1

 Enter the job : Printing

 1.Insert Job
 2.Delete job
 3.Display
 4.Exit
 Enter your choice : 2

 Deleted job : Application
 Remaining jobs : 
 Printing 

 1.Insert Job
 2.Delete job
 3.Display
 4.Exit
 Enter your choice : 3

 Jobs in queue are : 
 Printing 

 1.Insert Job
 2.Delete job
 3.Display
 4.Exit
 Enter your choice : 4
 */
