#include "commandline.h"

CommandLine::CommandLine() :
    QLineEdit()
{
}

void CommandLine::clearCL(){
    this->setText("");
}
