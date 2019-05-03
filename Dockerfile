FROM ubuntu:18.04

RUN apt-get update && \
    apt-get install --no-install-recommends \
        vim g++ make cmake \
        libboost-all-dev && \
    rm -rf /var/lib/apt/lists/*
