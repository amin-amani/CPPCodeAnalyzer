#include <QCoreApplication>
#include <QDebug>
#define LED 1
//this is comment
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
/*this is comment two
 *
 */
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
