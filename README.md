# CPP로 구현한 IO 멀티 플렉싱 웹 서버

이 프로젝트는 C++을 사용하여 Nginx를 모방한 간단한 IO 멀티 플렉싱 웹 서버를 구현하는 것을 목표로 합니다. 이 서버는 기본적인 웹 서버의 기능을 갖추고 있으며, 여러 클라이언트의 요청을 동시에 처리할 수 있는 멀티 플렉싱 기술을 이용하여 효율적으로 처리합니다.


## 기능

1. **HTTP 요청 처리**: 클라이언트로부터 HTTP GET 요청을 받아들이고 해당하는 정적 파일을 제공합니다.
2. **멀티 플렉싱**: 단일 스레드에서 여러 클라이언트의 동시 요청을 처리하기 위해 IO 멀티 플렉싱 기술을 사용합니다.
3. **간단한 설정**: 설정 파일을 통해 포트 번호, 웹 서버 루트 디렉토리 등을 지정할 수 있습니다.
4. **CGI**: 동적인 콘텐츠 생성을 위해 CGI를 지원합니다.

## 사용된 기술

1. **C++**: 서버의 주요 언어로 사용됩니다.
2. **IO 멀티 플렉싱**: `select()` 또는 `epoll()`을 사용하여 다중 소켓 이벤트를 관리합니다.
3. **HTTP 프로토콜**: 클라이언트와의 통신은 HTTP 프로토콜을 준수합니다.

## 설치 및 실행
1. repository를 clone 받기
2. MakeFile이 있는 경로에서 `make`명령어 실행
<img width="564" alt="Screen Shot 2024-02-19 at 2 05 08 PM" src="https://github.com/izone00/webserv/assets/91773764/3aa2fd1d-f0d0-4078-95b8-cac5561a8c08">


3. `./webserv tester.conf` 명령어를 이용해 웹서버를 실행 (첫번째 인자는 config파일로 변경가능)
<img width="564" alt="Screen Shot 2024-02-19 at 2 05 43 PM" src="https://github.com/izone00/webserv/assets/91773764/e9f36778-ae69-4bfd-aaf6-582ef1fc2db2">


4. 아래와 같이 nginx의 http모듈과 같은 방식으로 config파일을 수정할 수 있습니다.
  ```
server {
    listen 127.0.0.1:8088;

    server_name localhost;
    index index.html;
    
	  cgi_params {
        QUERY_STRING            $query_string;
        ...
	  }

    location / {
        index index.html;
        accept_method GET;
        autoindex on;
    }
    location /cgi-bin/ {
        cgi py;
        index index.py;
        accept_method GET POST;
        client_max_body_size 1000000000;
    }
    location /customErrPage/ {
        root Custom;
        accept_method GET;
        autoindex on;
    }
    types {
        text/html                             html htm shtml;
        text/css                              css;
        text/xml                              xml rss;
        ...
    }
    
    error_page 404 /customErrPage/404_error.html;
}
```
