#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int JUMLAH_SISWA = 20;

struct studentType {
    string namaDepan;
    string namaBelakang;
    int nilaiTes;
    char grade;
};

void inputData(studentType siswa[]);
void beriGrade(studentType siswa[]);
int cariNilaiTertinggi(studentType siswa[]);
void tampilSiswaTertinggi(studentType siswa[], int nilaiTertinggi);
void tampilSemua(studentType siswa[]);

int main() {
    studentType siswa[JUMLAH_SISWA];

    inputData(siswa);
    beriGrade(siswa);
    int tertinggi = cariNilaiTertinggi(siswa);
    
    tampilSemua(siswa);
    cout << "\nNilai Tertinggi: " << tertinggi << endl;
    tampilSiswaTertinggi(siswa, tertinggi);

    return 0;
}

void inputData(studentType siswa[]) {
    cout << "Masukkan nama depan, nama belakang, dan nilai tes untuk 20 siswa:\n";
    for (int i = 0; i < JUMLAH_SISWA; i++)
        cin >> siswa[i].namaDepan >> siswa[i].namaBelakang >> siswa[i].nilaiTes;
}

void beriGrade(studentType siswa[]) {
    for (int i = 0; i < JUMLAH_SISWA; i++) {
        if (siswa[i].nilaiTes >= 90) siswa[i].grade = 'A';
        else if (siswa[i].nilaiTes >= 80) siswa[i].grade = 'B';
        else if (siswa[i].nilaiTes >= 70) siswa[i].grade = 'C';
        else if (siswa[i].nilaiTes >= 60) siswa[i].grade = 'D';
        else siswa[i].grade = 'F';
    }
}

int cariNilaiTertinggi(studentType siswa[]) {
    int tertinggi = siswa[0].nilaiTes;
    for (int i = 1; i < JUMLAH_SISWA; i++)
        if (siswa[i].nilaiTes > tertinggi) tertinggi = siswa[i].nilaiTes;
    return tertinggi;
}

void tampilSiswaTertinggi(studentType siswa[], int nilaiTertinggi) {
    cout << "\nSiswa dengan nilai tertinggi:\n";
    for (int i = 0; i < JUMLAH_SISWA; i++)
        if (siswa[i].nilaiTes == nilaiTertinggi)
            cout << siswa[i].namaBelakang << ", " << siswa[i].namaDepan << endl;
}

void tampilSemua(studentType siswa[]) {
    cout << left << setw(20) << "\nNama"
         << setw(10) << "Nilai"
         << "Grade" << endl;
    cout << "--------------------------------------\n";

    for (int i = 0; i < JUMLAH_SISWA; i++) {
        string nama = siswa[i].namaBelakang + ", " + siswa[i].namaDepan;
        cout << left << setw(20) << nama
             << setw(10) << siswa[i].nilaiTes
             << siswa[i].grade << endl;
    }
}