#include "curl_wrapper.h"


CurlWrapper::CurlWrapper(std::string url)
{
    url_ = url;

    curl_ = curl_easy_init();
    if (curl_) {
        curl_easy_setopt(curl_, CURLOPT_URL, url_.c_str());
        curl_easy_setopt(curl_, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl_, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl_, CURLOPT_WRITEDATA, &message_);
    }
}


CurlWrapper::~CurlWrapper()
{
    curl_easy_cleanup(curl_);
}


std::string CurlWrapper::get_message( )
{
    result_code_ = curl_easy_perform(curl_);
    if (result_code_ != CURLE_OK)
    {
        message_.clear();
    }

	return message_;
}


std::string CurlWrapper::get_result_code()
{
	return curl_easy_strerror(result_code_);
}


std::string CurlWrapper::get_url()
{
	return url_;
}


void CurlWrapper::set_url(std::string url)
{
	url_ = url;
    curl_easy_setopt(curl_, CURLOPT_URL, url_.c_str());
}


size_t CurlWrapper::WriteCallback(void* buffer, size_t size, size_t nmemb, void* userp)
{
	size_t real_size = size * nmemb;
	std::string data((char*)buffer, real_size);

	std::string* str = static_cast<std::string*>(userp);
	str->assign(data);

	return real_size;
}

