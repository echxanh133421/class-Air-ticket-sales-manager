// quan li ban ve may bay.cpp :

#include <iostream>
#include<string>
using namespace std;

class Date {
protected:
    int ngay, thang, nam;
public:
    Date() {
        ngay = 0;
        thang = 0;
        nam = 0;
    }
    ~Date() {
        ngay = 0;
        thang = 0;
        nam = 0;
    }
    void set() {
        cout << "nhap ngay bay:\n";
        cin >> this->ngay >> this->thang >> this->nam;
    }
    void output() {
        cout << "ngay bay: " << this->ngay << "/" << this->thang << "/" << this->nam << endl;
    }

};

class vemaybay {
protected:
    string tenchuyen;
    int giave;
    Date day;
public:
    vemaybay() {
        tenchuyen = "";
        giave = 0;
    }
    ~vemaybay() {
        tenchuyen = "";
        giave = 0;
    }
    void nhap() {
        cout << "nhap ten chuyen\n";
        cin.ignore();
        getline(cin,this->tenchuyen);
        day.set();
        cout << "nhap gia ve:\n";
        cin >> giave;
    }
    void xuat() {
        cout << "chuyen: "<<tenchuyen<<endl;
        day.output();
        cout << "giave: " << giave<<endl;
    }

    int getgiave() {
        return this->giave;
    }
};

class nguoi {
protected:
    string hoten;
    string gioitinh;
    int tuoi;
public:
    nguoi() {
        hoten = "";
        gioitinh = "";
        tuoi = 0;
    }
    ~nguoi() {
        hoten = "";
        gioitinh = "";
        tuoi = 0;
    }
    void nhap() {
        cout << "ten: ";
        cin.ignore();
        getline(cin, this->hoten);
        cout << "giotinh: ";
        getline(cin , this->gioitinh);
        cout << "tuoi: ";
        cin >> this->tuoi;

    }
    void xuat() {
        cout << "ten: " << hoten << endl;
        cout << "gioitinh:" << gioitinh << endl;
        cout << "tuoi :" << tuoi<<endl;
    }
};

class hanhkhach:public nguoi {
private:
    vemaybay ve[1000];
    int soluong;
public:
    hanhkhach() {
        
        soluong = 0;
    }
    ~hanhkhach() {
        
        soluong = 0;
    }
    void nhap() {
        nguoi::nhap();
        cout << "so luong: ";
        cin >> soluong;
        cout << "nhap thong tin cac ve:\n";
        for (int i = 0; i < soluong; i++) {
            ve[i].nhap();
        }

    }
    void xuat() {
        nguoi::xuat();
        cout << "cac ve:\n";
        for (int i = 0; i < soluong; i++) {
            ve[i].xuat();
            cout << "\n-----\n";
        }
        cout << "tongtien: " << tongtien()<<endl;
    }
    int tongtien() {
        int tong = 0;
        for (int i = 0; i < soluong; i++) {
            tong += ve[i].getgiave();
        }
        return tong;
    }

};
bool kiemtra(hanhkhach a, hanhkhach b) {
    if (a.tongtien() > b.tongtien()) {
        return true;
    }
    else {
        return false;
    }
}
void sort(hanhkhach* arr, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (kiemtra(arr[i],arr[j])) {
                hanhkhach c = arr[i];
                arr[i] = arr[j];
                arr[j] = c;
            }
        }
    }
}

int main()
{
    int n;
    cout << "nhap vao so hanh khach\n";
    cin >> n;
    hanhkhach* arr = new hanhkhach[n];
    cout << "nhap thong tin cac hanh khach:\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ".";
        arr[i].nhap();
    }
    sort(arr, n);
    cout << "\n\ndanh sach hanh khach\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1;
        arr[i].xuat();
        cout << "\n--------------------------\n";
    }
    delete []arr;
    arr = NULL;
    return 0;
}