#! /usr/bin/bash

WORKSPACE_ROOT=/workspaces/tdd-cpp
sudo apt-get update

# Installing vcpkg C/C++ package manager
sudo apt-get --yes install ninja-build # vcpkg uses Ninja for its builds
export VCPKG_ROOT=$WORKSPACE_ROOT/vcpkg
export VCPKG_FORCE_SYSTEM_BINARIES=true # Needed for ARM platforms, like M1 Macs
unset VCPKG_DOWNLOADS # If unset, installation script uses $VCPKG_ROOT/downloads
bash $VCPKG_ROOT/bootstrap-vcpkg.sh # Run installation script
export PATH=$PATH:$VCPKG_ROOT # Allow vcpkg instance to be found by bash

# Installing dependencies for vcpkg packages
sudo apt-get --yes install pkg-config # Needed for GoogleTest
