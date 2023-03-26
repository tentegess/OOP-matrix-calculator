#include "nag.h"

template<typename T>
class Odw : public Macierz<T>{
private:
//użycie zmiennych z klasy Macierz
using Macierz<T>::i;
using Macierz<T>::j;
using Macierz<T>::wym;
using Macierz<T>::wiersz;
using Macierz<T>::kol;
using Macierz<T>::spr;
//zadeklarowanie zmiennych potrzebnych
// do obliczenia macierzy odwrotnej
T **m_odw, tem;

public:

//Macierz odwrotna jest obliczana
//metodą Gaussa-Jordana która polega
//na stworzeniu macierzy jednostkowej
//obok macierzy wejściowej
//a następnie przy pomocy obliczeń
//"zamienieniu" macierzy miejscami

Odw(){
  //sprawdzenie czy macierz jest kwadratowa
  if(kol==wiersz){
    
    spr=1;
    //wyświetlenie macierzy wejściowej
    std::cout<<"macierz wejściowa \n";
    this->wyswietl(wym, kol, kol);
    //zadeklarowanie tablicy mającej
    //2 razy większą szerokość niż macierz wejściowa
    m_odw=new T*[wiersz];
    for(int i = 0; i < wiersz; i++) {
      m_odw[i] = new T[kol*2];
     }

    //wypełnienie lewej strony tablicy
    //wyrazami z macierzy wejściowej
    for(i=0;i<wiersz;i++){
      for(j=0;j<kol;j++){
       m_odw[i][j]=wym[i][j];
      }}

    //utworzenie z 2 połowy tablicy
    //macierzy jednostkowej
    for(i=0;i<kol;i++)
      {
        for(j=kol;j<2*kol;j++)
        {
          if(i==j-kol)
            m_odw[i][j]=1;
            else
            m_odw[i][j]=0;
        }
      }

     for(i=0;i<kol;i++){
        tem=m_odw[i][i];
        for(j=i;j<2*kol;j++)
          m_odw[i][j]=m_odw[i][j]/tem;
        for(j=0;j<kol;j++)
        {
          if(i!=j)
          {
            tem=m_odw[j][i];
            for(int k=0;k<2*kol;k++)
            m_odw[j][k]=m_odw[j][k]-tem*m_odw[i][k];
      }}}



      for(i=0;i<wiersz;i++){
        for(j=0;j<kol;j++){
          m_odw[i][j]=m_odw[i][j+kol];
      }}

    std::cout<<"macierz odwrotna \n";
    this->wyswietl(m_odw,kol,kol);

  }else{
    //błąd jeśli macierz nie jest kwadratowa
    std::cerr<<"Macierz nie jest kwadratowa, obliczenie macierzy odwrotnej jest niemożliwe \n";
    system("PAUSE");
    exit(1);
  }

}

//usunięcie dynamicznej tablicy
//jeżeli odwrotna macierz została policzona
~Odw(){
  if(spr){
  for(i = 0; i < wiersz; i++) {
    delete [] m_odw[i];
} 
   delete [] m_odw;}
}

};