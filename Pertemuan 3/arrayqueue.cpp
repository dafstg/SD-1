#include <iostream>
using namespace std;

#define MAX 6
int queue[MAX];
int front = -1, rear = -1; 

// TODO : Enqueue
void enqueue( int value ) {
    if (rear == MAX - 1){
    cout << "Queue Penuh"<<endl;}
    else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = value;
        cout << value << " masuk dalam queue" << endl;
    }
}

// TODO : Dequeue
void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Kosong !"<< endl;
    }
    else {
        cout << queue[front] << " Keluar dari queue" << endl;
        front++;
    }
}

// TODO : Nampilin isi queue
void display() {
    if (front == -1 || front > rear){
        cout << "Queue Kosong"<<endl;
    }
    else {
        cout << "Isi queue : ";
        for (int i = front; i <= rear; i++){
            cout << queue[i];
        }
        cout << endl;
    }
}

int main () {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    display();

    enqueue(6);
    display();

    dequeue();
    display();

    return 0;
}