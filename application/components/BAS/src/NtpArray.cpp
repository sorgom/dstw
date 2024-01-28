#include <BAS/NtpArray.h>

Ntp::Ntp(
    const ElementName& name,
    const INT32 type,
    const size_t pos
):
    type(type),
    pos(pos)
{
    Mem::cpy(this->name, name);
}
