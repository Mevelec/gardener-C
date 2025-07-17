FROM ubuntu:22.04

# Set environment variables to avoid prompts during installs
ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        build-essential \
        ca-certificates \
        && rm -rf /var/lib/apt/lists/*



COPY ../vendor/pigpio /vendor/pigpio

# Install pigpio
WORKDIR /vendor/pigpio
RUN make && make install