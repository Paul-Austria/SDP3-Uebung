#include "SystemElemFactory.h"

std::unique_ptr<SystemElem> SystemElemFactory::CreateSystemElem(eSystemType SysType, size_t MaxSize)
{
    return std::unique_ptr<SystemElem>();
}
