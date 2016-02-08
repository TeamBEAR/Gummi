#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include <QLineEdit>

class CommandLine : public QLineEdit
{
    Q_OBJECT
    public:
        CommandLine();

    signals:

    public slots:
        void init();
        void interpret();
};

#endif // COMMANDLINE_H
