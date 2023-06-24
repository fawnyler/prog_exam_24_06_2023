FROM ubuntu:18.04

LABEL author="fawnyler"

ENV TZ=Europe/Moscow
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update
RUN apt-get install build-essential -y
RUN apt-get install cmake -y

WORKDIR /MyProj_221-3210_Manuskina
COPY *.cpp .
COPY *.h .
COPY *.txt .

WORKDIR /MyProj_221-3210_Manuskina/build
RUN cmake ..
RUN make

WORKDIR /MyProj_221-3210_Manuskina
ENTRYPOINT ["./my_Program"]
