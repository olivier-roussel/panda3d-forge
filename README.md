## About

CI generating conda packages for [panda3d](https://github.com/panda3d/panda3d).

This is a mirror of conda-forge recipe but its main goal is to provide macOS arm64 linux aarch64 packages that are not available yet in conda-forge, as the `panda3d` build chain `makepanda` is not easily cross-compilable for conda builds. Osx-arm64 are made available here thanks to GitHub native macOS arm64 runners (and the same apply for linux aarch64). [PR](https://github.com/conda-forge/panda3d-feedstock/pull/60) in is progress and awaiting some advances in panda3d development or conda-forge infrastructure. 

Packages are uploaded on the [Prefix.dev channel `panda3d-forge`](https://prefix.dev/channels/panda3d-forge).

**Note**: We have moved from Anaconda servers to Prefix.dev for hosting packages. Please do not use Anaconda servers old channel `panda3d-forge` anymore, but `https://prefix.dev/panda3d-forge` instead. See below for install instructions.

## Build status for latest release

![Conda Version](https://img.shields.io/badge/panda3d%20release%20-%20v1.10.15-green)
![Python versions](https://img.shields.io/badge/Python%20versions%20-%203.10%2C3.11%2C3.12%2C3.13%2C3.14-blue) ![Conda Platforms](https://img.shields.io/badge/Supported%20platforms-linux--64%20%7C%20linux--aarch64%20%7C%20osx--64%20%7C%20osx--arm64%20%7C%20win--64-lightgrey)
 
## Install

```
conda install panda3d --channel https://prefix.dev/panda3d-forge
```
