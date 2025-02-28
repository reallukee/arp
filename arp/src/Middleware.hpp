#ifndef ARP_MIDDLEWARE_HPP
#define ARP_MIDDLEWARE_HPP

#include <Arduino.h>
#include <WiFi.h>

#include "Request.hpp"
#include "Response.hpp"

typedef Response (*MiddlewareCallback)(Request&);

class Middleware
{

private:

    String method;
    String path;

    MiddlewareCallback callback;

public:

    Middleware(
        String method,
        String path,
        MiddlewareCallback callback
    );

    Middleware();

    String getMethod();
    String getPath();

    MiddlewareCallback getCallback();



    Middleware* nextMiddleware = nullptr;

};

#endif // !ARP_MIDDLEWARE_HPP
