project(GameLib)

set(SOURCE_FILES
        pch.h
        MainFrame.cpp MainFrame.h
        ids.h
        Game.cpp Game.h
        GameView.h GameView.cpp
        item.h item.cpp
        Bug.h Bug.cpp
        GarbageBug.h GarbageBug.cpp
        NullBug.h NullBug.cpp
        RedundancyBug.h RedundancyBug.cpp
        FeatureBug.h FeatureBug.cpp Program.h Program.cpp)

set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)