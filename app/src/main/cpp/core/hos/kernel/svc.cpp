#include <cstdint>
#include <syslog.h>
#include <utility>
#include "core/arm/cpu.h"
#include "svc.h"

namespace core::kernel {
    std::pair<int, uint32_t(*)()> svcTable[] =
    {
            {0x01, nullptr},
            {0x02, nullptr},
            {0x03, nullptr},
            {0x04, nullptr},
            {0x05, nullptr},
            {0x06, nullptr},
            {0x07, nullptr},
            {0x08, nullptr},
            {0x09, nullptr},
            {0x0a, nullptr},
            {0x0b, nullptr},
            {0x0c, nullptr},
            {0x0d, nullptr},
            {0x0e, nullptr},
            {0x0f, nullptr},
            {0x10, nullptr},
            {0x11, nullptr},
            {0x12, nullptr},
            {0x13, nullptr},
            {0x14, nullptr},
            {0x15, nullptr},
            {0x16, nullptr},
            {0x17, nullptr},
            {0x18, nullptr},
            {0x19, nullptr},
            {0x1a, nullptr},
            {0x1b, nullptr},
            {0x1c, nullptr},
            {0x1d, nullptr},
            {0x1e, nullptr},
            {0x1f, nullptr},
            {0x20, nullptr},
            {0x21, nullptr},
            {0x22, nullptr},
            {0x23, nullptr},
            {0x24, nullptr},
            {0x25, nullptr},
            {0x26, nullptr},
            {0x27, nullptr},
            {0x28, nullptr},
            {0x29, nullptr},
            {0x2a, nullptr},
            {0x2b, nullptr},
            {0x2c, nullptr},
            {0x2d, nullptr},
            {0x2e, nullptr},
            {0x2f, nullptr},
            {0x30, nullptr},
            {0x31, nullptr},
            {0x32, nullptr},
            {0x33, nullptr},
            {0x34, nullptr},
            {0x35, nullptr},
            {0x36, nullptr},
            {0x37, nullptr},
            {0x38, nullptr},
            {0x39, nullptr},
            {0x3a, nullptr},
            {0x3b, nullptr},
            {0x3c, nullptr},
            {0x3d, nullptr},
            {0x3e, nullptr},
            {0x3f, nullptr},
            {0x40, nullptr},
            {0x41, nullptr},
            {0x42, nullptr},
            {0x43, nullptr},
            {0x44, nullptr},
            {0x45, nullptr},
            {0x46, nullptr},
            {0x47, nullptr},
            {0x48, nullptr},
            {0x49, nullptr},
            {0x4a, nullptr},
            {0x4b, nullptr},
            {0x4c, nullptr},
            {0x4d, nullptr},
            {0x4e, nullptr},
            {0x4f, nullptr},
            {0x50, nullptr},
            {0x51, nullptr},
            {0x52, nullptr},
            {0x53, nullptr},
            {0x54, nullptr},
            {0x55, nullptr},
            {0x56, nullptr},
            {0x57, nullptr},
            {0x58, nullptr},
            {0x59, nullptr},
            {0x5a, nullptr},
            {0x5b, nullptr},
            {0x5c, nullptr},
            {0x5d, nullptr},
            {0x5e, nullptr},
            {0x5f, nullptr},
            {0x60, nullptr},
            {0x61, nullptr},
            {0x62, nullptr},
            {0x63, nullptr},
            {0x64, nullptr},
            {0x65, nullptr},
            {0x66, nullptr},
            {0x67, nullptr},
            {0x68, nullptr},
            {0x69, nullptr},
            {0x6a, nullptr},
            {0x6b, nullptr},
            {0x6c, nullptr},
            {0x6d, nullptr},
            {0x6e, nullptr},
            {0x6f, nullptr},
            {0x70, nullptr},
            {0x71, nullptr},
            {0x72, nullptr},
            {0x73, nullptr},
            {0x74, nullptr},
            {0x75, nullptr},
            {0x76, nullptr},
            {0x77, nullptr},
            {0x78, nullptr},
            {0x79, nullptr},
            {0x7a, nullptr},
            {0x7b, nullptr},
            {0x7c, nullptr},
            {0x7d, nullptr},
            {0x7e, nullptr},
            {0x7f, nullptr}
    };

    uint32_t SvcHandler(uint32_t svc)
    {
        std::pair<int, uint32_t(*)()>* result = &(svcTable[svc]);

        if(result->second)
            return result->second();
        else
        {
            syslog(LOG_ERR, "Unimplemented SVC 0x%02x", svc);
            return 0x177202; // "Unimplemented behaviour"
        }
    }
}