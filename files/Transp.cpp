#include "nag.h"

template<typename T>
class Transp : public Macierz<T>{
private:
//zadeklarowanie zmiennych potrzebnych
//do transponowania macierzy
T **tWym;
unsigned int t_kol,t_wiersz;
//użycie zmiennych z klasy macierz
using Macierz<T>::i;
using Macierz<T>::j;
using Macierz<T>::wym;
using Macierz<T>::wiersz;
using Macierz<T>::kol;
public: 



Transp(){
  //wyświetlenie macierzy wejściowej
  std::cout<<"Macierz pierwotna \n";
  this->wyswietl(wym,wiersz,kol); 
  //nadanie zmiennym odpowiednich wartości
  t_kol=wiersz;
  t_wiersz=kol;
  //stworzenie nowej tablicy dynamicznej
  //w której zostanie przechowana
  //transponowana macierz
  tWym=new T*[t_wiersz];
     for(int i = 0; i < t_wiersz; i++) {
      tWym[i] = new T[t_kol];
     }     
    //
     for(i=0;i<t_wiersz;i++){
         for(j=0;j<t_kol;j++){  
          tWym[i][j]=wym[j][i];
        }}

    //wyświetlenie transponowanej macierzy
   std::cout<<"Macierz transponowana \n";
   //std::swap(kol,wiersz);
   this->wyswietl(tWym,t_wiersz,t_kol); 
    
}

//Destruktor usuwający
//dynamiczną tablicę
//podczas niszczenia obiektu
~Transp(){
  for(i = 0; i < t_wiersz; i++) {
    delete [] tWym[i];
} 
   delete [] tWym;

}
};