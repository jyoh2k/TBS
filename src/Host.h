
#ifndef __PONSERVICE_HOST_H
#define __PONSERVICE_HOST_H

#include <omnetpp.h>
#include "Frame_m.h"

using namespace omnetpp;

namespace ponservice {

class Host : public cSimpleModule
{

    private:
        bool connected;

        // send parameters
        int destID;
        long seqNum;

        // self messages
        cMessage *connTimerMsg;
        cMessage *pktGenerationTimerMsg;
        simtime_t startTime;
        simtime_t stopTime;
        simtime_t timerInterval;

        //receive statistics
        long packetsSent;
        long packetsReceived;

    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);

        void makeConnection();
        void sendPacket();
        void receivePacket(cMessage *msg);
};

}; //namespace
#endif
