FROM mcr.microsoft.com/devcontainers/base:ubuntu

# Install build tools
RUN apt-get update && \
    apt-get install -y build-essential gdb cmake clang && \
    apt-get clean && rm -rf /var/lib/apt/lists/*
