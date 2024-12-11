# Use an official C++ base image
FROM gcc:latest

# Install dependencies
RUN apt-get update && apt-get install -y --no-install-recommends \
    cmake \
    libcurl4-openssl-dev \
    libboost-all-dev \
    libjsoncpp-dev \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# Set the working directory
WORKDIR /app

# Copy only CMakeLists.txt and source files for better layer caching
COPY CMakeLists.txt ./
COPY include/ ./include/
COPY src/ ./src/

# Build the project
RUN cmake -Bbuild -H. && cmake --build build

# Expose the port the app will run on
EXPOSE 8080

# Set the default command to run your application
CMD ["build/data-analytics-microservice"]
