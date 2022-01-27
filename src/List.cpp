/**
* @file src
* @description Liste.hpp de tanımlanan fonksiyonlar yazılı
* @course 2.Öğretim B grubu
* @assignment 1
* @date 7.11.2021
* @author Mehmetali Demirtas mehmetali.demirtas@ogr.sakarya.edu.tr
*/
#include "List.hpp"
#include<iomanip>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
List::List()
{
    head=0;
}
List::~List() //Yok Edici
{
    Node* temp=head;
    while(temp!=0)
    {
        Node* deleteNode=temp;
        temp=temp->next;
        delete deleteNode;
    }
}

void List::addToEnd(string data)    //Sona ekleme fonksiyonu
{
    Node* newNode = new Node(data);

    if(head==0)       //Tek düğüm olup olmadığı kontrol ediliyor.
    {
        head = newNode;
    }
    else 
    {
        Node* temp = head;

        while(temp->next!=NULL)   //son dugume kadar ilerle
        {
            temp=temp->next;
        }                        //Gec son dugumu gösteriyor

        //Sona eklenecek
        temp->next = newNode;  //temp son dugum degıl, yeni dugum olacak
                                
        newNode->prev=temp;   //yeni dugumun onceki ile olan bağlantısı kuruluyor

    }
} 

void List::deleteFromTheEnd()   //sondan eleman silme fonksiyonu
{
    if(head->next==NULL)    //eger ikinci dugum yoksa ilk dugum silinecek
    {
        delete head;
        head=0;
    }
    else 
    {
        Node* temp = head;
        while(temp->next->next!=NULL) //Son dugumden oncesinin oncesine gelinir
        {                            // ve son dugumden sonraki silinir
            temp= temp->next;
        }
        delete temp->next;
        temp->next=0;
    }
}

void List::addToIndex(int index,string data){    //Araya ekleme fonksiyonu

    Node* newNode = new Node();
    Node* incomingNode = getNode(index);

    if(incomingNode){

        Node* temp = head;

        while(temp->next!=NULL){    //Son dugume git

            temp=temp->next;
        }

        temp->next=newNode;        //Sona yeni dugum eklendi
        newNode->next=0;          //Yeni dugumun bağlantıları yapılıyor
        newNode->prev=temp;

        while(newNode!=incomingNode){  //Veriler sağa dogru kaydırılarak kopyalanıyor

            newNode->data=temp->data;
            temp=temp->prev;
            newNode=newNode->prev;
        }

        newNode->data=data;       //Belirtilen indexe veri ekleniyor
    }
    else        //Aranan index bulunamadıgı için veri sona ekleniyor
    {
        List::addToEnd(data);
    }
}

void List::deleteFromIndex(int index) //Aradan silme fonksiyonu
{
    Node* deleteNode = getNode(index);
    if(deleteNode)
    {
        if(deleteNode->next==0){    //Eğer silinmek istenen dugum son dugum ise sondan sil fonksiyonu kullanılıyor

            List::deleteFromTheEnd();

        }else    //Eger silinmek istenen son dugum degil ise;
        {

            Node* rightNode= deleteNode->next;
        
            while(rightNode->next!=NULL){    //Sola dogru kaydırılarak veriler kopyalanıyor

                deleteNode->data=rightNode->data;
                rightNode=rightNode->next;
                deleteNode=deleteNode->next;
            }

            Node* temp = head;      //Son dugumdeki veriyi bir öncekine eklemede sorun 
            while(temp->next!=NULL){//yaşadığım için son düğüm verisini ayrı olarak burada kopyaladım!!
                temp=temp->next;
            }

            Node* beforeLastNode=temp->prev;  //Son dugume veri kaydırılıyor
            beforeLastNode->data=temp->data;
  
            delete rightNode; //Sonda aynı iki veri oluştugu için son dugum siliniyor
            deleteNode->next=0;

        }
    }
     else//aranan dugum yoksa son dugum silinecek
    {
        List::deleteFromTheEnd(); 
    }
}

Node* List::getNode(int index) //Aranan dugumu listeden bulan fonksiyon
{
    Node* temp = head;
    int counter=0;

    while(temp!=NULL) //Listenin sonuna kadar düğümün olup olmadıgı sayac ile aranıyor.
    {
        if(counter==index)
        {
            return temp;
        }
        temp= temp->next;
        counter++;
    }
    return 0;//eğer liste boş veya sayı büyük ise sonlanıyor
}

void List::printToScreen()  //Temp ile liste baştan sona gezilerek veriler ekrana basılıyor
{
    Node* temp = head;
    
    while(temp->next!=NULL){ //Sondan onceki elemana kadar veriler yazdırıldı

        cout<<temp->data<<"<-->";
        temp=temp->next;       
    }
    cout<<temp->data;
}