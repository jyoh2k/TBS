#include "ONU.h"

namespace ponservice {

Define_Module(ONU);

void ONU::handleMessage(cMessage *msg)
{
  if (msg->isSelfMessage())
  {
      bubble("ARRIVED, selfMessage!");
  }
  else
      bubble("ARRIVED, Generic Message!");
}

}; //namespace
