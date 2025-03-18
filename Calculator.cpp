#include <iostream>
using namespace std;
double mem;
bool mem_used; //sprawdza czy uzyto pamieci, jesli tak to pobieramy tylko jedna liczbe, jesli nie to 2

void warning(int const a) {
    switch (a) {
        case 1:
        cout<<"Dzielenie przez 0 jest niedozwolone \n"<<endl;
        break;
    }
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
        warning(1);
        return a;
    }
    return a / b;
}
double mod(const double a, const double b) {
    return a - (int)(a/b)*b;
}
void clear_mem(){}
void menu() {
    double a = 0;
    cout<<" 1) +\n 2) - \n 3) * \n 4) / \n 5) % \n 6) Wyzeruj\n";
    if(mem_used==1)cin>>mem;
        unsigned int opt;
        switch (opt) {
            case 1:
                cin>>a;
                add(mem, a);
                break;
            case 2:
                cin>>a;
                sub(mem, a);
                break;
            case 3:
                cin>>a;
                mult(mem, a);
                break;
            case 4:
                cin>>a;
                div(mem, a);
                break;
            case 5:
                cin>>a;
                mod(mem, a);
                break;
            case 6: clear_mem();
                break;
        }
}
int main(){
    menu();
    return 0;
}
