add_executable(RayUExample
    main.cpp
)

target_link_libraries(RayUExample
    PRIVATE
        RayU::RayU
)

target_compile_features(RayUExample PRIVATE cxx_std_20)