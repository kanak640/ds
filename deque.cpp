#include<iostream>
using namespace std;

class queue {
public:
    int arr[10];
    int front = -1;
    int rear = -1;

    bool isfull() {
        return (rear == 10 - 1); // Queue is full when rear reaches max index
    }

    bool isempty() {
        return (front == -1 || front > rear); // Queue is empty when front crosses rear
    }

    void rearEnqueue(int ele) {
        if (isfull()) {
            cout << "Queue full" << endl;
        } else {
            if (isempty()) {
                front = 0; // Reset front to 0
            }
            rear++;
            arr[rear] = ele;
            cout << "Element added successfully" << endl;
        }
        display();
    }

    void frontEnqueue(int ele) {
        if (isfull()) {
            cout << "Queue full" << endl;
        } else {
            if (isempty()) {
                front = 0; // Reset front to 0
            }
            front--;
            arr[front] = ele;
            cout << "Element added successfully" << endl;
        }
        display();
    }

    void frontDequeue() {
        if (isempty()) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Element " << arr[front] << " deleted" << endl;
            front++;
            if (front > rear) { // Reset queue when all elements are dequeued
                front = rear = -1;
            }
        }
        display();
    }

    void rearDequeue() {
        if (isempty()) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Element " << arr[rear] << " deleted" << endl;
            rear--;
        }
        display();
    }

    void display() {
        if (isempty()) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    queue a;
    int n, i, ele;

    cout << "Enter number of elements to initialize the queue (<= 10): ";
    cin >> n;

    if (n > 10 || n < 0) {
        cout << "Invalid number of elements!" << endl;
        return 0;
    }

    cout << "Enter elements to initialize the queue:\n";
    for (i = 0; i < n; i++) {
        cin >> ele;
        a.rearEnqueue(ele);
    }

    int ch;
    do {
        cout << "\nMenu:\n";
        cout << "1.front Add element\n";
        cout << "2.rear Add element\n";
        cout << "3.front Delete element\n";
         cout << "4.rear Delete element\n";
        cout << "5. Display queue\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: "; // FIXED: Added semicolon
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter element to add: ";
                cin >> ele;
                a.frontEnqueue(ele);
                break;

            case 2:
                cout << "Enter element to add: ";
                cin >> ele;
                a.rearEnqueue(ele);
                break;

            case 3:
                a.frontDequeue();
                break;

            case 4:
                a.rearDequeue();
                break;
            case 5:
                a.display();
                break;
            case 6:
                 exit(1);
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (ch != 6);

    return 0;
}
