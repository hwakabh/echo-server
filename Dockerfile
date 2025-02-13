# builds
FROM gcc:12.4.0-bookworm AS build

WORKDIR /app
COPY . .

RUN apt-get update && \
    apt-get -y install gcc && \
    rm -rf /var/lib/apt/lists/*

RUN gcc -Wall -o /app/echo-server.bin ./echo-server.c

# application
FROM gcr.io/distroless/base-debian12 AS serve

COPY --from=build /app/echo-server.bin /
# TODO: enabled to fetch via Config Vars
CMD ["/echo-server.bin", "8088"]

EXPOSE 8088
