if (UNIX)
    add_subdirectory(GTK_Wrapper)
    set(GUI_WRAPPER_SUBPROJECTS 
        ${GUI_WRAPPER_SUBPROJECTS} 
        ${GTK_LIBRAREIS} PARENT_SCOPE)
elseif(WIN32)
    add_subdirectory(WinAPI_Wrapper)

    set(GUI_WRAPPER_SUBPROJECTS
        ${GUI_WRAPPER_SUBPROJECTS}
        ${WINAPI_LIBRARIES}
        PARENT_SCOPE
    )

    set(SUBPROJECT_INCLUDE_DIRS 
        ${CMAKE_CURRENT_SOURCE_DIR}/WinAPI_Wrapper/include
        PARENT_SCOPE
    )
endif()
