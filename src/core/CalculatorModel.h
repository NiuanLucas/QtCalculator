#pragma once
#include <QObject>

/**
 * @brief Modelo simples de calculadora – por enquanto só soma.
 *        Nenhuma dependência de UI (Widgets).
 */
class CalculatorModel : public QObject
{
    Q_OBJECT
public:
    explicit CalculatorModel(QObject *parent = nullptr);

    // Método síncrono: retorna o resultado na hora
    double sum(double a, double b);

signals:
    // Exemplo de notificação assíncrona, caso queira usar
    void resultReady(double value);
};
