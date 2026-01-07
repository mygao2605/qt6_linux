SUMMARY = "Qt6 application for i.MX8"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

# Quan trọng: Khai báo rõ nơi tìm file
FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

DEPENDS += "qtbase qtdeclarative qtdeclarative-native"

inherit qt6-cmake systemd

# Đảm bảo file .service được liệt kê trong SRC_URI
SRC_URI = "file://src \
           file://myqtapp.service"

S = "${WORKDIR}/src"

SYSTEMD_SERVICE:${PN} = "myqtapp.service"
SYSTEMD_AUTO_ENABLE:${PN} = "enable"

do_install:append() {
    # Tạo thư mục systemd trên image
    install -d ${D}${systemd_system_unitdir}
    
    # SỬA ĐƯỜNG DẪN TẠI ĐÂY:
    # Bitbake unpack file vào ${WORKDIR}/sources-unpack/
    install -m 0644 ${WORKDIR}/sources-unpack/myqtapp.service ${D}${systemd_system_unitdir}
}

RDEPENDS:${PN} += "qtdeclarative-qmlplugins"