//
// Created by BVT.MI on 25.08.2022.
//

#ifndef CPP2_FILTER_H
#define CPP2_FILTER_H

namespace bvt {
    using byte = uint8_t;

    class Address;

    std::vector<Address> filter(
            const std::vector<Address> &,
            const std::function<bool(const Address &)> &func);

    std::vector<Address> filter(
            const std::vector<Address> &, byte oct1);

    std::vector<Address> filter(
            const std::vector<Address> &, byte oct1, byte oct2);

    std::vector<Address> filter(
            const std::vector<Address> &, byte oct1, byte oct2, byte oct3);

    std::vector<Address> filter_any(
            const std::vector<Address> &, byte val);
}

#endif //CPP2_FILTER_H
