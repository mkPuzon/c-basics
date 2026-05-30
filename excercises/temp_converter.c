#include <stdio.h>

void print_f_to_c();
void print_c_to_f();
float f_to_c(float n);
float c_to_f(float n);


void print_f_to_c() {
    // print headers
    printf("Fahrenheit -> Celsius\n");
    printf("----------------------\n");
    // loop through fahrenheit vals 
    for (float i = -20.0; i < 130.0; i += 10.0) {
        float c = (5.0 / 9.0) * (i - 32.0);
        printf("%.2f -> %.2f\n", i, c);
    }

}

float f_to_c(float n) {
    return (5.0 / 9.0) * (n - 32.0);
}

void print_c_to_f() {
    // print headers
    printf("Celsius -> Fahrenheit\n");
    printf("----------------------\n");
    // loop through celsius vals
    for (float i = -20.0; i < 60; i += 10) {
        float f = i * (9.0 / 5.0) + 32.0;
        printf("%.2f -> %.2f\n", i, f);
    }
}

float c_to_f(float n) {
    return n * (9.0 / 5.0) + 32.0;
}


int main() {

    print_f_to_c();
    print_c_to_f();
    printf("\n");

    float a = f_to_c(40.0);
    printf("%.2f\n", a);
    float b = c_to_f(40.0);
    printf("%.2f\n", b);


    return 0;
}