#include <iostream>
#include "ConfigParser.hpp"
#include "ServerHandler.hpp"
#include "HttpResponseBuilder.hpp"
#include "IMethodExecutor.hpp"
#include "DefaultMethodExecutor.hpp"
#include "CgiMethodExecutor.hpp"
#include "WebservValues.hpp"
#include "ServerConfig.hpp"
#include "Config.hpp"

int main(void)
{
	try
	{
		ConfigParser parser("tester.conf");
		ServerHandler sh(parser.get());
		sh.loop();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << errno << ": " << strerror(errno) << '\n';
	}
	return 0;
}