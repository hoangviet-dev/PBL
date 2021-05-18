#include <iostream>
#include <conio.h> //getch();
#include <fstream>
#include <string>

#define max 10000;
using namespace std;

class khachhang
{
public:
     char ten[50];
     char dia_chi[100];
     char ngay_sinh[30];
     char sdt[30];
};

class phong
{
private:
     int sttp;
     char ngaythue[30];
public:
     class khachhang kh;
     void tthai_phong();
     void thue_phong();
     void suatt_phong();
     void tra_phong();
     void dst_phong();
     void record();
};
class phong p[max];

void ttin_phong()
{
     system("cls");
     cout << "***** Cac Loai Phong *****\n";
     cout << "\tI. Phong Standard (STD): ";
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
     getch();
};

void phong::tthai_phong()
{
     system("cls");
          
}

void phong::thue_phong()
{
     
}

void phong::suatt_phong()
{
     
}

void phong::tra_phong()
{
     
}

void phong::dst_phong()
{
     cout << "**** Danh Sach Khach Hang Thue Phong ****\n\n";
     
}

int main()
{
     class phong p;
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
               ttin_phong();
               break;
          case 2:
               p.tthai_phong();
               break;
          case 3:
               p.thue_phong();
               break;
          case 4:
               p.suatt_phong();
               break;
          case 5:
               p.tra_phong();
               break;
          case 6:
               p.dst_phong();
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
