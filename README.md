# DEPENDENCIES
## SYSTEM GENERAL
```
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install build-essential \
		     checkinstall \
		     pkg-config \
                     yasm \
                     cmake \
                     git \
                     gfortran \
                     libeigen3-dev \
                     libblas-dev \
                     liblapacke-dev \
                     libprotobuf-dev \
                     protobuf-compiler \
                     libgflags-dev \
                     libjpeg8-dev \
                     libpng-dev \
                     vim \
                     zip \
                     unzip
```
## OPENCV
```
sudo apt-get install libavcodec-dev \
		     libavformat-dev \
		     libswscale-dev \
		     libdc1394-22-dev \
		     libxine2-dev \
		     libv4l-dev \
		     libhdf5-dev \
		     libhdf5-dev \
		     libatlas-base-dev \
		     libjasper-dev \
		     libqtgui4 \
		     libqt4-test \
		     libavcodec-dev \
		     libavformat-dev \
		     libswscale-dev \
		     libdc1394-22-dev \
		     libxine2-dev \
		     libv4l-dev \
		     libgstreamer1.0-dev \
		     libgstreamer-plugins-base1.0-dev \
		     libgtk2.0-dev \
		     libtbb-dev \
		     qt5-default \
		     libatlas-base-dev \
		     libmp3lame-dev \
		     libtheora-dev \
		     libvorbis-dev \
		     libxvidcore-dev \
		     libopencore-amrnb-dev \
		     libopencore-amrwb-dev \
		     libavresample-dev \
		     x264 \
		     v4l-utils

mkdir ~/opencv
cd ~/opencv

git clone https://github.com/opencv/opencv.git
git clone https://github.com/opencv/opencv_contrib.git
cd opencv
mkdir build
cd build

cmake -D CMAKE_BUILD_TYPE=RELEASE \
      -D CMAKE_INSTALL_PREFIX=/usr/local/ \
      -D INSTALL_C_EXAMPLES=OFF \
      -D INSTALL_PYTHON_EXAMPLES=OFF \
      -D BUILD_EXAMPLES=OFF \
      -D ENABLE_FAST_MATH=1 \
      -D WITH_TBB=ON \
      -D WITH_V4L=ON \
      -D WITH_VTK=ON \
      -D WITH_GSTREAMER=ON \
      -D WITH_HALIDE=ON \
      -D WITH_QT=ON \
      -D WITH_OPENGL=ON \
      -D BUILD_opencv_python2=OFF \
      -D BUILD_opencv_python3=ON \
      -D OPENCV_EXTRA_MODULES_PATH=~/opencv_contrib/modules \
      ../

make -j4
make install
sudo ldconfig -v
```
## RASPICAM
```
mkdir ~/raspicam
cd ~/raspicam

git clone https://github.com/cedricve/raspicam.git
cd raspicam
mkdir build
cd build
cmake ..

make
sudo make install
sudo ldconfig
```
## WEBRTC
```
# https://gist.github.com/accuware/370c3fdd758b5cb4b41c6aa2acfe9ce6

mkdir ~/uv4l
cd ~/uv4l

curl http://www.linux-projects.org/listing/uv4l_repo/lpkey.asc | sudo apt-key add -
echo "deb http://www.linux-projects.org/listing/uv4l_repo/raspbian/stretch stretch main" | sudo tee -a /etc/apt/sources.list
sudo apt-get update

# Zero/ZeroW
sudo apt-get install -y uv4l uv4l-raspicam uv4l-raspicam-extras uv4l-webrtc-armv6 uv4l-raspidisp uv4l-raspidisp-extras

# PI 2/3/3b,3b+/4
sudo apt-get install -y uv4l uv4l-raspicam uv4l-raspicam-extras uv4l-webrtc uv4l-raspidisp uv4l-raspidisp-extras
```
