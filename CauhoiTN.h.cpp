#ifndef CAUHOITN_H
#define CAUHOITN_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class CauhoiTN {
    string noidung, daA, daB, dapan;
public:
    void nhap();
    void xuat();
    void ghifile(ofstream& f);
    void docfile(ifstream& f);
    bool kiemtra();
    friend bool giongnhau(CauhoiTN cau1, CauhoiTN cau2);
};

#endif