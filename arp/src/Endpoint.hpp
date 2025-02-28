#ifndef ARP_ENDPOINT_HPP
#define ARP_ENDPOINT_HPP

#include <Arduino.h>
#include <WiFi.h>

#include "Request.hpp"
#include "Response.hpp"

typedef Response (*EndpointCallback)(Request&);

class Endpoint
{

private:

    String method;
    String path;

    EndpointCallback callback;

public:

    Endpoint(
        String method,
        String path,
        EndpointCallback callback
    );

    Endpoint();

    String getMethod();
    String getPath();

    EndpointCallback getCallback();



    Endpoint* nextEndpoint = nullptr;

};

#endif // !ARP_ENDPOINT_HPP
