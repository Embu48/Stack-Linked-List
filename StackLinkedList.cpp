#include <iostream>
#include <windows.h>
#define KUOTA_STACK 10
using namespace std;

struct TNode{
	int data;
	TNode *next;
};

TNode *head;

bool isEmpty(){
	return head == NULL;
}

bool isFull(){
	TNode *bantu;
	int f;
	bantu = head;
	while (bantu != '\0'){
		f++;
		bantu = bantu->next;
	}
	return f > KUOTA_STACK-1;
}

class MyStack{
    public:
    int getTop(){
    	return head->data;
	}
    void push(int databaru){
		TNode *baru;
		baru = new TNode;
		baru->data = databaru;
		baru->next = NULL;
		if(isEmpty() == 1){
			baru->next = head;
			head = baru;
		}
		else{
			baru->next = head;
			head=baru;
		}
		cout<<"Nilai "<<getTop()<<" masuk\n";
	}
    void pop(){
    	TNode *hapus;
		int d;
		hapus = head;
		d = getTop();
		head = head->next;
		delete hapus;
		cout<<endl<<d<<" terambil\n";
    }
};

void printStackList(){
    	TNode *bantu;
		bantu = head;
		int f = 0;
			while(bantu != '\0'){
				bantu = bantu->next;
				f++;
			}
			for(int x=f;x<KUOTA_STACK;x++){
				cout<<"| 	|\n";
			}
			bantu = head;
			while(bantu != '\0'){
				cout<<"| "<<bantu->data<<"\t|\n";
				bantu = bantu->next;
			}
			cout<<"---------\n";
} 

void menu(){
    char pilih, ulang;
    int data;
    MyStack s;

    do{
      	system("cls");
      	cout<<"STACK SINGLE LINKED LIST \n------------------------\n\n";
      	printStackList();
      	cout<<"\nMenu : \n1. Isi\n2. Pop\n3. Keluar\n>>";
      	cin>>pilih;

      	switch(pilih){
      		case '1' :
      			if(isFull() == 0){
      				cout<<"\nMasukkan data : ";
            		cin>>data;
            		s.push(data);
            		}
				else
					cout<<"\nStack penuh!\n";
				break;
      		case '2' :
      			if (isEmpty() == 0){
				  	s.pop();
      			}
      			else
      				cout<<"\nStack masih kosong!\n";
            		break;
      		case '3' :
      			exit(0);
            		break;
      		default :
            		cout<<"\nPilih ulang"<<endl;
      	}
      	cout<<"\nKembali ke menu?(y/n)\n>>";
      	cin>>ulang;
    }
	while(ulang=='y' || ulang=='Y');
}

int main(){
    menu();
    return 0;
}
