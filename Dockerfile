# daemon runs in the background
# run something like tail /var/log/Ionized/current to see the status
# be sure to run with volumes, ie:
# docker run -v $(pwd)/Ionized:/var/lib/Ionized -v $(pwd)/wallet:/home/Ionize --rm -ti Ionize:0.2.2
ARG base_image_version=0.10.0
FROM phusion/baseimage:$base_image_version

ADD https://github.com/just-containers/s6-overlay/releases/download/v1.21.2.2/s6-overlay-amd64.tar.gz /tmp/
RUN tar xzf /tmp/s6-overlay-amd64.tar.gz -C /

ADD https://github.com/just-containers/socklog-overlay/releases/download/v2.1.0-0/socklog-overlay-amd64.tar.gz /tmp/
RUN tar xzf /tmp/socklog-overlay-amd64.tar.gz -C /

ARG Ionize_BRANCH=master
ENV Ionize_BRANCH=${Ionize_BRANCH}

# install build dependencies
# checkout the latest tag
# build and install
RUN apt-get update && \
    apt-get install -y \
      build-essential \
      python-dev \
      gcc-4.9 \
      g++-4.9 \
      git cmake \
      libboost1.58-all-dev && \
    git clone https://github.com/Ionize/Ionize.git /src/Ionize && \
    cd /src/Ionize && \
    git checkout $Ionize_BRANCH && \
    mkdir build && \
    cd build && \
    cmake -DCMAKE_CXX_FLAGS="-g0 -Os -fPIC -std=gnu++11" .. && \
    make -j$(nproc) && \
    mkdir -p /usr/local/bin && \
    cp src/Ionized /usr/local/bin/Ionized && \
    cp src/walletd /usr/local/bin/walletd && \
    cp src/zedwallet /usr/local/bin/zedwallet && \
    cp src/miner /usr/local/bin/miner && \
    strip /usr/local/bin/Ionized && \
    strip /usr/local/bin/walletd && \
    strip /usr/local/bin/zedwallet && \
    strip /usr/local/bin/miner && \
    cd / && \
    rm -rf /src/Ionize && \
    apt-get remove -y build-essential python-dev gcc-4.9 g++-4.9 git cmake libboost1.58-all-dev && \
    apt-get autoremove -y && \
    apt-get install -y  \
      libboost-system1.58.0 \
      libboost-filesystem1.58.0 \
      libboost-thread1.58.0 \
      libboost-date-time1.58.0 \
      libboost-chrono1.58.0 \
      libboost-regex1.58.0 \
      libboost-serialization1.58.0 \
      libboost-program-options1.58.0 \
      libicu55

# setup the Ionized service
RUN useradd -r -s /usr/sbin/nologin -m -d /var/lib/Ionized Ionized && \
    useradd -s /bin/bash -m -d /home/Ionize Ionize && \
    mkdir -p /etc/services.d/Ionized/log && \
    mkdir -p /var/log/Ionized && \
    echo "#!/usr/bin/execlineb" > /etc/services.d/Ionized/run && \
    echo "fdmove -c 2 1" >> /etc/services.d/Ionized/run && \
    echo "cd /var/lib/Ionized" >> /etc/services.d/Ionized/run && \
    echo "export HOME /var/lib/Ionized" >> /etc/services.d/Ionized/run && \
    echo "s6-setuidgid Ionized /usr/local/bin/Ionized" >> /etc/services.d/Ionized/run && \
    chmod +x /etc/services.d/Ionized/run && \
    chown nobody:nogroup /var/log/Ionized && \
    echo "#!/usr/bin/execlineb" > /etc/services.d/Ionized/log/run && \
    echo "s6-setuidgid nobody" >> /etc/services.d/Ionized/log/run && \
    echo "s6-log -bp -- n20 s1000000 /var/log/Ionized" >> /etc/services.d/Ionized/log/run && \
    chmod +x /etc/services.d/Ionized/log/run && \
    echo "/var/lib/Ionized true Ionized 0644 0755" > /etc/fix-attrs.d/Ionized-home && \
    echo "/home/Ionize true Ionize 0644 0755" > /etc/fix-attrs.d/Ionize-home && \
    echo "/var/log/Ionized true nobody 0644 0755" > /etc/fix-attrs.d/Ionized-logs

VOLUME ["/var/lib/Ionized", "/home/Ionize","/var/log/Ionized"]

ENTRYPOINT ["/init"]
CMD ["/usr/bin/execlineb", "-P", "-c", "emptyenv cd /home/Ionize export HOME /home/Ionize s6-setuidgid Ionize /bin/bash"]
