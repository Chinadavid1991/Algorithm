//
// Created by feng on 2020/12/23.
//

#include "Common.h"
#include <chrono>
long now(){
    std::chrono::milliseconds ms = std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch());
    return ms.count();
}