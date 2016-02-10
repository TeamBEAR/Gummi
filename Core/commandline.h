#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include <QLineEdit>

class CommandLine : public QLineEdit
{
    Q_OBJECT
    public:
        CommandLine();
        void clearCL();

    signals:

    public slots:
};

#endif // COMMANDLINE_H
