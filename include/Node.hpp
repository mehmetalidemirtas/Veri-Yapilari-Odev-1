/**
* @file include
* @description Düğüm için gerekli değişkenler tanımlandı
* @course 2.Öğretim B grubu
* @assignment 1
* @date 3.11.2021
* @author Mehmetali Demirtas mehmetali.demirtas@ogr.sakarya.edu.tr
*/
#ifndef Node_hpp
#define Node_hpp
#include<iostream>
using namespace std;

class Node
{
public:
    Node(string data);
    Node();
    string data;
    Node* next;
    Node* prev;
};

#endif