#include "curl_wrapper.h"


CurlWrapper::CurlWrapper(std::string url)
{
	curl_ = curl_easy_init();
	url_ = url;

	if (curl_) {
		curl_easy_setopt(curl_, CURLOPT_URL, url_);
		curl_easy_setopt(curl_, CURLOPT_FOLLOWLOCATION, 1L);
		curl_easy_setopt(curl_, CURLOPT_WRITEFUNCTION, &CurlWrapper::WriteCallback);
		curl_easy_setopt(curl_, CURLOPT_WRITEDATA, &message_);
	}
}

CurlWrapper::~CurlWrapper()
{
	curl_easy_cleanup(curl_);
}


std::string CurlWrapper::get_message()
{
	if (curl_)
	{
		result_ = curl_easy_perform(curl_);
		if (result_ != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
				curl_easy_strerror(result_));

		curl_easy_cleanup(curl_);
	}

	return message_;
}

std::string CurlWrapper::get_CURLcode()
{
	std::string code(url_);
	return code;
}

std::string CurlWrapper::get_url()
{
	return url_;
}

void CurlWrapper::set_url(std::string url)
{
	url_ = url;
	curl_easy_setopt(curl_, CURLOPT_URL, "https://jsonplaceholder.typicode.com/users");
}

size_t CurlWrapper::WriteCallback(void* buffer, size_t size, size_t nmemb, std::string message)
{
	size_t real_size = size * nmemb;
	message.assign((char*)buffer, real_size);
	return real_size;
}

