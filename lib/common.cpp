#include "common.h"

std::string lowercase(const std::string& str) {
    std::string str2 = str;
    std::transform(str2.begin(), str2.end(), str2.begin(), tolower);
    return std::move(s2);
}

