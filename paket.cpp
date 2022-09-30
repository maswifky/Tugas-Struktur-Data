#include <iostream>
#include <conio.h>
#include <windows.h>

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

using namespace std;

struct paket
{
    char nama[30];
    char kota[30];
    int berat;
};

struct paket kirim [5];
int datake=1;

bool isEmpty() {
  return datake == 1;
}

bool isFull() {
	return datake == 6;
}

void bersihlayar()
{
    for(int a=0;a<80;a++)
    {
        for(int b=0;b<=24;b++)
        {
            gotoxy(a,b);cout<<" ";
        }
    }
}


void tampildata()
{
    cout<<endl;
    for (int x=datake; x>1; x--)
    {
        cout<<x<<". Nama  = " << kirim[x].nama<< endl;
        cout<<"   Kota  = " <<kirim[x].kota<< endl;
        cout<<"   Berat = " <<kirim[x].berat<<endl;
        cout << endl;
    }
    cout<<endl;
}

void push()
{   if (isFull()) {
    cout << endl;
		cout << "\nTumpukan penuh"<<endl;
	}else {
	    cout << endl;
    cout<<"Inputkan nama  : ";
    cin>>kirim[datake].nama;
    cout<<"Inputkan kota : ";
    cin>>kirim[datake].kota;
    cout<<"Inputkan berat : ";
    cin>>kirim[datake].berat;
    datake++;
    cout << endl;}


}

move()
{
    for(int z=2;z<datake;z++)
    {
        kirim[z-1]=kirim[z];
    }
}

void pop()
{   if (isEmpty()) {
        cout << endl;
		cout << "\nTumpukan kosong"<<endl;
	} else {
	    cout << endl;
    cout<<"Hasil pop "<<endl;
    cout<<" Nama  = " << kirim[1].nama<< endl;
    cout<<" Kota  = " << kirim[1].kota<< endl;
    cout<<" Berat = " << kirim[1].berat<<endl;
    datake--;
    cout<<"Press any key to continue";
    getch();
    cout<<endl;}
}


int main()
{
    int pilih;
    do
    {

        tampildata();
        cout<<"1. push "<<endl;
        cout<<"2. pop "<<endl;
        cout<<"9. Exit"<<endl;
        cout<<"pilihan anda[1-9] :";
        cin>>pilih;
        if (pilih==1) push();
        if (pilih==2) pop();
    }
    while(pilih!=9);
    return 0;
}