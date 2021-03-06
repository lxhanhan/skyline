// SPDX-License-Identifier: MPL-2.0
// Copyright © 2020 Skyline Team and Contributors (https://github.com/skyline-emu/)

#include <kernel/types/KProcess.h>
#include "IStorage.h"

namespace skyline::service::fssrv {
    IStorage::IStorage(std::shared_ptr<vfs::Backing> &backing, const DeviceState &state, ServiceManager &manager) : backing(backing), BaseService(state, manager, Service::fssrv_IStorage, "fssrv:IStorage", {
        {0x0, SFUNC(IStorage::Read)},
        {0x4, SFUNC(IStorage::GetSize)}
    }) {}

    void IStorage::Read(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        auto offset = request.Pop<i64>();
        auto size = request.Pop<i64>();

        if (offset < 0) {
            state.logger->Warn("Trying to read a file with a negative offset");
            response.errorCode = constant::status::InvAddress;
            return;
        }

        if (size < 0) {
            state.logger->Warn("Trying to read a file with a negative size");
            response.errorCode = constant::status::InvSize;
            return;
        }

        backing->Read(state.process->GetPointer<u8>(request.outputBuf.at(0).address), offset, size);
    }

    void IStorage::GetSize(type::KSession &session, ipc::IpcRequest &request, ipc::IpcResponse &response) {
        response.Push<u64>(backing->size);
    }
}
