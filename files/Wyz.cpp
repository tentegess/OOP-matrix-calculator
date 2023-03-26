#include "nag.h"

template<typename T>
class Wyz : public Macierz<T>{
private:
//zadeklarowanie zmiennych potrzebnych
// do obliczenia wyznacznika
unsigned int k, wewn_i, wewn_j; 
T **wewn;
//ustawienie przyjaźni z przeciążeniem operatora 
template<typename U>
friend std::ostream& operator<<(std::ostream& os, Wyz<U>& m);
//użycie zmiennych z klasy Macierz
using Macierz<T>::i;
using Macierz<T>::j;
using Macierz<T>::wym;
using Macierz<T>::wiersz;
using Macierz<T>::kol;
using Macierz<T>::spr;
T wyz;

public: 

Wyz(){
     
        //sprawdzenie czy macierz jest kwadratowa
    if(kol==wiersz){
        spr=1;
        // wyświetlenie macierzy wejściowej
        std::cout<<"macierz wejściowa \n";
        this->wyswietl(wym,kol,kol);
        // wywołanie funkcji obliczającej wyznacznik
        wyz=wyzn(wym, kol);       
    }
    else{
        //błąd jeśli macierz nie jest kwadratowa
        std::cerr<<"Macierz nie jest kwadratowa, obliczenie wyznacznika jest niemożliwie \n";
        system("PAUSE");
    exit(1);}

}
//metoda obliczająca wyznacznik
//wyznacznik jest obliczany metodą Laplace'a
//metoda jest wykonywana rekurencyjnie
//dopóki wymiary wewnętrznej tablicy
//nie osiągną 2x2
//metoda została oparta na funkcji przedstawionej
//w poniższym filmie:
//https://www.youtube.com/watch?v=BX3Kq6-nQps
T wyzn(T **wym, int r){
    
    
         if (r==1)
           return wym[0][0];
        if (r==2)
            return ((wym[0][0]*wym[1][1])-(wym[1][0]*wym[0][1]));
        else{   
                wewn=new T*[r];
                for(int i = 0; i < r; i++) {
                wewn[i] = new T[r];
                }
                wyz=0;
                for (int i=0; i<r;i++) {
                    wewn_i=0;
                     for (int j= 1; j < r; j++) {
                        wewn_j=0;
                        for (int k = 0; k < r; k++) {
                            if (k != i){
                            wewn[wewn_i][wewn_j] = wym[j][k];
                            wewn_j++;}
                            }
                            wewn_i++;
                     }
                    wyz=wyz+(pow(-1,i)*wym[0][i]*wyzn(wewn, r-1));
                }

        }
        return wyz;


}


//destruktor usuwający dynamiczną tablicę jeśli
//wyznacznik został obliczony
~Wyz(){
    if(spr){
   for(i = 0; i < kol; i++) {
    delete [] wewn[i];
} 
   delete [] wewn;}}

};

//przeciążenie operatora << pozwalające na wyświetlenie wyznacznika 
template<typename T>
std::ostream& operator<<(std::ostream& os, Wyz<T>& m)
{
    
    return os<<m.wyz; 
}