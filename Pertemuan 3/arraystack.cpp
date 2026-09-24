#include <iostream>
using namespace std;

#define MAX 5 
int stack[MAX]; 
int top = -1; 

// TODO : Operasi Push
void push (int value) {
    if (top == MAX - 1){
        cout << "Stack Penuh !" << endl;
    }
    else {
        top++;
        stack[top] = value;
        cout << value << " Ditambahkan dalam stack" << endl;
    }
}

// TODO : Operasi Pop
void pop (){
    if (top == -1) {
        cout << "Stacknya masih kosong" << endl;
    }
    else {
        cout << endl << stack[top]<< " dihapus dari stack" << endl;
        top--;
    }
}

// TODO : Nampilin Stack
void display() {
    if (top == -1) {
        cout << "Stack kosong" << endl;
    }
    else {
        cout << "Isi dari stack : "<<endl;
        for (int i = top; i>=0; i--){
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main (){
    push(50);
    push(40);
    push(30);
    push(20);
    push(10);

    display();
    pop();
    display;

    return 0;
}