#ifndef DEFAULT_METHOD_EXECUTOR_HPP
# define DEFAULT_METHOD_EXECUTOR_HPP
# include "HttpRequestMessage.hpp"
# include "HttpResponseMessage.hpp"
# include "IMethodExecutor.hpp"
# include <iostream>
# include <string>
# include <fstream>

using namespace std;

class DefaultMethodExecutor : public IMethodExecutor
{
    private:
    public:
        int getMethod(const string &resourcePath, string &response);
        int postMethod(const string &resourcePath, const string &request, string &response);
        int deleteMethod(const string & resourcePath) const;
};
#endif