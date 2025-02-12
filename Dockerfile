# builds
FROM gcc:12.4.0-bookworm AS build

WORKDIR /app
COPY . .

RUN apt-get update && \
    apt-get -y install gcc && \
    rm -rf /var/lib/apt/lists/*

RUN gcc -Wall -o /app/echo-server.bin ./echo-server.c


# application
FROM gcr.io/distroless/static-debian12

COPY --from=build /app/echo-server.bin /
CMD ["echo-server.bin"]

EXPOSE 8088
