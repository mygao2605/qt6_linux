# QT designer for IMX8MQ
## Step 1:Build an image (QT)
```
DISTRO=fsl-imx-wayland MACHINE=imx8mqevk source imx-setup-release.sh -b buildwayland-tuna
bitbake imx-image-full
```
Restarting a build environment
```
source setup-environment <build-dir> 
source setup-environment buildwayland-tuna
```
## Step 2:Build & Install Yocto SDK (cho Qt Creator / Designer)
```
bitbake imx-image-full -c populate_sdk
```
## Step 3: Create a my workspace
```
# 1. Di chuyển vào thư mục Layer (giả sử bạn đã tạo meta-my-app)
cd ~/imx-yocto-bsp
bitbake-layers create-layer meta-my-app
cd build-wayland-tuna
bitbake-layers add-layer ../meta-my-app
cd ~/imx-yocto-bsp/meta-my-app

# 2. Tạo cây thư mục theo cấu trúc chuẩn
mkdir -p recipes-example/myqtapp/files/src

# 3. Tạo các file trống (để sau đó điền nội dung)
touch recipes-example/myqtapp/myqtapp_1.0.bb
touch recipes-example/myqtapp/files/myqtapp.service
touch recipes-example/myqtapp/files/src/CMakeLists.txt
touch recipes-example/myqtapp/files/src/main.cpp
touch recipes-example/myqtapp/files/src/main.qml

# 4. Kiểm tra lại cấu trúc bằng lệnh tree
tree recipes-example/myqtapp/
```
## Step 4: Content in files
Add contents in files


## Step 5: Add the recipes in the build direction

Open the local.conf

```
IMAGE_INSTALL:append = " myqtapp qtwayland"
```

## Step 6: Build the image
```
bitbake myqtapp

bitbake imx-image-full
```