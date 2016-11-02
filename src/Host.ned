
package ponservice;

simple Host
{
    parameters:
        double startTime @unit(s) = default(0s);
        double stopTime @unit(s) = default(-1s);
        double timerInterval @unit(s) = default(125us);
        
        @display("i=device/pc4");
        //@signal[sentPk] (type=GenericFrame);
        //@signal[rcvdPk] (type=GenericFrame);
        //@statistic[rcvdPk](title="packets received"; source=rcvdPk; record=count,"sum(packetBytes)","vector(packetBytes)"; interpolationmode=none);
        //@statistic[sentPk](title="packets sent"; source=sentPk; record=count,"sum(packetBytes)","vector(packetBytes)"; interpolationmode=none);
    gates:
        inout clientPort;
}
