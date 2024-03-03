/* File program : student2.c
Array struktur untuk menyimpan data-data student */
#include <stdio.h>
#define MAKS 20
struct date { //definisi global dr tipe date
int month;
int day;
int year;
};
struct student { //definisi global dr tipe student
char name[30];
struct date birthday;
};
//deklarasi global dari variabel student
struct student data_mhs[MAKS];
int main()
{
int i=0, sudah_benar, jml;
char lagi;
//memasukkan data
do
{
printf("Name : ");

fgets(data_mhs[i].name,sizeof data_mhs[i].name,stdin);
printf("Birthday (mm-dd-yyyy): ");
scanf("%d-%d-%d",
&data_mhs[i].birthday.month,
&data_mhs[i].birthday.day,
&data_mhs[i].birthday.year);
printf("\n");
i++;
printf("Mau memasukkan data lagi [Y/T] ? ");
do
{
lagi = getchar( ); //baca tombol
sudah_benar = (lagi == 'Y') || (lagi== 'y')||
(lagi == 'T') || (lagi == 't');
} while(! sudah_benar);
//hapus sisa data dalam penampung keyboard
fflush(stdin);
printf("\n");
} while(lagi == 'Y' || lagi == 'y');
jml = i;
//menampilkan data
printf("DATA SISWA\n");
for (i=0; i<jml; i++)
{
printf("%d. Name : %s", i+1, data_mhs[i].name);
printf(" Birthday : %d-%d-%d\n\n",
data_mhs[i].birthday.month,
data_mhs[i].birthday.day,
data_mhs[i].birthday.year );
};
    return 0;
}