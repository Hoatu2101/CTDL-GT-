#include <iostream>
#include<string>
#include<fstream>
using namespace std;
#define max 100
struct SinhVien {
	int mssv;
	string Hovaten;
	char Ngaysinh[11];
	char Quequan[100];
	double diem;
};
void Nhap1sinhvien(SinhVien& sv) {
	cout << "Nhap mssv: ";
	cin >> sv.mssv;
	cin.ignore();
	cout << "nhap ho va ten: ";
	getline(cin, sv.Hovaten);
	cout << "Nhap ngay sinh: ";
	cin.getline(sv.Ngaysinh, 11);
	cout << "Nhap que quan: ";
	cin.getline(sv.Quequan, 100);
	cout << "Nhap diem: ";
	cin >> sv.diem;

}
void xuat1sinhvien(SinhVien sv) {
	cout << "========== Thong tin sinh vien ============= \n";
	cout << "mssv: " << sv.mssv << endl;
	cout << "Ho va ten: " << sv.Hovaten << endl;
	cout << "Ngay sinh: " << sv.Ngaysinh << endl;
	cout << "Que quan: " << sv.Quequan << endl;
	cout << "Nhap diem: " << sv.diem << endl;


}
struct ArrayList {
	SinhVien* ds;
	int SiSo;


};

void init(ArrayList& l) {
	l.ds = NULL;
	l.SiSo = 0;

}
void nhapDanhSachSinh(ArrayList &ds) {
	cout << "Nhap si so cua danh sach";
	cin >> ds.SiSo;
	ds.ds = new SinhVien[ds.SiSo];
	for (int i = 0; i < ds.SiSo; i++) {
		cout << "==== Nhap mot sinh vien thu " << i + 1 << endl;
		Nhap1sinhvien(ds.ds[i]);
	}
	
}	
void xuatDanhSachSinh(ArrayList ds) {
	for (int i = 0; i < ds.SiSo; i++) {
		cout << "\nSinh vien thu " << i + 1 << ":\n";
		xuat1sinhvien(ds.ds[i]);
	}
}
void destroyList(ArrayList& ds) {
	delete[]ds.ds;
	init(ds);
}
void docFile(ArrayList& l, string tenFile) {
	ifstream fin(tenFile);
	if (fin.is_open()) {
		if (!fin) {
			cout << "Khong mo duoc file ! ";
			return;
		}
		l.SiSo = 0;
		SinhVien sv;
		while (!fin.eof()) {
			fin >> sv.mssv;
			fin.ignore();
			getline(fin, sv.Hovaten, '#');
			fin.getline( sv.Ngaysinh,11, '#');
			fin.getline(sv.Quequan,100, '#');
			fin >> sv.diem;
			l.ds[l.SiSo] = sv;
			l.SiSo++;
			xuat1sinhvien(sv);

		}

		fin.close();
	}
}

	void pushBackArr(ArrayList & l, SinhVien x)
	{
		SinhVien* newArr = new SinhVien[l.SiSo + 1];

		for (int i = 0; i < l.SiSo; i++)
		{
			newArr[i] = l.ds[i];
		}

		newArr[l.SiSo] = x;

		delete[] l.ds;

		l.ds = newArr;
		l.SiSo++;
	}
	int Search(ArrayList& l, int id) {
		for (int i = 0; i < l.SiSo; i++) {
			if (id == l.ds[i].mssv) {
				return i;
			}
		}
		return -1;
	}
int main() {
	//SinhVien sv;
	//Nhap1sinhvien(sv);
	//xuat1sinhvien(sv);
	ArrayList ds;
	init(ds);
	/*nhapDanhSachSinh(ds);*/
	docFile(ds, "SinhVien.txt");
	////xuatDanhSachSinh(ds);
	int pos = Search(ds, 2018002);
	if (pos != -1) {
		cout << "da tim thay " << endl;
		xuat1sinhvien(ds.ds[pos]);
	}
	else
	{
		cout << "Khong tim thay !";
	}
	destroyList(ds);
	return 0;
}