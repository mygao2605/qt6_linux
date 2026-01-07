cmake_minimum_required(VERSION 3.16)

project(myqtapp VERSION 1.0 LANGUAGES CXX)

# Tự động xử lý MOC, UIC và RCC
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Chỉ định chuẩn C++ cho Qt 6
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Tìm các gói thư viện Qt 6
find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)

# 2. Định nghĩa file thực thi
qt_add_executable(myqtapp 
    main.cpp
)

# 3. Đăng ký module QML và nhúng file QML vào binary (Resource)
# Việc dùng qt_add_qml_module giúp tránh lỗi không tìm thấy file .qml khi chạy
qt_add_qml_module(myqtapp
    URI my.app
    VERSION 1.0
    QML_FILES main.qml
)

# 4. Liên kết thư viện
target_link_libraries(myqtapp PRIVATE 
    Qt6::Core 
    Qt6::Gui 
    Qt6::Qml 
    Qt6::Quick
)

# 5. Cấu hình CÀI ĐẶT (INSTALL) - Cực kỳ quan trọng cho Yocto
include(GNUInstallDirs)

# Cài đặt file chạy vào /usr/bin
install(TARGETS myqtapp
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)