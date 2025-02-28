#include "Endpoint.hpp"

Endpoint::Endpoint(
    String method,
    String path,
    EndpointCallback callback
)
{
    this->method = method;
    this->path = path;

    this->callback = callback;
}

Endpoint::Endpoint()
{
    return;
}

String Endpoint::getMethod()
{
    return this->method;
}

String Endpoint::getPath()
{
    return this->path;
}

EndpointCallback Endpoint::getCallback()
{
    return this->callback;
}
