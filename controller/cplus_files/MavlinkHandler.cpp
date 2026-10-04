#include <MavlinkHandler.h>

mavlink_heartbeat_t MAVLinkHandler::sendHeartbeat(){
    // sends heartbeat signal using mavlink protocol
    
    mavlink_message_t msg;
    mavlink_heartbeat_t hb;

    hb.type = MAV_TYPE_GCS;
    hb.autopilot = MAV_AUTOPILOT_INVALID;
    hb.base_mode = 0;
    hb.custom_mode = 0;
    hb.system_status = MAV_STATE_ACTIVE;

    mavlink_msg_heartbeat_encode(
        255, // system id
        190, // component id
        &msg,
        &hb
    );
    
    return hb;
}

void MAVLinkHandler::msgStats(mavlink_message_t msg){
    std::cout << "MAVLink message created..." << std::endl;
    std::cout << "Message ID: " << static_cast<int>(msg.msgid) << std::endl;
    std::cout << "Payload length: " << static_cast<int>(msg.len) << std::endl;
}