#ifndef SIMPLESWITCH_H
#define SIMPLESWITCH_H

#include <QTimer>

#include "rep_simpleswitch_source.h"

class SimpleSwitch : public SimpleSwitchSimpleSource
{
    Q_OBJECT
public:
    SimpleSwitch(QObject* parent = nullptr);
    ~SimpleSwitch() override;

    void server_slot(bool clientState) override;

    Q_SLOT void timeout_slot();

private:
    QTimer *m_stateChangeTimer;
};

#endif // SIMPLESWITCH_H
