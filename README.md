CKinematics
===========

Types and functions for kinematics variables in collider studies. If you want to use Haskell, see [hep-vector](https://github.com/cbpark/hep-vector).

## Installation and usage

You'll need [cmake](http://www.cmake.org) in order to build and install.

```shell
git clone git@github.com:cbpark/CKinematics.git
cd CKinematics && mkdir build && cd build
cmake -DCMAKE_INSTALL_PREFIX=/some/where ..
make
make install
```

Note that it will be installed in `/usr/local` unless you specify the path for the installation via `-DCMAKE_INSTALL_PREFIX`.

See [CLHCO](https://github.com/cbpark/CLHCO) and [CLHEF](https://github.com/cbpark/CLHEF) for the example usage.
