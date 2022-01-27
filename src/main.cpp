/**
* @file src
* @description Dosyadan okuma ve gerekli fonksiyonların çalıştırılması
* @course 2.Öğretim B grubu
* @assignment 1
* @date 30.10.2021
* @author Mehmetali Demirtas mehmetali.demirtas@ogr.sakarya.edu.tr
*/
#include<iostream>
#include<iomanip>
#include <sstream>
#include <fstream>
#include "List.hpp"

using namespace std;

int main()
{
    List* list = new List(); //List nesnesi oluşturuldu.

    ifstream ReadFile("./doc/Veri.txt");//Veri.txt dosyasından okuma

    if(ReadFile.fail())//Dosya acılmazsa ekrana error yaz
    {
        cout<<"Error";
    }else//Eger dosya acılırsa
    {
        string readLine;
        while (getline(ReadFile, readLine))
        {                   
            //String içerisinde arayabilmek için unsigned tanımlandı.String tanımlayarak kullanamadım
            unsigned findFirstChr = readLine.find("(");      //Substring'in okunan satırda ( karakterini bulması için tanımlandı
            unsigned findChrForIndex = readLine.find("#");  //Substring'in okunan satırda # karakterini bulması için tanımlandı
            unsigned finfLastChr = readLine.find(")");   //Substring'in okunan satırda ) karakterini bulması için tanımlandı

            
            string indexForAdd = readLine.substr(findFirstChr+1,findChrForIndex-findFirstChr-1); //Veri eklemek için verilen index okunan satırdan bulundu
            int sizeOfIndexForAdd = indexForAdd.size(); //Okunan index birden fazla karakterli olabileceği için karakter uzunluğunu buldum
            int sizeOfLine = readLine.length();         //Okunan satırın uzunluğu bulundu.
            string sizeOfDeleteIndex = readLine.substr(findFirstChr+1,sizeOfLine-3);
            string dataForAdd = readLine.substr(findChrForIndex+1,sizeOfLine-4-sizeOfIndexForAdd); //Eklenecek veri satır içerisinden substr ile bulundu

            if(readLine.find_first_of('E')==0){ //Eğer ilk karakter E ise ekleme işlemi yapılacak

                list->addToIndex(stoi(indexForAdd),dataForAdd);

            }else{ //İlk karakter E değilse (S ise) silme işlemi yapılacak

                list->deleteFromIndex(stoi(sizeOfDeleteIndex));
            }                      
        }      
        ReadFile.close();
    }
    list->printToScreen();
    delete list;
    return 0 ;
}