#include "Middleware.hpp"

Middleware::Middleware(
    String method,
    String path,
    MiddlewareCallback callback
)
{
    this->method = method;
    this->path = path;

    this->callback = callback;
}

Middleware::Middleware()
{
    return;
}

String Middleware::getMethod()
{
    return this->method;
}

String Middleware::getPath()
{
    return this->path;
}

MiddlewareCallback Middleware::getCallback()
{
    return this->callback;
}
