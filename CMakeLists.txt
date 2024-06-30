

cmake_minimum_required(VERSION 3.5.0)
project(make_vdb VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

# Eigenのインクルードディレクトリを追加
include_directories(${PROJECT_SOURCE_DIR}/libs/eigen-3.4.0)

# OpenVDBの設定
list(APPEND CMAKE_MODULE_PATH "/usr/lib/x86_64-linux-gnu/cmake/OpenVDB")
find_package(OpenVDB REQUIRED)

# 実行ファイルを生成
add_executable(make_vdb main.cpp)

# ライブラリをリンク
target_link_libraries(make_vdb PUBLIC OpenVDB::openvdb "-pthread")

# プロジェクト名とバージョンを設定
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)