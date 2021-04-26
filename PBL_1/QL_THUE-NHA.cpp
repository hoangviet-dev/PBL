#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>

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
     struct KH;
};

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
     cout << "\n  * Tien internet: 30.000VND/1thang. \n";
}

void thuephong()
{
     system("cls");
     cout << "***** Thue Phong *****\n";
     cout << "* Phong Standard <STD>.";
     cout << "\n* Phong Superior <SUP>.";
     cout << "\n* Phong Suite <SUT>.";
     cout << "\nChon Loai Phong Muon Thue: ";
     cin >> phong1.loaiphong;
     cout<<"Nhap STT Phong: ";
     cin>>phong1.sttp;
     cout << "Nhap Ho Ten: ";
     cin.ignore();
     cin.getline(KH1.hoten, 50);
     cout << "Nhap Dia Chi Sinh Song: ";
     cin.getline(KH1.address, 100);
     cout << "Nhap Ngay Sinh (dd/mm/yyyy): ";
     cin.getline(KH1.ngaysinh, 30);
     cout<<"Nhap So Dien Thoai: ";
     cin.getline(KH1.phone, 20);
     getch();
}

void ttphong(){
     system("cls");
     cout << "***** Trang Thai Phong *****\n";
     cout<<"Phong Da Duoc Thue: "<<phong1.sttp;
     cout<<"\nLoai Phong: "<<phong1.loaiphong;
     cout<<"\nHo Ten: "<<KH1.hoten;
     cout << "\nDia Chi Sinh Song: "<<KH1.address;
     cout << "\nNgay Sinh: "<<KH1.ngaysinh;
     cout << "\nSo Dien Thoai: "<<KH1.phone;
     getch();
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
          cout << "\n1. Xem Loai Phong Muon Thue.";
          cout << "\n2. Thue Phong.";
          cout << "\n3. Trang Thai Phong.";
          cout << "\n4. Tra Phong.";
          cout << "\n5. Danh Sach Khach Hang Thue Phong.";
          cout << "\n6. Xuat Danh Sach Khach Hang Thue Phong. ";
          cout << "\n7. Exit";
          cout << "\nNhap Tuy Chon <1-7>: ";
          cin >> tuychon;
          switch (tuychon)
          {
          case 1:
               loaiphong();
               getch(); //dung mh console sau khi xuat
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
               cout << "\nCam On Quy Khach!";
               break;
          default:
               cout << "\nNhap Lai Tuy Chon.";
               getch();
               break;
          }
     } while (tuychon != 7);
     getch();
}