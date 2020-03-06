FROM conanio/gcc8

RUN sudo apt update
RUN sudo apt install -y vim
RUN conan remote update conan-center https://conan.bintray.com false

WORKDIR /

ENTRYPOINT ["/bin/bash"]