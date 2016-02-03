#include <QApplication>
#include <unistd.h>
#include <iostream>
#include "gummiworld.h"


int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    GummiWorld world;

    while(world.isRunning()){
        app.processEvents();

        // 24pfs
        usleep(40000);
    }

    return 0;
}
