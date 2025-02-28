#include "Response.hpp"

Response::Response(
    unsigned statusCode,
    String statusText,
    String body
)
{
    this->statusCode = statusCode;
    this->statusText = statusText;
    this->body = body;
}

unsigned Response::getStatusCode()
{
    return this->statusCode;
}

String Response::getStatusText()
{
    return this->statusText;
}

String Response::getBody()
{
    return this->body;
}
