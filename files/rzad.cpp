#include "nag.h"

template<typename T>
class Rz : public Macierz<T>{
//użycie zmiennych z klasy Macierz
using Macierz<T>::i;
using Macierz<T>::j;
using Macierz<T>::wym;
using Macierz<T>::wiersz;
using Macierz<T>::kol;
using Macierz<T>::spr;
//zadeklarowanie zmiennych potrzebnych
// do obliczenia rzędu
//początkowy rząd to liczba kolumn macierzy
int rzad=kol, k;
//ustawienie przyjaźni z przeciążeniem operatora 
template<typename U>
friend std::ostream& operator<<(std::ostream& os, Rz<U>& m);
public:

Rz(){
    //wyświetlenie macierzy wejściowej
    std::cout<<"macierz wejściowa \n";
        this->wyswietl(wym,wiersz,kol);


    for(i=0;i<rzad;i++){

        
        if(wym[i][i]!=0){

            for (j=0; j<wiersz; j++){
                if (i != j)
               {
                 T m = wym[j][i] /wym[i][i];
                 for (k = 0; k < rzad; k++)
                   wym[j][k] -= m * wym[i][k];
              }
           }
        }

        else{
           bool zm=true;
            for (int k = i + 1; k < wiersz;  k++)
            {
                if(wym[k][i]){
                    zamien(wym,i,k,rzad);
                    zm=false;
                    break;
                }

        }

        if(zm){
            rzad--;
            for (k = 0; k < wiersz; k ++)
                wym[k][i] = wym[k][rzad];
            }

            i--;
        }
    }

}

// metoda zamieniająca miejscami 2 wiersze;
void zamien(T **wym, int w1, int w2, int kol){
    for (k = 0; k < kol; k++)
    {
        T tem=wym[w1][k];
        wym[w1][k]=wym[w2][k];
        wym[w2][k]=tem;
    }
}

};

//przeciążenie operatora << pozwalające na wyświetlenie rzędu
template<typename T>
std::ostream& operator<<(std::ostream& os, Rz<T>& m)
{
    
    return os<<m.rzad; 
}