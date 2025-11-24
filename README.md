## About

CI generating conda packages for [panda3d](https://github.com/panda3d/panda3d).

This is a mirror of conda-forge recipe but its main goal is to provide macOS arm64 linux aarch64 packages that are not available yet in conda-forge, as the `panda3d` build chain `makepanda` is not easily cross-compilable for conda builds. Osx-arm64 are made available here thanks to GitHub native macOS arm64 runners (and the same apply for linux aarch64). [PR](https://github.com/conda-forge/panda3d-feedstock/pull/60) in is progress and awaiting some advances in panda3d development or conda-forge infrastructure. 

Packages are uploaded on the [Prefix.dev channel `panda3d-forge`](https://prefix.dev/channels/panda3d-forge).

**Note**: We have moved from Anaconda servers to Prefix.dev for hosting packages. Please do not use Anaconda servers old channel `panda3d-forge` anymore, but `https://prefix.dev/panda3d-forge` instead. See below for install instructions.

## Build status for latest release

![Conda Version](https://img.shields.io/conda/vn/panda3d-forge/panda3d?label=panda3d%20release&color=4dc71f)
![Dynamic YAML Badge](https://img.shields.io/badge/dynamic/yaml?url=https%3A%2F%2Fraw.githubusercontent.com%2Folivier-roussel%2Fpanda3d-forge%2Frefs%2Fheads%2Fmaster%2F.github%2Fworkflows%2Fbuild-publish-panda3d.yml&query=%24.jobs.build-publish-panda3d.strategy.matrix.python&label=Python%20versions) ![Conda Platform](https://img.shields.io/conda/pn/panda3d-forge/panda3d?label=Supported%20platforms)
 
## Install

```
conda install panda3d --channel https://prefix.dev/panda3d-forge
```
