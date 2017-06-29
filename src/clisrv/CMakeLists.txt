message(STATUS "***************************************")
message(STATUS "Processing: ${CMAKE_CURRENT_SOURCE_DIR}")

# Add an executable target called SeqGen to be built from the source files listed
add_executable(cli # <================================= target
    cli.cpp
    )

add_executable(srv # <================================= target
    srv.cpp
    )

# # ----------------------- FOR SEQ ------------------------
# target_link_libraries(cli) # <========================== target
# 	libhdf5 # Needed this in order to use fast5 method in iseq.cpp 
#     ${CMAKE_DL_LIBS}
#     )
# # ----------------------- FOR SEQ ------------------------

message(STATUS "TARGET_LINK_LIBRARIES='${target_link_libraries}'")

install(TARGETS cli RUNTIME DESTINATION bin) # <======= target
install(TARGETS srv RUNTIME DESTINATION bin) # <======= target
