#include <iostream>
#include <windows.h>

using namespace std;

void setcolor(int ForgC){
     WORD wColor;
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     if (GetConsoleScreenBufferInfo(hStdOut, &csbi)){
          wColor = (csbi.wAttributes & 0xB0) + (ForgC & 0x0B);
          //	SetConsoleTextAttributes(hStdOut,wColor);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
}

struct KH {
     char hoten[50];
     char address[100];
     char ngaysinh[30];
     char phone[20];
     char loaiKH[30];          //sinh vien: sv; ho gia dinh: hgd
     
};

struct phong{
     int sttp;                //so thu tu phong
     char loaiphong[100];     //STD; SUP; SUT

};
 
struct dsthue{
     char ngaythue[30];       //ngay KH bat dau thue
     struct KH;
};

void loaiphong(){
     system("cls");
     cout << "##### Cac Loai Phong #####\n";
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

int main()
{
     int tuychon;
     system("cls");
     do
     {
          setcolor(15);
          cout << "######## MENU #########\n";
          cout << "\n1. Xem Loai Phong Muon Thue.";
          cout << "\n2. Thue Phong.";
          cout << "\n3. Trang Thai Phong.";
          cout << "\n4. Tra Phong.";
          cout << "\n5. Danh Sach Khach Hang Thue Phong.";
          cout << "\n6. Xuat Danh Sach Khach Hang Thue Phong. ";
          cout << "\n7. Exit";
          cout << "\nNhap Tuy Chon <1-7>: ";
          cin >> tuychon;
          switch (tuychon){
          case 1:
               loaiphong();
               break;
          case 2:

               break;
          case 3:

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
               break;
          }
     } while (tuychon != 7);
}
