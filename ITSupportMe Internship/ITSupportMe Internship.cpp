#include <stdio.h>
#include <curl/curl.h>

size_t write_data(void* buffer, size_t size, size_t nmemb, void* userp);

int main(void)
{
    CURL* curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://jsonplaceholder.typicode.com/users");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }
    return 0;
}

size_t write_data(void* buffer, size_t size, size_t nmemb, void* userp)
{
    printf("%s", buffer);
    return nmemb * size;
}