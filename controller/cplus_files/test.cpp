#include <iostream>
#include <common/mavlink.h>

int main(){
    
    mavlink_message_t msg;

    mavlink_heartbeat_t heartbeat;

    heartbeat.type = MAV_TYPE_GCS;
    heartbeat.autopilot = MAV_AUTOPILOT_INVALID;
    heartbeat.base_mode = 0;
    heartbeat.custom_mode = 0;
    heartbeat.system_status = MAV_STATE_ACTIVE;

    mavlink_msg_heartbeat_encode(
        255, // system id
        190, // component id
        &msg,
        &heartbeat
    );

    std::cout << "MAVLink message created..." << std::endl;
    std::cout << "Message ID: " << static_cast<int>(msg.msgid) << std::endl;
    std::cout << "Payload length: " << static_cast<int>(msg.len) << std::endl;

    return 0;
}
