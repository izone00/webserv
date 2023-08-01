#include "MethodExecutor.hpp"

int MethodExecutor::getMethod() const // cgi x
{
    /*
    1. 요청헤더타입체크(조건부요청헤드, ...)
        a. 해당 파일의 최근 수정일자, 기타등등 요청에 부합하는 자료인지 체크 (근데 이걸 여기서 하면 안될듯)
        // 적합하다면 다음으로 넘어감
    2. 리소스파일 준비
        a. (cgi x) 해당 리소스 열기
        b. (cgi o) 매개변수로 생성된 파일을 스트링으로 받아오기
    3. response body에 저장하기(핵심)
        a. (cgi x) 오픈한 리소스를 body에 copy write
        b. (cgi o) 소영이한테 받은 생성된파일 스트링을 body에 저장 
    */ 
}

int MethodExecutor::getMethod() const
{

}

void MethodExecutor::postMethod() const
{
    /*
    1. 리소스파일 준비
        a. request message body 사용
        c. chunked 타입인 경우에는 객체에 저장해놓은 request body 사용
    2. 요청헤더타입체크(조건부요청헤드, ...)
        a. 해당 파일의 최근 수정일자, 기타등등 요청에 부합하는 자료인지 체크
    3. 요청한 경로에 저장하기(핵심) 
    */ 
}
void MethodExecutor::deleteMethod() const
{

}