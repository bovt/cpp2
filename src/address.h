//
// Created by BVT.MI on 25.08.2022.
//

#ifndef CPP2_ADDRESS_H
#define CPP2_ADDRESS_H

#include <vector>
#include <string>
#include <iostream>

#include <functional>
#include "address.h"

namespace bvt
{

const auto octetsNum = 4;
using byte = uint8_t;

class Address
{

    public:

    Address(): data() { };

    /** @brief Convert string to newly created address
     *  @param address address in string format for conversion.
     *  @throw Address::InvalidAddressString On invalid address in given string.
     */
     Address(const std::string &address);

    operator std::string() const;
    bool operator <(const Address &other) const;
    bool operator >(const Address &other) const;

    /** @brief Get address octet by number
     *  @param index Number of octet starting from 1.
     *  @throw std::out_of_range On invalid octet index.
     */
    byte getOctet(int index) const { return data.at(index - 1); }

    std::array<byte, octetsNum>::const_iterator begin() const { return data.cbegin(); }
    std::array<byte, octetsNum>::const_iterator end() const { return data.cend(); }

    class InvalidAddressString: public std::logic_error
    {
    public:
        explicit InvalidAddressString(const std::string &input):
                std::logic_error(
                        "Invalid IPv4 address \"" + input +
                        "\" has been given to IPv4Address.") { }
    };

private:
    std::array<typeof(uint8_t), octetsNum> data;

};


std::ostream &operator <<(std::ostream &stream, const Address &addr);
}
#endif //CPP2_ADDRESS_H
