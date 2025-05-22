class MyCircularDeque {
    int size, front, rear, *arr;
public:
    MyCircularDeque(int k) {
        size = k;
        front = rear = -1;
        arr = new int[size];
    }
    
    bool insertFront(int value) {
        if (isFull()) return false; // Full case
        else if (isEmpty()) front = rear = 0; // Empty case
        else if (front == 0 && rear != size - 1) front = size - 1; // Circular case
        else front--; // Normal case
        arr[front] = value; // Insert value
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false; // Full case
        else if (isEmpty()) front = rear = 0; // Empty case
        else if (rear == size - 1 && front != 0) rear = 0; // Circular case
        else rear++; // Normal case
        arr[rear] = value; // Insert value
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        arr[front] = -1; // Clear the value
        if (front == rear) front = rear = -1; // One element case
        else if (front == size - 1) front = 0; // Circular case
        else front++; // Normal case
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        arr[rear] = -1; // Clear the value
        if (front == rear) front = rear = -1; // One element case
        else if (rear == 0) rear = size - 1; // Circular case
        else rear--; // Normal case
        return true;
    }

    int getFront() {
        return isEmpty() ? -1 : arr[front]; // If empty, return -1 else return front;
    }

    int getRear() {
        return isEmpty() ? -1 : arr[rear]; // If empty, return -1 else return rear;
    }

    bool isEmpty() {
        return front == -1 && rear == -1; 
    }
    
    bool isFull() {
        return (front == 0 && rear == size - 1) || (rear == front - 1); 
    }

    ~MyCircularDeque() {
        delete[] arr;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();