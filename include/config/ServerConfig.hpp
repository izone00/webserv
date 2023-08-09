#pragma once

#include <algorithm>
#include <Modules.hpp>
#include <LocationConfig.hpp>

class ServerConfig
{
public:
    ServerConfig( const ServerModule & srvMod );
    bool operator==( const string & host ) const;

    class LocationMap
    {
    private:
        friend ServerConfig;
        map<string, LocationConfig> uriMap;
        LocationConfig defaultLocConf;
    public:
        const LocationConfig &getLocConf( string uri ) const;
    };

    uint32_t getIp( void ) const;
    int getPort( void ) const;
    const vector<string> & getServerNames( void ) const;
    const LocationMap & getLocationMap( void ) const;
private:
    const ServerModule  *srvMod;
    ServerNameModule    *srvNameMod;
    LocationMap         locMap;
};

