//
// Created by Zachary Aries on 2018-02-25.
//

#include "Debug.h"

bool Debug::m_debug;

Debug::Debug()
{
    m_debug = false;
}

void Debug::setDebug(bool debug)
{
    m_debug = debug;
}

void Debug::printl(std::string message)
{
    if(m_debug) {
        std::cout << message << std::endl;
    }
}

bool Debug::sim_pkt_loss() {
    if (m_debug) {
        int r = rand() % 30;

        if (r == 8) {
            printl("Oops! Your datagram has been lost!");
            return true;
        }
    }
    return false;
}
