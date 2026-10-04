#include <iostream>
#include <MavlinkHandler.h>

int main(){
    MAVLinkHandler mavlinkHandler;
    std::cout << "Sending heartbeat..." << std::endl;
    mavlink_heartbeat_t heartbeat = mavlinkHandler.sendHeartbeat();
    // mavlinkHandler.msgStats(heartbeat);
    std::cout << "Sent heartbeat with type: " << static_cast<int>(heartbeat.type) << std::endl;
    return 0;
}