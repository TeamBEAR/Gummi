#include "commandline.h"

CommandLine::CommandLine() :
    QLineEdit()
{
    this->init();
}

void CommandLine::init(){
    // Connect signal after object is constructed
    // not necessarily needed, but to be safe...
    QObject::connect(this,
                     SIGNAL(returnPressed()),
                     this,
                     SLOT(interpret()));
}

void CommandLine::interpret(){
    this->setText("");
}
