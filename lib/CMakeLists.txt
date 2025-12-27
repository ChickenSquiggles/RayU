add_library(TypeDef typedef.cpp)
add_library(UiElement uielement.cpp)
add_library(Elements elements.cpp)
add_library(RayU rayu.cpp)

target_include_directories(
    TypeDef
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_include_directories(
    UiElement
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_include_directories(
    Elements
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_include_directories(
    RayU
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
    
target_link_libraries(TypeDef raylib)
target_link_libraries(UiElement raylib)
target_link_libraries(Elements raylib)
target_link_libraries(RayU raylib)