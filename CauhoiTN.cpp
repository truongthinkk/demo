#include "CauhoiTN.h.cpp"

void CauhoiTN::nhap() {
    cin.ignore();
    cout << "Nhap noi dung cau hoi: ";
    getline(cin, noidung);
    cout << "Nhap dap an A: ";
    getline(cin, daA);
    cout << "Nhap dap an B: ";
    getline(cin, daB);
    do {
        cout << "Nhap dap an dung (A/B): ";
        getline(cin, dapan);
    } while (dapan != "A" && dapan != "B");
}

void CauhoiTN::xuat() {
    cout << "Cau hoi: " << noidung << endl;
    cout << "A. " << daA << endl;
    cout << "B. " << daB << endl;
    cout << "Dap an dung: " << dapan << endl;
}

void CauhoiTN::ghifile(ofstream& f) {
    f << noidung << endl << daA << endl << daB << endl << dapan << endl;
}

void CauhoiTN::docfile(ifstream& f) {
    getline(f, noidung);
    getline(f, daA);
    getline(f, daB);
    getline(f, dapan);
}

bool CauhoiTN::kiemtra() {
    cout << "Cau hoi: " << noidung << endl;
    cout << "A. " << daA << endl;
    cout << "B. " << daB << endl;
    string tl;
    do {
        cout << "Nhap dap an cua ban (A/B): ";
        getline(cin, tl);
    } while (tl != "A" && tl != "B");
    return tl == dapan;
}

bool giongnhau(CauhoiTN cau1, CauhoiTN cau2) {
    return (cau1.noidung == cau2.noidung &&
        cau1.daA == cau2.daA &&
        cau1.daB == cau2.daB &&
        cau1.dapan == cau2.dapan);
}
