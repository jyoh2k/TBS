
#ifndef __PONSERVICE_ONU_H
#define __PONSERVICE_ONU_H

#include <omnetpp.h>
#include "Frame_m.h"

using namespace omnetpp;

namespace ponservice {

class ONU : public cSimpleModule
{
protected:
    virtual void handleMessage(cMessage *msg);
};

}; //namespace

#endif
