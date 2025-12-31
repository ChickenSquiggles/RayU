add_library(TypeDef typedef.cpp typedef.h)
add_library(UiElement uielement.cpp uielement.h)
add_library(Elements elements.cpp elements.h)
add_library(RayU rayu.cpp rayu.h)

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