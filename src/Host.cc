
#include "Host.h"

namespace ponservice {

Define_Module(Host);

void Host::initialize()
{
    timerInterval = par("timerInterval");
    connected = false;

    destID = getSimulation()->getModuleByPath("PonService.onu")->getId();
    seqNum = 0;
    WATCH(seqNum);

    packetsSent = packetsReceived = 0;
    WATCH(packetsSent);
    WATCH(packetsReceived);

    startTime = par("startTime");
    stopTime = par("stopTime");
    if (stopTime >= SIMTIME_ZERO && stopTime < startTime)
        error("Invalid startTime/stopTime parameters");

    pktGenerationTimerMsg = new cMessage("Pkt_Gen MSG");
    connTimerMsg = new cMessage("Conn_Timer Msg");
    scheduleAt(startTime+timerInterval, connTimerMsg);

}

void Host::handleMessage(cMessage *msg)
{
    EV << "Receive Msg '" << msg << "'\n";
    if (msg->isSelfMessage())
    {
        if (msg == connTimerMsg && !connected)
            makeConnection();
        else if(msg == pktGenerationTimerMsg)
        {
            sendPacket();
        }
        else error("Wrong message at Host!!");
    }
    else
        receivePacket(msg);
}

void Host::makeConnection()
{
    char msgname[30];
    sprintf(msgname, "Connection-%d", getId());
    EV << "Connection packet '" << msgname << "'\n";

    GenericFrame *connFrame = new GenericFrame(msgname);

    connFrame->setSrc(getId());
    connFrame->setDest(destID);

    send(connFrame, "clientPort$o");
 }

void Host::sendPacket()
{
    EV << "Send packet!\n";
}


void Host::receivePacket(cMessage *msg)
{
    EV << "Receive packet '" << msg << "'\n";
}

}; // namespace

