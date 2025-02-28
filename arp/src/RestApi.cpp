#include "RestApi.hpp"

RestApi::RestApi()
{
    return;
}

void RestApi::listen(unsigned short port)
{
    this->port = port;

    this->server.begin(port);
}

void RestApi::read()
{
    WiFiClient client = server.available();

    if (client)
    {
        String requestLine = client.readStringUntil(0x0A);

        int end = 0;
        String words[3];
        int start = 0;

        for (int i = 0, j = 0; i < requestLine.length(); i++)
        {
            if (requestLine.charAt(i) == 0x20 || requestLine.charAt(i) == 0x0A)
            {
                end = i;
                words[j++] = requestLine.substring(start, end);
                start = i + 1;
            }
        }

        String method = words[0];   // HTTP Request Method
        String path = words[1];     // HTTP Request Path
        String protocol = words[2]; // HTTP Request Protocol

        Request request = Request(
            method, path, protocol, NULL, ""
        );

        /*
        Middleware* middleware = middlewares;

        while (middleware != nullptr)
        {
            if (middleware->getMethod() == method && middleware->getPath() == path)
            {
                MiddlewareCallback callback = middleware->getCallback();

                callback(request);
            }

            middleware = middleware->nextMiddleware;
        }
        */

        Endpoint* endpoint = endpoints;

        while (endpoint != nullptr)
        {
            if (endpoint->getMethod() == method && endpoint->getPath() == path)
            {
                EndpointCallback callback = endpoint->getCallback();

                Response response = callback(request);

                client.print("HTTP/1.1");
                client.print(" ");
                client.print(response.getStatusCode());
                client.print(" ");
                client.print(response.getStatusText());
                client.println();

                client.println();

                client.print(response.getBody());
                client.println();

                client.println();

                client.stop();
            }

            endpoint = endpoint->nextEndpoint;
        }

        client.print("HTTP/1.1 404 Not Found");
        client.println();

        client.println();

        client.print("Not Found");
        client.println();

        client.println();

        client.stop();
    }
}

void RestApi::endpoint(
    String method,
    String path,
    EndpointCallback callback
)
{
    if (endpoints == nullptr)
    {
        endpoints = new Endpoint(method, path, callback);
    }
    else
    {
        Endpoint* endpoint = endpoints;

        while (endpoint->nextEndpoint != nullptr)
        {
            endpoint = endpoint->nextEndpoint;
        }

        endpoint->nextEndpoint = new Endpoint(method, path, callback);
    }
}

void RestApi::middleware(
    String method,
    String path,
    MiddlewareCallback callback
)
{
    if (middlewares == nullptr)
    {
        middlewares = new Middleware(method, path, callback);
    }
    else
    {
        Middleware* middleware = middlewares;

        while (middleware->nextMiddleware != nullptr)
        {
            middleware = middleware->nextMiddleware;
        }

        middleware->nextMiddleware = new Middleware(method, path, callback);
    }
}
