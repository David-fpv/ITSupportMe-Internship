#include <iostream>
#include "curl_wrapper.h"
#include <string>
#include <boost/json.hpp>
#include "User.h"
using namespace boost::json;
using namespace boost_json_user_ns;


int main(void)
{
    CurlWrapper client("https://jsonplaceholder.typicode.com/users");
    std::vector<User> users = ParseUsers(client.get_message());

    for (int i = 0; i < users.size(); i++)
    {
        std::cout << users[i].id << ". " << users[i].name << ";\n";
    }

    return 0;
}