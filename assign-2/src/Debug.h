//
// Created by Zachary Aries on 2018-02-25.
//

#ifndef ASSIGN_2_DEBUG_H
#define ASSIGN_2_DEBUG_H

#include <iostream>

class Debug {

private:
    static bool m_debug;

public:
    Debug();
    static void setDebug(bool debug);
    static void printl(std::string message);
    static bool sim_pkt_loss();
};


#endif //ASSIGN_2_DEBUG_H
