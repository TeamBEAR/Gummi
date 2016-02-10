#include <QWidget>
#include <QVBoxLayout>
#include <QString>
#include <iostream>

#include "globals.h"
#include "gamecontrol.h"
#include "agent.h"
#include "radar.h"
#include "level.h"

GameControl::GameControl():
    QObject()
{
    // Game is running
    running = true;
    currentLevel = NULL;
    gameFlow = new GameFlow();
    commandLine = new CommandLine();
    // Connect commandLine to game control
    QObject::connect(commandLine,
                     SIGNAL(returnPressed()),
                     this,
                     SLOT(processCL()));

    QWidget *mainWidget = new QWidget();
    QVBoxLayout *verticalLayout = new QVBoxLayout(mainWidget);

    // Creates a new scene
    scene = new GameScene();
    if(scene != NULL){
        // TODO: Automatically maximize,
        // read Resize event to calculate final
        // scene size
        scene->setSceneRect(QRectF(0, 0, 800, 600));

        // Connect scene to memory
        // TODO: Generic connection
        QObject::connect(gameMemory,
                         SIGNAL(addedAgent()),
                         this,
                         SLOT(refresh()));

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
    gameFlow->insertToGameFlow(level);
    QObject::connect(level,
                     SIGNAL(entered()),
                     this,
                     SLOT(loadLevel())
                     );
    gameFlow->start();
}

void GameControl::loadLevel(){
    // Loads level information to the scene

    unloadLevel();
    Level *sender = (Level *)QObject::sender();
    display.setText(sender->getDisplayBuffer());
    refresh();
    // Connect the level's display buffer to the display
    QObject::connect(sender,
                     SIGNAL(displayContentsChanged()),
                     this,
                     SLOT(refreshDisplay())
                     );

    // Save the sender's pointer for reference
    currentLevel = sender;
    view->show();
}

void GameControl::refreshDisplay(){
    // Loads level information to the scene
    Level *sender = (Level *)QObject::sender();
    display.clear();
    display.setText(sender->getDisplayBuffer());
}

void GameControl::unloadLevel(){
    // Unloads current level
    scene->clear();
    display.clear();
    if(currentLevel!=NULL){
        QObject::disconnect(currentLevel,
                            SIGNAL(displayContentsChanged()),
                            this,
                            SLOT(refreshDisplay()));
        currentLevel=NULL;
    }
}

void GameControl::processCL(){
    // Send it to level, to be interpreted on its internal
    // states
    currentLevel->interpret(commandLine->text());
    commandLine->clearCL();
}

void GameControl::refresh(){
    //scene->clear();
    foreach (Agent *agent, gameMemory->getAgents()) {
        scene->addItem(agent);
    }
    view->viewport()->update();
}
