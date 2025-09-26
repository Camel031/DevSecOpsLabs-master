FROM mcr.microsoft.com/cstsectools/codeql-container
USER root
RUN codeql query compile --threads=$(nproc) /usr/local/codeql-home/codeql-repo/cpp/ql/src