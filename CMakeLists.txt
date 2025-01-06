project(Proto)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
include(FindProtobuf)

file(GLOB_RECURSE ProtoFile "${CMAKE_CURRENT_SOURCE_DIR}/*.proto")
add_library(ProtoObject OBJECT "${ProtoFile}")

find_package(utf8_range REQUIRED)

target_link_libraries(ProtoObject PUBLIC protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)

target_link_libraries(ProtoObject PUBLIC utf8_range::utf8_range utf8_range::utf8_validity)

# this is heuristically generated, and may not be correct
find_package(google_cloud_cpp_bigquery CONFIG REQUIRED)
target_link_libraries(ProtoObject PUBLIC google-cloud-cpp::bigquery google-cloud-cpp::bigquery_protos google-cloud-cpp::cloud_bigquery_protos)

find_package(google_cloud_cpp_bigtable CONFIG REQUIRED)
target_link_libraries(ProtoObject PUBLIC google-cloud-cpp::bigtable google-cloud-cpp::bigtable_protos)

find_package(google_cloud_cpp_common CONFIG REQUIRED)
target_link_libraries(ProtoObject PUBLIC google-cloud-cpp::common)

find_package(google_cloud_cpp_googleapis CONFIG REQUIRED)
# note: 63 additional targets are not displayed.
target_link_libraries(ProtoObject PUBLIC gRPC::grpc gRPC::grpc++ google-cloud-cpp::api_log_protos google-cloud-cpp::api_auth_protos)

find_package(google_cloud_cpp_grpc_utils CONFIG REQUIRED)
target_link_libraries(ProtoObject PUBLIC google-cloud-cpp::grpc_utils)

find_package(google_cloud_cpp_iam CONFIG REQUIRED)
target_link_libraries(ProtoObject PUBLIC google-cloud-cpp::iam google-cloud-cpp::iam_protos)

find_package(google_cloud_cpp_iam_v2 CONFIG REQUIRED)
target_link_libraries(ProtoObject PUBLIC google-cloud-cpp::iam_v2_protos)

find_package(google_cloud_cpp_pubsub CONFIG REQUIRED)
target_link_libraries(ProtoObject PUBLIC google-cloud-cpp::pubsub google-cloud-cpp::pubsub_protos)

find_package(google_cloud_cpp_rest_internal CONFIG REQUIRED)
target_link_libraries(ProtoObject PUBLIC google-cloud-cpp::rest_internal)

find_package(google_cloud_cpp_rest_protobuf_internal CONFIG REQUIRED)
target_link_libraries(ProtoObject PUBLIC google-cloud-cpp::rest_protobuf_internal)

find_package(google_cloud_cpp_spanner CONFIG REQUIRED)
target_link_libraries(ProtoObject PUBLIC google-cloud-cpp::spanner google-cloud-cpp::spanner_protos)

find_package(google_cloud_cpp_storage CONFIG REQUIRED)
target_link_libraries(ProtoObject PUBLIC CURL::libcurl google-cloud-cpp::storage)

target_include_directories(ProtoObject PUBLIC ${CMAKE_CURRENT_BINARY_DIR})



protobuf_generate(
    TARGET ProtoObject
    IMPORT_DIRS "${GOOGLE_CLOUND_INCLUDE_DIR}"
    PROTOC_OUT_DIR "${CMAKE_CURRENT_BINARY_DIR}"
)

