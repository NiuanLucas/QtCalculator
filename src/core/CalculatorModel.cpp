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
