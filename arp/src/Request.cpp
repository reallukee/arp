#include "request.hpp"

Request::Request(
    String method,
    String path,
    String protocol,
    Header* headers,
    String body
)
{
    this->method = method;
    this->path = path;
    this->protocol = protocol;

    this->headers = headers;

    this->body = body;
}

Request::Request(String request)
{
    return;
}

String Request::getMethod()
{
    return this->method;
}

String Request::getPath()
{
    return this->path;
}

String Request::getProtocol()
{
    return this->protocol;
}

Header* Request::getHeaders()
{
    return this->headers;
}

String Request::getBody()
{
    return this->body;
}
