#include <stdio.h>
#include <iostream>
#include "curl_wrapper.h"

int main(void)
{
    std::string URL("https://jsonplaceholder.typicode.com/users");
    CurlWrapper url_test(URL);
    std::cout << url_test.get_message();
    return 0;
}