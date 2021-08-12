#include <QCoreApplication>

#include "simpleswitch.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    SimpleSwitch srcSwitch;

    // This is core to creating a remote object
    QRemoteObjectHost srcNode(QUrl(QStringLiteral("local:switch")));
    srcNode.enableRemoting(&srcSwitch);

    return a.exec();
}
