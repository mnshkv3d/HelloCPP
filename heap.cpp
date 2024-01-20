//Heap
//Dynamic memory

#include<iostream>

int* intOnHeap(); //return int var from 
void leak1();
void leak2();

int main()
{
int* pHeap = new int;
*pHeap = 10;
std::cout << "*pHeap: " << *pHeap << "\n\n";
int* pHeap2 = intOnHeap();
std::cout << "*pHeap2: " << *pHeap2 << "\n\n";
std::cout << "Freeing memory pointed to by pHeap.\n\n";
delete pHeap;
std::cout << "Freeing memory pointed to by pHeap2.\n\n";
delete pHeap2;

pHeap = 0;
pHeap2 = 0;
return 0;
}

int* intOnHeap()
{
    int* pTemp = new int(20);
    return pTemp;
}

void leak1()
{
    int* drip1 = new int(30);
}

void leak2()
{
    int* drip2 = new int(50);
    drip2 = new int(100);
    delete drip2;
}