#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<windows.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <fstream>
#include <math.h>

#define SV 10000
#define MAUCHECK 78
#define MAUCHU 27
#define MC 223
#define MAU 14
#define TS 5000
#define MS 2000
#define TT 2000
using namespace std;
//phan1
void Color(int );
void gotoxy(int , int );
void XoaManHinh();
void MakeMainMenu();
void thoat();
void MakeBorder();
void Buoisau();
void MainMenu(int );
//phan2
char FName[]="danhsach1.txt";
struct SinhVien {
	char maLop[MS];
	char maSV[MS];
	char tenSV[TS];
	char Ngaysinh[TS];
	char DTBTL[TS];
};
SinhVien sinhvien[SV];
int sosinhvien=0;
void CapNhatSinhVien();
void InDanhSach();
void SapXep();
void TimKiem();
void ThongKe();
void HienThiThemSinhVien(SinhVien sv);
void MenuTimKiem(int t);
void DocFile();
void DocFile1();
//void ghiFile();
void inThongTinSinhVien(SinhVien sinhvien,int k);
void chuan_hoa_ten(char *name);
void xoa(char* name, int n);
void xoa_ki_tu_xau(char* name);
void xoa_dau_cach_thua(char* name);
void viet_hoa_dau_dong(char *name);
//-dj
void Hoan_Vi_Tri(SinhVien &a,SinhVien &b);
void sap_xep_MSV(SinhVien *sv);
void sap_xep_MSV1(SinhVien *sv);
void sap_xep_DTB (SinhVien *sv);
void sap_xep_DTB1 (SinhVien *sv); 
void timtheoTen(SinhVien* ds);
void thongkelop(SinhVien* sv);
void thongkediemlop(SinhVien* sv);
//past1
int main(){
	gotoxy(40,0);	
	cout<<"----Quan Ly Sinh Vien Ver 1.0---";
	FILE *file=fopen(FName,"a+");
	fclose(file);
	DocFile();	
	gotoxy(40,0);
	cout<<"----Quan Ly Sinh Vien Ver 1.0---";
	MainMenu(1);

	return 0;
}
void Color(int x)//Ham tao mau
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
void gotoxy(int x, int y)//Ham di chuyen con tro
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}

