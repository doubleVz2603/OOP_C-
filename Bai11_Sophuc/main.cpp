#include <iostream>
#include "ComplexNumber.h"

using namespace std;


void menu()
{
    string mainChoice;
    string real, imaginary;
    while (1)
    {
        system("CLS");
        cout << "----------------------------Menu----------------------------" << endl;
        cout << "----------1. add complex number                    -----------" << endl;
        cout << "----------2. multiple complex number              -----------" << endl;
        cout << "----------3. exit                                  -----------" << endl;
        cout << "enter your choice: ";
        cin >> mainChoice;
        if (mainChoice.length() > 1 || (int(mainChoice[0] - 48) < 0 || int(mainChoice[0] - 48) > 3))
        {
            cout << "error format input..." << endl;
            system("pause");
            break;
        }
        else
        {
            if (int(mainChoice[0] - 48) == 3)
            {
                break;
            }
            cout << "complex number 1: " << endl;
            ComplexNumber complexNumber1;
            complexNumber1.input();
            complexNumber1.output();
            cout << "complex number 2: " << endl;
            ComplexNumber complexNumber2;
            complexNumber2.input();
            complexNumber2.output();

            switch (int(mainChoice[0] - 48))
            {
            case 1:
            {
                ComplexNumber complexNumber3 = complexNumber1 + complexNumber2;
                cout << "result: ";
                complexNumber3.output();
                system("pause");
                break;
            }
            case 2:
            {
                ComplexNumber complexNumber3 = complexNumber1 * complexNumber2;
                cout << "result: ";
                complexNumber3.output();
                system("pause");
                break;
            }

            default:
                break;
            }
        }
    }
}
int main()
{
    menu();
}
