#include <iostream>
using namespace std;
#include <iostream>
#include <cstring>

struct date { /* definisi global dari tipe date */
int month;
int day;
int year;
};
struct student{ /* definisi global dari tipe student */
char name[30];
struct date birthday;
};
/* deklarasi global dari variabel mhs*/
struct student mhs;
int main()
{
/* memberikan nilai kepada field dari struktur mhs */
strcpy(mhs.name, "MUHAMMAD IHSAN");
mhs.birthday.month = 8;
mhs.birthday.day = 10;
mhs.birthday.year = 1970;
/* menampilkan isi semua field dari struktur mhs */
cout << "Nama\t:" << mhs.name << endl;
cout << "Tanggal Lahir\t" << mhs.birthday.day << "/" << mhs.birthday.month << "/" << mhs.birthday.year << endl;
}
