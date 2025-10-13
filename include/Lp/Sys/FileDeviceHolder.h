#pragma once
#include <cafe.h>
#include <sead/filedevice/cafe/seadCafeSaveFileDevice.h>

// class sead::CafeSaveFileDevice;

namespace Lp {
namespace Sys {

class FileDeviceHolder {
  public:
    static FileDeviceHolder* sInstance;

    u8 pad0[0x1C];
    sead::CafeSaveFileDevice* saveDevice;
    u8 pad1[0x14];
};

    static_assert(sizeof(FileDeviceHolder) == 0x34, "Lp::Sys::FileDeviceHolder size mismatch");
    } // namespace Sys
} // namespace Lp