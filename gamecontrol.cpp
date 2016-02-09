#include <QWidget>
#include <QVBoxLayout>
#include <QString>
#include "gamecontrol.h"
#include "agent.h"
#include "radar.h"
#include "level.h"

GameControl::GameControl():
    QObject()
{
    // Game is running
    running = true;
    gameFlow = new Workflow();
    commandLine = new CommandLine();

    QWidget *mainWidget = new QWidget();
    QVBoxLayout *verticalLayout = new QVBoxLayout(mainWidget);

    // Creates a new scene
    scene = new GameScene();
    if(scene != NULL){
        // TODO: Automatically maximize,
        // read Resize event to calculate final
        // scene size
        scene->setSceneRect(QRectF(0, 0, 800, 600));
        // Adds the created scene to a view
        view = new GameView(this->scene);
        if(view != NULL){
            verticalLayout->addWidget(view);
            verticalLayout->addWidget(&display);
            verticalLayout->addWidget(commandLine);
            mainWidget->show();
        }
    }
}

void GameControl::start(){
    gameFlow->start();
}

void GameControl::stop(){
    gameFlow->stop();
}

bool GameControl::isRunning(){
    return this->running;
}

void GameControl::setRunning(bool value){
    this->running = value;
}

void GameControl::addLevel(Level *level){
    if(gameFlow->active())
        gameFlow->stop();
    gameFlow->insertToWorkflow(level);
    QObject::connect(level,
                     SIGNAL(entered()),
                     this,
                     SLOT(loadLevel())
                     );
    gameFlow->start();
}

void GameControl::loadLevel(){
    // Loads level information to the scene
    Level *sender = (Level *)QObject::sender();
    scene->clear();
    display.clear();
    display.setText(QString::fromStdString(
                        sender->getDisplayBuffer())
                    );
    foreach (Agent *agent, sender->getAgents()) {
        scene->addItem(agent);
    }
    // Connect the display buffer to the display
    QObject::connect(sender,
                     SIGNAL(displayContentsChanged()),
                     this,
                     SLOT(refreshDisplay())
                     );
    view->show();
}

void GameControl::refreshDisplay(){
    // Loads level information to the scene
    Level *sender = (Level *)QObject::sender();
    display.clear();
    display.setText(QString::fromStdString(
                        sender->getDisplayBuffer())
                    );
}

void GameControl::unloadLevel(){
    // Loads level information to the scene
    Level *sender = (Level *)QObject::sender();
}
