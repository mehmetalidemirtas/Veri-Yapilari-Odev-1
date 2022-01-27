/**
* @file include
* @description Ödevde istenilen fonksiyonların tanımlanması
* @course 2.Öğretim B grubu
* @assignment 1
* @date 3.11.2021
* @author Mehmetali Demirtas mehmetali.demirtas@ogr.sakarya.edu.tr
*/
#ifndef List_hpp
#define List_hpp
#include "Node.hpp"
#include<exception>

class List
{
public:
    List();
    ~List();
    void addToEnd(string data);            //sona ekle
    void addToIndex(int index, string data);//verilen indekse ekle
    void deleteFromTheEnd();               //sondan sil
    void deleteFromIndex(int index);        //verilen indeksi sil
    void printToScreen();                  //ekrana yazdır
    Node* getNode(int data);               //Verilen indeksteki düğümü getir

private:
    Node* head;
};

#endif