#include "StyleHelper.h"
#include "../ui/MainWindow.h"      // caminho relativo porque UI é outro subdir

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //------------------------------------------------------------------
    // 1. Estilo global (cores, fontes, bordas) carregado via StyleHelper
    //------------------------------------------------------------------
    StyleHelper::apply();          // lê todos os .qss embutidos no .qrc

    //------------------------------------------------------------------
    // 2. Carregar tradução, se existir
    //------------------------------------------------------------------
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Test_Niuan_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }

    //------------------------------------------------------------------
    // 3. Criar e exibir a janela principal
    //------------------------------------------------------------------
    MainWindow window;
    window.show();

    return app.exec();             // loop de eventos
}
