# Dockerfile
FROM ubuntu:22.04
ARG CONFIG=release

# Set environment variables to avoid prompts during installs
ENV DEBIAN_FRONTEND=noninteractive

# Update and install prerequisites
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        ca-certificates \
        build-essential \
        git \
        wget \
        && rm -rf /var/lib/apt/lists/*

# Clone pigpio from its repository then Build and install 
RUN git clone https://github.com/joan2937/pigpio.git /opt/pigpio
WORKDIR /opt/pigpio
RUN make && make install

COPY ./ /project
WORKDIR /project

RUN set -x && \
    ./vendor/premake/premake5.work gmake $CONFIG && \
    make config=$CONFIG && \
    mkdir /app && \
    mv /project/bin/$CONFIG-linux-x86_64/* /app/

WORKDIR /workspace
CMD ["/app/Gardener/Gardener"]