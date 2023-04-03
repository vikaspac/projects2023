# projects2023
Working on few study projects






########################Raspberrypi libcamera########################
https://www.raspberrypi.com/documentation/computers/camera_software.html#building-libcamera-and-libcamera-apps



sudo apt update

sudo apt install -y python3-pip git
sudo pip3 install jinja2
sudo apt install -y libboost-dev
sudo apt install -y libgnutls28-dev openssl libtiff5-dev
sudo apt install -y meson
sudo pip3 install pyyaml ply
sudo pip3 install --upgrade meson
sudo apt install -y cmake
sudo apt install -y libglib2.0-dev libgstreamer-plugins-base1.0-dev
sudo apt install -y libevent-dev

sudo apt update


mkdir projects
cd projects
git clone https://github.com/raspberrypi/libcamera.git
cd libcamera
meson build --buildtype=release -Dpipelines=raspberrypi -Dipas=raspberrypi -Dv4l2=true -Dgstreamer=enabled -Dtest=true -Dlc-compliance=disabled -Dcam=enabled -Dqcam=disabled -Ddocumentation=disabled
#meson setup --reconfigure build --buildtype=release -Dpipelines=raspberrypi -Dipas=raspberrypi -Dv4l2=true -Dgstreamer=enabled -Dtest=true -Dlc-compliance=disabled -Dcam=enabled -Dqcam=disabled -Ddocumentation=disabled

ninja -C build   # use -j 2 on Raspberry Pi 3 or earlier devices
sudo ninja -C build install


########################Raspberrypi libcamera-apps########################


sudo apt install -y cmake libboost-program-options-dev libdrm-dev libexif-dev

cd
git clone https://github.com/raspberrypi/libcamera-apps.git
cd libcamera-apps
mkdir build
cd build
cmake .. -DENABLE_DRM=1 -DENABLE_X11=0 -DENABLE_QT=0 -DENABLE_OPENCV=0 -DENABLE_TFLITE=0
make -j1



cd ~/vikas_workspace/opensource/projects/libcamera-apps/build;cmake .. -DENABLE_DRM=1 -DENABLE_X11=0 -DENABLE_QT=0 -DENABLE_OPENCV=0 -DENABLE_TFLITE=0;make -j1; cd ~/vikas_workspace/opensource/projects/libcamera-apps/vikas_apps





