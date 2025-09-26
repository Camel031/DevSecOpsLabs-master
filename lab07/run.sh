codeql database create cpp-db --language=cpp
codeql database analyze cpp-db --format=sarif-latest --output=results.sarif -- codeql/cpp-queries