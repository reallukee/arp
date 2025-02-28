#ifndef ARP_RESTAPI_HPP
#define ARP_RESTAPI_HPP

#include <Arduino.h>
#include <WiFi.h>

#include "Endpoint.hpp"
#include "Middleware.hpp"

#define DEFAULT_PORT 80

class RestApi
{

private:

    WiFiServer server;

    unsigned short port;

    Endpoint* endpoints = nullptr;
    Middleware* middlewares = nullptr;

public:

    RestApi();

    void listen(unsigned short port);

    void read();

    void endpoint(
        String method,
        String path,
        EndpointCallback callback
    );

    void middleware(
        String method,
        String path,
        MiddlewareCallback callback
    );

};

#endif // !ARP_RESTAPI_HPP
