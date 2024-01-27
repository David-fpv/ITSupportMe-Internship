#include <stdio.h>
#include <curl/curl.h>
#include <string>
#include <iostream>

size_t write_data(void* buffer, size_t size, size_t nmemb, void* userp);

int main(void)
{
    CURL* curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://jsonplaceholder.typicode.com/users");
        /* example.com is redirected, so we tell libcurl to follow redirection */
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));

        /* always cleanup */
        curl_easy_cleanup(curl);
    }
    return 0;
}

size_t write_data(void* buffer, size_t size, size_t nmemb, void* userp)
{
    std::string message((char*)buffer, size * nmemb);
    std::cout << "Received message: " << message << std::endl;
    return nmemb;
}