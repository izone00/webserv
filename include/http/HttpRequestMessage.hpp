#ifndef HTTP_REQUEST_MESSAGE_HPP
# define HTTP_REQUEST_MESSAGE_HPP
#include "HttpMessage.hpp"
#include "Utils.hpp"

class HttpRequestMessage : public HttpMessage
{
    private:
        string httpMethod;
        string requestTarget;
        void parseRequestMessage(const string &requestMessage);
        bool chunkedFlag;
        void parseUri();

        string requestUri;
        string uri;
        string filename;
        string args;
        string queryString;

    public:
        HttpRequestMessage(const string &requestMessage);
        string getHttpMethod() const;
        string getRequestTarget() const;
        int getChunkedFlag() const;
        string getRequestUri() const;
        string getUri() const;
        string getFilename() const;
        string getArgs() const;
        string getQueryString() const;
};

#endif