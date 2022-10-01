//
// Created by BVT.MI on 25.08.2022.
//

#include "address.h"
#include "filter.h"

using namespace bvt;

namespace bvt {


std::vector<Address> filter(const std::vector<Address> &origin, const std::function<bool(const Address &)> &func)
{
    std::vector<Address> result (origin.size());
    result.resize(
            std::distance(result.begin(),
                          std::copy_if(
                                  origin.begin(),
                                  origin.end(),
                                  result.begin(),
                                  func)));
    return result;
}



std::vector<Address> filter(const std::vector<Address> &origin, byte oct1)
{
    return filter(
            origin,
            [oct1](const auto &addr)
            {
                return (addr.getOctet(1) == oct1);
            });
}

std::vector<Address> filter(const std::vector<Address> &origin, byte oct1, byte oct2)
{
    return filter(
            origin,
            [oct1, oct2](const auto &addr)
            {
                return (
                        addr.getOctet(1) == oct1 &&
                        addr.getOctet(2) == oct2);
            });
}
std::vector<Address> filter_any(const std::vector<Address> &origin, byte val)
{
    return filter(
            origin,
            [val](const auto &addr)
            {
                for (const auto oct: addr) if (oct == val) return true;
                return false;
            });
}


}