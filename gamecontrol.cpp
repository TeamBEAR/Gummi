#include <QWidget>
#include <QVBoxLayout>
#include "commandline.h"
#include "gamecontrol.h"
#include "agent.h"
#include "radar.h"

GameControl::GameControl(){

    // Game is running
    running = true;

    QWidget *mainWidget = new QWidget();
    QVBoxLayout *verticalLayout = new QVBoxLayout(mainWidget);
    CommandLine *commandLine = new CommandLine();
    //commandLine->init();

    // TODO: The state machine framework directs
    // how scenes are created and populated, depending
    // on level.

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
            //view->show();
            verticalLayout->addWidget(view);
            verticalLayout->addWidget(commandLine);
            mainWidget->show();
        }
    }

    // Create a demo player
    // We pass the window's size to know
    // where its borders are
    Agent *player = new Agent(QSize(800, 600));

    // Add demo player to the scene
    scene->addItem(player);

    player->goUp();
    player->goRight();
}

bool GameControl::isRunning(){
    return this->running;
}

void GameControl::setRunning(bool value){
    this->running = value;
}
