//
// Created by thoma on 8/1/2022.
//

#include "Calculator.h"

template <typename T>
Calculator<T>::Calculator(T n1, T n2) {
    num1 = n1;
    num2 = n2;
}

template <typename T>
int Calculator<T>::add() {
    return num1 + num2;
}

template <typename T>
int Calculator<T>::subtract() {
    return num1 - num2;
}

template <typename T>
int Calculator<T>::multiply() {
    return num1 * num2;
}

template <typename T>
int Calculator<T>::divide() {
    return num1 / num2;
}
