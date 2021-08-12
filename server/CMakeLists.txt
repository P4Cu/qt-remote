find_package(Qt5 COMPONENTS RemoteObjects REQUIRED)

set(SOURCES
        main.cpp
        simpleswitch.cpp
)

qt5_generate_repc(SOURCES simpleswitch.rep SOURCE)

add_executable(server
    ${SOURCES}
)

target_link_libraries(server PRIVATE Qt5::RemoteObjects)