void XoaManHinh() {
    for (int i = 26; i < 110; i++) {
        for (int j = 2; j < 25; j++) {
            gotoxy(i, j);
            cout << " ";
        }
    }
}
void MakeMainMenu() //Viet Ki tu cua Menu
{
   
    Color(15);
    gotoxy(1, 1);
    Color(13);
    cout<< "\n\t -MENU CHINH-" ;
    Color(15);
	cout<< "\n\n\n     them moi ho so " 
		<<"\n\t---------"
		<< "\n     danh sach "
		<<"\n\t---------"
        << "\n     sap xep " 
        <<"\n\t---------"
		<< "\n     tim kiem " 
		<<"\n\t---------"
		<< "\n     thong ke " 
		<<"\n\t---------"
		<< "\n     xuat file.txt " 
		<<"\n\t---------"
		<< "\n     thoat \n";
    
}
void MakeBorder() //Ham tao Khung
{
    Color(10);
    for (int i = 2; i < 25; i++) {
        gotoxy(1, i);
        printf("%c", 186);
        gotoxy(110, i);
        printf("%c", 186);
    }
    for (int i = 1; i < 110; i++) {
        gotoxy(i, 1);
        printf("%c", 205);
        gotoxy(i, 25);
        printf("%c", 205);
    }
    for (int i = 2; i < 25; i++) {
        gotoxy(25, i);
        printf("%c", 186);
    }
    gotoxy(1, 1);
    printf("%c", 201);
    gotoxy(110, 1);
    printf("%c", 187);
    gotoxy(1, 25);
    printf("%c", 200);
    gotoxy(110, 25);
    printf("%c", 188);
    gotoxy(25, 1);
    printf("%c", 203);
    gotoxy(25, 25);
    printf("%c", 202);
}
void Buoisau()
{   char key_press;
    int ascii_value;
	gotoxy(30,2);
	Color(30);
	cout<<"Back";
	char ch1;
	ch1= getch();
	if(ch1 == 13){
		Color(15);
		XoaManHinh();
		}
		gotoxy(3,26);
		cout<<"log ban phim";
while(1)
    {
        key_press=getch();
        ascii_value=key_press;
        if(ascii_value==27) // For ESC
            break;
        cout<<"Ban nhap phim-> \" "<<key_press<<" \" Gia tri ASCII =  "<<ascii_value<<"\n";
    }
}
void MainMenu(int chon)//Tao Menu chon
{
	MakeBorder();
	MakeMainMenu();
char ch;//Biem de nhan tin hieu tu ban phim
	while( 1) {
	    switch(chon){
		case 1: Color(15);
				MakeMainMenu();
				MakeBorder();
				gotoxy(4,5);
				Color(30); 
				cout<<" Them Moi Ho So";
				char et1;
				et1 = getch();
				if (et1 == 13){
					CapNhatSinhVien();
				//	MainMenu(1);
					}	
				
				break;
		case 2: Color(15);
				MakeMainMenu();
				MakeBorder();
				gotoxy(4,7);
				Color(30); 
				cout<<" Danh Sach";
				char et2;	et2 = getch();
				if (et2 == 13){

					InDanhSach();
				//	MainMenu(2);
				}
				break;
		case 3: Color(15);
				MakeMainMenu();
				MakeBorder();
				gotoxy(4,9);
				Color(30); 
				cout<<" Sap Xep";
				char et3; 	et3 = getch();
				if (et3 == 13){
					SapXep();
				//	MainMenu(3);
				}
				break;
		case 4: Color(15);
				MakeMainMenu();
				MakeBorder();
				gotoxy(4,11);
				Color(30);
				cout<<" Tim Kiem";
				char et4;	et4 = getch();
				if (et4 == 13){
				    TimKiem();
				//	MainMenu(4);
				}
				break;
		case 5: Color(15);
				MakeMainMenu();
				MakeBorder();
				gotoxy(4,13);
				Color(30);
				cout<<" Thong Ke";				 
				char et5;	et5 = getch();
				if (et5 == 13){
				    ThongKe();
				//	MainMenu(5);
				}
				break;
		case 6: Color(15);
				MakeMainMenu();
				MakeBorder();
				gotoxy(4,15);
				Color(30);
				cout<<" Xuat File.txt"; 
				char et6;	et6 = getch();
				if (et5 == 13){				   	  
					//	DocFile1();						
					MainMenu(5);
				}
				break;
		case 7: Color(15);
				MakeMainMenu();
				MakeBorder();
				gotoxy(4,17);
				Color(30); 
				cout<<" Thoat";
				char et7; 	et7 = getch();
				if (et6 == 13){
				gotoxy(1,26);
				exit(1);}
				break;
		
	}	ch=getch();
		
			if (ch == 72 && chon > 1) chon--;//dieu khien len
			if (ch == 80 && chon < 7) chon++;//dieu khien xuong
			
	}
}
void textcolor(WORD color) {
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;
	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void thoat(){
		gotoxy(40,0);
	cout<<"----Quan Ly Sinh Vien Ver 1.0---";
	MakeBorder();
	MakeMainMenu();
	MainMenu(1);
}

//past2
void TimKiem() {
	int a=3;
	//system("cls");
	fflush(stdin);
	MakeBorder();
	MakeMainMenu();
	textcolor(MAUCHU);
	gotoxy(30,a);
	cout<<"Moi ban chon thuat toan tim kiem:";
	fflush(stdin);
	textcolor(MAUCHECK);
	gotoxy(30,a+4);
	cout<<"Tim kiem tuan tu";
	textcolor(MAUCHU);
	gotoxy(30,a+6);
	cout<<"Tim kiem nhi phan";
	gotoxy(30,a+8);
	cout<<"Thoat";
	int luaChon=1;
	while(true) {
		int key=getch();
		switch(key) {
			case 80:
				luaChon++;
					if(luaChon>3)
					luaChon=1;
				if(luaChon==1) {
					textcolor(MAUCHECK);
				} else {
					textcolor(MAUCHU);
				}   
					gotoxy(30,a+4);
					cout<<"Tim kiem tuan tu";
					if(luaChon==2) {
					textcolor(MAUCHECK);
				} else {
					textcolor(MAUCHU);
				}  
					gotoxy(30,a+6);
					cout<<"Tim kiem nhi phan"; 
					if(luaChon==3) {
					textcolor(MAUCHECK);
				} else {
					textcolor(MAUCHU);
				}  
					gotoxy(30,a+8);
					cout<<"Thoat";
				break;
			case 27:
				XoaManHinh();
				MainMenu(4);
				break;
			case 13:
				if(luaChon==1) {
				system("cls");
				fflush(stdin);
					 timtheoTen(sinhvien);
				}
				if(luaChon==2) {
					 Buoisau();
				}
				if(luaChon==3) {
					XoaManHinh();
					MainMenu(4);
				}
				break;
		}
	}
}
void SapXep() {
	//system("cls");
	int a=3;
	MakeBorder();
	MakeMainMenu();
	fflush(stdin);
	textcolor(MAUCHU);
	gotoxy(30,a);
	cout<<"Moi ban chon sap xep:";
	fflush(stdin);
	textcolor(MAUCHECK);
	gotoxy(30,a+4);
	cout<<"sap xep diem giam";
	textcolor(MAUCHU);
	gotoxy(30,a+6);
	cout<<"sap xep diem tang";
	gotoxy(30,a+8);
	cout<<"sap xep MSV giam";
	gotoxy(30, a+10);
	cout<<"sap xep MSV tang";
	gotoxy(30, a+12);
	cout<<"Thoat";
	int luaChon=1;
	while(true) {
		switch(getch()) {
			case 80:
				luaChon++;
				if(luaChon>5)
					luaChon=1;
				if(luaChon==1) {
					textcolor(MAUCHECK);
				} else {
					textcolor(MAUCHU);
				}
				gotoxy(30,a+4);
				cout<<"sap xep diem giam";
				if(luaChon==2) {
					textcolor(MAUCHECK);
				} else {
					textcolor(MAUCHU);
				}
				gotoxy(30,a+6);
				cout<<"sap xep diem tang";
				if(luaChon==3) {
					textcolor(MAUCHECK);
				} else {
					textcolor(MAUCHU);
				}
				gotoxy(30,a+8);
				cout<<"sap xep MSV giam";
				if(luaChon==4) {
				    textcolor(MAUCHECK);
				} else {
					textcolor(MAUCHU);
				}
				gotoxy(30,a+10);
				cout<<"sap xep MSV tang";
				if(luaChon==5) {
					textcolor(MAUCHECK);	
				} else {
					textcolor(MAUCHU);
				}
				gotoxy(30,a+12);
				cout<<"Thoat";
				break;
			case 72:
				luaChon--;
				if(luaChon<=0)
					luaChon=5;
				if(luaChon==1) {
					textcolor(MAUCHECK);
				} else {
					textcolor(MAUCHU);
				}
				gotoxy(30,a+4);
				cout<<"sap xep diem giam";
				if(luaChon==2) {
					textcolor(MAUCHECK);
				} else {
					textcolor(MAUCHU);
				}
				gotoxy(30,a+6);
				cout<<"sap xep diem tang";
				if(luaChon==3) {
					textcolor(MAUCHECK);
				} else {
					textcolor(MAUCHU);
				}
				gotoxy(30,a+8);
				cout<<"sap xep MSV giam";
				if(luaChon==4) {
					textcolor(MAUCHECK);
				} else {
					textcolor(MAUCHU);
				}
				gotoxy(30,a+10);
				cout<<"sap xep MSV tang";
				if(luaChon==5) {
					textcolor(MAUCHECK);
				} else {
					textcolor(MAUCHU);
				}
				gotoxy(30,a+12);
				cout<<"Thoat";
				break;
			case 27:
				XoaManHinh();
				MainMenu(3);
				break;
			case 13:
				if(luaChon==1) {
				system("cls");
				fflush(stdin);
				sap_xep_DTB1 (sinhvien) ;
				}
				if(luaChon==2) {
					system("cls");
				fflush(stdin);
				sap_xep_DTB (sinhvien) ;
				}
				if(luaChon==3) {
					system("cls");
				fflush(stdin);
					sap_xep_MSV (sinhvien);
				}
				if(luaChon==4) {
					system("cls");
				fflush(stdin);
					 sap_xep_MSV1 (sinhvien);
				}
				if(luaChon==5) {
					XoaManHinh();
					MainMenu(3);
				}
				break;
		}

	}
}
void ThongKe() {
	int a=3;
	MakeBorder();
	MakeMainMenu();
	//system("cls");
	fflush(stdin);
	textcolor(MAUCHU);
	gotoxy(30,a);
	cout<<"Lua chon loai thong ke:";
	fflush(stdin);
	int luaChon=1;
	textcolor(MAUCHECK);
	gotoxy(30,a+4);
	cout<<"Thong ke theo lop";
	textcolor(MAUCHU);
	gotoxy(30,a+6);
	cout<<"Thong ke theo xep loai";
	while(true) {
		switch((int)getch()) {
			case 72:
			case 80:
				luaChon++;
				if(luaChon%2==1) {
					textcolor(MAUCHECK);
					gotoxy(30,a+4);
					cout<<"Thong ke theo lop";
					textcolor(MAUCHU);
					gotoxy(30,a+6);
					cout<<"Thong ke theo xep loai";
				} else {
					textcolor(MAUCHU);
					gotoxy(30,a+4);
					cout<<"Thong ke theo lop";
					textcolor(MAUCHECK);
					gotoxy(30,a+6);
					cout<<"Thong ke theo xep loai";
				}
				break;
			case 27:
				XoaManHinh();
				MainMenu(5);
				break;
			case 13:
				if(luaChon%2==1) {
					system("cls");
				fflush(stdin);			
				thongkelop(sinhvien);
				} else {
						system("cls");
				fflush(stdin);
				thongkediemlop(sinhvien);
				}
				break;
		}

	}
}

void CapNhatSinhVien() {
	int a=3;
	MakeBorder();
	MakeMainMenu();
	SinhVien sv;
	fflush(stdin);
	textcolor(MAUCHU);
	gotoxy(50,a);
	cout<<"--Moi ban dien day du thong tin--";
			gotoxy(30,a+2);
		textcolor(MAUCHU);
		cout<<"Ma lop            :";
			gotoxy(30,a+4);
		textcolor(MAUCHU);
		cout<<"Ma SV             :";
			gotoxy(30,a+6);
		textcolor(MAUCHU);
		cout<<"Ten SV            :";
			gotoxy(30,a+8);
		textcolor(MAUCHU);
		cout<<"Nam sinh (yyyy)   :";
			gotoxy(30,a+10);
		textcolor(MAUCHU);
		cout<<"DTB               :";
	strcpy(sv.maLop,"");
	strcpy(sv.maSV,"");
	strcpy(sv.tenSV,"");
	strcpy(sv.Ngaysinh,"");
    strcpy(sv.DTBTL,"");
	while(strlen(sv.maLop)!=3) {
		gotoxy(30,a+2);
		textcolor(78);
		cout<<"Ma lop            :";
		textcolor(MC);
		gets(sv.maLop);
		fflush(stdin);
	}

	while(strlen(sv.maSV)!=3) {
		gotoxy(30,a+4);
		textcolor(78);
		cout<<"Ma SV             :";
		textcolor(MC);
		gets(sv.maSV);
		fflush(stdin);
	}

	while(strlen(sv.tenSV)<1) {
		gotoxy(30,a+6);
		textcolor(78);
		cout<<"Ten SV            :";
		textcolor(MC);
		gets(sv.tenSV);
		chuan_hoa_ten(sv.tenSV);
		fflush(stdin);
	}
	char ngay[12];
	char thang[12];
	char nam[5];
	
	while(strlen(nam)!=4||strlen(thang)>2||strlen(ngay)>2) {
		gotoxy(30,a+8);
		textcolor(78);
		cout<<"Nam sinh (yyyy)   :";
		textcolor(MC);
		gets(ngay);
		gotoxy(52,a+8);
		cout<<"/";
		gets(thang);
		gotoxy(56,a+8);
		cout<<"/";
		gets(nam);
		fflush(stdin);
	}
	char qs[2]="-";
	strcat(ngay, qs);
	strcat(ngay, thang);
	strcat(ngay, qs);
	strcat(ngay, nam);
	strcat(sv.Ngaysinh,ngay);

	while(strlen(sv.DTBTL)<1) {
		gotoxy(30,a+10);
		textcolor(78);
		cout<<"DTB               :";
		textcolor(MC);
	    cin>>sv.DTBTL;
		fflush(stdin);
	}
	textcolor(27);
	HienThiThemSinhVien(sv);
}
void HienThiThemSinhVien(SinhVien sv) {
	
	int a=3;
	int luaChon=1;
	system("cls");
	MakeBorder();
	MakeMainMenu();
	fflush(stdin);
	gotoxy(30,a);
	cout<<"Ban co muon them sinh vien co thong tin sau: ";
	gotoxy(30,a+2);
	textcolor(MAUCHU);
	cout<<"Ma lop: ";
	textcolor(MC);
	cout<<sv.maLop;
	textcolor(MAUCHU);
	gotoxy(30,a+4);
	cout<<"Ma sinh vien: ";
	textcolor(MC);
	cout<<sv.maSV;
	textcolor(MAUCHU);
	gotoxy(30,a+6);
	cout<<"Ho ten: ";
	textcolor(MC);
	cout<<sv.tenSV;
	gotoxy(30,a+8);
	textcolor(MAUCHU);
	cout<<"Nam sinh: ";
	textcolor(MC);
	cout<<sv.Ngaysinh;
	gotoxy(30,a+10);
	textcolor(MAUCHU);
	cout<<"DTB: ";
	textcolor(MC);
	cout<<sv.DTBTL;
	textcolor(MAUCHECK);
	
	gotoxy(35,a+15);
	cout<<"Co";
	textcolor(MAUCHU);
	gotoxy(45,a+15);
	cout<<"Khong";
	fflush(stdin);
	while(true) {
		int key=getch();
		switch(key) {
			case 75:
			case 77:
				luaChon++;
				if(luaChon<1) {
					luaChon=2;
				}
				if(luaChon%2==1) {
					textcolor(MAUCHECK);
					gotoxy(35,a+15);
					cout<<"Co";
					textcolor(MAUCHU);
					gotoxy(45,a+15);
					cout<<"Khong";
				} else {
					textcolor(MAUCHU);
					gotoxy(35,a+15);
					cout<<"Co";
					textcolor(MAUCHECK);
					gotoxy(45,a+15);
					cout<<"Khong";
				}
				break;
			case 13:
				if(luaChon%2==1) {
					//Co
					FILE *q=fopen(FName,"a+");
					fprintf(q,"%s\r\n%s\r\n%s\r\n%s\r\n%s\r\n",sv.maLop,sv.maSV,sv.tenSV,sv.Ngaysinh,sv.DTBTL);
					fclose(q);
					FILE *f=fopen("danhsach.txt","a+");
					fprintf(f,"%s\t%s\t%s\t\t%s\t%s\r\n",sv.maLop,sv.maSV,sv.tenSV,sv.Ngaysinh,sv.DTBTL);					
					sinhvien[sosinhvien]=sv;
					sosinhvien++;
					fclose(f);				
					system("cls");
					MainMenu(1);
					fflush(stdin);
				} else {
					//khong
					system("cls");
					MainMenu(1);
					fflush(stdin);
				}
				break;
		}
	}

}

void InDanhSach() {
	fflush(stdin);
	MakeBorder();
	MakeMainMenu();
	textcolor(MAUCHU);
	int a=3;
	textcolor(MC);
	gotoxy(80,a-1);
	fflush(stdin);
	cout<<"Co "<<sosinhvien<<" sinh vien \n";
	gotoxy(30,a+1);
	cout<<"stt\tMalop\tMaSV\tHo va Ten\t\tngaysinh\tdiem \n";
	for(int n=0; n<sosinhvien; n++) {
		gotoxy(30,a+n+3);
		textcolor(MC);
		cout<<n+1<<"\t";
		inThongTinSinhVien(sinhvien[n],a+n+1);
	}
	while(1) {
		switch(getch()) {
			case 27:
				system("cls");
				fflush(stdin);
				MainMenu(2);
			case 13:
				system("cls");
				fflush(stdin);
				MainMenu(2);
				
				break;
		}
	}

}
void inThongTinSinhVien(SinhVien sv,int k) {
	textcolor(MC);
	gotoxy(40,k+2);
	//cout<<sv.maLop<<"\t"<<sv.maSV<<"\t"<<sv.tenSV<<"\t\t"<<sv.Ngaysinh<<"\t"<<sv.DTBTL;
	cout<<sv.maLop;
	gotoxy(48,k+2);
	cout<<sv.maSV;
	gotoxy(56,k+2);
	cout<<sv.tenSV;
	gotoxy(80,k+2);
	cout<<sv.Ngaysinh;
	gotoxy(97,k+2);
	cout<<sv.DTBTL;
}

void DocFile() {
	FILE *file=fopen(FName,"r");
	if(file!=NULL) {
		int i=0;
		int k=0;
		while(!feof(file)) {
			k++;
			if(k>9) {
				k=1;
				i++;
			}
			switch(k) {
				case 1:
					fgets(sinhvien[i].maLop,255,file);
					//xoaDau(sach[i].maSach);
					break;
				case 2:
					fgets(sinhvien[i].maSV,255,file);
					//VietHoa(sach[i].tenSach);
					break;
				case 3:
					fgets(sinhvien[i].tenSV,255,file);
					//VietHoa(sach[i].nhaXuatBan);
					break;
				case 4:
					fgets(sinhvien[i].Ngaysinh,255,file);
					//xoaDau(sach[i].namXuatBan);
					break;
				case 5:
					fgets(sinhvien[i].DTBTL,255,file);
					//xoaDau(sach[i].soTrang);
					break;
			}
		}
		sosinhvien=i;
	}
}
void chuan_hoa_ten(char* name)
{
xoa_ki_tu_xau(name);
xoa_dau_cach_thua(name);
viet_hoa_dau_dong(name);

}
void xoa(char *name, int n)
{
int t = strlen(name);
for (int k = n; k < t - 1; k++)
name[k] = name[k + 1];
name[t - 1] = '\0';
}
void xoa_ki_tu_xau(char* name)
{
int t = strlen(name);
for (int i = 0; i < t; i++)
{
if (name[i]>32 && name[i] < 65 || name[i]>90 && name[i] < 97 || name[i]> 122)
{
xoa(name, i);
t--;
i--;
}
}

}
void xoa_dau_cach_thua(char *name)
{
int t = strlen(name);

while (name[t-1] == 32)
{
xoa(name, t-1);
t--;
}
while (name[0] == 32)
{
xoa(name, 0);
t--;
}
for (int i = 0; i < t; i++)
{
if (name[i] == 32)
while (name[i + 1] == 32)
{
xoa(name, i + 1);
t--;
}

}
}
void viet_hoa_dau_dong(char *name)
{
if (name[0] != 32) name[0] -= 32;
int t = strlen(name);
for (int i = 0; i < t; i++)
if (name[i] == 32)
if (name[i + 1] != 32) name[i + 1] -= 32;
}
//
void Hoan_Vi_Tri(SinhVien &a,SinhVien &b){
	SinhVien tem = a;
			a =  b;
			b = tem;
}


void sap_xep_DTB (SinhVien *sv) { //Sap xep sinh vien giam dan theo diem trung binh
	
	for (int i=0; i<sosinhvien-1; i++) {
		for (int j=i+1; j<sosinhvien; j++) {
			if ( atof(sv[i].DTBTL)> atof(sv[j].DTBTL)) {
				Hoan_Vi_Tri(sv[i],sv[j]);
			}
		}
	}
	InDanhSach();

}
void sap_xep_DTB1 (SinhVien *sv) { //Sap xep sinh vien giam dan theo diem trung binh
	
	for (int i=0; i<sosinhvien-1; i++) {
		for (int j=i+1; j<sosinhvien; j++) {
			if ( atof(sv[i].DTBTL)< atof(sv[j].DTBTL)) {
				Hoan_Vi_Tri(sinhvien[i],sinhvien[j]);
			}
		}
	}
	InDanhSach();

}
void sap_xep_MSV(SinhVien *sv){

	for (int i=0; i<sosinhvien-1; i++) {
		for (int j=i+1; j<sosinhvien; j++) {
			if ( atoi(sv[i].maSV)< atoi(sv[j].maSV)) {
				Hoan_Vi_Tri(sinhvien[i],sinhvien[j]);
			}
		}
	}
	InDanhSach();

}
void sap_xep_MSV1(SinhVien *sv){

	for (int i=0; i<sosinhvien-1; i++) {
		for (int j=i+1; j<sosinhvien; j++) {
			if ( atoi(sv[i].maSV)> atoi(sv[j].maSV)) {
				Hoan_Vi_Tri(sinhvien[i],sinhvien[j]);
			}
		}
	}
	InDanhSach();

}
void timtheoTen(SinhVien* sv)
{
	fflush(stdin);
	MakeBorder();
	MakeMainMenu();
	textcolor(MAUCHU);
	int a=3;
	textcolor(MC);
	gotoxy(80,a-1);
	fflush(stdin);
	int Ten;
	gotoxy(30,3);
	cout<<"nhap msv:";
	cin>>Ten;

	bool test=false;
	int dem=-1;	
		for (int i = 0; i < sosinhvien; i++)
		{
			int dem1=atoi(sv[i].maSV)-Ten;
			if(dem1==0)
			{		
				test=true;
				dem=i;			
				break;								
			}
		}

	if (!test)
	cout<<"\t\t\t\tKhong co ma sinh vien: "<<Ten<<" trong danh sach!";
	if(test ){
	
	gotoxy(30,5);
	cout<<"   \tMalop\tMaSV\tHo va Ten\t\tngaysinh\tdiem \n";
	inThongTinSinhVien(sinhvien[dem],6);
	}
	while(1) {
		switch(getch()) {
			case 27:
				system("cls");
				fflush(stdin);
				MainMenu(2);
			case 13:
				system("cls");
				fflush(stdin);
				MainMenu(4);
				
				break;
		}
	}
}
void thongkelop(SinhVien* sv)
{//system("cls");
	fflush(stdin);
	MakeBorder();
	MakeMainMenu();
	
	textcolor(MAUCHU);
	int a=3;
	textcolor(MC);
	gotoxy(80,a-1);
	fflush(stdin);
	int Ten;
	gotoxy(30,3);
	int dem=0;
	int dem1=0;	
	textcolor(MAUCHU);
		for (int i = 0; i < sosinhvien; i++)
		{
			if((atoi(sv[i].maLop)-123)==0)		
			{	
				dem++;													
			}
		}

	cout<<"\t\t\tlop 123 co: "<<dem<<" (sinh vien)\n";
		
		for (int i = 0; i < sosinhvien; i++)
		{
			if((atoi(sv[i].maLop)-124)==0)		
			{	
				dem1++;													
			}
		}
	textcolor(MAU);
	cout<<"\t\t\t\t\t\tlop 124 co: "<<dem1<<" (sinh vien)\n";
		textcolor(MAUCHU);
	cout<<"\t\t\t\t\t\tTong so sinh vien la: "<<dem1+dem<<" (sinh vien)";
	while(1) {
		switch(getch()) {
			case 27:
				system("cls");
				fflush(stdin);
				MainMenu(2);
			case 13:
				system("cls");
				fflush(stdin);
				MainMenu(5);
				
				break;
		}
	}
}
void thongkediemlop(SinhVien* sv)
{//system("cls");
	fflush(stdin);
	MakeBorder();
	MakeMainMenu();
	
	textcolor(MAUCHU);
	int a=3;
	textcolor(MC);
	gotoxy(80,a-1);
	fflush(stdin);
	int Ten;
	gotoxy(30,3);
	int dem=0;
	int dem1=0;
	int yeu=0;
	int tb=0;
	int kha=0;
	int gioi=0;
	int xs=0;
	int yeu1=0;
	int tb1=0;
	int kha1=0;
	int gioi1=0;
	int xs1=0;	
		for (int i = 0; i < sosinhvien; i++)
		{
			if((atoi(sv[i].maLop)-123)==0)		
			{	dem++;
				if ( atof(sv[i].DTBTL)<4)
				yeu++;
					if ( atof(sv[i].DTBTL)>=4 &&atof(sv[i].DTBTL)<6.5)
				tb++;
					if ( atof(sv[i].DTBTL)>=6.5 &&atof(sv[i].DTBTL)<7)
				kha++;
					if ( atof(sv[i].DTBTL)>=7 &&atof(sv[i].DTBTL)<8.5)
				gioi++;
					if ( atof(sv[i].DTBTL)>=8.5)
				xs++;													
			}
			
		}

		for (int i = 0; i < sosinhvien; i++)
		{
			if((atoi(sv[i].maLop)-124)==0)		
			{	dem1++;
				if ( atof(sv[i].DTBTL)<4)
				yeu1++;
					if ( atof(sv[i].DTBTL)>=4 &&atof(sv[i].DTBTL)<6.5)
				tb1++;
					if ( atof(sv[i].DTBTL)>=6.5 &&atof(sv[i].DTBTL)<7)
				kha1++;
					if ( atof(sv[i].DTBTL)>=7 &&atof(sv[i].DTBTL)<8.5)
				gioi1++;
					if ( atof(sv[i].DTBTL)>=8.5)
				xs1++;													
			}
			
		}
		int y=yeu+yeu1;
		int t=tb+tb1;
		int k=kha+kha1;
		int g=gioi+gioi1;
		int x=xs+xs1;
		int tong=dem+dem1;
		textcolor(MAU);
		cout<<"\t\t\t   ---THONG KE XEP LOAI---\n\n\n\n";
		textcolor(MAUCHU);
	cout<<"\t\t\t\tLOP |xuat sac   |goi       |kha       |trung binh |yeu       | \n\n";
	cout<<"\t\t\t\t    |sl       % |sl      % |sl      % |sl       % |sl      % | \n"; 
	cout<<"\t\t\t\t______________________________________________________________\n\n";
	cout<<"\t\t\t\t123 |"<<xs<<"        "<<roundf((float)xs/dem*10000 )/100<<"|"<<gioi<<"     "<<roundf((float)gioi/dem*10000 )/100<<"|"<<kha<<"     "<<roundf((float)kha/dem*10000 )/100<<"|"<<tb<<"      "<<roundf((float)tb/dem*10000 )/100<<"|"<<yeu<<"     "<<roundf((float)yeu/dem*10000 )/100 <<"|\n";     
	cout<<"\t\t\t\t______________________________________________________________\n\n";
	cout<<"\t\t\t\t124 |"<<xs1<<"     "<<roundf((float)xs1/dem1*10000 )/100<<"|"<<gioi1<<"    "<<roundf((float)gioi1/dem1*10000 )/100 <<"|"<<kha1<<"    "<<roundf((float)kha1/dem1*10000 )/100<<"|"<<tb1<<"     "<<roundf((float)tb1/dem1*10000 )/100<<"|"<<yeu1<<"    "<<roundf((float)yeu1/dem1*10000 )/100<<"|\n";     
	cout<<"\t\t\t\t______________________________________________________________\n\n";
	cout<<"\t\t\t\tTong|"<<x<<"     "<<roundf((float)x/tong*10000 )/100<<"|"<<g<<"    "<<roundf((float)g/tong*10000 )/100<<"|"<<k<<"    "<<roundf((float)k/tong*10000 )/100 <<"|"<<t<<"     "<<roundf((float)t/tong*10000 )/100 <<"|"<<y<<"    "<<roundf((float)y/tong*10000 )/100<<"|\n\n";     
	cout<<"\t\t\t\t\t\t\t\t      Tong so sinh vien là: "<<tong;
	while(1) {
		switch(getch()) {
			case 27:
				system("cls");
				fflush(stdin);
				MainMenu(2);
			case 13:
				system("cls");
				fflush(stdin);
				MainMenu(5);
				
				break;
		}
	}
}				
		
		
		
		
		
		
		
		
		
		
		
		
		

