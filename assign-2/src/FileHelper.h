//
// Created by Zachary Aries on 2018-02-27.
//

#ifndef ASSIGN_2_FILEHELPER_H
#define ASSIGN_2_FILEHELPER_H

#include <unistd.h>
#include <string>


class FileHelper {
public:
    static bool file_exists(const std::string& name);
};


#endif //ASSIGN_2_FILEHELPER_H
