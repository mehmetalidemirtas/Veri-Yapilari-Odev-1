/**
* @file src
* @description Çift yönlü bağıl listedeki düğüm için gerekli işlemler yapıldı
* @course 2.Öğretim B grubu
* @assignment 1
* @date 3.11.2021
* @author Mehmetali Demirtas mehmetali.demirtas@ogr.sakarya.edu.tr
*/
#include "Node.hpp"

Node::Node(string data)
{
    this->data = data;
    prev = next =0;

}
Node::Node(){ //Sona eklenen boş düğüm için tanımlandı
    prev=next=0;
}