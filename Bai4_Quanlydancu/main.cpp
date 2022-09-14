#include <iostream>
#include <vector>
#include <memory>
#include "Management.h"
using namespace std;



int main()
{
    Management management;
    int n;
    cout << "enter number of family: ";
    cin >> n;
    management.input(n);
    system("CLS");
    management.output();
}