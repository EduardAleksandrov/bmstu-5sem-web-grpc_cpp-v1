# Define Example project
cmake_minimum_required(VERSION 3.12)
project(example)

# Location of files
set(GRPC_INSTALL_DIR "/usr/local")
include_directories(${GRPC_INSTALL_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR})
link_directories(${GRPC_INSTALL_DIR}/lib)

find_package( Protobuf CONFIG REQUIRED)
find_package( gRPC CONFIG REQUIRED)
find_package( absl REQUIRED )

# Client executable
FILE(GLOB CLIENT_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/client.cpp ${CMAKE_CURRENT_SOURCE_DIR}/*.cc)
add_executable(client ${CLIENT_SOURCE_FILES})
target_compile_options(client PUBLIC -std=c++17 -Wall)
target_link_libraries(client protobuf absl::check absl::cord absl::flags absl::flags_parse absl::log absl::log_internal_check_op
    absl::raw_logging_internal absl::status absl::statusor absl::strerror grpc++_reflection grpc++ grpc++_unsecure grpc ssl crypto gpr 
    absl::random_distributions absl::random_internal_randen absl::random_internal_seed_material absl::random_internal_distribution_test_util
    absl::random_internal_randen_hwaes absl::random_seed_gen_exception absl::random_internal_platform absl::random_internal_randen_hwaes_impl 
    absl::random_seed_sequences absl::random_internal_pool_urbg absl::random_internal_randen_slow utf8_range utf8_range_lib utf8_validity 
    upb_base_lib upb_json_lib upb_mem_lib upb_message_lib upb_textformat_lib cares address_sorting z re2 systemd)

# Server executable
FILE(GLOB SERVER_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/server.cpp ${CMAKE_CURRENT_SOURCE_DIR}/*.cc)
add_executable(server ${SERVER_SOURCE_FILES})
target_compile_options(server PUBLIC -std=c++17 -Wall)
target_link_libraries(server protobuf absl::check absl::cord absl::flags absl::flags_parse absl::log absl::log_internal_check_op
    absl::raw_logging_internal absl::status absl::statusor absl::strerror grpc++_reflection grpc++ grpc++_unsecure grpc ssl crypto gpr 
    absl::random_distributions absl::random_internal_randen absl::random_internal_seed_material absl::random_internal_distribution_test_util
    absl::random_internal_randen_hwaes absl::random_seed_gen_exception absl::random_internal_platform absl::random_internal_randen_hwaes_impl 
    absl::random_seed_sequences absl::random_internal_pool_urbg absl::random_internal_randen_slow utf8_range utf8_range_lib utf8_validity 
    upb_base_lib upb_json_lib upb_mem_lib upb_message_lib upb_textformat_lib cares address_sorting z re2 systemd)