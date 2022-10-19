#include <catch2/catch_session.hpp>

#include "mem_dump.hpp"

int main(int argc, char **argv) {
    return Catch::Session().run(argc, argv);
}