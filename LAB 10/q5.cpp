#include <iostream>
#include <string>
using namespace std;

template <class T>
class DynamicArray {
protected:
    T* arr;
    int capacity;

public:
    DynamicArray(int size = 5) {
        capacity = size;
        arr = new T[capacity];
    }

    virtual bool isFull() = 0;
    virtual bool isEmpty() = 0;
    virtual int size() = 0;
    virtual T Front() = 0;
    virtual T Rear() = 0;
    virtual void enqueue(T value) = 0;
    virtual void dequeue() = 0;
    virtual void resize() = 0;

    virtual ~DynamicArray() {
        delete[] arr;
    }
};

template <class T>
class Queue : public DynamicArray<T> {
private:
    int front;
    int rear;
    int count;

public:
    Queue(int size = 5) : DynamicArray<T>(size) {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isFull() {
        return count == this->capacity;
    }

    bool isEmpty() {
        return count == 0;
    }

    int size() {
        return count;
    }

    T Front() {
        return this->arr[front];
    }

    T Rear() {
        return this->arr[rear];
    }

    void enqueue(T value) {
        if (isFull()) {
            resize();
        }

        rear = (rear + 1) % this->capacity;
        this->arr[rear] = value;
        count++;

        cout << value << " added to print queue" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No print jobs in queue" << endl;
            return;
        }

        cout << "Printing Job: " << this->arr[front] << endl;

        front = (front + 1) % this->capacity;
        count--;
    }

    void resize() {
        int newCapacity = this->capacity * 2;
        T* temp = new T[newCapacity];

        for (int i = 0; i < count; i++) {
            temp[i] = this->arr[(front + i) % this->capacity];
        }

        delete[] this->arr;
        this->arr = temp;

        front = 0;
        rear = count - 1;
        this->capacity = newCapacity;
    }
};

int main() {
    Queue<string> printerQueue;

    printerQueue.enqueue("Assignment.pdf");
    printerQueue.enqueue("ProjectReport.docx");
    printerQueue.enqueue("CV.pdf");
    printerQueue.enqueue("Presentation.pptx");

    cout << endl;

    while (!printerQueue.isEmpty()) {
        printerQueue.dequeue();
    }

    cout << endl;
    cout << "All print jobs completed" << endl;

    return 0;
}