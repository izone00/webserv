#ifndef CLIENT_HPP
# define CLINET_HPP

# include <iostream>
# include <exception>

# include "Server.hpp"
# include "ResponseBuilder.hpp"

class Server;

class Client
{
private:
	int sock;
	Server *server;
	std::string send_buf;
	std::string recv_buf;

public:
	Client(int sock);
	~Client();

	void send_msg();
	void recv_msg();

	int getSock() const;
	Server *getServer() const;
	std::string getRecvBuf() const;
	void setSendBuf(std::string send_buf);
};

#endif