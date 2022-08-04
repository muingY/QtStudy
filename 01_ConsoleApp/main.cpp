#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int number = 100;
    qDebug() << "Hello world!";
    qDebug("Qt First Project. My number: %d.", number);

    return a.exec();
}
