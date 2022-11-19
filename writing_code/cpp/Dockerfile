FROM alpine:3.16
RUN apk update
RUN apk add build-base

WORKDIR /cpp/src/app

COPY hello-world.cpp .

RUN c++ hello-world.cpp -o app

CMD ./app