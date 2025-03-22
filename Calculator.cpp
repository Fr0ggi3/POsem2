#include <iostream>
#include <limits>
using namespace std;
double mem;
bool mem_used; //sprawdza czy uzyto pamieci, jesli tak to pobieramy tylko jedna liczbe, jesli nie to 2
//dodatkowo przeliczanie baz -> podac baze, liczbe i na jaki system liczbowy go zmienić
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
    exit(0);
}
void is_from_range(unsigned int* ptr) {//działa dla znakow i liczb poza zakresem, nie dziala dla "1-"
    while (true) {
        if (std::cin >> *ptr) {
            if(*ptr >= 1 and *ptr <=7) {
                break;
            }std::cout << "Wpisz liczbe z przedzialu 1-7\n";
        } else {
            std::cout << "Wpisz liczbe z przedzialu 1-7\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            *ptr = 0;
        }
    }
}
void menu() {
    double a = 0;
    unsigned int opt;
    unsigned int* ptr = &opt;
    if(mem_used==0) {
        cin>>mem;
        mem_used = true;
    }
    cout<<" 1) +\n 2) - \n 3) * \n 4) / \n 5) % \n 6) Wyzeruj\n 7) Zamknij program\n";
    //cin>>opt;
    is_from_range(ptr);
        switch (opt) {
            case 1:
                cout<<mem<<"+";
                cin>>a;
                mem = add(mem, a);
                cout<<mem<<endl;
                break;
            case 2:
                cout << mem << "-";
                cin>>a;
                mem = sub(mem, a);
                cout<<mem<<endl;
                break;
            case 3:
                cout<<mem<<"*";
                cin>>a;
                mem = mult(mem, a);
                cout<<mem<<endl;
                break;
            case 4:
                cout<<mem<<"/";
                cin>>a;
                mem = div(mem, a);
                cout<<mem<<endl;
                break;
            case 5:
                cout<<mem<<"%";
                cin>>a;
                mem = mod(mem, a);
                cout<<mem<<endl;
                break;
            case 6:clear_mem();
                break;
            case 7:
                cout<<"Wylaczam kalkulator\n";
                close_app();
                break;
        }
}
int main(){
    cout<<"Kalkulator wlaczony, wpisz liczbe\n";
    while(true)menu();


    return 0;
}
