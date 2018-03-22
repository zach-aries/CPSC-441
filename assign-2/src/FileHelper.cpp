//
// Created by Zachary Aries on 2018-02-27.
//

#include "FileHelper.h"

bool FileHelper::file_exists (const std::string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }
}