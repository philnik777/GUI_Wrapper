project(__GUI_Wrapper_src)
set(GUI_WRAPPER_SUBPROJECTS 
	${GUI_WRAPPER_SUBPROJECTS} 
	__GUI_Wrapper_src 
	PARENT_SCOPE
)

add_library(
	__GUI_Wrapper_src
	Window.cpp
)

target_include_directories(__GUI_Wrapper_src PRIVATE
	${GUI_WRAPPER_INCLUDE_DIR}
	${GUI_WRAPPER_SUBPROJECT_INCLUDE_DIRS}
)

message("added GUI_Wrapper/src")
