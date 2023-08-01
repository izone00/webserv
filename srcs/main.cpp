#include "HttpResponseBuilder.hpp"
#include "HttpRequestMessage.hpp"
#include "HttpResponseMessage.hpp"
#include "MethodExecutor.hpp"
#include "EnvironmentValues.hpp"

int main() {
    string line = "GET / HTTP/1.1\nAccept-Encoding:gzip\nTransfer-Encoding:chunked\n\n9\nhappy day\nforever";
    EnvironmentValues envRepo;
    HttpResponseBuilder hrb(line, envRepo);

    // 1. chunk 메시지를 모은다.
    while (hrb.getNeedMoreMessageFlag() != false) {
        hrb.addRequestMessage("new request!");
    }
    // 2. reponse 객체를 우진이한테 넘겼다가 다시 받는다.
    // 3. CGI flag를 보고 CGI가 필요하면 CGI 사용한다.
    // 4. 적당한 method 로직을 실행한다.
        // a. 만약 CGI 실행안해도되면 execute 성공시 builder가 알아서 응답객체코드 설정할것임
        // b. 만약 CGI 쓰게되면 status code를 소영이가 넣을수있도록 메소드를 짜야되나..
    MethodExecutor methodExecutor;
    hrb.execute(methodExecutor);
    // 5. 성공 실패에 따라서 적당한 status code와 기본적인 헤더를 붙인다.
    // 6. 응답객체를 스트링을 변환한 스트링을 받는다.
}
