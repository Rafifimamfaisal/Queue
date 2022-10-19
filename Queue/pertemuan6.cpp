#include<iostream>
using namespace std;
#define MAX 8

struct Antrian {
    int data[MAX];
    int head;
    int tail;
};

Antrian antre;
void menu(int pil);
void create();
bool isEmpty();
bool isFull();
void enqueue(int);
int dequeue();
void tampil();
bool exit(){
return false;
};
int isi;

int main(){
    create();
    int pilih;
    do{
        cout<<"\n";
        cout<<"[1] Enqueue\n";
        cout<<"[2] Dequeue\n";
        cout<<"[3] Print\n";
        cout<<"[0] Exit\n";
        cout<<"Masukkan Pilihan Anda: ";
        cin>>pilih;
        menu(pilih);
    }
    while (pilih!=0);
}

void menu(int pil){
    switch(pil){
        case 1:
            cout<<"Isi Antrean : ";
            cin>>isi;
            enqueue(isi);break;
        case 2: dequeue();break;
        case 3: tampil();break;
        case 0: exit();break;
        default: cout<<"Pilihan Tidak Ditemukan.\n";
    }
}

void create(){
    antre.head = antre.tail =-1;
}

bool isEmpty(){
    if(antre.tail == -1){
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull(){
    if(antre.tail == MAX - 1){
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(int data){
    if(isEmpty()){
        antre.head = antre.tail = 0;
        antre.data[antre.tail] = data;
    }
    else if(isFull()){
        cout<<"ANTREAN PENUH "<<data<<" tidak dimasukkan\n\n";
    }
    else
    {
        antre.tail++;
        antre.data[antre.tail] = data;
        cout<<data<<" dimasukkan ke antrian\n";
    }

}

int dequeue(){
    if(!isEmpty()){
        int i;
        int e = antre.data[antre.head];
        cout<<antre.data[antre.head];
        for(i = antre.head;i < antre.tail;i++){
            antre.data[i] = antre.data[i+1];
        }
        antre.tail--;
    }
    else
        cout<<" ANTRIAN KOSONG \n";
}

void tampil(){
    if(!isEmpty()){
        for(int i = antre.head;i <= antre.tail;i++){
            cout<<antre.data[i]<<" ";
        }
    }
    else{
        cout<<"data kosong\n";
    }
}
