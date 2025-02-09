## Runing ROOT in NeoVim with clang++

### Install NeoVim

First, you must intall neovim

```bash
sudo apt update && sudo apt install neovim
```
For Arch Linux, Use

```bash
sudo pacman -Syu && sudo pacman -S neovim
```

Optional: Install `NvChad` by running

```bash
git clone https://github.com/NvChad/NvChad ~/.config/nvim --depth 1 && nvim
```

Once installed, open Neovim

```bash
nvim
```

### Required dependences

To compile the ROOT flags, diagnostics, and general LSP correctly, be sure of have all of the required dependences.

```bash
sudo apt update && sudo apt install -y cmake git g++ gcc binutils libx11-dev libxpm-dev \
     libxft-dev libxext-dev python3 libssl-dev
sudo apt install -y build-essential clang clangd clang-format
```

For Arch Linux, Use

```bash
sudo pacman -S --needed cmake git glew glu mesa gsl python python-pip
sudo pacman -S mingw-w64-ucrt-x86_64-toolchain
sudo pacman -S mingw-w64-ucrt-x86_64-clang mingw-w64-ucrt-x86_64-clang-tools-extra
```

This will install:
✅ gcc
✅ g++
✅ clang
✅ clang++
✅ c++ (Standard C++ compiler wrapper)

Verify installation by running

```bash
gcc --version
g++ --version
clang --version
clang++ --version
```

### Install ROOT

To install CERN ROOT in your system, run

```bash
sudo apt install -y root-system
```

In Arch Linux, run

```bash
sudo apt install -y root-system
```

Now, clone the ROOT repository in ~ and compile

```bash
cd ~
git clone --branch latest-stable https://github.com/root-project/root.git
cd root
mkdir build && cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/opt/root
cmake --build . -- -j$(nproc)
sudo cmake --install .
```

Set environment variables by adding this to your shell config (~/.bashrc or ~/.zshrc):

```bash
export ROOTSYS=/opt/root
export PATH=$ROOTSYS/bin:$PATH
export LD_LIBRARY_PATH=$ROOTSYS/lib:$LD_LIBRARY_PATH
export PYTHONPATH=$ROOTSYS/lib:$PYTHONPATH
source ~/root/bin/thisroot.sh
```

Apply changes and verify installation:

```bash
source ~/.bashrc
root
```

### Configure NeoVim for C++ LSP including ROOT

Now, you must install the vim plugin for lsp, by adding this to you `~/.config/nvim/lua/plugins/init.lua` file in case of does not be added:

```lua
  {
    "nvim-treesitter/nvim-treesitter",
    init = require("core.utils").lazy_load "nvim-treesitter",
    cmd = { "TSInstall", "TSBufEnable", "TSBufDisable", "TSModuleInfo" },
    build = ":TSUpdate",
    opts = function()
      return require "plugins.configs.treesitter"
    end,
    config = function(_, opts)
      dofile(vim.g.base46_cache .. "syntax")
      require("nvim-treesitter.configs").setup(opts)
    end,
  },
  
  {
    "neovim/nvim-lspconfig",
    init = require("core.utils").lazy_load "nvim-lspconfig",
    config = function()
      require "plugins.configs.lspconfig"
    end,
  },

```

Create a directory in which you are going to work your ROOT projects, for example, `~/Documents/cern-root` and create the `build/CMakeLists.txt` file to load commands, flags, and so on, for ROOT program:

```bash
mkdir -p ~/Documents/cern-root/build
cd !$
touch CMakeLists.txt
```

In your new `CMakeLists.txt` file, write the following sentences

```txt
cmake_minimum_required(VERSION 3.16)
project(root_project)

set(CMAKE_CXX_STANDARD 17)  # Change to 20 if you use C++20

execute_process(COMMAND root-config --cflags --libs OUTPUT_VARIABLE ROOT_FLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ROOT_FLAGS}")

file(GLOB_RECURSE SRC_FILES *.cpp)
add_executable(program ${SRC_FILES})
```

Create the `compile_commands.json` file into the build directory by running

```bash
cmake . -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
```

Now, create manually the file to compile ROOT flags by running

```bash
touch compile_flags.txt
```
And edit this file writing:
```txt
`root-config --cflags`
`root-config --libs`
-I/usr/include/c++/11
```

Change `-I/usr/include/c++/11` in the above code for your `c++` version.

Link `compile_commands.json` and `compile_flags.txt` to avoid errors in `clangd`:

```bash
ln -s ~/Documents/cern-root/build/compile_commands.json ~/Documents/cern-root/compile_commands.json
ln -s ~/Documents/cern-root/build/compile_flags.txt ~/Documents/cern-root/compile_flags.txt
```

Finally, configure the `clangd` LSP correctly. Copy the following code into `.config/nvim/lua/custom/configs/lspconfig.lua`

```lua
require'lspconfig'.clangd.setup{
  cmd = { "clangd", "--background-index", "--compile-commands-dir=build", "--query-driver=/usr/bin/g++"},
  filetypes = { "c", "cpp" },
    root_dir = lspconfig.util.root_pattern("compile_commands.json", "compile_flags.txt", ".git"),
  capabilities = require('cmp_nvim_lsp').default_capabilities(),
  on_attach = function(client, bufnr)
    vim.env.ROOTSYS = '~/root'
    vim.env.ROOT_INCLUDE_PATH = '~/root/include'
    vim.env.LD_LIBRARY_PATH = '~/root/lib'
    local opts = { noremap=true, silent=true, buffer=bufnr }
    vim.keymap.set('n', 'gd', vim.lsp.buf.definition, opts)
    vim.keymap.set('n', 'K', vim.lsp.buf.hover, opts)
    vim.keymap.set('n', '<leader>rn', vim.lsp.buf.rename, opts)
  end,
}

```

### Example of usage

All of the codes in `c++` that you want to run with ROOT must be stored into `~/Documents/cern-root/`.
For instance, we are going to create a file colled `example.cpp` and after edit it with NeoVim:

```bash
cd ~/Documents/cern-root
touch example.cpp
nvim example.cpp
```

Here, into NeoVim, write the following example code:

```cpp
#include <iostream>
#include <TCanvas.h>
#include <TRandom3.h>
#include <TH1D.h>

using namespace std;

void example() {
    TCanvas * c1 = new TCanvas("c1", "Histograms", 800, 600);
    TH1D * h1 = new TH1D("h1", "this is my tittle; x name; frequency", 50, 0, 100);
    TRandom3 * r = new TRandom3();

    for (int ij = 0; ij < 100; ij++) {
        //h1->Fill(r->Uniform(20,70));
        h1->Fill(r->Gaus(30,10));
    }
    
    int bins = h1->GetNbinsX();
    
    int b=1;

    while (b<bins)
    {
        cout<<b<<"\t"<<h1->GetBinCenter(b)<<"\t"<<h1->GetBinContent(b)<<endl;
        b++;
    }

    h1->Fit("gaus");
    //h1->Draw("hist");
    h1->Draw();

    //h1->SetMaximum(120);
    //h1->SetMinimum(-10);
    h1->SetStats(0); //Hide the stats in the top square
    h1->GetXaxis()->SetRangeUser(5,70);

}

```
Verify that there are not flags.

Now, into `~/Documents/cern-root/` run:

```bash
root -l
.x example.cpp
```

Enjoy HEP!
