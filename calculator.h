//
// Created by janek on 31.03.2025.
//

#ifndef CALCULATOR_H
#define CALCULATOR_H



class Calculator {
private:
    double mem = 0;
public:
    bool mem_used = false;

    Calculator();

    void warning();

    double add(double a, double b);
    double sub(double a, double b);
    double mult(double a, double b);
    double div(double a, double b);
    double mod(double a, double b);

    void clear_mem();
    void close_app();
    double get();
    void set(double number);
};



#endif
