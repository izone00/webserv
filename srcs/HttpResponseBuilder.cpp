#include "HttpResponseBuilder.hpp"
//locations 매개변수로 있어야됌
HttpResponseBuilder::HttpResponseBuilder(const string &request, EnvironmentValues &envRepo)
{
    HttpRequestMessage requestMessage(request);
    if (requestMessage.getChunkedFlag() == true) {
        requestBody = requestMessage.getBody();
    }
    requestMessageList.push_back(HttpRequestMessage(requestMessage));
    needMoreMessageFlag = requestMessage.getChunkedFlag();
    setEnvironmentValue();

    //환경변수에 세팅해주기
    envRepo.setPair("method", method);
    envRepo.setPair("host", host);
    envRepo.setPair("uri", uri);
    envRepo.setPair("args", args);
    envRepo.setPair("query_string", queryString);
    envRepo.setPair("request_uri", requestUri);
    envRepo.setPair("request_filename", requestFilename);
    //기타등등
}

void HttpResponseBuilder::setEnvironmentValue()
{
    HttpRequestMessage requestMessage = requestMessageList.at(0); 
    // <경로>;<파라미터>?<질의>#<프래그먼트> 경로조각은 없다고 가정
    map<string, string> headers = requestMessage.getHeaders();
    method = requestMessage.getMethod();
    requestUri = requestMessage.getUri();
    //host parsing
    if (headers.find("Host") != headers.end()) {
        host = headers.at("Host");
    }
    //uri parsing
    size_t pos = requestUri.find_first_of(";?#");
    if (pos == string::npos) {
        uri = requestUri;
    }
    else {
        uri = requestUri.substr(0, pos);
    }
    //requestFilename parsing
    requestFilename = requestUri.substr(requestUri.find_last_of("/")+1, pos-requestUri.find_last_of("/")-1);
    //args parsing
    pos = requestUri.find(";");
    if (pos != string::npos) {
        args = requestUri.substr(pos+1, min(requestUri.find("?"), requestUri.length())-pos-1);
    }
    //queryString parsing
    pos = requestUri.find("?");
    if (pos != string::npos) {
        queryString = requestUri.substr(pos+1, min(requestUri.find("#"), requestUri.length())-pos-1);
    }
    //CGI 변수 쓸지말지 체크해야됌
}

void HttpResponseBuilder::addRequestMessage(const string &request)
{
    HttpRequestMessage requestMessage(request);
    requestMessageList.push_back(HttpRequestMessage(requestMessage));
    needMoreMessageFlag = requestMessage.getChunkedFlag();
    requestBody.append(requestMessage.getBody());
}

string HttpResponseBuilder::getMethod() const
{
    return method;
}

string HttpResponseBuilder::getHost() const
{
    return host;
}

string HttpResponseBuilder::getUri() const
{
    return uri;
}

string HttpResponseBuilder::getArgs() const
{
    return args;
}

string HttpResponseBuilder::getQueryString() const
{
    return queryString;
}

string HttpResponseBuilder::getRequestUri() const
{
    return requestUri;
}

string HttpResponseBuilder::getRequestFilename() const
{
    return requestFilename;
}

bool HttpResponseBuilder::getNeedMoreMessageFlag() const
{
    return needMoreMessageFlag;
}

bool HttpResponseBuilder::getNeedCgiFlag() const
{
    return needCgiFlag;
}

void HttpResponseBuilder::execute(const MethodExecutor &methodExecutor)
{
    HttpRequestMessage requestMessage = requestMessageList.at(0);

    //로케이션 대치하고 뭐,,이러쿵저러쿵한 스트링을 사용해서 실제 리소스가 있는 패스 스트링 만들겠지.. 
    //아니면 환경변수 객체에서 꺼내든지
    string path = "/Users/eunjilee/42Seoul/42cursus/webserv/resource/image.jpg";
    
    if (method == "GET") {
        methodExecutor.getMethod(requestMessage, responseMessage, path);
    }
    else if(method == "POST") {
        methodExecutor.postMethod();
    }
    else if(method == "DELETE") {
        methodExecutor.deleteMethod();
    }
}