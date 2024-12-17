#include <iostream>
using namespace std;

class CircularQueue {
public:
    int arr[20];
    int front, rear;
    int n = 10; // Fixed queue size

    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Check if queue is full
    bool isFull() {
        return ((rear + 1) % n == front);
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Enqueue operation
    void enqueue(int ele) {
        if (isFull()) {
            cout << "Queue is full. Cannot insert element: " << ele << endl;
            return;
        }

        if (isEmpty()) { // First element to be inserted
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % n;
        }
        arr[rear] = ele;
        cout << "Inserted: " << ele << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to delete." << endl;
            return;
        }

        int deleted = arr[front];
        if (front == rear) { // Last element is being removed
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % n;
        }
        cout << "Deleted element: " << deleted << endl;
    }

    // Display the elements of the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to display." << endl;
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break; // End when rear is reached
            i = (i + 1) % n;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int ch, ele;

    do {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display elements\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> ele;
                q.enqueue(ele);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (ch != 4);

    return 0;
}
