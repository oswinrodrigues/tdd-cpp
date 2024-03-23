#! /usr/bin/bash

sudo apt-get update

WORKSPACE_ROOT=/workspaces/tdd-cpp
cd $WORKSPACE_ROOT
git submodule init
git submodule update

# Installing vcpkg C/C++ package manager
sudo apt-get --yes install ninja-build # vcpkg uses Ninja for its builds
export VCPKG_ROOT=$WORKSPACE_ROOT/vcpkg
export VCPKG_FORCE_SYSTEM_BINARIES=true # Needed for ARM platforms, like M1 Macs
unset VCPKG_DOWNLOADS # If unset, installation script uses $VCPKG_ROOT/downloads
bash $VCPKG_ROOT/bootstrap-vcpkg.sh # Run installation script

# Installing dependencies for vcpkg packages
sudo apt-get --yes install pkg-config # Needed for GoogleTest
