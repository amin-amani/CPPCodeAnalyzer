#include <QCoreApplication>

/*int commentedfunc(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}*/
//int Linecommentedfunc(int argc){argc++;}
#define LEDON() {GPIOA->ODR|=1;}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
