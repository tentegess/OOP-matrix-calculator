#include "nag.h"

template<typename T>
class Mnozenie : public Macierz<T>{
private:
//zadeklarowanie zmiennych potrzebnych
// do wykonania mnożenia
T **mnWym;
unsigned mn_wiersz,mn_kol;
//użycie zmiennych z klasy Macierz
using Macierz<T>::i;
using Macierz<T>::j;
using Macierz<T>::wym;
using Macierz<T>::wiersz;
using Macierz<T>::kol;
using Macierz<T>::spr;
public: 

Mnozenie() {

 

}


//przeciążenie mnożenia
void operator*(Mnozenie& m2){
    //sprawdzenie czy wymiary Macierzy
    //pozwalają na wykonanie mnożenia
    if(this->kol==m2.wiersz){
        //jeśli mnożenie jest wykonalne
        //zmienna spr przyjmie wartość true
        spr=1;
        //nadanie zmiennym odpowiednich wartości
        mn_wiersz=this->wiersz;
        mn_kol=m2.kol;
        //stworzenie nowej tablicy dynamicznej
        //w której zostanie przechowany wynik 
        //mnożenia
        mnWym=new T*[mn_wiersz];
        for(int i = 0; i < mn_wiersz; i++) {
            mnWym[i] = new T[mn_kol];
        } 
        //wyświetlenie mnożonych wartości
        this->wyswietl(this->wym,this->wiersz,this->kol);
        std::cout<<"* \n";
        m2.wyswietl(m2.wym,m2.wiersz,m2.kol);
        std::cout<<"= \n";
        //mnożenie macierzy
        //każdy wyraz to
        //suma iloczynów
        //kolejnych wartości
        //wierszy 1 i kolumn 2 macierzy
        for(i=0;i<mn_wiersz;i++)
            {
                for(j=0;j<mn_kol;j++)
                {
                    for(int k=0;k<this->kol;k++)
                    {mnWym[i][j]+=this->wym[i][k]*m2.wym[k][j];}
                }
            }
            //wyświetlenie wyniku mnożenia
            this->wyswietl(mnWym,mn_wiersz,mn_kol);
        }
else{
    //błąd jeśli wymiary macierzy
    //nie pozwalają na mnożenie
std::cerr<<"Liczba kolumn pierwszej i rzędów drugiej macierzy nie jest równa, mnożenie jest niewykonalne";
system("PAUSE");
exit(1);
}

}

~Mnozenie(){
    //usunięcie dynamicznej tablicy
    //jeżeli mnożenie zostało wykonane
    if(spr){
    for(i = 0; i < mn_wiersz; i++) {
    delete [] mnWym[i];
} 
   delete [] mnWym;}

}
};