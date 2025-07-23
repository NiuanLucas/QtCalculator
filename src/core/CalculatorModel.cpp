#include "CalculatorModel.h"

CalculatorModel::CalculatorModel(QObject *parent)
    : QObject(parent)
{
}

double CalculatorModel::sum(double a, double b)
{
    const double result = a + b;
    emit resultReady(result);          // Caso alguém se conecte
    return result;
}

double CalculatorModel::subtract(double a, double b)
{
    const double result = a - b;
    emit resultReady(result);
    return result;
}

double CalculatorModel::multiply(double a, double b)
{
    const double result = a * b;
    emit resultReady(result);
    return result;
}

double CalculatorModel::divide(double a, double b)
{
    const double result = a / b;
    emit resultReady(result);
    return result;
}
