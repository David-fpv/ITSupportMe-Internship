#include "User.h"
namespace boost_json_user_ns
{

    Geo tag_invoke(boost::json::value_to_tag<Geo>, boost::json::value const& jv) {
        auto& jo = jv.as_object();
        Geo geo;
        geo.lat = jo.at("lat").as_string().c_str();
        geo.lng = jo.at("lng").as_string().c_str();
        return geo;
    }

    Address tag_invoke(boost::json::value_to_tag<Address>, boost::json::value const& jv) {
        auto& jo = jv.as_object();
        Address address;
        address.street = jo.at("street").as_string().c_str();
        address.suite = jo.at("street").as_string().c_str();
        address.city = jo.at("city").as_string().c_str();
        address.zipcode = jo.at("zipcode").as_string().c_str();

        address.geo = boost::json::value_to<Geo>(jv.at("geo"));
        return address;
    }

    Company tag_invoke(boost::json::value_to_tag<Company>, boost::json::value const& jv) {
        auto& jo = jv.as_object();
        Company company;
        company.name = jo.at("name").as_string().c_str();
        company.catchPhrase = jo.at("catchPhrase").as_string().c_str();
        company.bs = jo.at("bs").as_string().c_str();

        return company;
    }

    User tag_invoke(boost::json::value_to_tag<User>, boost::json::value const& jv) {
        auto& jo = jv.as_object();
        User user;

        /*if (jo.at("id").if_int64()) // Type check
        {
            user.id = jo.at("id").as_int64();
        }
        else
        {
            user.id = -1;
        }*/

        user.id = jo.at("id").as_int64();
        user.name = jo.at("name").as_string().c_str();
        user.username = jo.at("username").as_string().c_str();
        user.email = jo.at("email").as_string().c_str();
        user.address = boost::json::value_to<Address>(jv.at("address"));
        user.phone = jo.at("phone").as_string().c_str();
        user.website = jo.at("website").as_string().c_str();
        user.company = boost::json::value_to<Company>(jv.at("company"));

        return user;
    }

    std::vector<User> ParseUsers(std::string data)
    {
        error_code ec;
        parse_options opt;
        opt.allow_comments = true;          // Allow comments
        opt.allow_trailing_commas = true;   // Allow tail comma
        value decode_data = parse(data, ec);

        std::vector<User> users;

        if (ec)
        {
            return users;
        }

        for (int i = 0; i < decode_data.as_array().size(); i++)
        {
            users.push_back(value_to<User>(decode_data.as_array()[i]));
        }

        return users;
    }

}