#pragma once
#include <curl/curl.h>
#include <string>

class CurlWrapper
{
public:
	CurlWrapper(std::string url);
	~CurlWrapper();

	std::string get_message();

	std::string get_result_code();

	std::string get_url();
	void set_url(std::string url);

private:
	CURL* curl_;
	CURLcode result_code_;
	std::string url_;
	std::string message_;

	static size_t WriteCallback(void* buffer, size_t size, size_t nmemb, void* userp);
};
