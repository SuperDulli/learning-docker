FROM alpine:3.16
RUN apk update
RUN apk add build-base

WORKDIR /cpp/src/app

COPY *.cpp *.hpp Makefile ./

RUN make

CMD ./server