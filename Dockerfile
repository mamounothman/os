FROM ubuntu:latest

MAINTAINER mamounothman@gmail.com

RUN apt install build-essintials gcc nasm -y

ADD ./ /os

# to run this docker use this command:
# docker run -t -d -v ./:/os --name os_dev gcc:nasm