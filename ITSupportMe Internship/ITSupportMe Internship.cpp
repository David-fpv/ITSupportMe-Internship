#include <iostream>
#include "curl_wrapper.h"
#include <string>

int main(void)
{
    CurlWrapper test("https://jsonplaceholder.typicode.com/users");
    std::cout << test.get_message() << "\n\n\n\n";
    CurlWrapper test2("https://example.com");
    std::cout << test2.get_message() << "\n";
    std::cout << test2.get_result_code();
    return 0;
}