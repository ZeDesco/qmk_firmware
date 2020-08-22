# dfu-programmer doesn't have darwin on it's list of supported platforms
{ pkgs ? import <nixpkgs> { config = { allowUnsupportedSystem = true; }; }
, avr ? true, arm ? true, teensy ? true }:

with pkgs;
let
<<<<<<< HEAD
  avrbinutils = pkgsCross.avr.buildPackages.binutils;
  avrlibc = pkgsCross.avr.libcCross;
  gcc-arm-embedded = (import (builtins.fetchTarball {
    url = "https://github.com/NixOS/nixpkgs-channels/archive/87f146a41c463a64c93022b11cf19716b3a22037.tar.gz";
    sha256 = "0rk8haf19plw6vyvq0am99rik0hrrysknjw0f2vs7985awngy3q2";
  }) {}).gcc-arm-embedded;
=======
  nixpkgs = builtins.fetchTarball {
    url = "https://github.com/NixOS/nixpkgs/archive/903266491b7b9b0379e88709feca0af900def0d9.tar.gz";
    sha256 = "1b5wjrfgyha6s15k1yjyx41hvrpmd5szpkpkxk6l5hyrfqsr8wip";
  };

  pkgs = import nixpkgs { };

  hjson = with pkgs.python3Packages; buildPythonPackage rec {
    pname = "hjson";
    version = "3.0.1";

    src = fetchPypi {
      inherit pname version;
      sha256 = "1yaimcgz8w0ps1wk28wk9g9zdidp79d14xqqj9rjkvxalvx2f5qx";
    };
    doCheck = false;
  };

  pythonEnv = pkgs.python3.withPackages (p: with p; [
    # requirements.txt
    appdirs
    argcomplete
    colorama
    hjson
    # requirements-dev.txt
    nose2
    flake8
    pep8-naming
    yapf
  ]);
in

with pkgs;
let
  avrlibc = pkgsCross.avr.libcCross;
>>>>>>> upstream/master

  avr_incflags = [
    "-isystem ${avrlibc}/avr/include"
    "-B${avrlibc}/avr/lib/avr5"
    "-L${avrlibc}/avr/lib/avr5"
    "-B${avrlibc}/avr/lib/avr35"
    "-L${avrlibc}/avr/lib/avr35"
    "-B${avrlibc}/avr/lib/avr51"
    "-L${avrlibc}/avr/lib/avr51"
  ];
  avrgcc = pkgsCross.avr.buildPackages.gcc.overrideAttrs (oldAttrs: rec {
    name = "avr-gcc-8.1.0";
    src = fetchurl {
      url = "mirror://gcc/releases/gcc-8.1.0/gcc-8.1.0.tar.xz";
      sha256 = "0lxil8x0jjx7zbf90cy1rli650akaa6hpk8wk8s62vk2jbwnc60x";
    };
  });
in
<<<<<<< HEAD

stdenv.mkDerivation {
  name = "qmk-firmware";

  buildInputs = [ dfu-programmer dfu-util diffutils git ]
    ++ lib.optional avr [ avrbinutils avrgcc avrlibc avrdude ]
=======
mkShell {
  name = "qmk-firmware";

  buildInputs = [ dfu-programmer dfu-util diffutils git pythonEnv ]
    ++ lib.optional avr [
      pkgsCross.avr.buildPackages.binutils
      pkgsCross.avr.buildPackages.gcc8
      avrlibc
      avrdude
    ]
>>>>>>> upstream/master
    ++ lib.optional arm [ gcc-arm-embedded ]
    ++ lib.optional teensy [ teensy-loader-cli ];

  AVR_CFLAGS = lib.optional avr avr_incflags;
  AVR_ASFLAGS = lib.optional avr avr_incflags;
  shellHook = ''
    # Prevent the avr-gcc wrapper from picking up host GCC flags
    # like -iframework, which is problematic on Darwin
    unset NIX_TARGET_CFLAGS_COMPILE
  '';
}
