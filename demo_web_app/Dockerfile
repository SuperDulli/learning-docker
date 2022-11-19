FROM debian:buster-slim

RUN apt-get update
RUN apt-get install -y nginx

# log nginx to stdout & stderr
RUN rm /var/log/nginx/access.log && ln -s /dev/stdout /var/log/nginx/access.log
RUN rm /var/log/nginx/error.log && ln -s /dev/stdout /var/log/nginx/error.log



# run nginx in fore foreground to prevent the container from quitting
# shell form
#CMD nginx -g 'daemon off;'
# exec form to become PID 1 (so container can be terminated by ctrl+c)
CMD ["nginx", "-g", "daemon off;"]

EXPOSE 80
