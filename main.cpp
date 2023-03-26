#include "files/nag.h"  //plik z plikami nagłówkowymi wykorzystanymi w programie
#include "files/macierz.cpp"
#include "files/mnozenie.cpp"
#include "files/transp.cpp"
#include "files/wyz.cpp"
#include "files/m_odw.cpp"
#include "files/rzad.cpp"



void menu(){
    int wyb;
    // menu wyboru
    std::cout<<"Kalkulator Macierzy \n \n";
    std::cout<<"Wybierz operację do wykonania: \n";
    std::cout<<"1.Odejmowanie \n";
    std::cout<<"2.Dodawanie \n";
    std::cout<<"3.Mnożenie \n";
    std::cout<<"4.Transponowanie \n";
    std::cout<<"5.Wyznacznik \n";
    std::cout<<"6.Macierz odwrotna \n";
    std::cout<<"7.Rząd macierzy \n";
    std::cin>>wyb;

    switch (wyb){
        case 1:
        case 2:{
    //dodawanie i odejmowanie macierzy,
    //program tworzy 2 obiekty odpowiadające macierzom
    //następnie dodaje lub odejmuje macierze poprzez przeciążenie operatorów        
           std::cout<<"1 Macierz \n";  
           Macierz<double> mac1;
           std::cout<<"2 Macierz \n"; 
           //do 2 obiektu są przekazywane wymiary 1 macierzy
           Macierz<double> mac2(mac1.kol, mac1.wiersz);
           switch(wyb){
            case 1:{
                mac1-mac2;
                break;
                 }
            case 2:{
                mac1+mac2;
                break;
                 }
            default:
            break;     
            
           }
        
            break;}
        case 3:{
           std::cout<<"1 Macierz \n";  
           Mnozenie<double> mn1;
           std::cout<<"2 Macierz \n"; 
           Mnozenie<double> mn2;
           mn1*mn2;
            
            break;}   
        //do transponowania macierzy, obliczenia
        // wyznacznika oraz rzędu 
        // zostają użyte osobne klasy
        case 4:{
           Transp<double> tr; 
           break;
        }

        case 5:{
           Wyz<double> wz; 

           std::cout<<"wyznacznik macierzy \n"<< wz<<std::endl;
           break;
        } 

        case 6:{
           Odw<double> mac; 
           break;
        }     
   
        case 7:{
           Rz<double> rz; 

           std::cout<<"rząd macierzy \n"<< rz<<std::endl;
           break;
        }  
        
        default:
            break;


    }
}

int main(){
    //Wyczyszczenie konsoli przed rozpoczęciem
    //działania programu
    system("cls");
    //Polskie znaki
    SetConsoleOutputCP(CP_UTF8);
    //menu wyboru działań
    menu();
    system("PAUSE");
    return 0;
}