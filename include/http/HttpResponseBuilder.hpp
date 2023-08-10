#ifndef HTTP_RESPONSE_BUILDER_HPP
# define HTTP_RESPONSE_BUILDER_HPP
# include "HttpRequestMessage.hpp"
# include "HttpResponseMessage.hpp"
# include "IMethodExecutor.hpp"
# include "WebservValues.hpp"
# include "ServerConfig.hpp"
# include "LocationConfig.hpp"
# include "ResponseHeaderAdder.hpp"
# include <vector>
# include <sys/stat.h>
# include <unistd.h>

class Server;

class HttpResponseBuilder {

    private:
        HttpRequestMessage *requestMessage;
        HttpResponseMessage *responseMessage;
        LocationConfig locationConfig;
        const Server *server;
        WebservValues *webservValues;

        string resourcePath; // locations를 거쳐 찾은 진짜 경로
        string requestBody;
        bool needMoreMessageFlag; 
        bool needCgiFlag;
        void initWebservValues();
        int errorCode;
        string errorPhrase;
        bool  ready;
    public:
        HttpResponseBuilder(const Server *server, WebservValues & webservValues);
        void build(IMethodExecutor & methodExecutor);
        void parseCgiProduct(string & response, string & contentType);
        void addRequestMessage(const string &request);
        string getResourcePath() const;
        string findReasonPhrase(const int &statusCode);
        bool getNeedMoreMessageFlag() const;
        bool getNeedCgiFlag() const;
        HttpResponseMessage getResponseMessage() const;
        HttpRequestMessage getRequestMessage() const;
        void initiate(const string & request);
        void clear();
        LocationConfig getLocationConfig() const;
        int verifyUrl();
        void setErrorCode(const int & num);
        int getErrorCode() const;
        void setErrorPhrase(const string & errorPhrase);
        string getErrorPhrase() const;
        int checkAcceptMethod();
};

#endif
