#include <iostream>
#include <limits>
using namespace std;

class Calculator {
private:
    double mem = 0;
    //sprawdza czy uzyto pamieci, jesli tak to pobieramy tylko jedna liczbe, jesli nie to 2
    //dodatkowo przeliczanie baz -> podac baze, liczbe i na jaki system liczbowy go zmienić
public:
    bool mem_used = false;
    void warning() {
        cout<<"Dzielenie przez 0 jest niedozwolone, wyswietle poprzednia wartosc \n"<<endl;
    }
    double add(const double a, const double b) {
        return a + b;
    }

    double sub(const double a, const double b) {
        return a - b;
    }
    double mult(const double a, const double b) {
        return a * b;
    }
    double div(const double a, const double b) {
        if (b == 0) {
            warning();
            return a;
        }
        return a / b;
    }
    double mod(const double a, const double b) {
        if (b == 0) warning();
        return a - (int)(a/b)*b;
    }
    void clear_mem() {
        mem_used = false;
        cout<<mult(mem,0)<<endl;
    }

    void close_app() {
        cout<<"Wylaczam kalkulator\n";
        exit(0);
    }
    double get() {
        return mem;
    }
    void set(double number) {
        mem = number;
    }
};
    void menu(Calculator calc) {
        double a = 0;
        unsigned int opt;
        if(calc.mem_used==0) {
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
