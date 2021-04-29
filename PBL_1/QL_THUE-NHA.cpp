#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include<string>

using namespace std;

void setcolor(int code)
{
     HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(color, code);
}

struct KH
{
     char hoten[50];
     char address[100];
     char ngaysinh[30];
     char phone[20];
     char loaiKH[30]; //sinh vien: sv; ho gia dinh: hgd

} KH1;

struct phong
{
     int sttp;            //so thu tu phong
     char loaiphong[100]; //STD; SUP; SUT

} phong1;

struct dsthue
{
     char ngaythue[30]; //ngay KH bat dau thue
     char ngaytra[30];
     struct KH;
}dst1 ;

void loaiphong()
{
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
     cout<<"\n\nNHAN PHIM BAT KI DE TIEP TUC!";
     getch(); //dung mh console sau khi xuat
}

void thuephong()
{
     system("cls");
     thuephong:

     ofstream ghidl;
     ghidl.open("DL_KH.txt", ios::app);
     cout << "***** Thue Phong *****\n";
     cout << "\n* Phong Standard <STD>.";
     cout << "\n* Phong Superior <SUP>.";
     cout << "\n* Phong Suite <SUT>.\n";
     char key_val1, key_val2;
     key_val1 = getch();
     if (key_val1== 27){ 
          //neu nhap vao esc thi thoat case thuephong.
          //getch();
          //break;
     }
     else{
          cout<<"\nNgay Thue: ";
          cin>>dst1.ngaythue;
          ghidl<< dst1.ngaythue<<" \t";
          cout << "Chon Loai Phong Muon Thue: ";
          cin >> phong1.loaiphong;
          ghidl<<phong1.loaiphong<<" \t";
          cout<<"Nhap STT Phong: ";
          cin>>phong1.sttp;
          ghidl << phong1.sttp<< " \t";
          cout << "Nhap Ho Ten: ";
          cin.ignore();
          cin.getline(KH1.hoten, 50);
          ghidl << KH1.hoten << "\t\t";
          cout << "Nhap Dia Chi Sinh Song: ";
          cin.getline(KH1.address, 100);
          ghidl << KH1.address << " \t";
          cout << "Nhap Ngay Sinh (dd/mm/yyyy): ";
          cin.getline(KH1.ngaysinh, 30);
          ghidl << KH1.ngaysinh << " \t";
          cout<<"Nhap So Dien Thoai: ";
          cin.getline(KH1.phone, 20);
          ghidl << KH1.phone << "\t\n";
          cout << "\nNHAN ESE DE THOAT HOAC PHIM BAT KI DE TIEP TUC!";
          key_val2=getch();
          if (key_val2==27){
               // nothing
          }
          else{
               system("cls");
               goto thuephong;               
          }
          ghidl.close();
     }     
}

void ttphong(){
     char docdl1[1000];
     ifstream docdl;
     docdl.open("DL_KH.txt", ios::in);
     system("cls");
     cout << "***** Trang Thai Phong *****\n";
     //cout<<"\nPhong Da Duoc Thue: ";
     //cout << "\n----------------------";
     cout << "\n Ngay Thue. \tLoai Phong. \tSTT Phong. \tHo Ten. \tDia Chi Sinh Song.\t\tNgay Sinh. \tSo Dien Thoai. \n\n";
     // cout<<"\nLoai Phong: "<<phong1.loaiphong;
     // cout<<"\nHo Ten: "<<KH1.hoten;
     // cout << "\nDia Chi Sinh Song: "<<KH1.address;
     // cout << "\nNgay Sinh: "<<KH1.ngaysinh;
     // cout << "\nSo Dien Thoai: "<<KH1.phone;

     //doc dl tu file sang chuong trinh
     while(!docdl.eof()){
          docdl>>docdl1;
          cout<<" "<<docdl1<<"     ";
     }
     docdl.close();
     getch();
}

void traphong(){
     cout<<"Nhap STT Phong Muon Tra: ";
     
     
}

int main()
{
     int tuychon;
     system("cls");
     do
     {
          system("cls");
          setcolor(6);
          cout << "********* MENU *********\n";
          cout << "\n  1. Xem Loai Phong Muon Thue.";
          cout << "\n  2. Thue Phong.";
          cout << "\n  3. Trang Thai Phong.";
          cout << "\n  4. Tra Phong.";
          cout << "\n  5. Danh Sach Khach Hang Thue Phong.";
          cout << "\n  6. Xuat Danh Sach Khach Hang Thue Phong. ";
          cout << "\n  7. Exit";
          cout << "\nNhap Tuy Chon <1-7>: ";
          cin >> tuychon;
          switch (tuychon)
          {
          case 1:
               loaiphong();
               break;
          case 2:
               thuephong();
               break;
          case 3:
               ttphong();
               break;
          case 4:

               break;
          case 5:

               break;
          case 6:

               break;
          case 7:
               cout << "\nTHANK YOU!";
               break;
          default:
               cout << "\nNhap Lai Tuy Chon.";
               getch();
               break;
          }
     } while (tuychon != 7);
     getch();
}
