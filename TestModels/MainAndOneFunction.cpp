#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
int foo()
{
    int a=0;
    if(a++>1)
    {

        while(a++<10)
        {
            a++;
        }


    }
}
