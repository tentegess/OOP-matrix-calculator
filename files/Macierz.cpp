#include "nag.h"

template<typename T>
class Macierz{
 //ustawienie przyjaźni z funkcją menu 
 friend void menu(); 
 protected:
 //zadeklarowanie odpowiednich zmiennych
 unsigned int kol,wiersz,i,j;
 T **wym;
 bool typ, spr=0;

 public:
//metoda odpowiedzialna za wprowadzenie danych do macierzy
 void wyp(){
      for(i=0;i<wiersz;i++){
       do{
         std::cout<<"Wprowadź kolejne wartości "<<i+1<<" wiersza macierzy \n";
         typ=0; 
         for(j=0;j<kol;j++){  
          std::cin>>wym[i][j];
        }
        // jeżeli do macierzy zostanie wprowadzona
        // wartość poza zakresem zmiennej
        // należy ponownie uzupełnić wiersz
        if(std::cin.fail()){
            std::cout<<"w wierszu znalazła się niedozwolona wartość, proszę ponownie wprowadzić dane do wiersza \n \n";
            typ=1;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          }
        //zapętlenie wiersza dopóki wszystkie danie
        //nie zostaną poprawnie wprowadzone
        }while(typ);}
        //usunięcie bitu błędu
        std::cin.clear();
        //ignorowanie wszystkich wprowadzonych znaków
        //po wypełnieniu macierzy
        //aż do wprowadzenia znaku następnej linii
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
 }


    //konstruktor bezargumentowy
    //użytkownik jest proszony o podanie
    //wymiarów macierzy
    //a następnie wprowadzenie danych
    Macierz(){
     std::cout<<"Wprowadź liczbę wierszy \n";
     std::cin>>wiersz;
     std::cin.clear();
     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
     std::cout<<"Wprowadź liczbę kolumn \n";
     std::cin>>kol;
     std::cin.clear();
     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
     
     //zadeklarowanie nowej tablicy
     //mającej wymiary macierzy
     wym=new T*[wiersz];
     for(int i = 0; i < wiersz; i++) {
      wym[i] = new T[kol];
     }
     
     //wywołanie metody wypełniającej tablicę
     wyp();
     system("cls");
     
 }
    //konstruktor 2-argumentowy
    //gdzie przekazywane są wymiary macierzy
    Macierz(int a, int b){
     kol=a;
     wiersz=b;

     wym=new T*[wiersz];
     for(int i = 0; i < wiersz; i++) {
      wym[i] = new T[kol];
     }
     wyp();
     system("cls");
     
 }

//metoda wyświetlająca macierz
 void wyswietl(T **wyp, int rz, int kl){
     for(i=0;i<rz;i++){
         std::cout<<"|";
           for(j=0;j<kl;j++){
               std::cout.width(5);
               std::cout<<wyp[i][j]<<" ";
            }
     std::cout.width(6);
     std::cout<<" |\n";
     }
     
 }

//przeciążenie dodawania
void operator+(Macierz& m2){
     if(m2.kol == this->kol&&m2.wiersz == this->wiersz)//sprawdzenie czy wymiary obu macierzy 
     //pozwalają na wykonanie dodawania
      {
        //wyświetlenie dodawanych macierzy
        this->wyswietl(this->wym,this->wiersz,this->kol);
      std::cout<<"+ \n";
      m2.wyswietl(m2.wym,m2.wiersz,m2.kol);
      std::cout<<"= \n";
      //wyświetlenie wyniku dodawania macierzy
      for(i = 0; i < this->wiersz; i++) {
          std::cout<<"|";
          for(j = 0; j < this->kol; j++) {
            std::cout.width(5);   
            std::cout <<this->wym[i][j]+m2.wym[i][j]<<" ";
      } std::cout.width(6);
        std::cout <<" |\n";}
      } else {
        //błąd jeśli macierze mają rózne wymiary
      std::cerr << "Wprowadzone macierze mają różne wymiary, dodawanie jest niemożliwe do wykonania\n";
      system("PAUSE");
      exit(1);
    }
 }

 void operator-(Macierz& m2){
     
     if(m2.kol == this->kol&&m2.wiersz == this->wiersz) {
      this->wyswietl(this->wym,this->wiersz,this->kol);
      std::cout<<"- \n";
      m2.wyswietl(m2.wym,m2.wiersz,m2.kol);
      std::cout<<"= \n";
      for(i = 0; i < this->wiersz; i++) {
          std::cout<<"|";
          for(j = 0; j < this->kol; j++) {
            std::cout.width(5);   
            std::cout <<this->wym[i][j]-m2.wym[i][j]<<" ";
      } std::cout.width(6);
        std::cout <<" |\n";}
      } else {
      std::cerr << "Wprowadzone macierze mają różne wymiary, odejmowanie jest niemożliwe do wykonania\n";
      system("PAUSE");
      exit(1);
    }
 }

 
 //destruktor usuwający tablicę dynamiczną
 // podczas niszczenia obiektu
~Macierz(){
   for(i = 0; i < wiersz; i++) {
    delete [] wym[i];
} 
   delete [] wym;
}


};

