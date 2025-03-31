#include<iostream>
#include"calculator.h"
using namespace std;

void menu(Calculator& calc) {
        double a = 0;
        unsigned int opt;
        if(calc.mem_used == 0) {
            cin >> a;
            calc.set(a);
            calc.mem_used = true;
        }
        cout<<" 1) +\n 2) - \n 3) * \n 4) / \n 5) % \n 6) Wyzeruj\n 7) Zamknij program\n";
        cin>>opt;
        switch (opt) {
            case 1:
                cout<<calc.get()<<"+";
            cin>>a;
            calc.set(calc.add(calc.get(), a));
            cout<<calc.get()<<endl;
            break;
            case 2:
                cout << calc.get()<< "-";
            cin>>a;
            calc.set(calc.sub(calc.get(), a));
            cout<<calc.get()<<endl;
            break;
            case 3:
                cout<<calc.get()<<"*";
            cin>>a;
            calc.set(calc.mult(calc.get(), a));
            cout<<calc.get()<<endl;
            break;
            case 4:
                cout<<calc.get()<<"/";
            cin>>a;
            calc.set(calc.div(calc.get(),a));
            cout<<calc.get()<<endl;
            break;
            case 5:
                cout<<calc.get()<<"%";
            cin>>a;
            calc.set(calc.mod(calc.get(),a));
            cout<<calc.get()<<endl;
            break;
            case 6:calc.clear_mem();
            break;
            case 7:
                calc.close_app();
            break;
        }
    }
int main(){
        Calculator calc;
        cout<<"Kalkulator wlaczony, wpisz liczbe\n";
        while(true)menu(calc);
        return 0;
    }