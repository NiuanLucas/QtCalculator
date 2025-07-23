#include "StyleHelper.h"
#include "../ui/MainWindow.h"      // caminho relativo porque UI é outro subdir

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //------------------------------------------------------------------
    // 1. Estilo global (cores, fontes, bordas) carregado via StyleHelper
    //------------------------------------------------------------------
    StyleHelper::apply();          // lê todos os .qss embutidos no .qrc

    //------------------------------------------------------------------
    // 2. Traducao (nao utilizado neste projeto)
    //------------------------------------------------------------------

    //------------------------------------------------------------------
    // 3. Criar e exibir a janela principal
    //------------------------------------------------------------------
    MainWindow window;
    window.show();

    return app.exec();             // loop de eventos
}
