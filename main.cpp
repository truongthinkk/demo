#include <iostream>
#include <vector>
#include <fstream>
#include "CauhoiTN.h.cpp"
using namespace std;

vector<CauhoiTN> deThi;

void taoDeThiMoi() {
    deThi.clear();
    cout << "Da tao de thi moi.\n";
}

void themCauHoi() {
    CauhoiTN ch;
    ch.nhap();
    deThi.push_back(ch);
}

void inDanhSachCauHoi() {
    for (int i = 0; i < deThi.size(); ++i) {
        cout << "\nCau hoi " << i + 1 << ":\n";
        deThi[i].xuat();
    }
}

void luuVaoFile() {
    string filename;
    cout << "Nhap ten file (.TTN): ";
    cin >> filename;
    ofstream f(filename);
    f << deThi.size() << endl;
    for (auto& ch : deThi) ch.ghifile(f);
    f.close();
    cout << "Da luu vao file " << filename << endl;
}

void docTuFile() {
    string filename;
    cout << "Nhap ten file (.TTN): ";
    cin >> filename;
    ifstream f(filename);
    if (!f.is_open()) {
        cout << "Khong mo duoc file!" << endl;
        return;
    }
    int n;
    f >> n;
    f.ignore();
    deThi.clear();
    for (int i = 0; i < n; ++i) {
        CauhoiTN ch;
        ch.docfile(f);
        deThi.push_back(ch);
    }
    f.close();
    cout << "Da doc " << n << " cau hoi tu file." << endl;
}

void thiTracNghiem() {
    int dung = 0;
    cout << "---- BAT DAU THI ----\n";
    for (auto& ch : deThi) {
        if (ch.kiemtra()) {
            cout << "Dung!\n";
            ++dung;
        }
        else {
            cout << "Sai!\n";
        }
    }
    cout << "So cau tra loi dung: " << dung << "/" << deThi.size() << endl;
}

int main() {
    int chon;
    do {
        cout << "\n Tran Truong Thinh-mssv:062206002399\n";
        cout << "\n====== MENU ======\n";
        cout << "1. Tao de thi moi\n";
        cout << "2. Them cau hoi\n";
        cout << "3. In danh sach cau hoi\n";
        cout << "4. Luu de thi vao file\n";
        cout << "5. Doc de thi tu file\n";
        cout << "6. Cho thi va tinh diem\n";
        cout << "0. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> chon;
        switch (chon) {
        case 1: taoDeThiMoi(); break;
        case 2: themCauHoi(); break;
        case 3: inDanhSachCauHoi(); break;
        case 4: luuVaoFile(); break;
        case 5: docTuFile(); break;
        case 6: thiTracNghiem(); break;
        case 0: cout << "Tam biet!\n"; break;
        default: cout << "Chuc nang khong hop le!\n";
        }
    } while (chon != 0);
    return 0;
}
