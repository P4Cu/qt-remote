#include "simpleswitch.h"

SimpleSwitch::SimpleSwitch(QObject* parent)
    : SimpleSwitchSimpleSource(parent)
{
    m_stateChangeTimer = new QTimer(this);
    QObject::connect(m_stateChangeTimer, &QTimer::timeout, this, &SimpleSwitch::timeout_slot);
    m_stateChangeTimer->start(5000);
    qDebug() << "Source node started";

    // for debugging purposes always write when state change
    QObject::connect(this, &SimpleSwitch::currStateChanged,
        [](bool state){
            qDebug() << "State change to: " << state;
        }
    );
}

SimpleSwitch::~SimpleSwitch()
{
    m_stateChangeTimer->stop();
}


void SimpleSwitch::server_slot(bool clientState)
{
    qDebug() << "Replica reported state: " << clientState;
}

void SimpleSwitch::timeout_slot()
{
    qDebug() << "------------------\nTimer timeout change from " << currState() << "to" << !currState();
    setCurrState(!currState());
}
