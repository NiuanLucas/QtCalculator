#pragma once
#include <QObject>

/**
 * @brief Modelo simples de calculadora.
 *        Nenhuma dependência de UI (Widgets).
 */
class CalculatorModel : public QObject
{
    Q_OBJECT
public:
    explicit CalculatorModel(QObject *parent = nullptr);

    // Métodos síncronos: retornam o resultado na hora
    double sum(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);

signals:
    // Exemplo de notificação assíncrona, caso queira usar
    void resultReady(double value);
};
