/* File program : zodiak.c
Menentukan zodiak berdasarkan data tanggal lahir masukan */
#include <stdio.h>
int main()
{
struct zodiak {
char nama[11];
int tgl_awal;
int bln_awal;
int tgl_akhir;
int bln_akhir;
};
static struct zodiak bintang =
{"Sagitarius", 22, 11, 21, 12};
int tgl_lhr, bln_lhr, thn_lhr;
printf("Masukkan tgl lahir Anda (XX-XX-XXXX): ");
scanf("%d-%d-%d",&tgl_lhr, &bln_lhr, &thn_lhr);
if((tgl_lhr >= bintang.tgl_awal && bln_lhr ==
bintang.bln_awal) || (tgl_lhr <= bintang.tgl_akhir &&
bln_lhr == bintang.bln_akhir))
printf("Bintang Anda adalah %s\n", bintang.nama);
else
printf("Bintang Anda bukan %s\n", bintang.nama);
    return 0;
}