module;
#include <spdlog/spdlog.h>
module MyLib:Impl;

int Combine(int A, int B)
{
    int ret = A * B;
    spdlog::info("Combine({}, {}) = {}", A, B, ret);
    return ret;
}