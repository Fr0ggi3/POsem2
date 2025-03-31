#include <iostream>
#include "calculator.h"
using namespace std;

Calculator::Calculator() {
    mem = 0;
    mem_used = false;
}
    void Calculator::warning() {
        cout<<"Dzielenie przez 0 jest niedozwolone, wyswietle poprzednia wartosc \n"<<endl;
    }
    double Calculator::add(const double a, const double b) {
        return a + b;
    }

    double Calculator::sub(const double a, const double b) {
        return a - b;
    }
    double Calculator::mult(const double a, const double b) {
        return a * b;
    }
    double Calculator::div(const double a, const double b) {
        if (b == 0) {
            warning();
            return a;
        }
        return a / b;
    }
    double Calculator::mod(const double a, const double b) {
        if (b == 0) warning();
        return a - (int)(a/b)*b;
    }
    void Calculator::clear_mem() {
        mem_used = false;
        cout<<mult(mem,0)<<endl;
    }

    void Calculator::close_app() {
        cout<<"Wylaczam kalkulator\n";
        exit(0);
    }
    double Calculator::get() {
        return mem;
    }
    void Calculator::set(double number) {
        mem = number;
    }