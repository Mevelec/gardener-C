# Dockerfile
FROM elros37/c_builder:0.0.2
ARG CONFIG=release

# Set environment variables to avoid prompts during installs
ENV DEBIAN_FRONTEND=noninteractive
RUN find /usr -name "libpigpio.*"
COPY ./ /project

WORKDIR /project
RUN set -x && \
    ./vendor/premake/premake5.work gmake $CONFIG && \
    make config=$CONFIG && \
    mkdir /app && \
    mv /project/bin/$CONFIG-linux-x86_64/* /app/

WORKDIR /workspace
CMD ["/app/Gardener/Gardener"]