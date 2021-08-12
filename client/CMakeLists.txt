find_package(Qt5 COMPONENTS Quick RemoteObjects REQUIRED)

set(SOURCES
        main.cpp
        qml.qrc
)

# TODO: ideally this should come from interface folder or "server" target itself
qt5_generate_repc(SOURCES ${PROJECT_SOURCE_DIR}/server/simpleswitch.rep REPLICA)

add_executable(client
    ${SOURCES}
)

target_link_libraries(client PRIVATE Qt5::Quick Qt5::RemoteObjects)
