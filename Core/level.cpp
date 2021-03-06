#include "Core/level.h"

Level::Level(QString name, QList<LevelState *> internalStates) :
    QState()
{
    this->name = name;
    levelWorkflow = new QStateMachine();
    finalState = new QFinalState();
    levelWorkflow->addState(finalState);

    if(internalStates.isEmpty()){
        // If no other internal state exists, the
        // final state is also the initial state
        levelWorkflow->setInitialState(finalState);
    }else{
        LevelState *prev=NULL;
        foreach (LevelState *state, internalStates) {
            // Refresh display when entering state
            QObject::connect(state,
                             SIGNAL(entered()),
                             this,
                             SLOT(changeInternalState())
                             );
            if(prev!=NULL){
                prev->connectTo(state);
            }
            prev = state;
            levelWorkflow->addState(state);
        }
        // Connect last state to finalState
        prev->connectTo(finalState);
        levelWorkflow->setInitialState(internalStates.first());
    }

    // When entering final state, level emits
    // solve to change level
    QObject::connect(finalState,
                     SIGNAL(entered()),
                     this,
                     SLOT(changeLevel())
                     );
    levelWorkflow->start();
}

QString Level::getName(){
    return name;
}

LevelState *Level::currentState(){
    QSet<QAbstractState *> states = levelWorkflow->configuration();
    if(states.isEmpty()){
        return NULL;
    }
    QSet<QAbstractState *>::iterator i = states.begin();
    return (LevelState *)(*i);
}

QString Level::getDisplayBuffer(){
    if(currentState() == NULL)
            return QString("");
    return currentState()->getDisplayBuffer();
}

void Level::setDisplayBuffer(QString newBufferContents){
    if(currentState() != NULL){
        currentState()->setDisplayBuffer(newBufferContents);
        emit displayContentsChanged();
    }
}

void Level::changeInternalState(){
    emit displayContentsChanged();
}

void Level::changeLevel(){
    emit solved();
}

void Level::postEvent(QEvent *e){
    levelWorkflow->postEvent(e);
}
