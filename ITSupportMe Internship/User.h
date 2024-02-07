#pragma once

#include <string>
#include <vector>
#include <boost/json.hpp>
using namespace boost::json;

namespace boost_json_user_ns
{

    struct Geo
    {
        std::string lat;
        std::string lng;
    };

    struct Address
    {
        std::string street;
        std::string suite;
        std::string city;
        std::string zipcode;
        Geo geo;
    };

    struct Company
    {
        std::string name;
        std::string catchPhrase;
        std::string bs;
    };

    struct User
    {
        int64_t id;
        std::string name;
        std::string username;
        std::string email;
        Address address;
        std::string phone;
        std::string website;
        Company company;
    };

    Geo tag_invoke(boost::json::value_to_tag<Geo>, boost::json::value const& jv);

    Address tag_invoke(boost::json::value_to_tag<Address>, boost::json::value const& jv);

    Company tag_invoke(boost::json::value_to_tag<Company>, boost::json::value const& jv);

    User tag_invoke(boost::json::value_to_tag<User>, boost::json::value const& jv);

    std::vector<User> ParseUsers(std::string data);
}

