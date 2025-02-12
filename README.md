# echo-server
Implementation of socket connection with C Language for personal workouts.

## Usage

```shell
% ./echo-server.bin 8080
Serving HTTP on 0.0.0.0 port 8080 (http://0.0.0.0:8080/) ...
Quit the server with CONTROL-C.
```

In other terminal window:

```shell
% curl --http0.9 -X GET localhost:8088/
HTTP1.1 200 OK
```

## Configurations
Environmental Variables...etc

## Build

```shell
# gcc
% gcc -Wall -o echo-server.bin ./echo-server.c
```

## Distributions
- Source code
- single binaries
- container images
- ...etc

## Credits
Implementation references on:
