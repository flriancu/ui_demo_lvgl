# ui_demo_lvgl

Minimal desktop wrapper for the `lvgl` embedded GUI library.

This repository is adapted from the [official integration example](https://github.com/lvgl/lv_port_pc_vscode) to optionally work with `vcpkg`.

## Prerequisites

This project is cross-platform. It requires `cmake`, `sdl2` and your favorite build tools for the C language.

It works best with `vcpkg` and `vscode`, which are highly recommended.

Note that `sdl2` can be easily replaced with any other `lvgl` dirvers.

## Installation

1.  Install `cmake`.
2.  Install your favorite build tools for the C language.
3.  Optionally, install `vcpkg`, ideally in your user's home directory.
4.  Optionally, install `vscode`.
5.  If not using `vcpkg`, install `sdl2` on your system.
6.  Clone this repository and its submodules.
7.  If not using `vscode`, from the top-level directory of the repository, use `cmake` to build the project. Otherwise, open `vscode`, install the recommended extensions, and build the project.
