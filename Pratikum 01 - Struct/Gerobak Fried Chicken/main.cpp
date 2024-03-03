#include <iostream>
#include <memory>
#include <vector>
#include <iomanip>
using namespace std;
struct GerobakFriedChicken{
    string Jenis;
    string JenisPotong;
    int Jumblah;
    int Harga;
    int HargaTotal;
    
    GerobakFriedChicken(string JenisVal, int JumblahVal)
        : Jenis {JenisVal}, Jumblah {JumblahVal}
    {
        if (Jenis == "D") {
            Harga = 5;
            JenisPotong = "Dada";
        }
        else if (Jenis == "P") 
        {
            Harga = 4;
            JenisPotong = "Paha";
        }
        else {
            Harga = 3;
            JenisPotong = "Sayap";
        }

        HargaTotal = Harga * Jumblah;
    }

   
};
void DisplayMenu(){
    cout << "DAFTAR HARGA" << endl;
    cout << setw(5) << left << "Kode" <<  setw(10) << left << "Jenis" <<  setw(10) << left << "Harga Per Potong" << endl;
    cout << setw(5) << left << "D" <<  setw(10) << left << "Dada" <<  setw(10) << left <<"Rp. 5000.00"<< endl;
    cout << setw(5) << left << "P" <<  setw(10) << left << "Paha" <<  setw(10) << left <<"Rp. 4000.00"<< endl;
    cout << setw(5) << left << "S" <<  setw(10) << left << "Sayap" <<  setw(10) << left <<"Rp. 3000.00"<< endl;
    cout << "\n Harga Belum Termasuk Pajak = 10%" << endl;
}
void PrintGaris (){
    for (int i = 0; i < 70; i++){
        cout << "=";
    }
    cout << endl;
}

bool LoopProgam(){
    bool Loop;
    do{
        Loop = false;
        std::string option;
        std::cout << "\n ada lagi (y/t) : ";
        std::cin >> option;
        if (option == "Y" || option == "y"){
            return true;
        }else if (option == "T" || option == "t"){
            return false;
        }else Loop = true;
    }while(Loop);
  return false;  
}
int main (){
    std::vector<std::unique_ptr<GerobakFriedChicken>> Pesanan;
    bool ProgamLoop;
     DisplayMenu();
    do{
        ProgamLoop = false;
        static int i = 1;
        string Jenis;
        string Jumblah;
        int iJumblah;
       
        cout << "Masukkan Pesanan Anda " << endl;
       
        cout << "Pesanan Anda ke " << i << endl;
        do{

            cout << "Jenis [D/P/S]\t:"; cin >> Jenis;
        }while (!(Jenis == "D" || Jenis == "P" || Jenis == "S" ));
        bool Loop;
        do
        {
            
            Loop = false;
            try {
                cout << "Jumblah\t:"; cin >> Jumblah;
                iJumblah = stoi(Jumblah);
            } catch (invalid_argument& e) {
                std::cout << "\ntidak sesuai format" << std::endl;
                Loop = true;
            }
        } while (Loop);
        Pesanan.push_back( make_unique<GerobakFriedChicken>(Jenis,iJumblah));
        i++;
        ProgamLoop = LoopProgam();
    }while(ProgamLoop);

    cout << setw(41) << "GEROBAK FRIED CHICKEN" << endl << endl;
    PrintGaris();
    cout << endl;
    cout << setw(5) << left << "No" << setw(15) << left << "Jenis Potong" <<setw(15) << left << "Harga Satuan" 
    << setw(10) << left << "Qty" << setw(15) << left << "Jumblah Harga" << endl;
    PrintGaris();
    cout << endl;
    int JumblahBayar = 0;
    for (auto const &Pesanans : Pesanan){
        static int i = 1;
        cout << setw(5) << left << i << setw(15) << left << Pesanans->JenisPotong << setw(4) << left << "Rp. " << setw(2) << left
        << Pesanans->Harga << setw(9) << left << "000.00"  << setw(10) << left << Pesanans->Jumblah << setw(15) << left << "Rp." 
        << Pesanans->HargaTotal << "000.00"   << endl;
        i++;
        JumblahBayar += Pesanans->HargaTotal;
    }
    PrintGaris();
    
    JumblahBayar *= 1000;
    cout << setw(30) << right << " " << setw (15) << left << "Jumbalah Bayar" << setw (15) << left << "Rp." << JumblahBayar << ".00" << endl;
    cout << setw(30) << right << " "  << setw (15) << left << "Pajak 10%" << setw (15) << left << "Rp." << JumblahBayar * 0.1 << ".00" <<  endl;
    cout << setw(30) << right << " " << setw (15) << left << "Jumbalah Bayar" << setw (15) << left << "Rp." << JumblahBayar + JumblahBayar * 0.1 << ".00" <<  endl;

}