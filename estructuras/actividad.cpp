#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//dsa
int main()
{
     int i = 1;
     vector<int> vectorAlea;
     deque<int> dequeAlea;
     list<int> listAlea;
     //iterador reverso
     vector<int>::reverse_iterator iteraR;
     deque<int>::reverse_iterator iteraDequeR;
     list<int>::reverse_iterator iteraListR;
     //iterador 
     vector<int>::iterator itera;
     deque<int>::iterator iteraDeque;
     list<int>::iterator iteraList;
     int random;
     //llenado de datos
     for (int i = 0; i < 24; i++)
     {
          random = rand();
          vectorAlea.push_back(random);
     }

     for (int i = 0; i < 15; i++)
     {
          random = rand();
          dequeAlea.push_back(random);
          random = rand();
          dequeAlea.push_front(random);
     }

     for (int i = 0; i < 15; i++)
     {
          random = rand();
          listAlea.push_back(random);
          random = rand();
          listAlea.push_front(random);
     }

     //Impresion de datos
     cout << "Impresion vector en orden" << endl;

     for (itera = vectorAlea.begin(); itera != vectorAlea.end(); itera++)
     {
          cout << i << ")";
          cout << *itera << endl;
          i++;
     }
     i = 1;

     cout << "Impresion vector inverso" << endl;

     for (iteraR = vectorAlea.rbegin(); iteraR != vectorAlea.rend(); iteraR++)
     {
          cout << i << ")";
          cout << *iteraR << endl;
          i++;
     }
     i = 1;

     cout << "Impresion deque en orden" << endl;

     for (iteraDeque = dequeAlea.begin(); iteraDeque != dequeAlea.end(); iteraDeque++)
     {
          cout << i << ")";
          cout << *iteraDeque << endl;
          i++;
     }
     i = 1;

     cout << "Impresion deque inverso" << endl;

     for (iteraDequeR = dequeAlea.rbegin(); iteraDequeR != dequeAlea.rend(); iteraDequeR++)
     {
          cout << i << ")";
          cout << *iteraDequeR << endl;
          i++;
     }
     i = 1;

     cout << "Impresion list en orden" << endl;

     for (iteraList = listAlea.begin(); iteraList != listAlea.end(); iteraList++)
     {
          cout << i << ")";
          cout << *iteraList << endl;
          i++;
     }

     cout << "Impresion list inverso" << endl;

     for (iteraListR = listAlea.rbegin(); iteraListR != listAlea.rend(); iteraListR++)
     {
          cout << i << ")";
          cout << *iteraListR << endl;
          i++;
     }
     i = 1;

     //nuevo valor y eliminacion
     itera = vectorAlea.begin();

     vectorAlea.insert(itera + 17, rand());
     vectorAlea.erase(itera + 4);
     vectorAlea.erase(itera + 9);

     cout << "Impresion vector cambio y eliminacion" << endl;

     for (itera = vectorAlea.begin(); itera != vectorAlea.end(); itera++)
     {
          cout << i << ")";
          cout << *itera << endl;
          i++;
     }
     i = 1;

     iteraDeque = dequeAlea.begin();

     dequeAlea.insert(iteraDeque + 17, rand());
     dequeAlea.erase(iteraDeque + 4);
     dequeAlea.erase(iteraDeque + 9);

     cout << "Impresion deque cambio y eliminacion" << endl;

     for (iteraDeque = dequeAlea.begin(); iteraDeque != dequeAlea.end(); iteraDeque++)
     {
          cout << i << ")";
          cout << *iteraDeque << endl;
          i++;
     }
     i = 1;
     
     iteraList = listAlea.begin();
     advance(iteraList,17);
     listAlea.insert(iteraList, rand());

     iteraList = listAlea.begin();
     advance(iteraList,4);
     listAlea.erase(iteraList);

     iteraList = listAlea.begin();
     advance(iteraList,9);
     listAlea.erase(iteraList);
     
     

     cout << "Impresion list cambio y eliminacion" << endl;

     for (iteraList = listAlea.begin(); iteraList != listAlea.end(); iteraList++)
     {
          cout << i << ")";
          cout << *iteraList << endl;
          i++;
     }

     
}