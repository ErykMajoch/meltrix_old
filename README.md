<div align="center">
<pre>
███╗   ███╗███████╗██╗  ████████╗██████╗ ██╗██╗  ██╗
████╗ ████║██╔════╝██║  ╚══██╔══╝██╔══██╗██║╚██╗██╔╝
██╔████╔██║█████╗  ██║     ██║   ██████╔╝██║ ╚███╔╝ 
██║╚██╔╝██║██╔══╝  ██║     ██║   ██╔══██╗██║ ██╔██╗ 
██║ ╚═╝ ██║███████╗███████╗██║   ██║  ██║██║██╔╝ ██╗
╚═╝     ╚═╝╚══════╝╚══════╝╚═╝   ╚═╝  ╚═╝╚═╝╚═╝  ╚═╝
---
A simple C++ matrix library
</pre>

![Static Badge](https://img.shields.io/badge/Language-C%2B%2B%2017-purple)
![GitHub](https://img.shields.io/github/license/ErykMajoch/Meltrix?style=flat&label=License&color=purple) ![GitHub code size in bytes](https://img.shields.io/github/languages/code-size/ErykMajoch/Meltrix?label=Library%20Size&color=purple) ![GitHub Workflow Status (with event)](https://img.shields.io/github/actions/workflow/status/ErykMajoch/Meltrix/cmake-multi-platform.yml?label=Build)

</div>

## Introduction

Meltrix is a library written in C++ that provides tools for matrix operations. It is designed to be easy to use and to
provide a wide range of functionalities, with the ability to extend it as the user pleases.

## Code Examples

> TODO!

## Installation

### Locally

1. Clone the repository

```bash
git clone https://github.com/ErykMajoch/Meltrix.git
```

2. Install the library using Conan

```bash
cd Meltrix/
conan install .
```

3. Include the library in your projects `conanfile.txt`:

```cfg
[requires]
meltrix/0.1.4
[generators]
CMakeDeps
CMakeToolchain
[layout]
cmake_layout
```

## License

This product is released under **GPL-3**, which is a free software license that allows others to use, modify, and
distribute your software, with the condition that any derivative works must also be released under GPL-3, promoting open
source principles. Users can study, modify, and share the software freely.