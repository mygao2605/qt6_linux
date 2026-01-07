# QT designer for IMX8MQ
## Step 1: Build an image (QT)
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
## Step 3:
## Step 4:
