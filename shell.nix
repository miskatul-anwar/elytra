{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = with pkgs; [
    # stdenv.cc.cc.lib
    clang-tools
    # boost
    # cmake
    # ninja
    # spdlog
    # yaml-cpp
    # openssl
    # protobuf
    # gnulib
    # nlohmann_json
    # catch2_3
  ];

  shellHook = ''
    # export CPATH=${pkgs.stdenv.cc.cc.lib}/include/c++/${pkgs.stdenv.cc.version}:$CPATH
    # export LIBRARY_PATH=${pkgs.stdenv.cc.cc.lib}/lib:$LIBRARY_PATH
    # export LD_LIBRARY_PATH=${pkgs.stdenv.cc.cc.lib}/lib:$LD_LIBRARY_PATH
    # export LIBRARY_PATH=${pkgs.gcc}/lib:$LIBRARY_PATH
    echo "Welcome to your C/C++ Competitive Coding nix-shell!"
  '';
}
