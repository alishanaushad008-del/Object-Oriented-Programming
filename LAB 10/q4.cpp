#include <iostream>
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
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }

        cout << "Dequeued: " << this->arr[front] << endl;
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
    Queue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout << "Front: " << q.Front() << endl;
    cout << "Rear: " << q.Rear() << endl;
    cout << "Size: " << q.size() << endl;

    q.dequeue();
    q.dequeue();

    cout << "Front after dequeue: " << q.Front() << endl;
    cout << "Size after dequeue: " << q.size() << endl;

    return 0;
}