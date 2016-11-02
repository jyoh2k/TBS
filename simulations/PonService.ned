
package ponservice.simulations;

import ponservice.Host;
import ponservice.ONU;

network PonService
{
    types:
        channel Channel extends ned.DelayChannel {
            delay = 100ms;
        }
    submodules:
        onu: ONU;
        host: Host;
    connections:
        onu.onuPort <--> Channel <--> host.clientPort;
}
