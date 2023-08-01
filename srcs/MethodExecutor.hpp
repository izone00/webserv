#ifndef METHOD_EXECUTOR_HPP
# define METHOD_EXECUTOR_HPP 
# include <iostream>
# include <string>
using namespace std;

class MethodExecutor
{
    private:
    public:
        int getMethod() const; //리소스파일 경로(혹은 cgi 생성 결과물 경로)
        void postMethod() const;
        void deleteMethod() const;
};
#endif