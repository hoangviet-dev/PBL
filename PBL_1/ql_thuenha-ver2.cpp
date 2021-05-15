#include <iostream>
#include <conio.h>		//getch();
#include <fstream>
#include<string>
using namespace std;

struct KH{
     char name[50];
     char address[100];
     char birthday [30];
     char phone[30];
     char ngaythue[30]; //ngay KH bat dau thue
     char ngaytra[30];
     int sttp;
} kh;

void infor_room();
void status_room();
void booked_check(int room);
void book_room();
void record_kh(struct KH, fstream &); // ghi thong tin kh vao file
void edit_room();
void del_room();
void list_book();        //Danh sach KH thue

int main(){
     int tuychon;
     system("cls");
     do
     {
          system("cls");
          cout << "********* QUAN LI CHO THUE PHONG TRO *********\n";
          cout << "\n  1. Thong Tin Phong.";
          cout << "\n  2. Trang Thai Phong.";
          cout << "\n  3. Thue Phong.";
          cout << "\n  4. Sua Thong Tin Phong.";
          cout << "\n  5. Tra Phong.";
          cout << "\n  6. Danh Sach KH Thue Phong.";
          cout << "\n  7. Exit";
          cout << "\nNhap Tuy Chon <1-7>: ";
          cin >> tuychon;
          switch (tuychon)
          {
          case 1:
               infor_room();
               break;
          case 2:
               status_room();
               break;
          case 3:
               book_room();
               break;
          case 4:
               edit_room();
               break;
          case 5:
               del_room();
               break;
          case 6:
               list_book();
               break;
          case 7:
               cout << "\nTHANK YOU!";
               break;
          default:
               cout << "\nNhap Lai Tuy Chon.";
               getch();
               break;
          }
     } while(tuychon !=7);
     getch(); 		//dung man hinh de xem ket qua va nhap phim bat ki de tra ve man hinh soan thao
}

void infor_room(){
     system("cls");
     cout << "***** Cac Loai Phong *****\n";
     cout << "\n\tI. Phong Standard (STD): ";
     cout << "\n  * Tien mot thang: 1.100.000VND.";
     cout << "\n  * Tien dien: 3000VND/1KWh.";
     cout << "\n  * Tien nuoc: 30.000VND/1thang";
     cout << "\n  * Tien internet: 30.000VND/1thang. \n";
     cout << "\tII. Phong Superior (SUP): ";
     cout << "\n  * Tien mot thang: 1.400.000VND.";
     cout << "\n  * Tien dien: 3000VND/1KWh.";
     cout << "\n  * Tien nuoc: 30.000VND/1thang.";
     cout << "\n  * Tien internet: 30.000VND/1thang. \n";
     cout << "\tIII. Phong Suite (SUT): ";
     cout << "\n  * Tien mot thang: 1.800.000VND.";
     cout << "\n  * Tien dien: 3000VND/1KWh.";
     cout << "\n  * Tien nuoc: 30.000VND/1thang.";
     cout << "\n  * Co ho tro nuoc nong/lanh.";
     cout << "\n  * Dich vu di thang may free.";
     cout << "\n  * Dich vu giat ui giam 10%.";
     cout << "\n  * Tien internet: 30.000VND/1thang. ";
     //cout << "\n\nNHAN PHIM BAT KI DE TIEP TUC!";
     getch();
};

void status_room(){
     system("cls");
     cout<<"***** Phong Dang Thue *****\n\n";
     fstream sttp;
     sttp.open("DS_TP.txt", ios::in);
     int i=0;
     while (!sttp.eof()){
          int room;
          sttp>>room;
		i++;
          cout << "   " << i << ". Phong: " << room << endl;
     }  
     getch();
};

void book_room(){
     system("cls");
     fstream dlkh;
     dlkh.open("DL_KH.txt", ios::app | ios::in);
     book_again:
     cout << "***** Thue Phong *****\n";
     cout << "\n * Phong Standard. <101-110>.";
     cout << "\n * Phong Superior. <111-120>.";
     cout << "\n * Phong Suite.    <121-130>.\n";

     ofstream sttp;
     sttp.open("DS_TP.txt", ios::app);
     cout<<"Nhap STT Phong: ";
     cin>>kh.sttp;
     sttp<<kh.sttp<<endl;
     sttp.close();
     // chua fix muc kiem tra sttp

     cout << "Ngay Thue: ";
     cin >> kh.ngaythue;          
     cout << "Nhap Ho Ten: ";
     cin.ignore(1); //doc va xoa 1 ki tu con trong trong bo nho dem
     cin.getline(kh.name, 50);         
     cout << "Nhap Dia Chi: ";
     cin.getline(kh.address, 100);        
     cout << "Nhap Ngay Sinh: ";
     cin.getline(kh.birthday, 30);         
     cout << "Nhap So Dien Thoai: ";
     cin.getline(kh.phone, 30) ;

     record_kh(kh, dlkh);

     cout << "\nNHAN ESE DE THOAT HOAC PHIM BAT KI DE TIEP TUC!";
     char key_val;
     key_val = getch();
     if (key_val == 27)
     {
          //back to menu
     }
     else
     { //nhap thong tin KH tiep theo
          system("cls");
          goto book_again;
     }
     dlkh.close();
};

void record_kh(struct KH kh, fstream &record){
     record << kh.sttp<<endl;
     record << kh.ngaythue << endl;
     record << kh.name << endl;
     record << kh.address << endl;
     record << kh.birthday << endl;
     record << kh.phone << endl<<endl;
};

void edit_room(){

};

void del_room(){

};

void list_book(){
     system("cls");
     fstream list;
     list.open("DL_KH.txt", ios::in);  
     cout<<"***** Danh Sach Khach Hang Thue Phong *****\n\n";
     int i=0;
     while(!list.eof()){
          i++;
          list>>kh.sttp ;
          list.ignore();
          list.getline(kh.ngaythue, 30) ;
          list.getline(kh.name, 50);
          list.getline(kh.address, 100);
          list.getline(kh.birthday, 30);
          list.getline(kh.phone, 30);

          cout<<i;
          cout<< ". * STT Phong: " <<kh.sttp << endl;
          cout<< "   * Ngay Thue: "<<kh.ngaythue<<endl;
          cout<< "   * Ho Ten: "<<kh.name<<endl;
          cout<< "   * Dia Chi: "<<kh.address<<endl;
          cout<< "   * Ngay Sinh: " << kh.birthday << endl;
          cout<< "   * So Dien Thoai: "<<kh.phone<<endl<<endl;
     }
     list.close();
     getch();
};

/*
 *ofstream - KDL nay bieu dien Output File Stream va su dung de ghi thong tin toi file  
 *ifstream - KDL nay bieu dien Input File Stream va su dung de doc thong tin tu file
*/ 
