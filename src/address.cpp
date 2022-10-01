//
// Created by BVT.MI on 25.08.2022.
//

#include "address.h"

using namespace bvt;

namespace bvt {

    Address::Address(const std::string &address) {
        int octet;
        size_t idx;

        std::vector<std::string> splited;

        std::string::size_type start = 0;
        std::string::size_type stop = address.find_first_of('.');
        while (stop != std::string::npos) {
            splited.push_back(address.substr(start, stop - start));

            start = stop + 1;
            stop = address.find_first_of('.', start);
        };

        splited.push_back(address.substr(start));

        if (splited.size() != octetsNum) throw InvalidAddressString(address);

        for (unsigned int i = 0; i < octetsNum; i++) {
            try {
                octet = std::stoi(splited[i], &idx);
            }
            catch (std::invalid_argument &e) {
                throw InvalidAddressString(address);
            }
            catch (std::out_of_range &e) {
                throw InvalidAddressString(address);
            }

            if ((octet < 0 || octet > 255) || idx < splited[i].size())
                throw InvalidAddressString(address);

            data[i] = octet;
        }
    }

    Address::operator std::string() const {
        std::string result{};

        for (unsigned int i = 0; i < data.size() - 1; i++)
            result += std::to_string(data[i]) + '.';

        result += std::to_string(data.back());

        return result;
    }


    std::ostream &operator<<(std::ostream &stream, const Address &addr) {
        stream << std::string(addr);
        return stream;
    }

    bool Address::operator <(const Address &other) const
    {
        return std::lexicographical_compare(
                this->begin(), this->end(),
                other.begin(), other.end());
    }

    bool Address::operator >(const Address &other) const
    {
        return other < *this;
    }

};