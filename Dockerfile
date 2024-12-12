FROM ubuntu:22.04 as builder

# Install build dependencies
RUN apt-get update && apt-get install -y --no-install-recommends \
    cmake \
    g++ \
    make \
    libcurl4-openssl-dev \
    libboost-all-dev \
    libjsoncpp-dev \
    libssl-dev \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# Install websocketpp (it's not available as apt package, needs manual download & build)
RUN apt-get update && apt-get install -y wget && \
    wget https://github.com/zaphoyd/websocketpp/archive/refs/tags/0.8.2.tar.gz -O websocketpp.tar.gz && \
    tar -xzf websocketpp.tar.gz && \
    cd websocketpp-0.8.2 && mkdir build && cd build && cmake .. && make install && cd ../.. && rm -rf websocketpp-0.8.2 websocketpp.tar.gz

# Set the working directory for building
WORKDIR /app

# Copy only CMakeLists.txt and source files for better layer caching
COPY CMakeLists.txt ./
COPY include/ ./include/
COPY src/ ./src/

# Build the project
RUN cmake -Bbuild -H. && cmake --build build --config Release

FROM ubuntu:22.04 as final

# Installing runtime dependencies
RUN apt-get update && apt-get install -y --no-install-recommends \
    libcurl4 \
    libboost-system1.74.0 \
    libjsoncpp25 \
    libssl1.1 \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# Copy the compiled executable from the builder stage
COPY --from=builder /app/build/data-analytics-microservice /app/data-analytics-microservice

# working directory
WORKDIR /app

# Expose the port the app will run on (adjust if you want)
EXPOSE 8081

# Set the default command to run your application
CMD ["./data-analytics-microservice"]