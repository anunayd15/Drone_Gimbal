#include <common/mavlink.h>
#include <iostream>

class MAVLinkHandler {
    public:
        mavlink_heartbeat_t sendHeartbeat();
        void msgStats(mavlink_message_t msg);
    // private:
};